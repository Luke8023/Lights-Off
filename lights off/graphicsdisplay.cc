#include "graphicsdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

GraphicsDisplay::GraphicsDisplay(Xwindow &xwin)
: xwin{xwin}, gridSize{0}, winSize{500}{}
GraphicsDisplay::~GraphicsDisplay(){}

void GraphicsDisplay::clearDisplay() {
	xwin.fillRectangle(0, 0, winSize, winSize, Xwindow::White);
}

void GraphicsDisplay::init(int n) {
	gridSize = n;
	int unit = 500 / gridSize;
	for(int r = 0; r < n; ++r) {
		for(int c = 0; c < n; ++c) {
			xwin.fillRectangle(r * unit, c * unit, unit, unit, Xwindow::Black);
		}
	}
}

void GraphicsDisplay::notify(Subject &whoNotified) {
	int unit = 500 / gridSize;
	int r = whoNotified.getInfo().row;
	int c = whoNotified.getInfo().col;
	if(whoNotified.getInfo().state) {
		xwin.fillRectangle(r * unit, c * unit, unit, unit, Xwindow::White);
	} else {
		xwin.fillRectangle(r * unit, c * unit, unit, unit, Xwindow::Black);
	}
}

SubscriptionType GraphicsDisplay::subType() const {
  return SubscriptionType::All;
}
