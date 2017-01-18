#include <iostream>

#include "problem/TowerOfHanoi.h"

void move(const int n, const int fromTower, const int toTower, const int spareTower)
{
	if(n>0)
    {
		move((n-1), fromTower, spareTower, toTower);
		std::cout << "\t Move the Top Disk from Tower " << fromTower << " to Tower "<<toTower<<"\n";
		move((n-1), spareTower, toTower, fromTower);
	}
}
