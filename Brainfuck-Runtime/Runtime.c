#include "Runtime.h"

void RunDebugMode(Execution* exc, bool wasError)
{
	bool running = true;
	int c;
	int lookingPointer = exc->memoryPointer;
	while (running)
	{
		// Set cursor
		// clear
		// Set cursor

		printf("Press \"n\" to run next instruct\n");
		printf("Press \"c\" to resume execution\n");
		printf("Press \"down\" to see else where in aray (heigher)\n");
		printf("Press \"up\" to see else where in aray (lower)\n");
		printf("Press \"right\" to increase current value\n");
		printf("Press \"right\" to decrease current value\n");

		// print
		int lowArrayNum = lookingPointer - 2;
		int highArrayNum = lookingPointer + 2;

		for (int i = lowArrayNum; i <= highArrayNum; i++)
		{
			printf("%d", i);
			printf(" = ");
			if (i > 2999 || i < 0)
				printf("Error");
			else
			{
				int value = exc->memory[i];
				printf("val:%d, char:\'%c\'", value, (char)value);
			}
			if (i == lookingPointer)
				printf(" <--");
			printf("\n");
		}

		c = GetKeyStroke;
		if (c == ArrowKeyPress)
		{
			c = GetKeyStroke;
			if (c == ArrowKeyDown)
				lookingPointer++;
			else if (c == ArrowKeyUp)
				lookingPointer--;
			else if (c == ArrowKeyRight && lookingPointer < 3000 && lookingPointer >= 0)
				exc->memory[lookingPointer]++;
			else if (c == ArrowKeyLeft && lookingPointer < 3000 && lookingPointer >= 0)
				exc->memory[lookingPointer]--;

		}
		//if (c)
	}
}

void Error(Execution* exc, const char* str, bool debugEnabled)
{
	if (debugEnabled)
	{
		// Run
		RunDebugMode(exc, true);
	}
	else
		ThrowExcepction(str);
}

void RunExecutable(Executable* ex, bool debugEnabled)
{
	Execution exc = { 0 };
	exc.length = ex->length;
	exc.stackSize = ex->stackSizeNeeded;
	exc.instructions = ex->instructions;
	exc.stackPointer = 0;
	while (exc.stack == NULL)
		exc.stack = malloc(sizeof(int) * exc.stackSize);
	exc.executionPointer = 0;
	char key = 0;

	while (exc.executionPointer < exc.length)
	{
		RunInstruct(&exc, debugEnabled);
	}
}

inline void RunInstruct(Execution* exc, bool debugEnabled)
{
	Instruct instruct = exc->instructions[exc->executionPointer];
	char key;
	switch (instruct)
	{
	case Brain_Plus:
		if (exc->memory[exc->memoryPointer] == 255)
			exc->memory[exc->memoryPointer] = 0;
		else
			exc->memory[exc->memoryPointer]++;
		break;
	case Brain_Minus:
		if (exc->memory[exc->memoryPointer] == 0)
			exc->memory[exc->memoryPointer] = 255;
		else
			exc->memory[exc->memoryPointer]--;
		break;
	case Brain_RightMove:
		exc->memoryPointer++;
		if (exc->memoryPointer > 2999)
			Error(exc, "Cannot set MemoryPointer outside of the memory buffer (above 3000)", debugEnabled);
		break;
	case Brain_LeftMove:
		exc->memoryPointer--;
		if (exc->memoryPointer < 0)
			Error(exc, "Cannot set MemoryPointer outside of the memory buffer (bellow 0)", debugEnabled);
		break;
	case Brain_Start:
		//Error(exc, "Start not implemented", debugEnabled);
		exc->stack[exc->stackPointer++] = exc->executionPointer;
		break;
	case Brain_End:
		//Error(&exc-> "End not implemented", debugEnabled);
		if (exc->memory[exc->memoryPointer] != 0)
			exc->executionPointer = exc->stack[exc->stackPointer - 1];
		else
			exc->stackPointer--;
		break;
	case Brain_Output:
		printf("%c", exc->memory[exc->memoryPointer]);
		break;
	case Brain_Input:
		key = GetKeyStroke;
		if (key == ArrowKeyPress)
		{
			GetKeyStroke; // clear keys
		}
		else
		{
			exc->memory[exc->memoryPointer];
		}
		break;
	case Brain_DebugSymbole:
		RunDebugMode(&exc, false);
		break;
	default:
		break;
	}
	exc->executionPointer++;
}
