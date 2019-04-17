#include "Animation.h"

void Animation::AddFrame(Sprite * sprite, DWORD time)
{
	DWORD t = time;
	pair <Sprite *, DWORD> frame(sprite, t);
	frames.push_back(frame);
}
void Animation::Render(SpriteData spriteData)
{
	DWORD now = GetTickCount();
	if (curFrame == -1)
	{
		curFrame = 0;
		lastFrameTime = now;
		done = false;
	}

	frames[curFrame].first->SetData(spriteData);
	CGame::GetInstance()->Draw(frames[curFrame].first);

	DWORD t = frames[curFrame].second;
	
	if (now - lastFrameTime > t)
	{
		curFrame++;
		lastFrameTime = now;
		if (curFrame == frames.size())
		{
			curFrame = 0;
			done = true;
		}
		else
			done = false;
	}
}