#pragma once
#include "State.h"

//Gold mine
class Dig : public State
{
private:
	Dig() {};
public:
	Dig(const Dig&) = delete;
	Dig& operator=(const Dig&) = delete;

	static Dig* Instance();
	void Enter(Miner*) override;
	void Execute(Miner*) override;
	void Exit(Miner*) override;
};

//Bank
class Deposit : public State
{
private:
	Deposit() {}
public:
	Deposit(const Deposit&) = delete;
	Deposit& operator=(const Deposit&) = delete;

	static Deposit* Instance();
	void Enter(Miner*) override;
	void Execute(Miner*) override;
	void Exit(Miner*) override;
};

// Reseting
class Sleep : public State
{
private:
	Sleep() {}
public:
	Sleep(const Sleep&) = delete;
	Sleep& operator=(const Sleep&) = delete;

	static Sleep* Instance();
	void Enter(Miner*) override;
	void Execute(Miner*) override;
	void Exit(Miner*) override;
};

//Quenching

class Quench : public State
{
private:
	Quench() {}
public:
	Quench(const Quench&) = delete;
	Quench& operator=(const Quench&) = delete;

	static Quench* Instance();
	void Enter(Miner*) override;
	void Execute(Miner*) override;
	void Exit(Miner*) override;
};
