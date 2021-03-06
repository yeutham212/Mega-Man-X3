#include "ExplosionEffect.h"



void ExplosionEffect::loadResources()
{
	auto ani = new AnimationOneTime(10);
	spritesGlobal->addSprite(ExplosionAnimation, TExplosion, 0, 9, 16, 16 );
	spritesGlobal->addSprite(ExplosionAnimation + 1, TExplosion, 23, 0, 32, 32);
	spritesGlobal->addSprite(ExplosionAnimation + 2, TExplosion, 61, 0, 32, 32);
	spritesGlobal->addSprite(ExplosionAnimation + 3, TExplosion, 94, 0, 32, 32);
	spritesGlobal->addSprite(ExplosionAnimation + 4, TExplosion, 133, 0, 32, 32);
	spritesGlobal->addSprite(ExplosionAnimation + 5, TExplosion, 174, 0, 32, 32);
	spritesGlobal->addSprite(ExplosionAnimation + 6, TExplosion, 254, 0, 32, 32);
	for (int i = 0; i < 7; i++)
	{
		ani->add(ExplosionAnimation + i);
	}
	this->animation = ani;
}

ExplosionEffect::ExplosionEffect()
{
	loadResources();
}

ExplosionEffect* ExplosionEffect::_instance = null;

ExplosionEffect* ExplosionEffect::getInstance()
{
	if (_instance == null) _instance = new ExplosionEffect();
	return _instance;
}

ExplosionEffect::~ExplosionEffect()
{
}
