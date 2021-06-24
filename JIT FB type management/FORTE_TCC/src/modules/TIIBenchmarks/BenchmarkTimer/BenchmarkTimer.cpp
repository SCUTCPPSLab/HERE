#include "BenchmarkTimer.h"
//////////////////////////////////////////
// class implementation:


BenchmarkTimer::BenchmarkTimer() {
	resetted = true;
	running = false;
	beg = 0;
	end = 0;
}


void BenchmarkTimer::start() {
	if(! running) {
		if(resetted)
			beg = (unsigned long) clock();
		else
			beg -= end - (unsigned long) clock();
		running = true;
		resetted = false;
	}
}


void BenchmarkTimer::stop() {
	if(running) {
		end = (unsigned long) clock();
		running = false;
	}
}


void BenchmarkTimer::reset() {
	bool wereRunning = running;
	if(wereRunning)
		stop();
	resetted = true;
	beg = 0;
	end = 0;
	if(wereRunning)
		start();
}


bool BenchmarkTimer::isRunning() {
	return running;
}


unsigned long BenchmarkTimer::getTime() {
	if(running)
		return ((unsigned long) clock() - beg) / (CLOCKS_PER_SEC/1000); //return ms
	else
		return ((unsigned long) end - beg) / (CLOCKS_PER_SEC/1000); //return ms
}


bool BenchmarkTimer::isOver(unsigned long seconds) {
	return seconds >= getTime();
}
