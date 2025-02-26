#include<iostream>
#include<Windows.h> // 包含Windows特定的函数，如控制台光标隐藏
#include<conio.h>   // 用于_kbhit()和_getch()函数，检测键盘输入
using namespace std;

#define H 27       // 定义游戏地图的高度
#define W 60       // 定义游戏地图的宽度

// 定义四个方向：上、右、下、左
const int dir[4][2] = {
    {-1, 0},      // 上
    {0, 1},       // 右
    {1, 0},       // 下
    {0, -1}       // 左
};

// 隐藏光标的函数
void hideCursor() {
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出句柄
    CONSOLE_CURSOR_INFO curInfo = { 1, FALSE };       // 设置光标大小和可见性
    SetConsoleCursorInfo(hOutput, &curInfo);          // 应用设置
}

// 枚举类型定义了方块类型：空或食物
enum BlockType {
    EMPTY = 0,
    FOOD = 1,
};

// 地图结构体，包含一个二维数组表示地图上的方块类型，以及是否有食物
struct Map {
    BlockType data[H][W];
    bool hasFood;
};

// 位置结构体，包含x和y坐标
struct Pos {
    int x;
    int y;
};

// 蛇结构体，包含蛇的位置列表、当前方向、长度、上次移动时间、移动频率
struct Snack {
    Pos snack[H * W];
    int snackDir;
    int snackLength;
    int lastMoveTime;
    int moveFrequency;
};

// 初始化蛇
void initSnack(Snack* snk) {
    snk->snackLength = 3;
    snk->snackDir = 1; // 初始向右移动
    snk->snack[0] = { W / 2, H / 2 }; // 蛇头位置
    snk->snack[1] = { W / 2 - 1, H / 2 };
    snk->snack[2] = { W / 2 - 2, H / 2 };
    snk->lastMoveTime = 0;
    snk->moveFrequency = 200; // 移动频率
}

// 初始化地图
void initMap(Map* map) {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            map->data[y][x] = BlockType::EMPTY;// 初始化地图为全部空
        }
    }
    map->hasFood = false;
}

// 绘制单个单元格
void drawUnit(Pos p, const char unit[]) {
    COORD coord = { p.x + 1, p.y + 1 }; // 计算新的坐标
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, coord); // 设置光标位置
    cout << unit; // 输出字符
}

// 绘制地图
void drawMap(Map* map) {
    system("cls");
    cout << "*";
    for (int i = 0; i < W; i++) {
        cout << "*";
    }
    cout << "*" << endl;
    for (int y = 0; y < H; y++) {
        cout << "*";
        for (int x = 0; x < W; x++) {
            if (map->data[y][x] == BlockType::EMPTY)
                cout << " ";
        }
        cout << "*" << endl;
    }
    cout << "*";
    for (int i = 0; i < W; i++) {
        cout << "*";
    }
    cout << "*" << endl;
}

// 绘制蛇
void drawSnack(Snack* snk) {
    for (int i = 0; i < snk->snackLength; i++) {
        drawUnit(snk->snack[i], "■");
    }
}

// 检查是否超出边界
bool checkOutOfBound(Pos p) {
    return (p.x == 0 || p.x == W + 1 || p.y == 0 || p.y == H + 1);
}

// 检查蛇是否吃到食物
void checkEatFood(Snack* snk, Pos tail, Map* map) {
    Pos head = snk->snack[0];
    if (map->data[head.y][head.x] == BlockType::FOOD) {
        snk->snack[snk->snackLength++] = tail; // 吃到食物后增加长度
        map->data[head.y][head.x] = BlockType::EMPTY;
        map->hasFood = false;
        drawUnit(tail, "■"); // 更新新加入的蛇身部分
    }
}

// 移动蛇
void moveSnack(Snack* snk) {
    for (int i = snk->snackLength - 1; i >= 1; i--) {
        snk->snack[i] = snk->snack[i - 1]; // 将前一个身体部分的位置赋值给当前部分
    }
    snk->snack[0].y += dir[snk->snackDir][0]; // 更新头部位置
    snk->snack[0].x += dir[snk->snackDir][1];
}

// 执行移动并检查碰撞
bool doMove(Snack* snk, Map* map) {
    Pos tail = snk->snack[snk->snackLength - 1];
    drawUnit(tail, " "); // 清除尾部痕迹
    moveSnack(snk);
    if (checkOutOfBound(snk->snack[0])) {
        return false; // 检测碰撞
    }
    checkEatFood(snk, tail, map);
    drawUnit(snk->snack[0], "■"); // 更新头部显示
    return true;
}

// 检测并改变方向
void checkChangeDir(Snack* snk) {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w':
            if (snk->snackDir != 2)
                snk->snackDir = 0;
            break;
        case 'd':
            if (snk->snackDir != 3)
                snk->snackDir = 1;
            break;
        case 's':
            if (snk->snackDir != 0)
                snk->snackDir = 2;
            break;
        case 'a':
            if (snk->snackDir != 1)
                snk->snackDir = 3;
            break;
        default:
            break;
        }
    }
}

// 检查并执行蛇的移动
bool checkSnackMove(Snack* snk, Map* map) {
    int curTime = GetTickCount();
    if (curTime - snk->lastMoveTime > snk->moveFrequency) {
        if (doMove(snk, map) == false) {
            return false; // 执行移动并检测碰撞
        }
        snk->lastMoveTime = curTime; // 更新上次移动时间
    }
    return true;
}

// 检查并生成食物
void checkFoodGenerate(Snack* snk, Map* map) {
    if (!map->hasFood) {
        while (true) {
            int x = rand() % W;
            int y = rand() % H;
            bool found = false;
            for (int i = 0; i < snk->snackLength; ++i) {
                if (x == snk->snack[i].x && y == snk->snack[i].y) {
                    found = true;
                    break;// 如果随机点在蛇身上则重新生成
                }
            }
            if (!found) {
                map->data[y][x] = BlockType::FOOD;
                map->hasFood = true;
                drawUnit({ x,y }, "●");
                return;
            }
        }
    }
}

// 初始化游戏
void initGame(Snack* snk, Map* map) {
    hideCursor(); // 隐藏光标
    initMap(map); // 初始化地图
    initSnack(snk); // 初始化蛇
    drawMap(map); // 绘制地图
    drawSnack(snk); // 绘制蛇
}

// 主函数
int main() {
    Map map;
    Snack snk;
    initGame(&snk, &map);
    while (true) {
        checkChangeDir(&snk); // 检查方向变化
        if (!checkSnackMove(&snk, &map)) {
            break; // 执行移动并检查游戏结束条件
        }
        checkFoodGenerate(&snk, &map); // 检查并生成食物
    }
    drawUnit({ W / 2 - 4,H / 2 }, "Game Over"); // 游戏结束提示
    while (1) {}
    return 0;
}