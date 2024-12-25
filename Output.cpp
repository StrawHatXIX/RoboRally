#include "Output.h"

#include "Input.h"

#include <iostream>
////////////////////////////////////////////////////////////////////////////////////////// 

Output::Output()
{
	// Initialize user interface parameters
	UI.InterfaceMode = MODE_DESIGN;

	// Widths and Heights

	UI.StatusBarHeight = 60;
	UI.CommandsBarHeight = 100;
	UI.CommandItemWidth = 70;
	UI.ToolBarHeight = 55;
	UI.MenuItemWidth = 55;

	UI.width = 1210; // make it divisible by NumHorizontalCells
	UI.height = 610;
	UI.wx = 5;
	UI.wy = 5;

	UI.CellWidth = UI.width / NumHorizontalCells;
	UI.CellHeight = (UI.height - UI.ToolBarHeight - UI.StatusBarHeight - UI.CommandsBarHeight) / NumVerticalCells;

	// Pen Colors of messages of status bar and players' info
	UI.MsgColor = LIGHTGRAY;
	UI.PlayerInfoColor = LIGHTGRAY;

	// Background Colors of toolbar and statusbar 
	UI.ToolBarColor = BLACK;
	UI.StatusBarColor = BLACK;
	UI.CommandBarColor = BLACK;

	// Line Colors of the borders of each cell
	UI.GridLineColor = BLACK;

	// Cell Color if Empty & Cell Number Font & Color
	UI.CellColor = DARKSLATEGRAY;
	UI.CellNumFont = 13;
	UI.CellNumColor = LIGHTGRAY;


	// Belt Line Width and Color
	UI.BeltLineWidth = 6;
	UI.BeltColor = CORNFLOWERBLUE;

	// The X and Y Offsets of the Space BEFORE Drawing the Belt (offset from the start X and Y of the Cell)
	UI.BeltXOffset = (UI.CellWidth - 2 * UI.BeltLineWidth) / 5;
	UI.BeltYOffset = (UI.CellHeight / 4) * 3;

	// Flag and Flag Pole Colors
	UI.FlagPoleWidth = 4;
	UI.FlagPoleHeight = UI.CellHeight / 2;
	UI.FlagWidth = UI.CellWidth / 4;
	UI.FlagHeight = UI.FlagPoleHeight / 2;

	UI.WorkshopOptionsOffset = 55;
	UI.WorkshopOptionsWidth = 100;
	UI.WorkshopOptionsHeight = 100;

	UI.EquipmentWidth = UI.CommandItemWidth;
	UI.EquipmentHeight = UI.CommandsBarHeight;
	UI.SameEquipmentOffset = 10;
	UI.DiffEquipmentOffset = 20;

	UI.FlagColor = RED;
	UI.FlagPoleColor = GHOSTWHITE;


	// Commands X and Y Coordinates
	UI.SpaceBetweenCommandsSlots = 10;
	UI.AvailableCommandsXOffset = (UI.CommandItemWidth + UI.SpaceBetweenCommandsSlots) * 6;


	// Colors of the 2 Players (4 if needed)
	UI.PlayerColors[0] = GOLD;
	UI.PlayerColors[1] = GREEN;
	UI.PlayerColors[2] = KHAKI;
	UI.PlayerColors[3] = CHOCOLATE;

	// Create the output window
	pWind = CreateWind(UI.width + 15, UI.height, UI.wx, UI.wy);

	// Change the title
	pWind->ChangeTitle("RoboRally");

	// Create the toolbar, grid area and status bar
	CreateDesignModeToolBar();
	ClearGridArea();
	ClearStatusBar();
	ClearCommandsBar();

}

////////////////////////////////////////////////////////////////////////////////////////// 

window* Output::CreateWind(int w, int h, int x, int y) const
{
	// The Window Object is created inside the Ouput class
	window* pW = new window(w, h, x, y);
	return pW;
}

////////////////////////////////////////////////////////////////////////////////////////// 

Input* Output::CreateInput() const
{
	// The Input Object is created inside the Output class
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Some Utility Functions										//
//======================================================================================//

int Output::GetCellStartX(const CellPosition& cellPos) const
{
	///TODO: implement the following function as described in Output.h file

	if (cellPos.IsValidCell())
	{
		return cellPos.HCell() * UI.CellWidth;
	}
	else
	{
		return 0;
	}

}

//////////////////////////////////////////////////////////////////////////////////////////

int Output::GetCellStartY(const CellPosition& cellPos) const
{
	///TODO: implement the following function as described in Output.h file

	if (cellPos.IsValidCell())
	{
		return cellPos.VCell() * UI.CellHeight + UI.ToolBarHeight;
	}
	else
	{
		return 0;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
	// Clear by drawing a rectangle filled with toolbar background color
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawTriangle(int triangleCenterX, int triangleCenterY, int triangleHeight, int triangleWidth, Direction direction, color triangleColor, drawstyle style, int penWidth) const
{
	int x1, y1, x2, y2, x3, y3;

	///TODO (Done.Y.S) : Calculate the coordiantes of the 3 vertices of the triangle based on the passed parameters

	// Calculate the coordinates of the 3 vertices of the triangle based on the passed parameters
	if (direction == UP)
	{
		x1 = triangleCenterX - triangleWidth / 2;
		y1 = triangleCenterY + triangleHeight / 2;
		x2 = triangleCenterX + triangleWidth / 2;
		y2 = triangleCenterY + triangleHeight / 2;
		x3 = triangleCenterX;
		y3 = triangleCenterY - triangleHeight / 2;
	}
	else if (direction == DOWN)
	{
		x1 = triangleCenterX - triangleWidth / 2;
		y1 = triangleCenterY - triangleHeight / 2;
		x2 = triangleCenterX + triangleWidth / 2;
		y2 = triangleCenterY - triangleHeight / 2;
		x3 = triangleCenterX;
		y3 = triangleCenterY + triangleHeight / 2;
	}
	else if (direction == LEFT)
	{
		x1 = triangleCenterX + triangleWidth / 2;
		y1 = triangleCenterY - triangleHeight / 2;
		x2 = triangleCenterX + triangleWidth / 2;
		y2 = triangleCenterY + triangleHeight / 2;
		x3 = triangleCenterX - triangleWidth / 4;
		y3 = triangleCenterY;
	}
	else if (direction == RIGHT)
	{
		x1 = triangleCenterX - triangleWidth / 2;
		y1 = triangleCenterY - triangleHeight / 2;
		x2 = triangleCenterX - triangleWidth / 2;
		y2 = triangleCenterY + triangleHeight / 2;
		x3 = triangleCenterX + triangleWidth / 4;
		y3 = triangleCenterY;
	}

	// Set the pen and brush for drawing the triangle
	pWind->SetPen(triangleColor, penWidth);
	pWind->SetBrush(triangleColor);
	// Draw the triangle
	///TODO (Done.Y.S): Continue the implementation
	pWind->DrawTriangle(x1, y1, x2, y2, x3, y3, FILLED);
}



//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawImageInCell(const CellPosition& cellPos, string image, int width, int height) const
{
	// TODO: Validate the cell position
	if (!cellPos.IsValidCell())
		return;

	int x = GetCellStartX(cellPos) + UI.CellWidth / 4;
	int y = GetCellStartY(cellPos) + UI.CellHeight / 4;

	// TODO: Complete the implementation of this function

}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

void Output::ClearStatusBar() const
{
	// Clear drawing a rectangle filled with statusbar background color
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}

void Output::ClearCommandsBar() const
{
	// Clear drawing a rectangle filled with command bar background color
	pWind->SetPen(UI.CommandBarColor, 1);
	pWind->SetBrush(UI.CommandBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight - UI.CommandsBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearGridArea() const
{
	// Draw each cell in the Grid: ( NumVerticalCells * NumberHorizontalCells )
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			CellPosition cellPos(i, j);
			DrawCell(cellPos);
		}
	}

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateDesignModeToolBar() const
{
	UI.InterfaceMode = MODE_DESIGN;

	ClearToolBar(); // in order not to draw above the icons of the other mode when you switch

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way

	// First prepare List of images for each menu item
	// To control the order of these images in the menu, 
	// reoder them in UI_Info.h ==> enum DESIGN_MODE_ITEMS
	// ** MAKE SURE THAT THE IMAGES ARE .JPG FILES **
	string MenuItemImages[DESIGN_ITM_COUNT];
	MenuItemImages[ITM_SET_FLAG_CELL] = "images\\Flag.jpg";
	MenuItemImages[ITM_Add_Antenna] = "images\\Antenna.jpg";
	MenuItemImages[ITM_Add_Belt] = "images\\Belt.jpg";
	MenuItemImages[ITM_Add_Water_Pit] = "images\\WaterPit2.jpg";
	MenuItemImages[ITM_Add_Danger_Zone] = "images\\danger.jpg";
	MenuItemImages[ITM_Add_WorkShop] = "images\\WorkshopPhoto.jpg";
	MenuItemImages[ITM_Add_Rotating_Gear] = "images\\GearIcon.jpg";
	MenuItemImages[ITM_Copy_Game_Object] = "images\\Copy.jpg";
	MenuItemImages[ITM_Cut_Game_Object] = "images\\Cut.jpg";
	MenuItemImages[ITM_Paste_Game_Object] = "images\\Paste.jpg";
	MenuItemImages[ITM_Delete_Game_Object] = "images\\Delete.jpg";
	MenuItemImages[ITM_Save_Grid] = "images\\Save.jpg";
	MenuItemImages[ITM_Load_Open_Grid] = "images\\Load.jpg";
	MenuItemImages[ITM_SWITCH_TO_PLAY_MODE] = "images\\Menu_SwitchToGame.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu_Exit.jpg";


	///TODO (Done.S) : Change the path of the images as needed (Seif: i downloaded photos, put them in images file in the project and added them like the given example)
	//MenuItemImages[ITM_SET_FLAG_CELL] = "images\\Menu_Dice.jpg";


	///TODO (Done.S) : Prepare images for each menu item and add it to the list



	// Draw menu item one image at a time
	for (int i = 0; i < DESIGN_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayModeToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	ClearToolBar(); // in order not to draw above the icons of the other mode when you switch

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way

	// First prepare List of images for each menu item
	// To control the order of these images in the menu, 
	// reoder them in UI_Info.h ==> enum DESIGN_MODE_ITEMS
	// ** MAKE SURE THAT THE IMAGES ARE .JPG FILES **
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_SWITCH_TO_DESIGN_MODE] = "images\\Menu_SwitchToGrid.jpg";

	///TODO (Done.S): Change the path of the images as needed
	MenuItemImages[ITM_SELECT_COMMAND] = "images\\Select Command.jpg";
	MenuItemImages[ITM_EXECUTE_COMMANDS] = "images\\Execute Commad.jpg";
	MenuItemImages[ITM_Reboot_Repair] = "images\\Repair.jpg";
	MenuItemImages[ITM_Use_Consumable] = "images\\Use Consumable.jpg";
	MenuItemImages[ITM_New_Game] = "images\\New_Game.jpg";
	MenuItemImages[ITM_SWITCH_TO_DESIGN_MODE] = "images\\Menu_SwitchToGrid.jpg";
	MenuItemImages[ITM_PEXIT] = "images\\Menu_Exit.jpg";

	///TODO (Done.Y) : Prepare images for each menu item and add it to the list //waiting for images like the copy, cut paste ones for consistency



	// Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

}

void Output::CreateCommandsBar(Command savedCommands[], int savedCommandsCount, Command availableCommands[], int availableCommandsCount) const
{
	ClearCommandsBar();
	UI.InterfaceMode = MODE_PLAY;
	string CommandItemImages[COMMANDS_COUNT];

	CommandItemImages[NO_COMMAND] = "images\\CommandSlot-grey.jpg";
	CommandItemImages[MOVE_FORWARD_ONE_STEP] = "images\\1-Steps-Forward.jpg";
	CommandItemImages[MOVE_BACKWARD_ONE_STEP] = "images\\1-Steps-Back.jpg";
	CommandItemImages[MOVE_FORWARD_TWO_STEPS] = "images\\2-Steps-Forward.jpg";
	CommandItemImages[MOVE_BACKWARD_TWO_STEPS] = "images\\2-Steps-Back.jpg";
	CommandItemImages[MOVE_FORWARD_THREE_STEPS] = "images\\3-Steps-Forward.jpg";
	CommandItemImages[MOVE_BACKWARD_THREE_STEPS] = "images\\3-Steps-Back.jpg";
	CommandItemImages[ROTATE_CLOCKWISE] = "images\\Turn-Right.jpg";
	CommandItemImages[ROTATE_COUNTERCLOCKWISE] = "images\\Turn-Let.jpg";

	// TODO (Done.Y) : Prepare images for more items with .jpg extensions and add them to the list //waiting for images like the copy, cut paste ones for consistency

	DrawSavedCommands(savedCommands, savedCommandsCount, CommandItemImages);
	DrawAvailableCommands(availableCommands, availableCommandsCount, CommandItemImages);
}

void Output::CreateWorkshopOptions(WORKSHOP_OPTIONS SavedOptions[], int OptionsCount) const
{
	/*ClearCommandsBar();*/ //ana mesh 3aozo ye clear elcommand bar
	UI.InterfaceMode = MODE_PLAY;
	string WorkshopOptions[WORKSHOP_OPTIONS_COUNT];

	WorkshopOptions[ITM_REPAIR] = "images\\No-Command.jpg"; //need 2 photos of those
	WorkshopOptions[ITM_EQUIPMENT] = "images\\WorkshopUpgrades.jpg";


	// TODO: Prepare images for more items with .jpg extensions and add them to the list //waiting for images like the copy, cut paste ones for consistency

	DrawWorkshopOptions(SavedOptions, OptionsCount, WorkshopOptions);
}


void Output::CreateEquipmentOptions(WORKSHOP_EQUIPMENT Equiments[], int EquipmentsCount) const
{
	/*ClearCommandsBar();*/ //ana mesh 3aozo ye clear elcommand bar
	UI.InterfaceMode = MODE_PLAY;
	string WorkshopOptions[WORKSHOP_ITMS_COUNT];

	WorkshopOptions[ITM_LASER] = "images\\Laser.jpg"; //need 5 photos of those
	WorkshopOptions[ITM_DOUBLE_lASER] = "images\\Double Laser.jpg";
	WorkshopOptions[ITM_EXTENDED_MEMORY] = "images\\ExtendedMemory.jpg";
	WorkshopOptions[ITM_TOOLKIT] = "images\\1-Steps-Forward.jpg";
	WorkshopOptions[ITM_HACK_DEVICE] = "images\\1-Steps-Forward.jpg";


	// TODO: Prepare images for more items with .jpg extensions and add them to the list //waiting for images like the copy, cut paste ones for consistency

	DrawEquipmentOptions(Equiments, EquipmentsCount, WorkshopOptions);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawSavedCommands(Command savedCommands[], int savedCommandsCount, string CommandItemImages[]) const
{
	if (UI.InterfaceMode == MODE_DESIGN)
		return;

	int spaceBetweenSlots = 10;
	for (int i = 0; i < savedCommandsCount; ++i)
	{
		int x = i * (UI.CommandItemWidth + spaceBetweenSlots);
		int y = UI.height - UI.StatusBarHeight - UI.CommandsBarHeight;
		pWind->DrawImage(CommandItemImages[savedCommands[i]], x, y, UI.CommandItemWidth, UI.CommandsBarHeight);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawAvailableCommands(Command availableCommands[], int availableCommandsCount, string CommandItemImages[]) const
{
	if (UI.InterfaceMode == MODE_DESIGN)
		return;

	// Define the size and spacing for the available commands
	int availableCommandWidth = UI.CommandItemWidth / 2;
	int availableCommandHeight = UI.CommandsBarHeight / 2;

	// Define the starting position for the available commands
	int startX = UI.AvailableCommandsXOffset;
	int startY = UI.height - UI.StatusBarHeight - UI.CommandsBarHeight;

	// Draw the "Available Commands" text above the command slots
	pWind->SetPen(WHITE);
	pWind->SetFont(UI.CellNumFont, BOLD, BY_NAME, "Arial");
	string availableCommandsText = "Available Commands";
	int textWidth = 0, textHeight = 0; // to be used in the next line as they are passed by reference
	pWind->GetStringSize(textWidth, textHeight, availableCommandsText);
	pWind->DrawString(startX, startY, availableCommandsText);




	UI.AvailableCommandsYOffset = textHeight + 10;  // vertical space between the start of the command bar and the cards of available commands
	// will be used in detecting selected command from the user click
	for (int i = 0; i < availableCommandsCount; ++i)
	{
		int x = startX + i * (availableCommandWidth);
		int y = startY + UI.AvailableCommandsYOffset; // Adjust the Y position to be below the text


		// Draw the command slot (assuming you have an image for the available commands)
		if (availableCommands[i] != NO_COMMAND)
			pWind->DrawImage(CommandItemImages[availableCommands[i]], x, y, availableCommandWidth, availableCommandHeight);


		// Draw the command number below the card
		pWind->SetPen(UI.CellNumColor);
		pWind->SetFont(UI.CellNumFont, BOLD | ITALICIZED, BY_NAME, "Arial");
		int w = 0, h = 0;
		pWind->GetIntegerSize(w, h, i + 1);
		int numX = x + (availableCommandWidth - w) / 2;
		int numY = y + availableCommandHeight + 5; // Adjust the Y position to be below the card
		pWind->DrawInteger(numX, numY, i + 1);
	}
}

void Output::DrawWorkshopOptions(WORKSHOP_OPTIONS SavedOptions[], int WorkshopOptionsCount, string WorkshopOptionsImages[]) const
{
	if (UI.InterfaceMode == MODE_DESIGN)
		return;

	int spaceBetweenSlots = 15;
	for (int i = 0; i < WorkshopOptionsCount; ++i)
	{
		int x = (UI.width - UI.WorkshopOptionsOffset) - i * (UI.WorkshopOptionsWidth + spaceBetweenSlots);
		int y = UI.height - UI.StatusBarHeight - UI.CommandsBarHeight;
		pWind->DrawImage(WorkshopOptionsImages[SavedOptions[i]], x, y, UI.WorkshopOptionsWidth, UI.WorkshopOptionsHeight);
	}
}


void Output::DrawEquipmentOptions(WORKSHOP_EQUIPMENT Equipments[], int EquipmentCount, string WorkshopEquipments[]) const
{
	if (UI.InterfaceMode == MODE_DESIGN)
		return;

	int x = UI.width;
	int y = UI.height - UI.StatusBarHeight - UI.CommandsBarHeight; //same y coordiante all over the function

	x -= UI.EquipmentWidth;
	pWind->DrawImage(WorkshopEquipments[Equipments[0]], x, y, UI.EquipmentWidth, UI.CommandsBarHeight); //draw ITM_TOOLKIT


	x -= (UI.EquipmentWidth + UI.SameEquipmentOffset);
	pWind->DrawImage(WorkshopEquipments[Equipments[1]], x, y, UI.EquipmentWidth, UI.CommandsBarHeight); //draw ITM_HACK_DEVICE


	x -= UI.DiffEquipmentOffset; //leave a space between consumables and devices


	x -= UI.EquipmentWidth; // x coordinate of the device icon
	pWind->DrawImage(WorkshopEquipments[Equipments[2]], x, y, UI.EquipmentWidth, UI.CommandsBarHeight);//draw ITM_EXTENDED_MEMORY


	x -= UI.DiffEquipmentOffset; //leave a space between consumables and devices


	x -= UI.EquipmentWidth;
	pWind->DrawImage(WorkshopEquipments[Equipments[3]], x, y, UI.EquipmentWidth, UI.CommandsBarHeight); //Draw ITM_LASER


	x -= (UI.EquipmentWidth + UI.SameEquipmentOffset);
	pWind->DrawImage(WorkshopEquipments[Equipments[4]], x, y, UI.EquipmentWidth, UI.CommandsBarHeight); //Draw ITM_DOUBLE_lASER
}



//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	// First clear the status bar from any previous writing

	// Set pen and font before drawing the string on the window
	pWind->SetPen(UI.MsgColor);
	pWind->SetFont(18, BOLD, BY_NAME, "Verdana");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.3), msg);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintPlayersInfo(string info)
{
	// One of the correct ways to implement the above TODO is to call CreatePlayModeToolBar(); 
	// to clear what was written in the player info (there are other ways too � You are free to use any)

	CreatePlayModeToolBar(); 	///TODO (Done.Y) : Clear what was written on the toolbar

	// Set the pen and font before drawing the string on the window
	pWind->SetPen(UI.PlayerInfoColor);
	pWind->SetFont(20, BOLD, BY_NAME, "Verdana");

	int w = 0, h = 0;

	// Calculate the Width and Height of the string if drawn using the current font
	pWind->GetStringSize(w, h, info);

	//TODO (Done.Y) Calculate the Width and Height of the string if drawn using the current font 
	//       (Use GetStringSize() window function) and set the "w" and "h" variables with its width and height

	// Set the start X & Y coordinate of drawing the string
	int x = UI.width - w - 20; // space 20 before the right-side of the window
	// ( - w ) because x is the coordinate of the start point of the string (upper left)
	int y = (UI.ToolBarHeight - h) / 2; // in the Middle of the toolbar height

	// Draw the string "info" in the specified location (x, y)
	//TODO (Done.Y): Draw the string "info" in the specified location (x, y)
	pWind->DrawString(x, y, info);

}

//======================================================================================//
//			         			Game Drawing Functions   								//
//======================================================================================//

void Output::DrawCell(const CellPosition& cellPos, color cellColor) const
{
	///TODO (given gone): COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION	

	// Get the Cell Number (from 1 to NumVerticalCells*NumHorizontalCells) and the X & Y of its upper left corner
	int cellNum = cellPos.GetCellNum();
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	// ----- 1- Draw the cell itself (background) --> Filled Rectangle -----
	pWind->SetPen(UI.GridLineColor, 1);
	pWind->SetBrush(UI.CellColor);
	pWind->DrawRectangle(cellStartX, cellStartY, cellStartX + UI.CellWidth, cellStartY + UI.CellHeight);
	///TODO (given done) : Draw the Cell Rectangle using the appropriate coordinates
	//       using cellStartX, cellStartY, UI.CellWidth, UI.CellHeight


	// ----- 2- Draw the CELL number (the small number at the bottom right of the cell) -----
	pWind->SetPen(UI.CellNumColor);
	pWind->SetFont(UI.CellNumFont, BOLD, BY_NAME, "Verdana");

	int w = 0, h = 0;

	///TODO (given done) : Get the Width and Height of the Cell Number if written using the current font 
	//       (Use GetIntegerSize() window function) and set the "w" and "h" variables with its width and height
	pWind->GetIntegerSize(w, h, cellNum);

	// Calculate X & Y coordinate of the start point of writing the card number (upper left point of the cell num)
	int x = cellStartX + (UI.CellWidth - w - 1);   // space 1 from the end of the cell width
	// ( - w ) because x is for the start point of cell num (num's left corner)
	int y = cellStartY + (UI.CellHeight - h - 1);  // space 1 from the end of the cell height
	// ( - w ) because y is for the start point of cell num (num's upper corner)

	//TODO (given done) : Draw the cell number in the x and y location

	pWind->DrawInteger(x, y, cellNum);

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawPlayer(const CellPosition& cellPos, int playerNum, color playerColor, Direction direction) const
{
	// TODO (Done) : Validate the cell position and the playerNum, if not valid return
	// TODO (Done): Complete the implementation of the following function

	// Draws "Player Triangle" filled with the passed color
	//	"playerNum" parameter is used for locating the triangle
	//	** Players' Triangle Locations depending on "playerNum" is as follows: **
	//	Player_0
	//	Player_1

	if (!cellPos.IsValidCell())
	{
		return;
	}
	if (playerNum < 0 || playerNum > 1)
	{
		return;
	}

	// Get the X & Y coordinates of the start point of the cell (its upper left corner)
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	// Calculate the center of the cell
	int centerX = cellStartX + UI.CellWidth / 2;
	int centerY = cellStartY + UI.CellHeight / 2;

	// Define the size of the triangle
	int triangleWidth = UI.CellWidth / 5;
	int triangleHeight = UI.CellHeight / 5;

	// Offset positions to avoid overlap
	int offsetX = UI.CellWidth / 6;
	int offsetY = UI.CellWidth / 6;

	int adjustedCenterX;
	int adjustedCenterY;

	switch (playerNum) //ready to draw 4 players although we only need 2
	{
	case 0: //up left
		adjustedCenterX = centerX - offsetX;
		adjustedCenterY = centerY + offsetY;
		break;
	case 1: // down left
		adjustedCenterX = centerX - offsetX;
		adjustedCenterY = centerY - offsetY;
		break;
	case 2: //down right
		adjustedCenterX = centerX + offsetX;
		adjustedCenterY = centerY - offsetY;
		break;
	case 3://up right
		adjustedCenterX = centerX + offsetX;
		adjustedCenterY = centerY + offsetY;
		break;
	default:
		break;
	}


	// TODO (Done) : Draw the player triangle in center(x,y) and filled with the playerColor passed to the function
	DrawTriangle(adjustedCenterX, adjustedCenterY, triangleHeight, triangleWidth, direction, UI.PlayerColors[playerNum], FILLED);
}




//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawBelt(const CellPosition& fromCellPos, const CellPosition& toCellPos) const
{
	// TODO (Done.S.Y): Validate the fromCell and toCell (Must be Horizontal or Vertical, and we can't have the first cell as a starting cell for a belt)
	if (!fromCellPos.IsValidCell() && !toCellPos.IsValidCell())
	{
		return;
	}
	if ((fromCellPos.GetCellNum() == 1) || (toCellPos.GetCellNum() == 1) || (fromCellPos.GetCellNum() == 55) || (toCellPos.GetCellNum() == 55))
	{
		//it goes like this : use pWind->DrawInteger after locating where you would print the message
		return;
	}
	if (fromCellPos.HCell() != toCellPos.HCell() && fromCellPos.VCell() != toCellPos.VCell())
	{
		return;
	}


	// Get the start X and Y coordinates of the upper left corner of the fromCell and toCell
	int fromCellStartX = GetCellStartX(fromCellPos);
	int fromCellStartY = GetCellStartY(fromCellPos);
	int toCellStartX = GetCellStartX(toCellPos);
	int toCellStartY = GetCellStartY(toCellPos);

	int beltFromCellX = fromCellStartX + (UI.CellWidth / 2);
	int beltToCellX = toCellStartX + (UI.CellWidth / 2);
	int beltFromCellY = fromCellStartY + (UI.CellHeight / 2);
	int beltToCellY = toCellStartY + (UI.CellHeight / 2);

	// TODO (Done) : Draw the belt line and the triangle at the center of the line pointing to the direction of the belt


	// TODO: 1 (Done) . Set pen color and width using the appropriate parameters of UI_Info object (UI)
	pWind->SetPen(UI.BeltColor, UI.BeltLineWidth);
	pWind->SetBrush(DARKSLATEGRAY);
	// TODO: 2 (Done) . Draw the line of the belt using the appropriate coordinates
	pWind->DrawLine(beltFromCellX, beltFromCellY, beltToCellX, beltToCellY, FRAME);


	// TODO (Done.S.Y) : Draw the triangle at the center of the belt line pointing to the direction of the belt


	// Calculate the center of the belt line
	int centerX = (beltFromCellX + beltToCellX) / 2;
	int centerY = (beltFromCellY + beltToCellY) / 2;

	// Draw the triangle at the center of the belt line pointing to the direction of the belt
	int triangleWidth = UI.CellWidth / 5;
	int triangleHeight = UI.CellHeight / 5;

	Direction direction;

	if (fromCellPos.HCell() == toCellPos.HCell()) {
		// Vertical belt
		direction = (fromCellPos.VCell() < toCellPos.VCell()) ? DOWN : UP;
	}
	else {
		// Horizontal belt
		direction = (fromCellPos.HCell() < toCellPos.HCell()) ? RIGHT : LEFT;
	}

	DrawTriangle(centerX, centerY, triangleHeight, triangleWidth, direction, LAVENDERBLUSH, ANTIALIASED);
}

//////////////////////////////////////////////////////////////////////////////////////////


void Output::DrawFlag(const CellPosition& cellPos) const
{
	// TODO (Done.S.Y): Validate the cell position
	if (!cellPos.IsValidCell() || cellPos.GetCellNum() == 1 || cellPos.GetCellNum() == 55)
	{
		return;
	}

	// Get the X and Y coordinates of the start point of the cell (its upper left corner)
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	// TODO (Done.S.Y): Draw the flag as a line with a triangle connected to it directed to right

	// Calculate the center of the cell
	int centerX = cellStartX + UI.CellWidth / 2;
	int centerY = cellStartY + UI.CellHeight / 2;

	// Define the length of the flagpole and the size of the flag
	int flagPoleHeight = UI.CellHeight * 2 / 3; // Make the flagpole longer
	int flagWidth = UI.CellWidth / 4;
	int flagHeight = UI.CellHeight / 5; // Fixed size for the flag

	// Calculate the coordinates for the flagpole
	int flagPoleTopX = centerX;
	int flagPoleTopY = centerY - flagPoleHeight / 4;
	int flagPoleBottomX = centerX;
	int flagPoleBottomY = centerY + flagPoleHeight / 2;

	// TODO (Done.Y) : 2. Draw the flag Pole (the Line)
	pWind->SetPen(UI.FlagPoleColor, UI.FlagPoleWidth);
	pWind->DrawLine(flagPoleTopX, flagPoleTopY, flagPoleBottomX, flagPoleBottomY, FRAME);

	// Calculate the coordinates for the flag (triangle)
	int flagTriangleTopX = flagPoleBottomX;
	int flagTriangleTopY = centerY - flagHeight;
	int flagTriangleBottomX = flagPoleBottomX;
	int flagTriangleBottomY = centerY + flagHeight / 2;
	int flagTriangleRightX = flagPoleBottomX + flagWidth;
	int flagTriangleRightY = centerY;

	// TODO (Done.S) : 2. Draw the flag (the triangle)
	pWind->SetPen(UI.FlagColor);
	pWind->SetBrush(UI.FlagColor);
	pWind->DrawTriangle(flagTriangleTopX, flagTriangleTopY, flagTriangleBottomX, flagTriangleBottomY, flagTriangleRightX, flagTriangleRightY, FILLED);
}



void Output::DrawRotatingGear(const CellPosition& cellPos, bool clockwise) const
{
	// TODO (Done.S): Validate the cell position
	if (!cellPos.IsValidCell())
	{
		return;
	}
	// TODO (Done.S): Draw the rotating gear image in the cell based on the passed direction (clockwise or counter clockwise)
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	int centerX = cellStartX + UI.CellWidth / 4;
	int centerY = cellStartY + UI.CellHeight / 4;
	int cellNum = cellPos.GetCellNum();
	int w, h;
	pWind->SetPen(BLACK);
	pWind->SetFont(UI.CellNumFont, BOLD, BY_NAME, "Verdana");
	pWind->GetIntegerSize(w, h, cellNum);
	int numX = (GetCellStartX(cellPos) + 1) + (UI.CellWidth - w - 1);
	int numY = (GetCellStartY(cellPos) + 1) + (UI.CellHeight - h - 1);
	if (clockwise)
	{
		pWind->DrawImage("images\\Gear Clock.jpg", GetCellStartX(cellPos) + 1, GetCellStartY(cellPos) + 1, UI.CellWidth - 1, UI.CellHeight - 1);
		pWind->DrawInteger(numX, numY, cellNum);
	}
	else
	{
		pWind->DrawImage("images\\Gear Anti.jpg", GetCellStartX(cellPos) + 1, GetCellStartY(cellPos) + 1, UI.CellWidth - 1, UI.CellHeight - 1);
		pWind->DrawInteger(numX, numY, cellNum);
	}
}

void Output::DrawAntenna(const CellPosition& cellPos) const
{
	// TODO (Done.S): Validate the cell position
	if (!cellPos.IsValidCell() || cellPos.GetCellNum() == 1 || cellPos.GetCellNum() == 55)
	{
		return;
	}
	// TODO (Done.S): Draw the antenna image in the cell
	// it is a triangle (direction up) with 6 arcs (each 2 are symmetric) whose center is the upper point
	int cellStartX = GetCellStartX(cellPos); // Gets the X coordinate of the upper left corner of the passed cellpos
	int cellStartY = GetCellStartY(cellPos);

	int x1 = cellStartX + (UI.CellWidth / 8) * 3;
	int y1 = cellStartY + (UI.CellHeight / 8) * 7;
	int x2 = cellStartX + (UI.CellWidth / 8) * 5;
	int y2 = y1;
	int x3 = cellStartX + ((UI.CellWidth / 2));
	int y3 = cellStartY + (UI.CellHeight / 8) * 3;

	pWind->SetBrush(BLACK);
	pWind->SetPen(WHITE);

	pWind->DrawTriangle(x1, y1, x2, y2, x3, y3, FILLED);
	pWind->DrawCircle(x3, y3, UI.CellWidth / 24, FILLED);
	int StartAngle = -60;
	int EndAngle = 60;
	int InreacingRadius = UI.CellWidth / 12;

	pWind->SetPen(BLUE, 2);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			pWind->DrawArc(x3 - InreacingRadius, y3 - InreacingRadius, x3 + InreacingRadius, y3 + InreacingRadius, StartAngle, EndAngle, FRAME);
			StartAngle += 180;
			EndAngle += 180;
		}
		InreacingRadius += UI.CellWidth / 12;
	}
}

void Output::DrawWorkshop(const CellPosition& cellPos) const
{
	// TODO (Done.Y.S): Validate the cell position
	if (!cellPos.IsValidCell() || cellPos.GetCellNum() == 1 || cellPos.GetCellNum() == 55)
	{
		return;
	}
	// TODO (Done.Y.S): Draw the workshop image in the cell

	pWind->DrawImage("images\\WorkshopPhoto.jpg", GetCellStartX(cellPos) + 1, GetCellStartY(cellPos) + 1, UI.CellWidth - 1, UI.CellHeight - 1);
	int cellNum = cellPos.GetCellNum();
	int w, h;
	pWind->SetPen(BLACK);
	pWind->SetFont(UI.CellNumFont, BOLD, BY_NAME, "Verdana");
	pWind->GetIntegerSize(w, h, cellNum);
	int numX = (GetCellStartX(cellPos) + 1) + (UI.CellWidth - w - 1);
	int numY = (GetCellStartY(cellPos) + 1) + (UI.CellHeight - h - 1);
	pWind->DrawInteger(numX, numY, cellNum);

}

void Output::DrawDangerZone(const CellPosition& cellPos) const
{
	//TODO (Done.Y.S): Complete the implementation of the following function
	if (!cellPos.IsValidCell() || cellPos.GetCellNum() == 1 || cellPos.GetCellNum() == 55)
	{
		return;
	}

	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	pWind->SetPen(UI.DangerZoneCellColor);
	pWind->SetBrush(UI.DangerZoneCellColor);

	// Draw a Red rectangle representing the DangerZone
	pWind->DrawRectangle(cellStartX + 1, cellStartY + 1, (cellStartX + UI.CellWidth) - 1, (cellStartY + UI.CellHeight) - 1);

	//Draw the cell number on top of the DangerZone Cell
	int cellNum = cellPos.GetCellNum();
	int w, h;
	pWind->SetPen(WHITE);
	pWind->SetFont(UI.CellNumFont, BOLD, BY_NAME, "Verdana");
	pWind->GetIntegerSize(w, h, cellNum);
	int numX = cellStartX + (UI.CellWidth - w - 1);
	int numY = cellStartY + (UI.CellHeight - h - 1);
	pWind->DrawInteger(numX, numY, cellNum);

}

void Output::DrawWaterPit(const CellPosition& cellPos) const
{
	//TODO (Done.Y): Complete the implementation of the following function
	if (!cellPos.IsValidCell() || cellPos.GetCellNum() == 1 || cellPos.GetCellNum() == 55)
	{
		return;
	}


	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	pWind->SetPen(UI.WaterPitsCellColor);
	pWind->SetBrush(UI.WaterPitsCellColor);

	// Draw a Blue rectangle representing the water pit
	pWind->DrawRectangle(cellStartX + 1, cellStartY + 1, (cellStartX + UI.CellWidth) - 1, (cellStartY + UI.CellHeight) - 1);

	//Draw the cell number on top of the WaterPit Cell
	int cellNum = cellPos.GetCellNum();
	int w, h;
	pWind->SetPen(WHITE);
	pWind->SetFont(UI.CellNumFont, BOLD, BY_NAME, "Verdana");
	pWind->GetIntegerSize(w, h, cellNum);
	int numX = cellStartX + (UI.CellWidth - w - 1);
	int numY = cellStartY + (UI.CellHeight - h - 1);
	pWind->DrawInteger(numX, numY, cellNum);
}




Output::~Output()
{
	// deallocating the window object
	delete pWind;
}