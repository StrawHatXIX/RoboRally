#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode
	SET_FLAG_CELL,	// Set Flag on a Cell
	Add_Antenna,
	Add_Belt,
	Add_Water_Pit,
	Add_Danger_Zone,
	Add_WorkShop,
	Add_Rotating_Gear,
	Copy_Game_Object,
	Cut_Game_Object,
	Paste_Game_Object,
	Delete_Game_Object,
	Save_Grid,
	Load_Open_Grid,
	TO_PLAY_MODE,	// Go to Play Mode
	EXIT,

	///TODO (Done.Y): Add more action types of Design Mode

	//  [2] Actions of Play Mode

	SELECT_COMMAND,		// Select a command from the available ones to be executed
	EXECUTE_COMMANDS,	// Execute the saved commands
	Reboot_Repair,
	Use_Consumable,
	New_Game,
	TO_DESIGN_MODE,	// Go to Design Mode
	//EXIT,	// Go to Design Mode

	///TODO (Done.Y): Add more action types of Play Mode

	NO_COMMAND_ACTION,
	MOVE_FORWARD_ONCE_ACTION,
	MOVE_BACKWARD_ONCE_ACTION,
	MOVE_FORWARD_TWICE_ACTION,
	MOVE_BACKWARD_TWICE_ACTION,
	MOVE_FORWARD_THRICE_ACTION,
	MOVE_BACKWARD_THRICE_ACTION,
	ROTATE_CLOCKWISE_ACTION,
	ROTATE_ANITCLOCKWISE_ACTION,


	// (Done.S) workshop actions we shall switch on in applicaation manager
	REPAIR_ACTION,
	TO_WORKSHOP_STORE,

	LASER_ACTION,
	DOUBLE_LASER_ACTION,
	EXTENDED_MEMORY_ACTION,
	TOOLKIT_ACTION,
	HACK_DEVICE_ACTION,

	//  [3] Others



	EMPTY,							// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,						// Inside Grid Area
	STATUS						// Inside StatusBar Area


};

enum Direction // Directions of the game
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum Command
{
	NO_COMMAND,
	MOVE_FORWARD_ONE_STEP,
	MOVE_BACKWARD_ONE_STEP,
	MOVE_FORWARD_TWO_STEPS,
	MOVE_BACKWARD_TWO_STEPS,
	MOVE_FORWARD_THREE_STEPS,
	MOVE_BACKWARD_THREE_STEPS,
	ROTATE_CLOCKWISE,
	ROTATE_COUNTERCLOCKWISE,

	COMMANDS_COUNT,
};

enum Type {
	FlagType,
	AntennaType,
	WaterPitType,
	DangerZoneType,
	BeltType,
	WorkshopType,
	RotatingGearType,
};


#endif