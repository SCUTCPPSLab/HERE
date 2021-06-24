#pragma once
#include <iostream>
#include <stdio.h>
//#include <conio.h>
#include <time.h>	// class needs this inclusion
// http://www.cplusplus.com/forum/beginner/317/

class BenchmarkTimer {
	public:
		BenchmarkTimer();
		void           start();
		void           stop();
		void           reset();
		bool           isRunning();
		unsigned long  getTime();
		bool           isOver(unsigned long seconds);
	private:
		bool           resetted;
		bool           running;
		unsigned long  beg;
		unsigned long  end;
};
