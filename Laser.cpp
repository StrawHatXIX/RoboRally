#include "Laser.h"

Laser::Laser(int a) : Weapon(a) {}

void Laser :: apply(Grid* pGrid)
{
	int Player = pGrid->GetCurrPlayer();

	if (Player == 0) //player 0 is using teh laser
	{
		int health = pGrid->GetPlayer(1)->GetHealth();
		pGrid->GetPlayer(1)->SetHealth(health - damage);
	}
	else
	{
		int health = pGrid->GetPlayer(0)->GetHealth();
		pGrid->GetPlayer(0)->SetHealth(health - damage);
	}
}