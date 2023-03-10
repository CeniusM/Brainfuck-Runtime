#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "Types.h"
#include "ThrowHelper.h"
#include "Misc.h"

void RunExecutable(Executable* ex, bool debugEnabled);

inline void RunInstruct(Execution* exc, bool debugEnabled);