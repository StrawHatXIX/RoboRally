#include "Workshop.h"



Workshop::Workshop(const CellPosition& workshopPosition) :GameObject(workshopPosition)
{

}


void Workshop::Draw(Output* pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid* pGrid, Player* pPlayer)
{

	Output* pOut = pGrid->GetOutput();

	WORKSHOP_OPTIONS ARRAY[2] = { ITM_REPAIR , ITM_EQUIPMENT };
	WORKSHOP_OPTIONS* ICONS = ARRAY;

	pOut->CreateWorkshopOptions(ICONS, WORKSHOP_OPTIONS_COUNT);
}

void Workshop::Save(ofstream& outfile, int Count, int* Locations_1, int* Locations_2)
{
	outfile << Count << endl;
	for (int i = 0; i < Count; i++)
	{
		outfile << Locations_1[i] << endl;
	}
}



Workshop::~Workshop()
{
}
