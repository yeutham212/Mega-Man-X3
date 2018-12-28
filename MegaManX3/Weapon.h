#pragma once
#include "GameObject.h"
#include "Camera.h"
#include "WeaponEffectController.h"
class Weapon :
	public GameObject
{
protected:
	int _damage = 0;
	bool isDelete;
	bool _isCollision = false;
	static WeaponEffectController* _weaponEffect;
public:
	static void setWeaponEffect(WeaponEffectController* effect);
	Weapon();

public:
	void setAnimationEnd(); //for bullet megaman collision with another dynamic object

public:
	virtual ~Weapon();
	virtual bool getIsDelete() { return isDelete; };
	virtual int getDamage() { return _damage; };
};

