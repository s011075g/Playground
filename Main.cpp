#include <iostream>
#include <memory>
#include "WestWorld/WestWorldManager.h"
int main()
{
	int result;
	{
		std::unique_ptr<WestWorldManager> westWorld = std::make_unique<WestWorldManager>();
		result = westWorld->Start();
	}
	std::cin.get();
	return result;
}