#include "Miner.h"
#include "States.h"
#include <cassert>

Miner::Miner()
	: Actor(), _mCurrentState(Sleep::Instance()), _mCurrentLocation(), 
_mGold(0), _mGoldBanked(0), _mThirst(0), _mFatigue(0)
{
}

Miner::~Miner()
{ }

void Miner::Update()
{
	_mThirst++;
	if (_mCurrentState)
		_mCurrentState->Execute(this);
}

void Miner::ChangeState(State* newState)
{
	assert(_mCurrentState && newState);
	_mCurrentState->Exit(this);
	_mCurrentState = newState;
	_mCurrentState->Enter(this);
}

Locations Miner::Location() const
{
	return _mCurrentLocation;
}

void Miner::ChangeLocation(const Locations location)
{
	_mCurrentLocation = location;
}

uint Miner::GoldCarrying() const
{
	return _mGold;
}

void Miner::SetGold(const uint value)
{
	_mGold = value;
}

void Miner::AddToGold(const uint value)
{
	_mGold += value;
}

bool Miner::PocketsFull() const
{
	return _mGold >= MAX_NUGGETS;
}

uint Miner::Wealth() const
{
	return _mGoldBanked;
}

void Miner::SetWealth(const uint value)
{
	_mGoldBanked = value;
}

void Miner::AddtoWealth(const uint value)
{
	_mGoldBanked += value;
}

uint Miner::GetComfortLevel()
{
	return COMFORT_LEVEL;
}

bool Miner::Fatigued() const
{
	return _mFatigue > TIREDNESS_THRESHOLD;
}

void Miner::DecreaseFatigue()
{
	_mFatigue--;
}

void Miner::IncreaseFatigue()
{
	_mFatigue++;
}

bool Miner::Thirsty() const
{
	return _mThirst >= THIRST_LEVEL;
}

void Miner::ResetThirst()
{
	_mThirst = 0;
	_mGoldBanked -= 2;
}
