#pragma once
#include "Action.h"
#include "Player.h"


class ShootingAction : public Action
{


public:
    bool isAligned(Player* pPlayer1, Player* pPlayer2);


    void ShootingAction::shooting(Player* pPlayer1, Player* pPlayer2);
};