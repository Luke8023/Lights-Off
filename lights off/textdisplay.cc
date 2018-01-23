#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n): gridSize{n} {
	for(int i = 0; i < n; ++i) {
		vector<char> temp;
		for(int k = 0; k < n; ++k) {
			temp.push_back('_');
		}
		theDisplay.push_back(temp);
	}
}

void TextDisplay::notify(Subject &whoNotified) {
	int r = whoNotified.getInfo().row;
	int c = whoNotified.getInfo().col;
	if(whoNotified.getInfo().state == false) {
		theDisplay[r][c] = '_';
	} else {
		theDisplay[r][c] = 'X';
	}
}

TextDisplay::~TextDisplay() {
	for(unsigned int i = 0; i < theDisplay.size(); ++i) {
		theDisplay[i].clear();
	}
	theDisplay.clear();
}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for(int r = 0; r < td.gridSize; ++r) {
		for(int c = 0; c < td.gridSize; ++c) {
			out << td.theDisplay[r][c];
		}
		out << endl;
	}
  return out;
}
