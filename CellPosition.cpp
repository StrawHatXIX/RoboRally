#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO (done.S): Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v < NumVerticalCells)
	{
		vCell = v;
		return true;
	}
	else
	{
		vCell = -1;
		return false;
	} // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///TODO (done.S): Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h < NumHorizontalCells)
	{
		hCell = h;
		return true;
	}
	else
	{
		hCell = -1;
		return false;
	} // this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO (done.S): Implement this function as described in the .h file
	if (vCell >= 0 && vCell < NumVerticalCells && hCell >= 0 && hCell < NumHorizontalCells)
	{
		return true;
	}
	else
		return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	if (cellPosition.IsValidCell())
	{
		int tens = (NumVerticalCells - cellPosition.VCell() - 1) * NumHorizontalCells;
		int units = cellPosition.HCell() + 1;
		int CellNumPosition = tens + units;
		return CellNumPosition;
	}
	else
		return -1;

	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO (Done.S): Implement this function as described in the .h file

	// this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position1;

	/// TODO (Done.S) : Implement this function as described in the .h file

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	int v, h;
	if (cellNum > 55 || cellNum < 1)
	{
		return position1;
	}

	if (cellNum == 11 || cellNum == 22 || cellNum == 33 || cellNum == 44 || cellNum == 55)
	{
		h = 10;
		switch (cellNum)
		{
		case 11:
			v = 4;
			break;
		case 22:
			v = 3;
			break;
		case 33:
			v = 2;
			break;
		case 44:
			v = 1;
			break;
		case 55:
			v = 0;
			break;
		}
	}
	else
	{
		v = NumVerticalCells - (cellNum / NumHorizontalCells) - 1;
		h = (cellNum % NumHorizontalCells) - 1;
	}

	CellPosition position;
	position.SetVCell(v);
	position.SetHCell(h);
	return position;
	// TODO (Done.S) : Implement this function as described in the .h file

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{
	if (addedNum <= 0)
	{
		return;
	}

	CellPosition position = GetCellPositionFromNum(addedNum);
	int h = position.HCell();
	int v = position.VCell();
	switch (direction)
	{
	case UP:
		if ((v - addedNum) < 0)
		{
			return;
		}
		else
		{
			v -= addedNum;
			position.SetVCell(v);
			break;
		}
	case DOWN:
		if ((v + addedNum) > (NumVerticalCells - 1))
		{
			return;
		}
		else
		{
			v += addedNum;
			position.SetVCell(v);
			break;
		}
	case LEFT:
		if ((h - addedNum) < 0)
		{
			return;
		}
		else
		{
			h -= addedNum;
			position.SetHCell(h);
			break;
		}
	case RIGHT:
		if ((h + addedNum) > (NumHorizontalCells - 1))
		{
			return;
		}
		else
		{
			h += addedNum;
			position.SetHCell(h);
			break;
		}
	}
	/// TODO (done.S) : Implement this function as described in the .h file


	// Note: this function updates the data members (vCell and hCell) of the calling object

}