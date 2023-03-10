#pragma once

typedef char Instruct;
typedef char bool;
//const bool true = 1;
//const bool false = 1;
#define true 1
#define false 0

#define Brain_Null '\0'
#define Brain_Plus '+'
#define Brain_Minus '-'
#define Brain_LeftMove '<'
#define Brain_RightMove '>'
#define Brain_Output '.'
#define Brain_Input ','
#define Brain_Start '['
#define Brain_End ']'
#define Brain_DebugSymbole '?'

#define GetKeyStroke (unsigned char)getch();

#define ArrowKeyPress 224
#define ArrowKeyUp 72
#define ArrowKeyDown 80
#define ArrowKeyLeft 75
#define ArrowKeyRight 77

// Used as a list to add the human instructions
typedef struct
{
	int capacity;
	int currentCount;
	Instruct* instructions;
}Instructions;

// Is the compiled down executable instructions for the runtime to run
typedef struct
{
	int length;
	// the amount of numbers you can hold for the []
	int stackSizeNeeded;
	Instruct* instructions;
}Executable;

typedef struct
{
	unsigned char memory[3000];
	int memoryPointer;
	int executionPointer;
	int length;
	Instruct* instructions;
	// the amount of numbers you can hold for the []
	int stackSize;
	int stackPointer;
	int* stack;
}Execution;


