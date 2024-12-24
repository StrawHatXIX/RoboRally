#pragma once
#include "Action.h"
class CopyGameObjectAction :
	public Action
{
	// [Action Parameters]
public:

	CopyGameObjectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 
	virtual void Execute(); // Creates a new Game Object in the Clipboard 
	~CopyGameObjectAction();
};

