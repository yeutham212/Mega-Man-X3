#pragma once
#include <stdlib.h>
#include "Weapon.h"
#include "Camera.h"
#include "ConstGlobals.h"
#include "CollisionEvent.h"
#include "Brick.h"


#define NOTOR_BANGER_BULLET_GRAVITY 0.01f
#define NOTOR_BANGER_BULLET_SPEED_X_SMALL 0.015f
#define NOTOR_BANGER_BULLET_SPEED_Y_SMALL 0.2f
#define NOTOR_BANGER_BULLET_SPEED_X_MEDIUM 0.08f
#define NOTOR_BANGER_BULLET_SPEED_Y_MEDIUM 0.2f
#define NOTOR_BANGER_BULLET_SPEED_X_LARGE 0.16f
#define NOTOR_BANGER_BULLET_SPEED_Y_LARGE 0.2f

#define NOTOR_BANGER_BULLET_STATE_DEFAULT 0

#define NOTOR_BANGER_BULLET_ID_TEXTURE 801

class NotorBangerBullet : public Weapon
{
public:
	bool nx;
	bool ny;

	NotorBangerBullet(float x, float y, bool nx, bool ny, int distance);
	NotorBangerBullet(int id, float x, float y, bool nx, bool ny, int distance);
	~NotorBangerBullet();
	void update(DWORD dt, unordered_map<int, GameObject*>* staticObjects = 0, unordered_map<int, GameObject*>* dynamicObjects = 0);
	void render(DWORD dt, D3DCOLOR colorBrush = WHITE(255));
	void setState(int state);
	void loadResources();
	void setPosition(float x, float y);
	void getBoundingBox(float & left, float & top, float & right, float & bottom) override;


private:
	int distance;

	void collisionStatic(unordered_map<int, GameObject*>* staticObjects);
};

