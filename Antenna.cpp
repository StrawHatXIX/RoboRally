#include "Antenna.h"

Antenna::Antenna(const CellPosition& antennaPosition) :GameObject(antennaPosition)
{
}

void Antenna::Draw(Output* pOut) const
{
    pOut->DrawAntenna(position);
}

int Antenna::DetermineCurrentPlayer(CellPosition player1Pos, CellPosition player2Pos) const {
    // Calculate the distance between the antenna and the players
    int distanceToPlayer1 = abs(position.VCell() - player1Pos.VCell()) + abs(position.HCell() - player1Pos.HCell());
    int distanceToPlayer2 = abs(position.VCell() - player2Pos.VCell()) + abs(position.HCell() - player2Pos.HCell());

    // Return 0 if Player 1 is closer, otherwise return 1
    return (distanceToPlayer1 <= distanceToPlayer2) ? 0 : 1;
}



void Antenna::Apply(Grid* pGrid, Player* pPlayer)
{
    // 1- Print a message "the antenna will decide the turn of players. Click to continue ..." and wait mouse click
    Output* pOut = pGrid->GetOutput();
    pOut->PrintMessage("The antenna will decide the turn of players. Click to continue ...");
    Input* pIn = pGrid->GetInput();
    int x, y;
    pIn->GetPointClicked(x, y);

    // Step 2: Get the positions of the two players
    CellPosition antennaPosition = position;  // Position of the antenna
    CellPosition FirstPlayer = pGrid->GetPlayer(0)->GetCell()->GetCellPosition();  // Player 1's position
    CellPosition SecondPlayer = pGrid->GetPlayer(1)->GetCell()->GetCellPosition();  // Player 2's position

    //Calculate the distances to each player
    int d1 = abs(antennaPosition.VCell() - FirstPlayer.VCell()) + abs(antennaPosition.HCell() - FirstPlayer.HCell());

    int d2 = abs(antennaPosition.VCell() - SecondPlayer.VCell()) + abs(antennaPosition.HCell() - SecondPlayer.HCell());

    //Determine which player goes first
    int currentPlayer;  // Variable to store the current player
    if (d1 < d2) {
        currentPlayer = 0;  // Player 1 is closer
    }
    else if (d1 > d2) {
        currentPlayer = 1;  // Player 2 is closer
    }
    else {
        currentPlayer = 0;  // Tie, Player 1 plays first by default
    }

    //Update the turn order in the grid
    pGrid->SetCurrentPlayer(currentPlayer);

    //Display which player will play first
    pOut->PrintMessage("Player " + to_string(currentPlayer + 1) + " will play first");
}

void Antenna::Save(ofstream& outfile, int Count, int* Locations_1, int* Locations_2)
{
    outfile << Count << endl << Locations_1[Count - 1] << endl;
}

GameObject* Antenna::Load(const CellPosition& pos, std::ifstream& infile)
{
    // No additional data is required for an Antenna
    return new Antenna(pos);
}


Antenna::~Antenna()
{
}
