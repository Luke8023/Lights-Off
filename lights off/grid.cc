#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid(Xwindow &xwin)
:gridSize{0}, td{nullptr}, gd{new GraphicsDisplay{xwin}}{}

Grid::~Grid() {
	for(unsigned int i = 0; i < theGrid.size(); ++i) {
		theGrid[i].clear();
	}
	theGrid.clear();
	delete td;
	delete gd;
}

void Grid::clearGrid() {
	gridSize = 0;
	for(unsigned int i = 0; i < theGrid.size(); ++i) {
		theGrid[i].clear();
	}
	theGrid.clear();
	delete td;
}

bool Grid::isWon() const {
	for(int i = 0; i < gridSize; ++i) {
		for(int k = 0; k < gridSize; ++k) {
			if(theGrid[i][k].getState() == true) return false;
		}
	}
    return true;
}

void Grid::init(int n) {
	clearGrid();
	gridSize = n;
	gd->clearDisplay();
	gd->init(n);
	td = new TextDisplay(n);
	for(int r = 0; r < n; ++r) {
		vector<Cell> temp(n, Cell());
		for(int c = 0; c < n; ++c) {
			temp[c].setCoords(r, c);
		}
		theGrid.push_back(temp);
	}
	for(int r = 0; r < n; ++r) {
		for(int c = 0; c < n; ++c) {
			if(r > 0) {
				theGrid[r][c].attach(&theGrid[r - 1][c]);
			}
			if(r < n - 1) {
				theGrid[r][c].attach(&theGrid[r + 1][c]);
			}
			if(c > 0) {
				theGrid[r][c].attach(&theGrid[r][c - 1]);
			}
			if(c < n - 1) {
				theGrid[r][c].attach(&theGrid[r][c + 1]);
			}
			theGrid[r][c].attach(td);
			theGrid[r][c].attach(gd);
		}
	}
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
}

ostream &operator<<(ostream &out, const Grid &g) {
	return operator<<(out, *(g.td));
}
