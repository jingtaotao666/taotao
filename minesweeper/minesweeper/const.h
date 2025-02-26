#pragma once
enum GridType {
	GT_EMPTY = 0,
	GT_COUNT_1 = 1,
	GT_COUNT_2 = 2,
	GT_COUNT_3 = 3,
	GT_COUNT_4 = 4,
	GT_COUNT_5 = 5,
	GT_COUNT_6 = 6,
	GT_COUNT_7 = 7,
	GT_COUNT_8 = 8,
	GT_BOMB = 9,
	GT_HIDE = 10,
	GT_FLAG = 11,
};

const int DIR[8][2] = {
	{-1,-1},  {-1, 0},  {-1,1},
	{0, -1},            {0, 1},
	{1, -1},  { 1, 0},  {1, 1}
};

const int ORI_GRID_SIZE = 96;//ԭͼƬ��ÿ�����ӵĴ�С
const int GRID_SIZE = 48;//��Ϸ��ÿ�����ӵĴ�С
const int MAP_COL = 15;//��Ϸ��ͼ�Ŀ�
const int MAP_ROW = 10;//��
const int WIN_W = GRID_SIZE * (1 + MAP_COL + 1);//��Ϸ���ڵĿ�
const int WIN_H = GRID_SIZE * (1 + MAP_ROW + 1);//��
