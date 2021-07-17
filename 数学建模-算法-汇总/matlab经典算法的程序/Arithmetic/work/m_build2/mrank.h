/*
 * MATLAB Compiler: 3.0
 * Date: Sat Sep 04 22:04:33 2004
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-m" "-W" "main" "-L"
 * "C" "-t" "-T" "link:exe" "-h" "libmmfile.mlib" "main.m" "my_rank.m"
 * "mrank.m" 
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#ifndef __mrank_h
#define __mrank_h 1

#ifdef __cplusplus
extern "C" {
#endif

#include "libmatlb.h"

extern void InitializeModule_mrank(void);
extern void TerminateModule_mrank(void);
extern _mexLocalFunctionTable _local_function_table_mrank;

extern mxArray * mlfMrank(mxArray * n);
extern void mlxMrank(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#ifdef __cplusplus
}
#endif

#endif
