#include <iostream>

void move(const int n, const int fromTower, const int toTower, const int spareTower)
{
	if(n>0)
    {
		move((n-1), fromTower, spareTower, toTower);
		std::cout << "\t Move the Top Disk from Tower " << fromTower << " to Tower "<<toTower<<"\n";
		move((n-1), spareTower, toTower, fromTower);
	}
}

int main( )
{
	move(4,1,3,2);
	return 0;
}
