#ifndef _KeyController_H_
#define _KeyController_H_
#include "CTime.h"
#include "GameObject.h"
#include "StaticObject.h"
#include "MegamanEffectFactory.h"
#include "MegamanWeapon.h"

enum StatusJump
{
	Jump = 1,
	Kick = 2,
	None = 0,
	Fall = -1,
	Slide = -2
};
enum class Arrow
{
	Left = -1,
	None = 0,
	Right = 1,
	Two = 2
};
class KeyController
{
private:
	MegamanEffectFactory* effect;
	MegamanWeapon *weapon;
private:
	GameObject* main;
	StaticObject* wall, *floor;

	int width = Stand_Shoot_Width;
	int height = Stand_Shoot_Width;

	bool toLeft = false;
	bool prepareRemoveWall = false;
	//arow
	int pressArrow = 0; // left right
	Arrow arrow = Arrow::None;

	bool pressZ = false;
	bool pressX = false;
	bool pressC = false;

	//stand
	bool onFloor = false;
	bool isStand = false;// don't direction
	bool isWall = false;//near wall

	bool isHoldLeft = false;
	bool isHoldRight = false;
	bool isWallLeft = false;//direction wall
	bool isHurt = false;
	// run
	bool isRun = false; // change direction
	int levelShoot = 0;


	// jum

	// 1 jum
	// 2 kick
	// -1 fall
	// -2 slide
	StatusJump statusJump = StatusJump::Jump;

	bool onAir = false;
	CTime timeJump = CTime(350);
	CTime timeKick = CTime(150);

	//dash
	bool isDash = false;
	CTime timeDash = CTime(600);
	CTime dashSmokeDelay = CTime(90);
	CTime timeslideDelay = CTime(50);
	//shoot
	bool isShot = false;
	CTime timeShoot = CTime(400);
	CTime timePressZ = CTime();
	

	UINT state = stand;
	UINT stateShoot = shoot;

	void updateShoot();
	void updateJump();
	void updateDash();
	void updateRun();

	void updateState();
	void updateVx();
	void _update();
public:
	KeyController(GameObject* megaman, MegamanEffectFactory* effect, MegamanWeapon *weapon, bool left);
	~KeyController() {};

	void setHurt(bool isTrue);
	bool isKeyZ();
	bool isKeyX();
	bool iskeyC();

	bool isLeft();

	void update();
	//cancel animation
	//jum
	void stopJumpRunning();
	void stopJump();
	void stopFall(); // 
	void stopSlideWall();

	void stopFallOrSlide();


	void stopDashRunning();
	void stopDash();

	void stopRun();
	void stopShoot();

	void setNearWall(bool, StaticObject*);
	void setFloor(StaticObject*);
	//jump
	void jump();
	void kickWall();
	//wall

	void addKeyZ();
	void addKeyX();
	void addKeyC();
	void addKeyArrow(bool isLeft);

	void removeKeyZ();
	void removeKeyX();
	void removeKeyC();
	void removeKeyArrow(bool isLeft);
	
	void getSize(int&width, int& height);
	UINT getState(bool& isLeft);
	void setToLeft(bool toLeft) { this->toLeft = toLeft; };
};

#endif //! _KeyController_H_