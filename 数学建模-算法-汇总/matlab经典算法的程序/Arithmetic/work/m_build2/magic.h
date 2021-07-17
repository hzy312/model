/*
 * MATLAB Compiler: 3.0
 * Date: Sat Sep 04 21:59:48 2004
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "mrank" 
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#ifndef __magic_h
#define __magic_h 1

#ifdef __cplusplus
extern "C" {
#endif

#include "libmatlb.h"

extern void InitializeModule_magic(void);
extern void TerminateModule_magic(void);
extern _mexLocalFunctionTable _local_function_table_magic;

extern mxArray * mlfMagic(mxArray * n);
extern void mlxMagic(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#ifdef __cplusplus
}
#endif

#endif
