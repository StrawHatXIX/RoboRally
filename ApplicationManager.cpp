#include "ApplicationManager.h"

#include "Grid.h"  //design mode buttons
#include "AddBeltAction.h"
#include "AddRotatingGearAction.h"
#include "AddFlagAction.h"
#include "AddAntennaAction.h"
#include "AddDangerZoneAction.h"
#include "AddWaterPitAction.h"
#include "AddWorkshopAction.h"
#include "SaveGridAction.h"
#include "CopyGameObjectAction.h"
#include "CutGameObjectAction.h"
#include "PasteGameObjectAction.h"
#include "DeleteGameObjectAction.h"
#include "ToPlayModeAction.h"

#include "ToDesignModeAction.h" //game mode buttons

#include "AddCommandAction.h"
#include "ExecuteCommandAction.h"
#include "RebootAndRepairAction.h"
#include "UseConsumableAction.h"

#include "ToWorkshopStoreAction.h"//workshop buttons
#include "RebootAndRepairAction.h"


///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid* ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case SET_FLAG_CELL:
		// create an object of AddFlagAction here
		pAct = new AddFlagAction(this);
		break;

	case Add_Antenna:
		// create an object of AddAntennaAction here
		pAct = new AddAntennaAction(this);
		break;

	case Add_Belt:
		// create an object of AddBeltAction here
		pAct = new AddBeltAction(this);
		break;

	case Add_Rotating_Gear:
		// create an object of AddRotatingGearAction here
		pAct = new AddRotatingGearAction(this);
		break;

	case ITM_Add_Water_Pit:
		// create an object of AddWaterPitAction here
		pAct = new AddWaterPitAction(this);
		break;

	case ITM_Add_Danger_Zone:
		// create an object of AddDangerzoneAction here
		pAct = new AddDangerzoneAction(this);
		break;

	case ITM_Add_WorkShop:
		// create an object of AddWorkshopAction here
		pAct = new AddWorkshopAction(this);
		break;

	case ITM_Save_Grid:
		// create an object of SaveGridAction here
		pAct = new SaveGridAction(this);
		break;

	case ITM_Copy_Game_Object:
		// create an object of CopyGameObjectAction here
		pAct = new CopyGameObjectAction(this);
		break;

	case ITM_Cut_Game_Object:
		// create an object of CutGameObjectAction here
		pAct = new CutGameObjectAction(this);
		break;

	case ITM_Paste_Game_Object:
		// create an object of PasteGameObjectAction here
		pAct = new PasteGameObjectAction(this);
		break;

	case ITM_Delete_Game_Object:
		// create an object of DeleteGameObjectAction here
		pAct = new DeleteGameObjectAction(this);
		break;

	case TO_PLAY_MODE:
		// create an object of ToPlayModeAction here		//TODO:
		pAct = new ToPlayModeAction(this);				// temporary till you made its action class (CHANGE THIS LATTER)
		break;


		//SELECT_COMMAND,		
		//	EXECUTE_COMMANDS,	
		//	Use_Consumable,
		//	New_Game,
		//	TO_DESIGN_MODE,


	case SELECT_COMMAND:
		pAct = new AddCommandAction(this);
		break;

	case EXECUTE_COMMANDS:
		pAct = new ExecuteCommandAction(this);
		break;

	case Reboot_Repair:
		pAct = new RebootAndRepairAction(this);
		break;

	case Use_Consumable:
		pAct = new UseConsumableAction(this);
		break;

	case TO_DESIGN_MODE:
		// create an object of ToDesignModeAction here		
		pAct = new ToDesignModeAction(this);				
		break;

	//case NO_COMMAND_ACTION:
	//	pAct = new AddCommandAction(this, NO_COMMAND);
	//	break;

	//case MOVE_FORWARD_ONCE_ACTION:
	//	pAct = new AddCommandAction(this, MOVE_FORWARD_ONE_STEP);
	//	break;

	//case MOVE_BACKWARD_ONCE_ACTION:
	//	pAct = new AddCommandAction(this, MOVE_BACKWARD_ONE_STEP);
	//	break;

	//case MOVE_FORWARD_TWICE_ACTION:
	//	pAct = new AddCommandAction(this, MOVE_FORWARD_TWO_STEPS);
	//	break;

	//case MOVE_BACKWARD_TWICE_ACTION:
	//	pAct = new AddCommandAction(this, MOVE_BACKWARD_TWO_STEPS);
	//	break;

	//case MOVE_FORWARD_THRICE_ACTION:
	//	pAct = new AddCommandAction(this, MOVE_FORWARD_THREE_STEPS);
	//	break;

	//case MOVE_BACKWARD_THRICE_ACTION:
	//	pAct = new AddCommandAction(this, MOVE_BACKWARD_THREE_STEPS);
	//	break;

	//case ROTATE_CLOCKWISE_ACTION:
	//	pAct = new AddCommandAction(this, ROTATE_CLOCKWISE);
	//	break;

	//case ROTATE_ANITCLOCKWISE_ACTION:
	//	pAct = new AddCommandAction(this, ROTATE_COUNTERCLOCKWISE);
	//	break;

	case TO_WORKSHOP_STORE:
		pAct = new ToWorkshopStoreAction(this);
		break;

	case REPAIR_ACTION:
		pAct = new RebootAndRepairAction(this);
		break;

	case LASER_ACTION:

		break;

	case DOUBLE_LASER_ACTION:

		break;

	case EXTENDED_MEMORY_ACTION:

		break;

	case TOOLKIT_ACTION:

		break;

	case HACK_DEVICE_ACTION:

		break;


		//	ITM_Load_Open_Grid,
		//	ITM_EXIT,



	case EXIT:
		break;





		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
