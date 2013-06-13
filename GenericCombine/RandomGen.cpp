#include <ctime>
#include <iostream>
#include "RandomGen.h"


int rgen::GetRandVal( int Lo, int Hi) {
	int Range = Hi - Lo + 1;
	int Num   = (int)(rand() / (RAND_MAX + 1.0) * Range);
	return Lo + Num;
}

void rgen::Init()
{
   srand((unsigned)time(0));
}
