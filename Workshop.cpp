#include "Workshop.h"



Workshop::Workshop(const CellPosition& workshopPosition) :GameObject(workshopPosition)
{

}


void Workshop::Draw(Output* pOut) const
{
    pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid* pGrid, Player* pPlayer)
{
    int x, y;
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("You have landed on a Workshop! Click to continue...");
    pGrid->GetInput()->GetPointClicked(x, y);
    pOut->ClearStatusBar();

    pOut->PrintMessage("Choose your Workshop service (1) Reboot & Repair (2) Upgrade artillery");
    int choice = pIn->GetInteger(pOut);

    if (choice == 1)
    {
        pPlayer->SetHealth(10);
        pGrid->GetOutput()->PrintMessage("Your health has been increased by 10!");
    }
    //else
    //{
    //    pOut->PrintMessage("Choose your Upgrade : (1) Laser (2) Double Laser (3) Hack Device (4) Toolkit (5) Extended Memory : ");
    //    int UpgradeChoice = pIn->GetInteger(pOut);
    //    switch (UpgradeChoice)
    //    {
    //    case 1:
    //        Laser * laser;
    //        pPlayer->EquipWeapon(laser);
    //        pOut->PrintMessage("Laser equiped successfully, click to continue..");
    //        break;

    //    case 2:
    //        DoubleLaser * doublelaser;
    //        pPlayer->EquipWeapon(doublelaser);
    //        pOut->PrintMessage("Double Laser equiped successfully, click to continue..");
    //        break;

    //    case 3:
    //        HackDevice * device;
    //        pPlayer->EquipHackDevice(device);
    //        pOut->PrintMessage("Hack device ");
    //        break;

    //    case 4:
    //        break;
    //    case 5:
    //        break;
    //    }
    //}

    // Example Effect: Increase the player's health or apply an upgrade

    // Optional: Add additional effects (e.g., custom player upgrades)
}



void Workshop::Save(ofstream& outfile, Type X, int& CellNum, int& Count, int Locations[])
{
    Locations[Count] = CellNum;
    Count++;
}

Workshop::~Workshop()
{
}
