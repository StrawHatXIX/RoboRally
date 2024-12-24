#pragma once
#include"Action.h"
#include "Player.h"

class RebootAndRepairAction : public Action
{
protected:

	ApplicationManager* pManager;

public:

	RebootAndRepairAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~RebootAndRepairAction();
};