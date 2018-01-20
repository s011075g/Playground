#include "WestWorldManager.h"
#include <memory>
#include "Miner.h"

WestWorldManager::WestWorldManager()
{ }

WestWorldManager::~WestWorldManager()
{ }

int WestWorldManager::Start()
{
	std::unique_ptr<Miner> miner = std::make_unique<Miner>();
	for(int i = 0; i < 50; i++)
		miner->Update();
	return 0;
}
