#ifndef UI_INFO_H
#define UI_INFO_H

#include "CMUgraphicsLib\CMUgraphics.h"

// User Interface information file.
// This file contains info that is needed by Input and Output classes to
// handle the user interface

#define NumHorizontalCells 11
#define NumVerticalCells 5
#define MaxPlayerCount 2
#define MaxAvailableCommands 10

enum GUI_MODE		// Graphical user interface mode
{
	MODE_DESIGN,	// Design mode (startup mode)
	MODE_PLAY       // Play mode
};

enum DESIGN_MODE_ITEMS // The items of the Design Mode (you should add more items)
{
	// Note: Items MUST be ordered here as they appear in menu
	// If you want to change the menu items order, change the order here
	ITM_SET_FLAG_CELL,
	ITM_Add_Antenna,
	ITM_Add_Belt,
	ITM_Add_Water_Pit,
	ITM_Add_Danger_Zone,
	ITM_Add_WorkShop,
	ITM_Add_Rotating_Gear,
	ITM_Copy_Game_Object,
	ITM_Cut_Game_Object,
	ITM_Paste_Game_Object,
	ITM_Delete_Game_Object,
	ITM_Save_Grid,
	ITM_Load_Open_Grid,
	ITM_SWITCH_TO_PLAY_MODE,
	ITM_EXIT,

	///TODO: Add more items names here

	DESIGN_ITM_COUNT	// no. of items ==> This should be the last line in this enum
};

enum PLAY_MODE_ITEMS // The items of the Play Mode (you should add more items)
{
	// Note: Items are ordered here as they appear in menu
	// If you want to change the menu items order, change the order here

	ITM_SELECT_COMMAND,		// Select a command from the available ones to be executed
	ITM_EXECUTE_COMMANDS,	// Execute the saved commands
	ITM_Reboot_Repair,
	ITM_Use_Consumable,
	ITM_New_Game,
	ITM_SWITCH_TO_DESIGN_MODE,
	ITM_PEXIT,

	///TODO: Add more items names here

	PLAY_ITM_COUNT		// no. of items ==> This should be the last line in this enum
};

enum WORKSHOP_OPTIONS
{
	ITM_REPAIR,
	ITM_EQUIPMENT,

	WORKSHOP_OPTIONS_COUNT
};

enum WORKSHOP_EQUIPMENT
{
	ITM_TOOLKIT,
	ITM_HACK_DEVICE,

	ITM_EXTENDED_MEMORY,

	ITM_LASER,
	ITM_DOUBLE_lASER,


	WORKSHOP_ITMS_COUNT
};


__declspec(selectany) // This line to prevent "redefinition error"

struct UI_Info	// User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,			// Window width and height
		wx, wy,				    // Window starting coordinates
		ToolBarHeight,			// Tool Bar Height (distance from top of window to bottom line of toolbar)
		CommandsBarHeight,		// Commands Bar Height (distance from bottom of window to bottom line of commands bar)
		StatusBarHeight,		// Status Bar Height
		MenuItemWidth,			// Width of each item in toolbar menu
		CommandItemWidth;		// Width of the saved commands in the commands bar (not the available commands)


	int CellHeight;				// Height of 1 CELL
	int CellWidth;				// Width of 1 CELL

	color MsgColor;				// Messages color (usually used in statusbar)
	color PlayerInfoColor;		// Players' Info color (used in the toolbar - right-indented)
	color CommandBarTextColor;	// Commands Bar text color

	color CellColor = SLATEGRAY;			// Default Cell color

	color ToolBarColor;			// Toolbar color (toolbar background)
	color StatusBarColor;		// Statusbar color (statusbar background)
	color CommandBarColor;		// Commands Bar background color

	color GridLineColor;		// Color of the Lines separating adjacent cells

	int CellNumFont;			// Font size of cell numbers
	color CellNumColor;			// Cell number color


	color BeltColor;			// Color of the belt
	color FlagColor;			// Color of the flag
	color FlagPoleColor;		// Color of the flag pole (the vertical part of the flag)
	color DangerZoneCellColor = RED;	// Color of the danger zone cells
	color WaterPitsCellColor = DARKBLUE;	// Color of the water pits cells


	int SpaceBetweenCommandsSlots; // Space between the slots of the saved commands in the commands bar
	int AvailableCommandsXOffset;	// Size of the horizontal space before drawing the available commands
	int AvailableCommandsYOffset;	// Size of the vertical space between the start of the command bar and the cards of available commands
	// will be used in detecting selected command from the user click
	int BeltXOffset;			// Size of the horizontal space before drawing the belt
	int BeltYOffset;			// Size of the vertical space before drawing the belt
	int BeltLineWidth;			// Width of the belt line
	int FlagWidth;				// Width of the flag
	int FlagHeight;				// Height of the flag
	int FlagPoleWidth;			// Width of the flag pole
	int FlagPoleHeight;			// Height of the flag pole


	// (Done.S)
	int WorkshopOptionsOffset;  //for workshop 2 options repair or purchase equipment
	int WorkshopOptionsWidth;
	int WorkshopOptionsHeight;

	int EquipmentWidth;
	int EquipmentHeight;
	int SameEquipmentOffset;
	int DiffEquipmentOffset;



	color PlayerColors[MaxPlayerCount] = { YELLOW, PURPLE }; // Color of each player

	int CommandItemsCount;		// Number of commands the player can use
	int AvailableCommandsCount;	// Number of available commands the player can select from

	///TODO: Add more members if needed

} UI;	// create a global object UI

#endif