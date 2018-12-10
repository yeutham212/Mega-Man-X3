#pragma once
#include<vector>

#include "DynamicObject.h";
#include "CTime.h";
#include "ConstGlobals.h"
#include "Camera.h"
#include "CollisionEvent.h"
#include "Brick.h"

#include "NotorBangerBullet.h"
#include "NotorBangerEffectShot.h"

using namespace std;

#define NOTOR_BANGER_GRAVITY 0.001f
#define NOTOR_BANGER_SPEED_X 0.075f
#define NOTOR_BANGER_SPEED_Y 0.35f

#define NOTOR_BANGER_STATE_INIT 0
#define NOTOR_BANGER_STATE_SHOT_SMALL 100
#define NOTOR_BANGER_STATE_SHOT_MEDIUM 200
#define NOTOR_BANGER_STATE_SHOT_LARGE 300
#define NOTOR_BANGER_STATE_READY_JUMP_SMALL 400
#define NOTOR_BANGER_STATE_READY_JUMP_MEDIUM 500
#define NOTOR_BANGER_STATE_READY_JUMP_LARGE 600
#define NOTOR_BANGER_STATE_JUMP 700
#define NOTOR_BANGER_STATE_TOUCH_FLOOR 800
#define NOTOR_BANGER_STATE_DIE 900

#define NOTOR_BANGER_ID_TEXTURE 701

class NotorBanger : public DynamicObject
{
public:
	NotorBanger();
	NotorBanger(int id, float x, float y, bool nx, int distance);
	~NotorBanger();
	void update(DWORD dt, unordered_map<int, CTreeObject*>* staticObjects = 0, unordered_map<int, CTreeObject*>* dynamicObjects = 0);
	void render(DWORD dt, D3DCOLOR colorBrush = WHITE(255));
	void setState(int state);
	void loadResources();
	void setPositionForListBullet();
	
	void resetPosition();
	void getBoundingBox(float & left, float & top, float & right, float & bottom) override;
	NotorBanger* clone(int id, int x, int y) override;

	void createBullet();
	void createEffect(float x, float y);


private:
	float initX;
	float initY;
	int repeat;
	bool nx;
	int distance; // 0: small, 1: medium, 2: large

	vector<NotorBangerBullet> listBullet;
	NotorBangerEffectShot* effectShot;

	void collisionStatic(unordered_map<int, CTreeObject*>* staticObjects);
};

