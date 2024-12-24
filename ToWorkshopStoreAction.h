#pragma once
#include "Action.h"
#include "Player.h"

class ToWorkshopStoreAction : public Action
{
protected:

	ApplicationManager* pManager;

public:

	ToWorkshopStoreAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~ToWorkshopStoreAction();
};