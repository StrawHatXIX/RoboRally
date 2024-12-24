#include "ToWorkshopStoreAction.h"


ToWorkshopStoreAction::ToWorkshopStoreAction(ApplicationManager* pApp) : Action(pApp) {}

void ToWorkshopStoreAction::ReadActionParameters()
{

}

void ToWorkshopStoreAction::Execute()
{
    ReadActionParameters();

    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Player* pPlayer = pGrid->GetCurrentPlayer();

    WORKSHOP_EQUIPMENT ARRAY[WORKSHOP_ITMS_COUNT] = { ITM_TOOLKIT, ITM_HACK_DEVICE, ITM_EXTENDED_MEMORY, ITM_LASER, ITM_DOUBLE_lASER };
    WORKSHOP_EQUIPMENT* ICONS = ARRAY;



    pOut->CreateEquipmentOptions(ICONS, WORKSHOP_ITMS_COUNT);

    pOut->PrintMessage("Workshop items displayed, choose your upgrade!");
}


ToWorkshopStoreAction :: ~ToWorkshopStoreAction()
{

}