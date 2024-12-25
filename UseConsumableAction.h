#pragma once
#pragma once
#include"Action.h"
#include "Player.h"

class UseConsumableAction : public Action
{
protected:

	ApplicationManager* pManager;

public:

	UseConsumableAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~UseConsumableAction();
};