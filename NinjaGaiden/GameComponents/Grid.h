#pragma once
#include "GameObject.h"
#include "Constants.h" 
#include "GridCell.h"
#include "Ninja.h"
#include <vector>
#define POSTOCELL(K) (int)(K/GRID_SIZE);
#define POSXTOCELL(K) (int)(K/GRID_SIZE);
#define POSYTOCELL(K) (int)(K % GRID_SIZE == 0 ? K/GRID_SIZE - 1 : K/GRID_SIZE);


class Cell;

typedef vector<GridCell *> CellRow;
typedef vector<CellRow> CellMatrix;

class Grid {
private:
	static Grid * __instance;
	int width, height;

	CellMatrix cells;

	vector<Tile *> curTiles;
	vector<GameObject *> curGameObjects;
	vector<Enemy* > enemies;
	Viewport *viewport;
	Ninja * ninja;

	void LoadEnemy();

	Grid();

public:

	static Grid * GetInstance();
	void LoadCells();

	void GetCameraPosOnGrid(int &l, int &r, int &t, int &b);
	void GetNinjaPosOnGrid(int &l, int &r, int &t, int &b);

	vector<Tile *> GetCurTiles() { return this->curTiles; }
	vector<GameObject *> GetCurGameObjects() { return this->curGameObjects; }
	vector<Enemy*> GetEnemies() { return enemies; }

	void Update(DWORD dt);
	void Render();

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