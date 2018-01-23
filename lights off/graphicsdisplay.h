#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include "observer.h"
#include "window.h"
class Cell;

class GraphicsDisplay: public Observer {
	Xwindow &xwin;
	int gridSize;
	int winSize = 500;
	
	public:
	GraphicsDisplay(Xwindow &xwin);
    ~GraphicsDisplay();
	void clearDisplay();
	void init(int n);
	void notify(Subject &whoNotified) override;
    SubscriptionType subType() const override;
};

#endif
