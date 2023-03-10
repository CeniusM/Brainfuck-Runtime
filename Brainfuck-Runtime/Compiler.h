#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Types.h"
#include "ThrowHelper.h"

void InitInstructions(const char* path, Instructions* i);

void CompileInstructions(Instructions* instructions, Executable* executable, bool debugMode);