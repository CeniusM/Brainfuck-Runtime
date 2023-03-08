#pragma once
#include <stdlib.h>

struct Instructions
{
	int capacity;
	int currentCount;
	char* instructions;
};

void InitInstructions(Instructions& i)
{
	i.capacity = 100;
	i.currentCount = 0;
	i.instructions = (char*)malloc(i.capacity * sizeof(char));
}