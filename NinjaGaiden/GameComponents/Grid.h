#pragma once
#include "GameObject.h"
#include "Constants.h" 
#include "GridCell.h"
#include "Ninja.h"
#include <vector>

#include <fstream>
#include <string>

#define POSTOCELL(K) (int)(K/GRID_SIZE);
#define POSXTOCELL(K) (int)(K/GRID_SIZE);
#define POSYTOCELL(K) (int)(K % GRID_SIZE == 0 ? K/GRID_SIZE - 1 : K/GRID_SIZE);

using namespace std;

class Cell;

typedef vector<GridCell *> CellRow;
typedef vector<CellRow> CellMatrix;

class Grid {
private:
	static Grid * __instance;
	int width, height;

	CellMatrix cells;

	vector<Tile *> curTiles;
	vector<Tile *> CollisionTiles;
	vector<GameObject *> curGameObjects;
	vector<Enemy* > enemies;
	Viewport *viewport;
	Ninja * ninja;

	void LoadEnemy(LPCWSTR filePath);

	Grid();

public:

	static Grid * GetInstance();
	void LoadCells();

	void GetCameraPosOnGrid(int &l, int &r, int &t, int &b);
	void GetNinjaPosOnGrid(int &l, int &r, int &t, int &b);

	vector<Tile *> GetCurTiles() { return this->curTiles; }
	vector<Tile *> GetCollisionTiles() { return this->CollisionTiles; }
	vector<GameObject *> GetCurGameObjects() { return this->curGameObjects; }
	vector<Enemy*> GetEnemies() { return enemies; }

	void ReadEnemiesFromFIle(Stage GameStage);
	void Update(DWORD dt);
	void Render();

	CellMatrix GetTile() { return this->cells; }

	void AddEnemy(Enemy* enemy)
	{
		enemies.push_back(enemy);
	}
	void DeleteEnemy(int pos)
	{
		this->enemies.erase(enemies.begin() + pos);
	}
	static void SetNewGrid()
	{
		__instance = NULL;
		__instance = new Grid();
	}
	~Grid() {
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
			{
				if (cells[i][j] != NULL)
					delete cells[i][j];
			}
	}
};