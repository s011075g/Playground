#pragma once
#include "Actor.h"
#include "Locations.h"

//Definition declared else where
class State;

#define COMFORT_LEVEL 5u;
#define MAX_NUGGETS 3u;
#define THIRST_LEVEL 5u;
#define TIREDNESS_THRESHOLD 5u;

class Miner : public Actor
{
private:
	State* _mCurrentState;
	Locations _mCurrentLocation;
	
	uint _mGold;
	uint _mGoldBanked;
	uint _mThirst;
	uint _mFatigue;
public:
	Miner();
	~Miner();

	void Update() override;
	void ChangeState(State* newState);
	//Location
	Locations Location() const;
	void ChangeLocation(const Locations location);
	//Gold
	uint GoldCarrying() const;
	void SetGold(const uint value);
	void AddToGold(const uint value);
	bool PocketsFull() const;
	//Saved
	uint Wealth() const;
	void SetWealth(const uint value);
	void AddtoWealth(const uint value);
	static uint GetComfortLevel();
	//Fatigued
	bool Fatigued() const;
	void DecreaseFatigue();
	void IncreaseFatigue();
	//Thirst
	bool Thirsty() const;
	void ResetThirst();
};
