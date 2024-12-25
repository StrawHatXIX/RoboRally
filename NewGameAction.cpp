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
#include <iostream>
#include <fstream>
#include <random>
#include "NewGameAction.h"

void NewGameAction::NewGame() {
};


void NewGameAction::NewGame(Grid* pGrid, Player* pPlayer)
{
    Output* pOut = pGrid->GetOutput();
    pGrid->SetEndGame(FALSE);
    pGrid->GetOutput()->ClearCommandsBar();
    pGrid->GetOutput()->ClearGridArea();
    pGrid->GetOutput()->ClearStatusBar();
    pGrid->ResetGrid();
    pGrid->SetCurrentPlayer(0);
    pGrid->UpdatePlayerCell(pPlayer, 1);
    pGrid->SetCurrentPlayer(1);
    pGrid->UpdatePlayerCell(pPlayer, 1);
    pGrid->UpdateInterface();
    pPlayer->SetDirection(RIGHT);
    pPlayer->SetHealth(10);
    pPlayer->ClearDrawing(pOut);
    pGrid->SetCurrentPlayer(0);

}