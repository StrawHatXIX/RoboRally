#include "UseConsumableAction.h"





UseConsumableAction :: UseConsumableAction(ApplicationManager* pApp) : Action(pApp) {}

void UseConsumableAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	Player* pPlayer = pGrid->GetCurrentPlayer();

	pOut->PrintMessage("Use consumables : (1) Toolkit (2) HackDevice :");
	int input = pIn->GetInteger(pOut);

	if (input == 1)//toolkit
	{
		if (pPlayer->ToolkitEquiped())
		{
			int health = pPlayer->GetHealth();
			pPlayer->SetHealth(health + 2);
			pPlayer->EquipToolkit(false);
		}
		else
		{
			pOut->PrintMessage("No toolkit available for use, click to continue");
		}
	}
	else
	{
		if (pPlayer->HackDeviceEquiped())
		{
			if (pPlayer->GetplayerNum() == 0)
			{
				pGrid->GetPlayer(1)->ApplyIsHacked();
				pGrid->GetPlayer(0)->EquipHackDevice(false);
			}
			else
			{
				pGrid->GetPlayer(0)->ApplyIsHacked();
				pGrid->GetPlayer(1)->EquipHackDevice(false);
			}
		}
		else
		{
			pOut->PrintMessage("No toolkit available for use, click to continue");
		}
	}

	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void UseConsumableAction :: Execute()
{

}

UseConsumableAction :: ~UseConsumableAction() {}
