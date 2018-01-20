#pragma once
#include "../Common.h"

class Actor
{
private:
	uint _mID;
	static uint _mNextID;
	void SetId();
public:
	Actor();
	virtual ~Actor();

	virtual void Update() = 0;

	uint ID() const { return _mID; }
};
