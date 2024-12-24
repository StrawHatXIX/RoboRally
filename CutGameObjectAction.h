#pragma once
#include "Action.h"
class CutGameObjectAction :
	public Action
{
	// [Action Parameters]
public:

	CutGameObjectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 
	virtual void Execute(); // Creates a new Game Object in the Clipboard and Removes the GameObject in that Cell
	~CutGameObjectAction();
};

