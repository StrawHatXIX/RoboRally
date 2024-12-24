#include "ToPlayModeAction.h"
#include "Player.h"

ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp) : Action(pApp)
{
}
void ToPlayModeAction::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();

    if (pGrid->FlagOnGrid())
        return;//if no flag, dont allow switch to gameMode

    if (pGrid->AntennaOnGrid())
        return;//if no Antenna, dont allow switch to gameMode

}
void ToPlayModeAction::Execute()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Player* pPlayer = pGrid->GetCurrentPlayer();

    const int maxSavedCommands = 5; // Example maximum saved commands count
    const int maxAvailableCommands = pPlayer->GetHealth(); // Total commands in the game

    Command savedCommands[maxSavedCommands] = {
        MOVE_FORWARD_ONE_STEP, MOVE_BACKWARD_ONE_STEP,
        ROTATE_CLOCKWISE, MOVE_FORWARD_TWO_STEPS,
        MOVE_BACKWARD_TWO_STEPS
    }; // Example of saved commands

    //Command availableCommands[maxAvailableCommands] = {
    //    NO_COMMAND, MOVE_FORWARD_ONE_STEP, MOVE_BACKWARD_ONE_STEP,
    //    MOVE_FORWARD_TWO_STEPS, MOVE_BACKWARD_TWO_STEPS,
    //    MOVE_FORWARD_THREE_STEPS, MOVE_BACKWARD_THREE_STEPS,
    //    ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE
    //}; // Example of all available commands

    Command* availableCommands = pGrid->GetRandomCommand();

    // Use Output::CreateCommandsBar to display the commands bar
    pOut->CreateCommandsBar(pPlayer->GetSavedCommands(), maxSavedCommands, availableCommands, maxAvailableCommands);

    // Optional: Notify the user
    pOut->PrintMessage("Switched to Play Mode! Commands Bar updated.");
}
ToPlayModeAction::~ToPlayModeAction()
{
}