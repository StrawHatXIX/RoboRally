#include "ShootingAction.h"
#include "Player.h"
#include "Grid.h"
#include "CellPosition.h"



bool  ShootingAction:: isAligned(Player* pPlayer1, Player* pPlayer2)
{

    int p1H = pPlayer1->GetCell()->GetCellPosition().HCell();
    int p1V = pPlayer1->GetCell()->GetCellPosition().VCell();
    int p2H = pPlayer2->GetCell()->GetCellPosition().HCell();
    int p2V = pPlayer2->GetCell()->GetCellPosition().VCell();


    if (p1H == p2H)
    {
        if (p1V < p2V && pPlayer1->GetDirection() == DOWN) //p2 below p1
        {
            return true;
        }
        if (p1V > p2V && pPlayer1->GetDirection() == UP) //p1 below p2
        {
            return true;
        }
    }

    else if (p1V == p2V)
    {
        if (p1H < p2H && pPlayer1->GetDirection() == RIGHT) //p2 on the right
        {
            return true;
        }
        if (p1H > p2H && pPlayer1->GetDirection() == LEFT) //p2 on the left
        {
            return true;
        }
    }// all return true initiate p1 to shoot.. what about p2?

    return false;
}




void ShootingAction::shooting(Player* pPlayer1, Player* pPlayer2)
{
    if (isAligned(pPlayer1, pPlayer2) == true)
    {
        if (pPlayer2->LaserEquiped())
        {
            pPlayer2->SetHealth(pPlayer1->GetHealth() - 1);
        }
        else if (pPlayer2->DoubleLaserEquiped())
        {
            pPlayer2->SetHealth(pPlayer1->GetHealth() - 2);
        }

    }
    else if (isAligned(pPlayer2, pPlayer1) == true)
    {
        if (pPlayer1->LaserEquiped())
        {
            pPlayer2->SetHealth(pPlayer2->GetHealth() - 1);
        }
        else if (pPlayer1->DoubleLaserEquiped())
        {
            pPlayer2->SetHealth(pPlayer2->GetHealth() - 2);


        }
    }
    else
    {
        return;
    }

}