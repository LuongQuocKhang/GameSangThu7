#pragma once

#include <d3dx9.h>
#include <d3d9.h>
#include <vector>
#include <unordered_map> 
#include <iostream>
#include <fstream>
#include <string>

#include "Sprite.h"
#include "Debug.h"
#include "Constants.h"
#include "Brick.h"

using namespace std;

struct Tile {
	int tileId;
	ObjectType type; 
	int x, y;
	int width = 16, height = 16;
};

typedef vector<Tile> Row;
typedef vector<Row> Matrix;

typedef vector<vector<Brick*>> BrickMatrix;
typedef vector<Brick*> BrickRow;

typedef GameObject * BrickTile;

typedef vector<BrickTile> BrickTileSet;

const vector<int> _BrickStage_31{ 71 , 72 , 24 , 26 , 25 , 76 , 70 , 77 , 61 };
const vector<int> _BrickStage_32{ 19 , 8 , 18 , 20 , 21 , 30 , 26 , 32 , 33 , 47 };
const vector<int> _BrickStage_BOSS{ 40 , 68 , 23 , 151 , 130 , 113 , 99 , 78 , 47 , 31 , 4 };

class TiledMap
{
private:
	static TiledMap * __instance;

	void LoadMap(LPCWSTR filePath);
	string LoadMatrix(LPCWSTR filePath);
	void LoadTileSet(LPCWSTR tilesLocation);
	Matrix matrix;

	void AddObjects(Stage stage);
	int mapWidth, mapHeight;
	int tileSetWidth, tileSetHeight;

	Row GetMatrixRow(int lineNum, string line, string delimiter);

	LPCWSTR infoLocation;
	unordered_map<int, Sprite*> tiles;

public:
	static TiledMap * GetInstance(LPCWSTR filePath = NULL);
	TiledMap(LPCWSTR filePath);

	int GetWidth();
	int GetHeight();
	int GetTileWidth();
	int GetTileHeight();

	Matrix& GetMatrix() { return this->matrix; }

	void RenderTile(Tile * curTile);
	void Render();

	~TiledMap();
};