#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "Map.h"
using namespace sf;
using namespace std;

int main() {
	srand((unsigned int)time(NULL));
	RenderWindow win(VideoMode(WIN_W, WIN_H),  L"扫雷");
	Texture t;
	t.loadFromFile("mine.png");
	Sprite s(t);
	Map mp;
	
	mp.init(&win, &s);
	while (win.isOpen()) {
		Event e; 
		Vector2i pos = Mouse::getPosition(win);
		int x = pos.x / GRID_SIZE;
		int y = pos.y / GRID_SIZE;

		while (win.pollEvent(e)) {
			if (e.type == Event::Closed) {
				cout << "按下关闭按钮" << endl;
				win.close();
			}
			mp.handleMouseEvent(e, x, y);
		}
		mp.draw(x, y);
		
		win.display();
	}
	return 0;
}