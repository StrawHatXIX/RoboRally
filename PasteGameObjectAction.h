#pragma once
#include "Action.h"
class PasteGameObjectAction :
	public Action
{
	// [Action Parameters]
public:

	PasteGameObjectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 
	virtual void Execute(); // Creates a new Game Object form the Clipboard to the Cell
	~PasteGameObjectAction();
};

