#include "Weapon.h"


WeaponEffectController* Weapon::_weaponEffect = null;
void Weapon::setWeaponEffect(WeaponEffectController * effect)
{
	Weapon::_weaponEffect = effect;
}
Weapon::Weapon()
{

}

void Weapon::setAnimationEnd()
{
	_isCollision = true;
}


Weapon::~Weapon()
{
}
