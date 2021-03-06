#include "ChargedShot2.h"

void ChargedShot2::loadResources()
{
	_animations[bullet_lv3] = animationsGlobal->get(bullet_lv3);
	_animations[bullet_lv3]->reset();
}

ChargedShot2::ChargedShot2(float x, float y, bool toLeft)
{
	loadResources();
	this->x = x;
	this->y = y;
	this->speed.vx = toLeft ? -0.25f : 0.25f;
	this->speed.vy = 0.00f;
	dy = 0;
	this->toLeft = toLeft;
	_damage = 3;
	soundsGlobal->play(sound_bul_lv3);
}

ChargedShot2::~ChargedShot2()
{
	if (_isCollision)
		_weaponEffect->createCharged2Effect(x, y, toLeft);
}

void ChargedShot2::getBoundingBox(float & left, float & top, float & right, float & bottom)
{
	//because draw center
	left = x - 22.5f;
	top = y - 14.5f;

	right = x + 22.5f;
	bottom = y + 14.5f;
}

void ChargedShot2::render(DWORD dt, D3DCOLOR colorBrush)
{
	auto pos = cameraGlobal->transform(x, y);
	
	if (toLeft)
		_animations[bullet_lv3]->renderFlipX(pos.x - 46, pos.y, true, colorBrush);
	else _animations[bullet_lv3]->render(pos.x, pos.y, true, colorBrush);
		
}
void ChargedShot2::update(DWORD dt, unordered_map<int, GameObject*>* staticObjects, unordered_map<int, GameObject*>* dynamicObjects)
{
	this->dt = dt;
	speed.vx += toLeft ? -0.001f * dt : 0.001f * dt;
	dx = speed.vx * dt;
	this->x += dx;
}