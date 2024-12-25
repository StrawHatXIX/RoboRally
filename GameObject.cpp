#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

void GameObject::Save(ofstream& outfile, int Count, int* Locations_1, int* Locations_2)
{

}

GameObject::~GameObject()
{
}