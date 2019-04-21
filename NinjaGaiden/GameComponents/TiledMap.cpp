#include "TiledMap.h"
#include "Game.h"

TiledMap::TiledMap(LPCWSTR filePath)
{
	infoLocation = filePath;
	
	LoadMap(filePath);

	mapsObject.clear();

	AddObjects(Game::GetInstance()->GetStage());
}
//Lấy dữ liệu đọc chuyển thành dòng trong ma trận
Row GetMatrixRow(string line, string delimiter)
{
	size_t pos = 0;
	string token;
	Row result = Row();
	while ((pos = line.find(delimiter)) != string::npos)
	{
		token = line.substr(0, pos);
		result.push_back(stoi(token));
		line.erase(0, pos + delimiter.length());
	}

	return result;
}
// -> stackoverflow.com => chuyển string thành wstring
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
		while (getline(tilesInfo, line))
		{
			matrixRow = GetMatrixRow(line, TILES_MATRIX_DELIMITER);
			this->matrix.push_back(matrixRow);
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
	tiles[0] = 0;
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
	
	for (int i = 0; i < matrix.size(); i++)
	{
		Row curRow = matrix[i];
		BrickRow Row;
		for (int j = 0; j < curRow.size(); j++)
		{
			if (Stage::STAGE_31 == stage)
			{
				Brick * brick = new Brick();
				if (71 == curRow[j] || 72 == curRow[j] || 24 == curRow[j] || 26 == curRow[j] || 25 == curRow[j]
					|| 76 == curRow[j] || 70 == curRow[j] || 77 == curRow[j] || 61 == curRow[j])
				{
					brick->SetType(ObjectType::BRICK);
					brick->SetPositionX(j * TILES_WIDTH_PER_TILE);
					brick->SetPositionY((matrix.size() - i) * TILES_HEIGHT_PER_TILE);
				}
				else if (36 == curRow[j] || 38 == curRow[j])
				{
					brick->SetType(ObjectType::BRICK);
					brick->SetPositionX(j * (TILES_WIDTH_PER_TILE - 10));
					brick->SetPositionY((matrix.size() - i) * (TILES_HEIGHT_PER_TILE - 10));
				}
				else
				{
					brick->SetType(ObjectType::DEFAULT);
					brick->SetPositionX(j * TILES_WIDTH_PER_TILE);
					brick->SetPositionY((matrix.size() - i) * TILES_HEIGHT_PER_TILE);
				}
				Row.push_back(brick);
			}
			else if (Stage::STAGE_32 == stage) {
				Brick * brick = new Brick();
				if (19 == curRow[j] || 8 == curRow[j] || 18 == curRow[j] || 20 == curRow[j] || 21 == curRow[j] || 30 == curRow[j]
					|| 26 == curRow[j] || 32 == curRow[j] || 33 == curRow[j] || 47 == curRow[j])
				{
					brick->SetType(ObjectType::BRICK);
					brick->SetPositionX(j * TILES_WIDTH_PER_TILE);
					brick->SetPositionY((matrix.size() - i) * TILES_HEIGHT_PER_TILE);
				}
				else
				{
					brick->SetType(ObjectType::DEFAULT);
					brick->SetPositionX(j * TILES_WIDTH_PER_TILE);
					brick->SetPositionY((matrix.size() - i) * TILES_HEIGHT_PER_TILE);
				}
				Row.push_back(brick);
			}
			else if (Stage::STAGE_BOSS == stage) {
				Brick * brick = new Brick();
				
				if (40 == curRow[j] || 68 == curRow[j] || 23 == curRow[j] || 151 == curRow[j] 	
					|| 130 == curRow[j] || 113 == curRow[j] || 99 == curRow[j]
					|| 78 == curRow[j] || 47 == curRow[j] || 31 == curRow[j] || 4 == curRow[j] )
				{
					brick->SetType(ObjectType::BRICK);
					brick->SetPositionX(j * TILES_WIDTH_PER_TILE);
					brick->SetPositionY((matrix.size() - i) * TILES_HEIGHT_PER_TILE);
				}
				else if (curRow[j]>=154 && curRow[j]<176)
				{
					brick->SetType(ObjectType::BRICK);
					brick->SetPositionX(j * TILES_WIDTH_PER_TILE);
					brick->SetPositionY((matrix.size() - i) * TILES_HEIGHT_PER_TILE);
				}
				else
				{
					brick->SetType(ObjectType::DEFAULT);
					brick->SetPositionX(j * TILES_WIDTH_PER_TILE);
					brick->SetPositionY((matrix.size() - i) * TILES_HEIGHT_PER_TILE);
				}
				Row.push_back(brick);
			}
		}
		mapsObject.push_back(Row);
	}
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
			if (curRow[j] != 0)
			{
				SpriteData spriteData;
				spriteData.width = TILES_WIDTH_PER_TILE;
				spriteData.height = TILES_HEIGHT_PER_TILE;
				spriteData.x = j * TILES_WIDTH_PER_TILE;
				spriteData.y = (matrix.size() - i) * TILES_HEIGHT_PER_TILE;
				spriteData.scale = 1;
				spriteData.angle = 0;
				//spriteData.isLeft = true;		
				if (mapsObject.size() > 0)
				{
					auto type = mapsObject[i].at(j)->GetType();
					if (ObjectType::BRICK == type)
					{
						tiles.at(curRow[j])->SetData(spriteData);
						//Graphics::GetInstance()->Draw(tiles.at(curRow[j]), D3DCOLOR_XRGB(200, 200, 255));
					}
					else if (ObjectType::DEFAULT == type)
					{
						tiles.at(curRow[j])->SetData(spriteData);
						Graphics::GetInstance()->Draw(tiles.at(curRow[j]));
					}
				}
				else
				{
					tiles.at(curRow[j])->SetData(spriteData);
					Graphics::GetInstance()->Draw(tiles.at(curRow[j]));
				}
			}
		}
	}
}