#include <stdio.h>

#include "Compiler.h"
#include "Runtime.h"

int main()
{
	/*Path to BrainFuckFile*/
	const char* path = "";
	if (path)
		ThrowExcepction("Path is not set, go into main and put in a path to the given file to run");

	Instructions instucts = { 0 };
	Execution exc = { 0 };
	bool debug_mode = true;
	InitInstructions(path, &instucts);
	CompileInstructions(&instucts, &exc, debug_mode);
	RunExecutable(&exc, debug_mode);

	return 0;
}

