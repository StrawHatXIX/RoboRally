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
#include <iostream>
#include <fstream>  

#include <random>

Grid::Grid(Input* pIn, Output* pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject* pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();

	if (pos.GetCellNum() == 1 || pos.GetCellNum() == 55)
	{
		pOut->PrintMessage("Error: The start & end cell cannot contain game object! Click to continue...");
		return false;
	}
	int x, y;



	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}


// Note: You may need to change the return type of this function (Think)
void Grid::RemoveObjectFromCell(const CellPosition& pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player* player, const CellPosition& newPosition)
{
	// Clear the player's triangle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell* newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's triangle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========


Input* Grid::GetInput() const
{
	return pIn;
}

Output* Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(GameObject* gameObject) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = gameObject;
}

GameObject* Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

void Grid::SetCurrentPlayer(int a)
{
	currPlayerNumber = a;
}

int Grid::GetCurrPlayer()
{
	return currPlayerNumber;
}


// ========= Other Getters =========


bool Grid::FlagOnGrid() const //checks if the grid alread has a flag, I used it in flag action
{
	bool found = false;
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasFlag())
			{
				found = true;
				break;
			}
		}
		if (found == true)
			break;
	}
	return found;
}


bool Grid::AntennaOnGrid() const //checks if the grid alread has an antenna, I used it in antenna action
{
	bool found = false;
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasAntenna())
			{
				found = true;
				break;
			}
		}
		if (found == true)
			break;
	}
	return found;
}

static bool hasCommonElement(int* arr1, int size1, int* arr2, int size2) //this function was declared specifically for the BeltOverLap below
{
	for (int i = 0; i < size1; ++i) {

		for (int j = 0; j < size2; ++j) {
			if (arr1[i] == arr2[j]) {
				return true; // If we find a common element, return true
			}
		}
	}
	return false; // No common elements found
}

bool Grid::AnyBeltOverlap(Belt* pBelt) const
{
	bool Overlapping = false;

	int* NewCells = pBelt->CoveredCells();
	int NewCellsNum = pBelt->NumCoveredCells();



	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			Belt* temp = CellList[i][j]->HasBelt();
			if (temp) // doesn't point to null
			{
				int* Cells = temp->CoveredCells();
				int CellsNum = temp->NumCoveredCells();

				Overlapping = hasCommonElement(Cells, CellsNum, NewCells, NewCellsNum);
				if (Overlapping)
					break;
			}
		}
		if (Overlapping)
			break;
	}

	return Overlapping;

}

int Grid::GetNumPlayers() const
{
	return currPlayerNumber;
}





Player* Grid::GetPlayer(int playerNum) const
{
	return PlayerList[playerNum];
}

Player* Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Belt* Grid::GetNextBelt(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the belt in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if (CellList[i][j]->HasBelt()) //any thing other than nullptr is true
			{
				return CellList[i][j]->HasBelt();
			}
			///TODO (Done.S) : Check if CellList[i][j] has a belt, if yes return it


		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}


// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without waterpits or dangerzone 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrWaterPitOrDangerZone(pOut);
			}
		}

		// 2- Draw other game objects(excluding waterpit and dangerzone)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawGameObject(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cgame objects do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Grid::GetAntennaPos(int& Xpos, int& Ypos)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0;j < 10; j++)
		{
			if (CellList[i][j]->HasAntenna())
			{
				CellPosition Temp = CellList[i][j]->GetCellPosition();
				Xpos = Temp.HCell();
				Ypos = Temp.VCell();
				return;
			}
		}
	}
}

Command* Grid::GetRandomCommand() const
{
	Command CommandsArray[] = { NO_COMMAND, MOVE_FORWARD_ONE_STEP,MOVE_BACKWARD_ONE_STEP, MOVE_FORWARD_TWO_STEPS,
	MOVE_BACKWARD_TWO_STEPS, MOVE_FORWARD_THREE_STEPS, MOVE_BACKWARD_THREE_STEPS, ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE };

	int NumAvailableCommands = (5 < PlayerList[currPlayerNumber]->GetHealth()) ? PlayerList[currPlayerNumber]->GetHealth() : 5;

	/*(std::rand % (COMMANDS_COUNT - 1));*/

	Command* array = new Command;
	for (int i = 0; i < NumAvailableCommands; i++)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<> dis(1, COMMANDS_COUNT - 1);
		int RandomIndex = dis(gen); //random number from 0 to 8

		array[i] = CommandsArray[RandomIndex];
	}
	return array;
}


void Grid::SaveAll(ofstream& outfile, Type X)
{
	/*int CellNum = 0;
	int Count = 0;
	int Locations[55];
	int Start_Locations[55];
	int End_Locations[55];
	switch (X)
	{
	case 0:
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				if (CellList[i][j]->HasFlag() != nullptr)
				{
					CellNum = CellList[i][j]->GetCellPosition().GetCellNumFromPosition(CellList[i][j]->GetCellPosition());
					CellList[i][j]->HasFlag()->Save(outfile, X, CellNum);
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				if (CellList[i][j]->HasAntenna() != nullptr)
				{
					CellNum = CellList[i][j]->GetCellPosition().GetCellNumFromPosition(CellList[i][j]->GetCellPosition());
					CellList[i][j]->HasAntenna()->Save(outfile, X, CellNum);
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				if (CellList[i][j]->HasWaterPit() != nullptr)
				{
					CellNum = CellList[i][j]->GetCellPosition().GetCellNumFromPosition(CellList[i][j]->GetCellPosition());
					CellList[i][j]->HasWaterPit()->Save(outfile, X, CellNum, Count, Locations);
				}
			}
		}
		outfile << Count << endl;
		for (int i = 0; i < Count; i++)
		{
			outfile << Locations[i] << " " << endl;
		}
		outfile << "----------" << endl;
		break;
	case 3:
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				if (CellList[i][j]->HasDangerZone() != nullptr)
				{
					CellNum = CellList[i][j]->GetCellPosition().GetCellNumFromPosition(CellList[i][j]->GetCellPosition());
					CellList[i][j]->HasDangerZone()->Save(outfile, X, CellNum, Count, Locations);
				}
			}
		}
		outfile << Count << endl;
		for (int i = 0; i < Count; i++)
		{
			outfile << Locations[i] << " " << endl;
		}
		outfile << "----------" << endl;
		break;
	case 4:
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				if (CellList[i][j]->HasBelt() != nullptr)
				{
					int SCell = CellList[i][j]->GetCellPosition().GetCellNumFromPosition(CellList[i][j]->GetCellPosition());
					int ECell = CellList[i][j]->HasBelt()->GetEndPosition().GetCellNumFromPosition(CellList[i][j]->HasBelt()->GetEndPosition());
					CellList[i][j]->HasBelt()->Save(outfile, X, SCell, ECell, Count, Start_Locations, End_Locations);

				}
			}
		}
		outfile << Count << endl;
		for (int i = 0; i < Count; i++)
		{
			outfile << Start_Locations[i] << " " << End_Locations[i] << endl;
		}
		outfile << "----------" << endl;
		break;
	case 5:
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				if (CellList[i][j]->HasWorkshop() != nullptr)
				{
					CellNum = CellList[i][j]->GetCellPosition().GetCellNumFromPosition(CellList[i][j]->GetCellPosition());
					CellList[i][j]->HasWorkshop()->Save(outfile, X, CellNum, Count, Locations);
				}
			}
		}
		outfile << Count << endl;
		for (int i = 0; i < Count; i++)
		{
			outfile << Locations[i] << " " << endl;
		}
		outfile << "----------" << endl;
		break;
	case 6:
		bool clock[55]{ 0 };
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 11; ++j)
			{
				if (CellList[i][j]->HasRotatingGear() != nullptr)
				{
					CellNum = CellList[i][j]->GetCellPosition().GetCellNumFromPosition(CellList[i][j]->GetCellPosition());
					bool rotation = CellList[i][j]->HasRotatingGear()->GetisClockWise();
					CellList[i][j]->HasRotatingGear()->Save(outfile, X, CellNum, Count, Locations, clock, rotation);
				}
			}
		}
		outfile << Count << endl;
		for (int i = 0; i < Count; i++)
		{
			outfile << Locations[i] << " " << clock[i] << endl;
		}
		outfile << "----------" << endl;
		break;
	}*/
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}