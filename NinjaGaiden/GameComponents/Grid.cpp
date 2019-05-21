﻿#include"Grid.h"
#include "Game.h"

Grid * Grid::__instance = NULL;
bool CellGameObjectAABB(GridCell * cell, GameObject * obj)
{
	return (
		cell->GetPositionX() < obj->GetPositionX() + obj->GetWidth() &&
		cell->GetPositionX() + GRID_SIZE > obj->GetPositionX() &&
		cell->GetPositionY() > obj->GetPositionY() - obj->GetHeight() &&
		cell->GetPositionY() - GRID_SIZE < obj->GetPositionY()
		);
}
bool CellTileAABB(GridCell * cell, Tile & tile)
{
	return (
		cell->GetPositionX() < tile.x + tile.width &&
		cell->GetPositionX() + GRID_SIZE > tile.x &&
		cell->GetPositionY() > tile.y - tile.height &&
		cell->GetPositionY() - GRID_SIZE < tile.y
		);
}

Grid::Grid()
{
	curTiles.clear();

	//khoi tao danh sach cac o trong
	this->width = (int)(Game::GetInstance()->GetTiledMap()->GetWidth() / 64) + 2;
	this->height = (int)(Game::GetInstance()->GetTiledMap()->GetHeight() / 64) + 2;

	for (int i = 0; i < height; i++)
	{
		CellRow curRow;
		for (int j = 0; j < width; j++)
		{
			GridCell * curCell = new GridCell(j, i);
			curRow.push_back(curCell);
		}
		cells.push_back(curRow);
	}
	LoadCells();

	//Luu viewport
	this->viewport = Viewport::GetInstance();
	//Lưu ninja
	this->ninja = Ninja::GetInstance();

	ReadEnemiesFromFIle(Game::GetInstance()->GetStage());
}
void Grid::LoadEnemy(LPCWSTR filePath, Stage gamestage)
{
	ifstream tilesInfo;
	DebugOut(L"filepath: %s\n", filePath);
	tilesInfo.open(filePath);

	int mapheight = TiledMap::GetInstance()->GetHeight();

	string line;
	int token;
	if (tilesInfo.is_open())
	{
		while (getline(tilesInfo, line))
		{
			size_t pos = 0;
			int rowNum = 0 , posx = 0, posy = 0 , type = 0;

			while ((pos = line.find(" ")) != string::npos)
			{
				token = stoi(line.substr(0, pos));
				if (rowNum == Column::Type)
				{
					type = token;
				}
				else if (rowNum == Column::PosX) posx = token;
				else if (rowNum == Column::PosY)
				{
					if (type == YELLOWSOLDIER)
					{
						posy = mapheight - token + 50;
					}
					else
					{
						posy = mapheight - token;
					}
				}

				line.erase(0, pos + 1);
				rowNum++;
			}
			LoadEnemy(type, posx, posy);

		}
		tilesInfo.close();
	}
}
void Grid::LoadEnemy(int type , int posx , int posy)
{
	Enemy * enemy = NULL;
	switch (type)
	{
	case YELLOWSOLDIER:
		enemy = new YellowSolider(posx, posy);
		break;
	case REDBIRD:
		enemy = new RedBird(posx, posy);
		break;
	case BROWNBIRD:
		enemy = new BrownBird(posx, posy);
		break;
	case YELLOWPANTHER:
		enemy = new YellowPanther(posx, posy);	
		break;
	case PINKWITCH:
		enemy = new PinkWitch(posx, posy);
		break;
	case GREENSOLDIER:
		enemy = new GreenSolider(posx, posy);
		break;
	case BLOODYBIRD:
		enemy = new BloodyBird(posx, posy);
		break;
	case GREENCANONSOLDIER:
		enemy = new GreenCanonSoldier(posx, posy);
		break;
	case GREENRUNNINGSOLDIER:
		enemy = new GreenRunningSoldier(posx, posy);
		break;
	default:
		break;
	}
	if (enemy != NULL)
	{
		if (type != YELLOWPANTHER)
		{
			enemy->TurnLeft();
		}
		int cellX = POSXTOCELL(posx);
		int cellY = POSYTOCELL(posy);

		cells[cellY][cellX]->AddEnemy(enemy);
		enemies.push_back(enemy);
	}
}


void Grid::LoadCells()
{
	Matrix &tiledMapMatrix = Game::GetInstance()->GetTiledMap()->GetMatrix();
	for (int i = 0; i < tiledMapMatrix.size(); i++)
	{
		for (int j = 0; j < tiledMapMatrix[i].size(); j++)
		{
			//Tim vi tri o chua tile
			int cellX = POSXTOCELL(tiledMapMatrix[i][j].x);
			int cellY = POSYTOCELL(tiledMapMatrix[i][j].y);

			Tile * dummyPtr = &tiledMapMatrix[i][j];
			cells[cellY][cellX]->AddTile(dummyPtr);

			if (tiledMapMatrix[i][j].type == ObjectType::BRICK)
			{
				CollisionTiles.push_back(dummyPtr);
			}
		}
	}
}

void Grid::GetCameraPosOnGrid(int &l, int &r, int &t, int &b) {
	RECT rect = viewport->GetRect();
	l = (int)(rect.left / GRID_SIZE);
	t = (int)(rect.top % GRID_SIZE == 0 ? rect.top / GRID_SIZE - 1 : rect.top / GRID_SIZE);
	r = (int)(rect.right / GRID_SIZE);
	b = (int)(rect.bottom / GRID_SIZE);
}

void Grid::GetNinjaPosOnGrid(int &l, int &r, int &t, int &b)
{
	RECT rect = ninja->GetRect();
	l = (int)(rect.left / GRID_SIZE);
	t = (int)(rect.top % GRID_SIZE == 0 ? rect.top / GRID_SIZE - 1 : rect.top / GRID_SIZE);
	r = (int)(rect.right / GRID_SIZE);
	b = (int)(rect.bottom / GRID_SIZE);
}
void Grid::ReadEnemiesFromFIle(Stage GameStage)
{
	LPCWSTR filePath = L"";
	if (GameStage == Stage::STAGE_31)
	{
		enemies.clear();
		filePath = ENEMIES_MAP_31;
	}
	else if (GameStage == Stage::STAGE_32)
	{
		enemies.clear();
		filePath = ENEMIES_MAP_32;
	}
	else if (GameStage == Stage::STAGE_BOSS)
	{
		enemies.clear();
		filePath = ENEMIES_MAP_BOSS;
	}
	LoadEnemy(filePath, GameStage);
}
void Grid::Update(DWORD dt)
{
	int lCell, rCell, tCell, bCell;
	this->GetCameraPosOnGrid(lCell, rCell, tCell, bCell);

	//Update ninja
	curTiles.clear();
	curEnemies.clear();
	
	for (size_t i = 0; i < cells.size(); i++)
	{
		for (size_t j = 0; j < cells[i].size(); j++)
		{
			cells[i][j]->clear();
		}
	}

	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i]->GetPositionY() < 50)
		{
			enemies.erase(enemies.begin() + i);
		}
		else
		{
			enemies[i]->Update(dt);
		}
	}

	for (int i = 0; i < enemies.size(); i++)
	{
		int cellX = POSXTOCELL((int)enemies[i]->GetPositionX());
		int cellY = POSYTOCELL((int)enemies[i]->GetPositionY());

		if (enemies[i]->Isdeath() == false && enemies[i]->IsActive() == true )
		{
			cells[cellY][cellX]->AddEnemy(enemies[i]);
		}
	}

	int ninjaLCell, ninjaRCell, ninjaTCell, ninjaBCell;
	this->GetNinjaPosOnGrid(ninjaLCell, ninjaRCell, ninjaTCell, ninjaBCell);
	for (int i = ninjaBCell; i <= ninjaTCell; i++)
	{
		for (int j = ninjaLCell; j <= ninjaRCell; j++)
		{
			cells[i][j]->InsertTiles(curTiles);		
			cells[i][j]->InsertEnemies(curEnemies);		
		}
	}
	ninja->Update(dt);
}
void Grid::Render()
{
	int lCell, rCell, tCell, bCell;
	this->GetCameraPosOnGrid(lCell, rCell, tCell, bCell);
	curTiles.clear();
	curEnemies.clear();

	for (int i = bCell; i <= tCell; i++)
	{
		for (int j = lCell; j <= rCell; j++)
		{
			cells[i][j]->Render();
		}
	}

	ninja->Render();
	for (size_t i = 0; i < enemies.size(); i++)
	{
		//if (Viewport::GetInstance()->IsEnemyInCamera(enemies[i]))
		if (enemies[i]->IsActive() == true)
		{
			enemies[i]->Render();
		}
	}
}

Grid * Grid::GetInstance()
{
	if (__instance == NULL)
		__instance = new Grid();
	return __instance;
}
