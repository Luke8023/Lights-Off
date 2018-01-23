#include "subject.h"
#include "observer.h"
#include "subscriptions.h"
#include "graphicsdisplay.h"
#include "window.h"
void Subject::attach(Observer *o) { 
	observers.emplace_back(o);
}

 void Subject::notifyObservers(SubscriptionType t) {
	for(unsigned int i = 0; i < observers.size(); ++i) {
		if(t == observers[i]->subType()) {
			observers[i]->notify(*this);
		} 
	}
} 


Subject::~Subject(){}
