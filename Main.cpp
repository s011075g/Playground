#include <iostream>
#include <memory>
#include "WestWorld/WestWorldManager.h"
int main()
{
	std::unique_ptr<WestWorldManager> westWorld = std::make_unique<WestWorldManager>();
	const int result = westWorld->Start();
	std::cin.get();
	return result;
}