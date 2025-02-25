/****************************************************************************
 * Copyright (C) 2016 Maschell
 * With code from chadderz and dimok
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#ifndef _FUNCTION_HOOKS_H_
#define _FUNCTION_HOOKS_H_


#ifdef __cplusplus
extern "C" {
#endif

#include <gctypes.h>
#include "common/common.h"
#include "dynamic_libs/source/aoc_functions.h"
#include "dynamic_libs/source/ax_functions.h"
#include "dynamic_libs/source/fs_functions.h"
#include "dynamic_libs/source/gx2_functions.h"
#include "dynamic_libs/source/os_functions.h"
#include "dynamic_libs/source/padscore_functions.h"
#include "dynamic_libs/source/socket_functions.h"
#include "dynamic_libs/source/sys_functions.h"
#include "dynamic_libs/source/vpad_functions.h"
#include "dynamic_libs/source/acp_functions.h"
#include "dynamic_libs/source/syshid_functions.h"
#include "dynamic_libs/source/proc_ui_functions.h"

//Orignal code by Chadderz.
#define DECL(res, name, ...) \
        res (* real_ ## name)(__VA_ARGS__) __attribute__((section(".data"))); \
        res my_ ## name(__VA_ARGS__)

#define FUNCTION_PATCHER_METHOD_STORE_SIZE  7

typedef struct {
    const unsigned int replaceAddr;
    const unsigned int replaceCall;
    const unsigned int library;
    const char functionName[50];
    unsigned int realAddr;
    unsigned int restoreInstruction;
    unsigned char functionType;
    unsigned char alreadyPatched;
} hooks_magic_t;

void PatchInvidualMethodHooks(hooks_magic_t hook_information[],int hook_information_size, volatile unsigned int dynamic_method_calls[]);
void RestoreInvidualInstructions(hooks_magic_t hook_information[],int hook_information_size);
unsigned int GetAddressOfFunction(const char * functionName,unsigned int library);
int isDynamicFunction(unsigned int physicalAddress);

//Orignal code by Chadderz.
#define MAKE_MAGIC(x, lib,functionType) { (unsigned int) my_ ## x, (unsigned int) &real_ ## x, lib, # x,0,0,functionType,0}
#define MAKE_MAGIC_NAME(x,y, lib,functionType) { (unsigned int) my_ ## x, (unsigned int) &real_ ## x, lib, # y,0,0,functionType,0}

#ifdef __cplusplus
}
#endif

#endif /* _FS_H */
