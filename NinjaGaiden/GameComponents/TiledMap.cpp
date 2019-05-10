#include "TiledMap.h"
#include "Game.h"

TiledMap::TiledMap(LPCWSTR filePath)
{
	infoLocation = filePath;
	
	LoadMap(filePath);
}
Row TiledMap::GetMatrixRow(int lineNum, string line, string delimiter)
{
	size_t pos = 0;
	string token;
	Row result = Row();
	int rowNum = 0;
	Stage stage = Game::GetInstance()->GetStage();
	while ((pos = line.find(delimiter)) != string::npos)
	{
		token = line.substr(0, pos);

		Tile curTile;
		curTile.x = rowNum * TILES_WIDTH_PER_TILE;
		curTile.y = this->mapHeight - lineNum * TILES_HEIGHT_PER_TILE;
		curTile.tileId = stoi(token);
		if (Stage::STAGE_31 == stage)
		{
			if (find(_BrickStage_31.begin(), _BrickStage_31.end(), curTile.tileId) != _BrickStage_31.end())
				curTile.type = ObjectType::BRICK;
			else
				curTile.type = ObjectType::DEFAULT;
		}
		result.push_back(curTile);
		line.erase(0, pos + delimiter.length());
		rowNum++;
	}

	return result;
}
std::wstring s2ws(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
//
void TiledMap::LoadMap(LPCWSTR filePath)
{
	string tilesLocation = LoadMatrix(filePath);

	std::wstring stemp = s2ws(tilesLocation);
	LPCWSTR wstrTilesLocation = stemp.c_str();
	LoadTileSet(wstrTilesLocation);
}
string TiledMap::LoadMatrix(LPCWSTR filePath)
{
	string tilesLocation;

	ifstream tilesInfo;
	DebugOut(L"filepath: %s\n", filePath);
	tilesInfo.open(filePath);
	if (tilesInfo.is_open())
	{
		getline(tilesInfo, tilesLocation);

		string line;
		Row matrixRow;
		this->matrix.clear();

		int lineNum = 0;
		while (getline(tilesInfo, line))
		{
			matrixRow = GetMatrixRow(lineNum,line, TILES_MATRIX_DELIMITER);
			this->matrix.push_back(matrixRow);
			lineNum++;
		}
		tilesInfo.close();
	}
	return tilesLocation;

}
void TiledMap::LoadTileSet(LPCWSTR tilesLocation)
{
	HRESULT result;
	//Thông tin tileset
	D3DXIMAGE_INFO info;
	//Lấy thông tin texture từ đường dẫn file
	result = D3DXGetImageInfoFromFile(tilesLocation, &info);
	//Kiểm tra lỗi khi lấy thông tin
	if (result != D3D_OK)
	{
		DebugOut(L"[ERROR] Load Map Tileset failed: %s\n", tilesLocation);
		return;
	}
	this->tileSetWidth = info.Width / TILES_WIDTH_PER_TILE;
	this->tileSetHeight = info.Height / TILES_HEIGHT_PER_TILE;

	if (Game::GetInstance()->GetStage() == STAGE_31)
	{
		result = D3DXGetImageInfoFromFile(BACKGROUND_3_1, &info);
	}
	else if (Game::GetInstance()->GetStage() == STAGE_32)
	{
		result = D3DXGetImageInfoFromFile(BACKGROUND_3_2, &info);
	}
	else if (Game::GetInstance()->GetStage() == STAGE_BOSS)
	{
		result = D3DXGetImageInfoFromFile(BACKGROUND_BOSS, &info);
	}
	this->mapWidth = info.Width;
	this->mapHeight = info.Height;
	
	for (int i = 0; i < this->tileSetHeight * this->tileSetWidth; i++)
	{
		RECT rect;
		rect.left = (i % this->tileSetWidth) * TILES_WIDTH_PER_TILE;
		rect.right = rect.left + TILES_WIDTH_PER_TILE;
		rect.top = (i / this->tileSetWidth) * TILES_HEIGHT_PER_TILE;
		rect.bottom = rect.top + TILES_HEIGHT_PER_TILE;

		Sprite * tile = new Sprite(tilesLocation, rect, TILES_TRANSCOLOR);

		tiles[i + 1] = tile;
	}
}

void TiledMap::AddObjects(Stage stage)
{
	
}

TiledMap::~TiledMap()
{

}

int TiledMap::GetWidth()
{
	return mapWidth;
}
int TiledMap::GetHeight()
{
	return mapHeight;
}
int TiledMap::GetTileWidth()
{
	return this->tileSetWidth;
}
int TiledMap::GetTileHeight()
{
	return this->tileSetHeight;
}
void TiledMap::Render()
{
	for (int i = 0; i < matrix.size(); i++)
	{
		Row curRow = matrix[i];
		for (int j = 0; j < curRow.size(); j++)
		{
			if (curRow[j].tileId != 0)
			{
				SpriteData spriteData;
				spriteData.width = TILES_WIDTH_PER_TILE;
				spriteData.height = TILES_HEIGHT_PER_TILE;
				spriteData.x = j * TILES_WIDTH_PER_TILE;
				spriteData.y = (matrix.size() - i) * TILES_HEIGHT_PER_TILE;
				spriteData.scale = 1;
				spriteData.angle = 0;
				
				tiles.at(curRow[j].tileId)->SetData(spriteData);
				Graphics::GetInstance()->Draw(tiles.at(curRow[j].tileId));
			}
		}
	}
}