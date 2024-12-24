#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
class SaveGridAction :
    public Action
{

public:
    SaveGridAction(ApplicationManager* pApp);

    virtual void ReadActionParameters(); // Reads action parameters 

    virtual void Execute();

    ~SaveGridAction();
};

