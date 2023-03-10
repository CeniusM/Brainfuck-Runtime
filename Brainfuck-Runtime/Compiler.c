#include "Compiler.h"

void InitInstructions(const char* path, Instructions* ins)
{
	ins->capacity = 100;
	ins->currentCount = 0;
	ins->instructions = (char*)malloc(ins->capacity * sizeof(char));

	// read file
	FILE* ptr;
	char ch;


	bool failed = fopen_s(&ptr, path, "r");

	if (failed)
		ThrowExcepction("Cannot read file path ");

	do {
		ch = fgetc(ptr);

		if (ch == Brain_Null ||
			ch == Brain_Plus ||
			ch == Brain_Minus ||
			ch == Brain_LeftMove ||
			ch == Brain_RightMove ||
			ch == Brain_Output ||
			ch == Brain_Input ||
			ch == Brain_Start ||
			ch == Brain_End ||
			ch == Brain_DebugSymbole)
		{
			ins->instructions[ins->currentCount++] = ch;
			if (ins->currentCount == ins->capacity)
			{
				Instruct* save = ins->instructions;
				int oldCapacity = ins->capacity;
				ins->capacity *= 2;
				ins->instructions = NULL;
				while (ins->instructions == NULL)
					ins->instructions = malloc(ins->capacity);
				memcpy_s(ins->instructions, ins->capacity * sizeof(Instruct), save, oldCapacity * sizeof(Instruct));
			}
		}
		else
			continue;

		//printf("%c", ch);
	} while (ch != EOF);

	fclose(ptr);
}

void CompileInstructions(Instructions* instructions, Executable* exc, bool debugMode)
{
	int debugSymbolsCount = 0;
	if (debugMode == false) // remove debug symbols
		for (int i = 0; i < instructions->currentCount; i++)
			if (instructions->instructions[i] == Brain_DebugSymbole)
				debugSymbolsCount++;

	free(exc->instructions);
	while (exc->instructions == NULL)
		exc->instructions = malloc(sizeof(Instruct) * (instructions->currentCount - debugSymbolsCount));

	int excPointer = 0;
	for (int i = 0; i < instructions->currentCount; i++)
	{
		if (debugMode == false)
		{
			if (instructions->instructions[i] != Brain_DebugSymbole)
				exc->instructions[excPointer++] = instructions->instructions[i];
		}
		else
			exc->instructions[excPointer++] = instructions->instructions[i];
	}

	exc->length = excPointer;

	int inStackCount = 0;
	int stackInTotal = 0;
	for (int i = 0; i < exc->length; i++)
	{
		if (exc->instructions[i] == Brain_Start)
		{
			inStackCount++;
			stackInTotal++;
		}
		else if (exc->instructions[i] == Brain_End)
			inStackCount--;
	}
	if (inStackCount != 0)
		ThrowExcepction("Invalid syntax, there is not the same amount of \"[\" as \"]\"");

	exc->stackSizeNeeded = stackInTotal;


}