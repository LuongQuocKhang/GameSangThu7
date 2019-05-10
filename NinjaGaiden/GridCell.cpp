#include "GridCell.h"
#include "Grid.h"


void GridCell::ExtractTiles(vector<Tile *> &output)
{
	output.insert(output.end(), this->tiles.begin(), this->tiles.end());
}

void GridCell::ExtractGameObjects(vector<GameObject *> &output)
{
	output.insert(output.end(), this->gameObjects.begin(), this->gameObjects.end());
}

void GridCell::Update(DWORD dt)
{
	return;
}
void GridCell::Render()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		TiledMap::GetInstance()->RenderTile(tiles[i]);
	}
}

GridCell::~Cell()
{
}
