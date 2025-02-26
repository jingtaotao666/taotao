#pragma once
#include "const.h"

class Grid {
public:
	Grid();
	void SetshowGridType(GridType showGridType);
	void SetRealGridType(GridType realGridType);
	bool IsEmpty()const;
	bool IsRealBOMB()const;
	void ShowGrid();
	bool IsShowBOMB();
	GridType GetShowGridType();
private:
	GridType m_realGridType;
	GridType m_showGridType;
};