#ifndef _Sprites_H_
#define _Sprites_H_

#pragma once

#include "Graphics.h"
#include "Textures.h"
#include "ConstGlobals.h"
using namespace std;

class CSprite;
class CSprites;

typedef CSprite * LPSPRITE;

class CSprite : public Graphics::Draw
{
protected:
	UINT id;				// Sprite ID in the sprite database
	CRectangle frame;
	LPDIRECT3DTEXTURE9 texture;
	CSprite();
public:
	CSprite(UINT id, UINT left, UINT top, UINT right, UINT bottom, LPDIRECT3DTEXTURE9 texure);
	void draw(float x, float y, bool center = false, D3DCOLOR colorBrush = WHITE(255)) override;
	void drawFlipX(float x, float y, bool center = false, D3DCOLOR colorBrush = WHITE(255)) override;
	void drawFlipY(float x, float y, bool center = false, D3DCOLOR colorBrush = WHITE(255)) override;
	Size getSize();
};

/*
	Manage sprite database
*/
class CSprites
{
private:
	static CSprites * __instance;
	unordered_map<UINT, LPSPRITE> sprites;

public:
	void add(UINT id, UINT idTexture, UINT left, UINT top, UINT right, UINT bottom);
	void addSprite(UINT id, UINT idTexture, UINT x, UINT y, UINT width, UINT height);
	LPSPRITE get(UINT id);
	void deleteAt(UINT id);
	void clear();
public:
	static CSprites * getInstance();
};

#endif // !_Sprites_H_