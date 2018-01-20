#include "Actor.h"

uint Actor::_mNextID = 0u;

void Actor::SetId()
{
	_mID = _mNextID;
	_mNextID++;
}

Actor::Actor() : _mID()
{
	SetId();
}

Actor::~Actor()
{ }
