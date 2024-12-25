#pragma once
#include "Action.h"
#include "Player.h"

class ExecuteCommandAction : public Action
{
	protected:

		ApplicationManager* pManager;	// Actions needs ApplicationManager to do their job

	public:

		ExecuteCommandAction(ApplicationManager* pApp);  

		// ============ Virtual Functions ============

		virtual void ReadActionParameters(); 

		virtual void Execute();  

		virtual ~ExecuteCommandAction();  
};