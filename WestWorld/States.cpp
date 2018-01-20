#include "States.h"
#include <iostream>
#include "Miner.h"

//Mining

Dig* Dig::Instance()
{
	static Dig instance;
	return &instance;
}

void Dig::Enter(Miner* ptr)
{
	if (ptr->Location() != LOCATION_GOLDMINE)
	{
		std::cout << "Miner " << ptr->ID() << ": Walking to the mine" << std::endl;
		ptr->ChangeLocation(LOCATION_GOLDMINE);
	}
}

void Dig::Execute(Miner* ptr)
{
	ptr->AddToGold(1);
	ptr->IncreaseFatigue();
	std::cout << "Miner " << ptr->ID() << ": Found a nugget" << std::endl;
	if (ptr->PocketsFull())
		ptr->ChangeState(Deposit::Instance());
	if (ptr->Thirsty())
		ptr->ChangeState(Quench::Instance());
}

void Dig::Exit(Miner* ptr)
{
	std::cout << "Miner " << ptr->ID() << ": Its dark and cold... I'm leaving" << std::endl;
}

//Bank

Deposit* Deposit::Instance()
{
	static Deposit instance;
	return &instance;
}

void Deposit::Enter(Miner* ptr)
{
	if (ptr->Location() != LOCATION_BANK)
	{
		std::cout << "Miner " << ptr->ID() << ": Going to the bank!" << std::endl;
		ptr->ChangeLocation(LOCATION_BANK);
	}
}

void Deposit::Execute(Miner* ptr)
{
	ptr->AddtoWealth(ptr->GoldCarrying());
	ptr->SetGold(0u);
	std::cout << "Miner " << ptr->ID() << ": Gold in the bank! I now have " << ptr->Wealth() << " gold" << std::endl;
	if (ptr->Wealth() >= Miner::GetComfortLevel())
	{
		std::cout << "Miner " << ptr->ID() << ": I can go home and face her now..." << std::endl;
		ptr->ChangeState(Sleep::Instance());
	}
	else
	{
		ptr->ChangeState(Dig::Instance());
	}
}

void Deposit::Exit(Miner* ptr)
{
	std::cout << "Miner " << ptr->ID() << ": Leaving the bank" << std::endl;
}

//Sleep

Sleep* Sleep::Instance()
{
	static Sleep instance;
	return &instance;
}

void Sleep::Enter(Miner* ptr)
{
	if (ptr->Location() != LOCATION_SHACK)
	{
		std::cout << "Miner " << ptr->ID() << ": Going home for a nap" << std::endl;
		ptr->ChangeLocation(LOCATION_SHACK);
	}
}

void Sleep::Execute(Miner* ptr)
{
	if (!ptr->Fatigued())
	{
		std::cout << "Miner " << ptr->ID() << ": Back to work!" << std::endl;
		ptr->ChangeState(Dig::Instance());
	}
	else
	{
		ptr->DecreaseFatigue();
		std::cout << "Miner " << ptr->ID() << ": ZZzzz" << std::endl;
	}
}

void Sleep::Exit(Miner* ptr)
{
	std::cout << "Miner " << ptr->ID() << ": Leaving home" << std::endl;
}

//Quench thirst

Quench* Quench::Instance()
{
	static Quench instance;
	return &instance;
}

void Quench::Enter(Miner* ptr)
{
	if (ptr->Location() != LOCATION_SALOON)
	{
		std::cout << "Miner " << ptr->ID() << ": Off to the saloon" << std::endl;
		ptr->ChangeLocation(LOCATION_SALOON);
	}
}

void Quench::Execute(Miner* ptr)
{
	if (ptr->Thirsty())
	{
		ptr->ResetThirst();
		std::cout << "Miner " << ptr->ID() << ": Mighty fine liquer" << std::endl;
		ptr->ChangeState(Dig::Instance());
	}
	else
	{
		throw std::logic_error("Unreachable code.");
	}
}

void Quench::Exit(Miner* ptr)
{
	std::cout << "Miner " << ptr->ID() << ": Run before the wife finds out I'm at the saloon again!" << std::endl;
}
