#pragma once
#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
#include "Belt.h"
#include "Player.h"
#include "Flag.h"
#include "Antenna.h"
#include "Workshop.h"
#include "RotatingGear.h"
#include "WaterPit.h"
#include "DangerZone.h"
#include "Action.h"
#include <iostream>
#include <fstream>
#include <random>
class NewGameAction :
    public Action
{
    void NewGame();
    void NewGame(Grid* pGrid, Player* pPlayer);

};