#include "Input.h"

#include "Output.h"

//======================================================================================//
//								General Functions									    //
//======================================================================================//

Input::Input(window* pW)
{
	pWind = pW; // point to the passed window
}

////////////////////////////////////////////////////////////////////////////////////////// 

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y); // Note: x and y of WaitMouseClick are sent by reference
}

////////////////////////////////////////////////////////////////////////////////////////// 

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	// ESCAPE key is pressed
			return "";	// returns nothing as user has cancelled label
		if (Key == 13)	// ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	// BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

////////////////////////////////////////////////////////////////////////////////////////// 

int Input::GetInteger(Output* pO) const
{

	///TODO (Done.Y): implement the GetInteger function as described in Input.h file 
	//       using function GetString() defined above and function stoi()

	string Input = GetSrting(pO);
	//check if the string input is integer only, not alphabets 
	if (Input == "")
	{
		return -1;
	}
	for (int i = 0; i < Input.length(); i++)
	{
		if (Input[i] < '0' || Input[i] > '9')
		{
			return -1;
		}
	}
	int Number = stoi(Input);
	// Note: stoi(s) converts string s into its equivalent integer (for example, "55" is converted to 55)

	return Number; // this line should be changed with your implementation
}

//======================================================================================//
//								Game  Functions									        //
//======================================================================================//

ActionType Input::GetUserAction() const
{
	int x = -1, y = -1;
	GetPointClicked(x, y);

	//  ============ GUI in the Design mode ============
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// [1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==

			int clickedItemOrder = (x / UI.MenuItemWidth);

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (clickedItemOrder)
			{
			case ITM_SET_FLAG_CELL: return SET_FLAG_CELL;
			case ITM_Add_Antenna: return Add_Antenna;
			case ITM_Add_Belt: return Add_Belt;
			case ITM_Add_Water_Pit: return Add_Water_Pit;
			case ITM_Add_Danger_Zone: return Add_Danger_Zone;
			case ITM_Add_WorkShop: return Add_WorkShop;
			case ITM_Add_Rotating_Gear: return Add_Rotating_Gear;
			case ITM_Copy_Game_Object: return Copy_Game_Object;
			case ITM_Cut_Game_Object: return Cut_Game_Object;
			case ITM_Paste_Game_Object: return Paste_Game_Object;
			case ITM_Delete_Game_Object: return Delete_Game_Object;
			case ITM_Save_Grid: return Save_Grid;
			case ITM_Load_Open_Grid: return Load_Open_Grid;
			case ITM_SWITCH_TO_PLAY_MODE: return TO_PLAY_MODE;
			case ITM_EXIT: return EXIT;

				//TODO (Done.Y): Add cases for the other items of Design Mode

			default: return EMPTY;	// A click on empty place in toolbar
			}
		}

		// [2] User clicks on the grid area
		if ((y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;
		}

		// [3] User clicks on the status bar
		return STATUS;
	}

	// ============ GUI in the Play mode ============
	else
	{
		///TODO (Done.Y) :
		// perform checks similar to Design mode checks above for the Play Mode
		// and return the corresponding ActionType
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int clickedItemOrder = (x / UI.MenuItemWidth);
			switch (clickedItemOrder)
			{
			case ITM_SELECT_COMMAND: return SELECT_COMMAND;
			case ITM_EXECUTE_COMMANDS: return EXECUTE_COMMANDS;
			case ITM_Reboot_Repair: return Reboot_Repair;
			case ITM_Use_Consumable: return Use_Consumable;
			case ITM_New_Game: return New_Game;
			case ITM_SWITCH_TO_DESIGN_MODE: return TO_DESIGN_MODE;
			case ITM_PEXIT: return EXIT;

				//TODO (Done.Y) : Add cases for the other items of Play Mode

			default: return EMPTY;
			}

			/*return TO_DESIGN_MODE;*/	// just for now ==> This should be updated
		}

		if (y >= (UI.height - UI.StatusBarHeight - UI.CommandsBarHeight) && y <= (UI.height - UI.StatusBarHeight))
		{
			int spaceBetweenSlots = 10;
			int clickedCommandOrder = (x / (UI.CommandItemWidth + spaceBetweenSlots));

			switch (clickedCommandOrder)
			{
			case NO_COMMAND: return NO_COMMAND_ACTION;
			case MOVE_FORWARD_ONE_STEP: return MOVE_BACKWARD_ONCE_ACTION;
			case MOVE_BACKWARD_ONE_STEP: return MOVE_BACKWARD_ONCE_ACTION;
			case MOVE_FORWARD_TWO_STEPS: return MOVE_FORWARD_TWICE_ACTION;
			case MOVE_BACKWARD_TWO_STEPS: return MOVE_BACKWARD_TWICE_ACTION;
			case MOVE_FORWARD_THREE_STEPS: return MOVE_FORWARD_THRICE_ACTION;
			case MOVE_BACKWARD_THREE_STEPS: return MOVE_BACKWARD_THRICE_ACTION;
			case ROTATE_CLOCKWISE: return ROTATE_CLOCKWISE_ACTION;
			case ROTATE_COUNTERCLOCKWISE: return ROTATE_ANITCLOCKWISE_ACTION;

				//TODO (Done.Y.S) : Add cases for the other items of Play Mode

			default: return EMPTY;
			}

		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////// 

CellPosition Input::GetCellClicked() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	// Get the coordinates of the user click

	CellPosition cellPos;

	if (UI.InterfaceMode == MODE_DESIGN)
	{
		if (y >= UI.ToolBarHeight && y <= (UI.height - UI.StatusBarHeight))
		{
			//TODO (Done.S): SetHCell and SetVCell of the object cellPost appropriately
			//       using the coordinates x, y and the appropriate variables of the UI_Info Object (UI)
			int vCell = (y - UI.ToolBarHeight) / UI.CellHeight;

			int hCell = x / UI.CellWidth;

			// Set the cell position using the calculated vCell and hCell
			cellPos.SetVCell(vCell);
			cellPos.SetHCell(hCell);

		}
	}
	else
	{
		if (y >= UI.ToolBarHeight && y <= (UI.height - UI.StatusBarHeight))
		{
			int vCell = (y - UI.ToolBarHeight) / UI.CellHeight;
			int hCell = x / UI.CellWidth;


			cellPos.SetVCell(vCell);
			cellPos.SetHCell(hCell);
		}
	}
	return cellPos;
}

//////////////////////////////////////////////////////////////////////////////////////////

int Input::GetSelectedCommandIndex() const
{
	int x = -1, y = -1;
	GetPointClicked(x, y);

	if ((y >= UI.height - UI.StatusBarHeight - UI.CommandsBarHeight - UI.AvailableCommandsYOffset) && (y < UI.height - UI.StatusBarHeight))
	{
		if (x < UI.AvailableCommandsXOffset || x > UI.AvailableCommandsXOffset + (UI.CommandItemWidth / 2) * MaxAvailableCommands)
			return -1;

		return (x - UI.AvailableCommandsXOffset) / (UI.CommandItemWidth / 2);;
	}

	return -1;
}

////////////////////////////////////////////////////////////////////////////////////////// 