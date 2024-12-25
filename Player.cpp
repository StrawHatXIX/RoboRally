#include "Player.h"

#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT)
{
	this->pCell = pCell;
	bool Laser = true;
	bool DoubleLaser = false;

	// carried consumables
	bool HasToolkit = false;
	bool HasHackDevice = false;

	// carried laser type (default, double laser)
	bool ExtendedMemory = false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetHealth(int h)
{
	this->health = (h >= 0 && h <= 10) ? h : 0;

	///TODO (Done.S) : Do any needed validations
}

int Player::GetHealth()
{
	return this->health;
}

void Player:: EquipLaser(bool a)
{
	Laser = a;
}

bool Player ::LaserEquiped()
{
	return Laser;
}

void Player::EquipDoubleLaser(bool a)
{
	DoubleLaser = a;
}

bool Player::DoubleLaserEquiped()
{
	return DoubleLaser;
}


void Player::EquipToolkit(bool a)
{
	HasToolkit = a;
}

bool Player::ToolkitEquiped()
{
	return HasToolkit;
}

void Player::EquipHackDevice(bool a)
{
	HasHackDevice = a;
}

bool Player::HackDeviceEquiped()
{
	return HasHackDevice;
}

void Player::ApplyExtendedMemory()
{
	ExtendedMemory = true;
}

void Player :: ApplyIsHacked()
{
	isHacked = true;
}



Direction Player::GetDirection() const
{
	return this->currDirection;
}

void Player::SetDirection(Direction dir)
{
	this->currDirection = dir;
}

int Player::GetplayerNum() const
{
	return this->playerNum;

}


bool Player::SetSavedCommands(Command command)
{
	if (NumSavedCommands < 5 || (NumSavedCommands == 5 && ExtendedMemory))
	{
		SavedCommands[NumSavedCommands] = command;
		NumSavedCommands++;
		return true;
	}
	return false;
}

Command* Player::GetSavedCommands()
{
	return SavedCommands;
}

int Player::GetNumSavedCommands()
{
	return NumSavedCommands;
}




// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	///TODO (Done.S): use the appropriate output function to draw the player with "playerColor"

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor, currDirection);

}

void Player::ClearDrawing(Output* pOut) const
{
	///TODO (Done.S) : Modify the cellColor to draw the correct cellColor (hint: if cell contains non-default cellColor)
	color cellColor = UI.CellColor;

	if (pCell->HasDangerZone())
	{
		cellColor = UI.DangerZoneCellColor;
	}

	if (pCell->HasWaterPit())
	{
		cellColor = UI.WaterPitsCellColor;
	}

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor, currDirection); //fill in the player's old position with the cell original color
	///TODO (Done.S) : use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, Command moveCommands[])
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	///TODO (Done.S): Implement this function using the guidelines mentioned below

	CellPosition currentPosition = pCell->GetCellPosition();

	CellPosition nextPosition;//new position for pCell to draw the pler in it 
	nextPosition.SetVCell(currentPosition.VCell());
	nextPosition.SetHCell(currentPosition.HCell());

	Cell* NewCell = new Cell(nextPosition);


	if (NumSavedCommands >= 5) { //LATER for the extended memory upgrade later

		for (int i = 0; i < NumSavedCommands; i++) {

			// Display a message to execute the next command
			pOut->PrintMessage("Click anywhere to execute the next command");
			int x, y;
			pIn->GetPointClicked(x, y);

			switch (moveCommands[i])
			{
			case NO_COMMAND:
				break;

			case MOVE_FORWARD_ONE_STEP:
				ClearDrawing(pOut);

				switch (currDirection)
				{
				case UP:
					stepCount += NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() - 1);
					SetCell(NewCell);
					break;

				case DOWN:
					stepCount -= NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() + 1);
					SetCell(NewCell);
					break;

				case RIGHT:
					stepCount += 1;
					nextPosition.SetHCell(currentPosition.HCell() + 1);
					SetCell(NewCell);
					break;

				case LEFT:
					stepCount -= 1;
					nextPosition.SetHCell(currentPosition.HCell() - 1);
					SetCell(NewCell);
					break;
				}

				pGrid->UpdatePlayerCell(this, nextPosition);
				Draw(pOut);
				break;

			case MOVE_BACKWARD_ONE_STEP:
				ClearDrawing(pOut);

				switch (currDirection)
				{

				case UP:
					stepCount -= NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() + 1);
					SetCell(NewCell);
					break;

				case DOWN:
					stepCount += NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() - 1);
					SetCell(NewCell);
					break;

				case RIGHT:
					stepCount -= 1;
					nextPosition.SetHCell(currentPosition.HCell() - 1);
					SetCell(NewCell);
					break;

				case LEFT:
					stepCount += 1;
					nextPosition.SetHCell(currentPosition.HCell() + 1);
					SetCell(NewCell);
					break;
				}

				Draw(pOut);
				break;

			case MOVE_FORWARD_TWO_STEPS:
				ClearDrawing(pOut);

				switch (currDirection)
				{
				case UP:
					stepCount += 2 * NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() - 2);
					SetCell(NewCell);
					break;

				case DOWN:
					stepCount -= 2 * NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() + 2);
					SetCell(NewCell);
					break;

				case RIGHT:
					stepCount += 2;
					nextPosition.SetHCell(currentPosition.HCell() + 2);
					SetCell(NewCell);
					break;

				case LEFT:
					stepCount -= 2;
					nextPosition.SetHCell(currentPosition.HCell() - 2);
					SetCell(NewCell);
					break;
				}

				Draw(pOut);
				break;

			case MOVE_BACKWARD_TWO_STEPS:
				ClearDrawing(pOut);

				switch (currDirection)
				{
				case UP:
					stepCount -= 2 * NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() + 2);
					SetCell(NewCell);
					break;

				case DOWN:
					stepCount += 2 * NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() - 2);
					SetCell(NewCell);
					break;

				case RIGHT:
					stepCount -= 2;
					nextPosition.SetHCell(currentPosition.HCell() - 2);
					SetCell(NewCell);
					break;

				case LEFT:
					stepCount += 2;
					nextPosition.SetHCell(currentPosition.HCell() + 2);
					SetCell(NewCell);
					break;

				}

				Draw(pOut);
				break;

			case MOVE_FORWARD_THREE_STEPS:
				ClearDrawing(pOut);

				switch (currDirection)
				{
				case UP:
					stepCount += 3 * NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() - 3);
					SetCell(NewCell);
					break;

				case DOWN:
					stepCount -= 3 * NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() + 3);
					SetCell(NewCell);
					break;

				case RIGHT:
					stepCount += 3;
					nextPosition.SetHCell(currentPosition.HCell() + 3);
					SetCell(NewCell);
					break;

				case LEFT:
					stepCount -= 3;
					nextPosition.SetHCell(currentPosition.HCell() - 3);
					SetCell(NewCell);
					break;
				}

				Draw(pOut);
				break;

			case MOVE_BACKWARD_THREE_STEPS:
				ClearDrawing(pOut);

				switch (currDirection)
				{
				case UP:
					stepCount -= 3 * NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() + 3);
					SetCell(NewCell);
					break;
				case DOWN:
					stepCount += 3 * NumHorizontalCells;
					nextPosition.SetVCell(currentPosition.VCell() - 3);
					SetCell(NewCell);
					break;
				case RIGHT:
					stepCount -= 3;
					nextPosition.SetHCell(currentPosition.HCell() - 3);
					SetCell(NewCell);
					break;
				case LEFT:
					stepCount += 3;
					nextPosition.SetHCell(currentPosition.HCell() + 3);
					SetCell(NewCell);
					break;
				}

				Draw(pOut);
				break;

			case ROTATE_CLOCKWISE:
				ClearDrawing(pOut);

				switch (currDirection)
				{
				case UP:
					currDirection = RIGHT;
					break;
				case DOWN:
					currDirection = LEFT;
					break;
				case RIGHT:
					currDirection = DOWN;
					break;
				case LEFT:
					currDirection = UP;
					break;
				}
				Draw(pOut);
				break;


			case ROTATE_COUNTERCLOCKWISE:
				ClearDrawing(pOut);

				switch (currDirection)
				{
				case UP:
					currDirection = LEFT;
					break;
				case DOWN:
					currDirection = RIGHT;
					break;
				case RIGHT:
					currDirection = UP;
					break;
				case LEFT:
					currDirection = DOWN;
					break;
				}
				Draw(pOut);
				break;
			}

			pGrid->UpdateInterface();

			GameObject* pGameObject = pCell->GetGameObject();
			if (pGameObject)
			{
				pGameObject->Apply(pGrid, this); // Apply the effect of the game object
			}

			if (pGrid->GetEndGame())
			{
				//Seif : 7d y7ot el winning condition 
				pOut->PrintMessage("Player " + to_string(playerNum) + " Wins, Click to continue");
				break;
			}
		}
	}
}
// - If a player has 5 (could have less) saved moveCommands, the robot will execute the first saved command,
//		then wait for a mouse click (display a message "Click anywhere to execute the next command").
//		After executing all the 5 saved commands, the game object effect at the final destination cell will
//		be applied.
// 
// - Use the CellPosition class to help you calculate the destination cell using the current cell
// - Use the Grid class to update pCell
// - Don't forget to apply game objects at the final destination cell and check for game ending


//void Player::SaveCommands(const Command commands[], int NumCommands)
//{
//	int maxCommands = (health < 5) ? health : 5;
//
//	if (NumCommands > maxCommands)
//	{
//		NumCommands = maxCommands;
//	}
//
//	// Clean up any previously saved commands
//	SavedCommands[0] =
//
//	// Allocate new memory for the commands
//	//SavedCommands = new Command[NumCommands];
//
//	// Save the commands
//	//for (int i = 0; i < NumCommands; i++)
//	//{
//	//	SavedCommands[i] = commands[i];
//	//}
//
//	// Update the number of saved commands
//	NumSavedCommands = NumCommands;
//}



void Player::AppendPlayerInfo(string& playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(currDirection) + ", ";
	playersInfo += to_string(health) + ")";

}