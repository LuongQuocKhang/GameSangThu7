#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <DirectXMath.h>;
#include "Sprites.h";
#include "Ninja.h"
#include "Mario.h"
class CGame;

class Camera
{
public:
	Camera(int width, int height, float angle , DirectX::XMFLOAT3 scaleFactors);
	~Camera();

	void Update();
	void Follow(Ninja * following);
	bool IsFollowing() const;

	void SetTransform(CGame *Device) const;

private:
	float angle;
	DirectX::XMFLOAT3 scaleFactors;
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX ViewMatrix;

	Ninja *following;

	int width;
	int height;
};


#endif // !CAMERA_H


