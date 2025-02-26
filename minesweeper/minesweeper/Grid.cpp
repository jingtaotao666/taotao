#include "Grid.h"

Grid::Grid() {
	m_realGridType = GridType::GT_EMPTY;
	m_showGridType = GridType::GT_EMPTY;
}
void Grid::SetshowGridType(GridType showGridType) {
	m_showGridType = showGridType;
}
void Grid::SetRealGridType(GridType realGridType) {
	m_realGridType = realGridType;
}
bool Grid::IsEmpty()const {
	return m_realGridType == GridType::GT_EMPTY;
}
bool Grid::IsRealBOMB()const {
	return m_realGridType == GridType::GT_BOMB;
}
void Grid::ShowGrid() {
	m_showGridType = m_realGridType;
}
bool Grid::IsShowBOMB() {
	return m_showGridType == GridType::GT_BOMB;
}
GridType Grid::GetShowGridType() {
	return m_showGridType;
}