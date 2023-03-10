#include <stdio.h>

#include "Compiler.h"
#include "Runtime.h"

int main()
{
	while (true)
	{
		unsigned char c = GetKeyStroke;
		printf("%d\n", c);
	}

	Instructions instucts = { 0 };
	Execution exc = { 0 };
	bool debug_mode = true;
	InitInstructions("C:\\Users\\ceniu\\source\\repos\\Brainfuck-Runtime\\Brainfuck-Runtime\\HelloWorld.bf", &instucts);
	CompileInstructions(&instucts, &exc, debug_mode);
	RunExecutable(&exc, debug_mode);

	//printf("Capacity %d\n", instucts.capacity);
	//printf("Count %d\n", instucts.currentCount);

	//int c = 1;
	//while (c != 32)
	//{
	//	bool isArrow = false;
	//	c = getch();
	//	if (c == 224)
	//	{
	//		isArrow = true;
	//		c = getch();
	//	}
	//	if (isArrow)
	//	{
	//		if (c == ArrowKeyUp)
	//			printf("Up\n");
	//		else if (c == ArrowKeyDown)
	//			printf("Down\n");
	//		else if (c == ArrowKeyLeft)
	//			printf("Left\n");
	//		else if (c == ArrowKeyRight)
	//			printf("Right\n");
	//	}
	//	else
	//	{
	//		printf("%c\n", c);
	//		//printf("%d\n", (int)c);
	//	}
	//}

	return 0;
}

