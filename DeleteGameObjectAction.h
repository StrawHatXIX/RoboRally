#pragma once
#include "Action.h"
class DeleteGameObjectAction :
	public Action
{
	// [Action Parameters]
public:

	DeleteGameObjectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 
	virtual void Execute(); // Removes the Game Object in the Selected Cell 
	~DeleteGameObjectAction();
};

