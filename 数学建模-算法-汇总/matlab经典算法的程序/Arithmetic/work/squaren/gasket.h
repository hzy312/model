/*
 * MATLAB Compiler: 3.0
 * Date: Sat Sep 04 16:28:02 2004
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "gasket" 
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#ifndef __gasket_h
#define __gasket_h 1

#ifdef __cplusplus
extern "C" {
#endif

#include "libmatlb.h"

extern void InitializeModule_gasket(void);
extern void TerminateModule_gasket(void);
extern _mexLocalFunctionTable _local_function_table_gasket;

extern mxArray * mlfGasket(mxArray * numPoints);
extern void mlxGasket(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#ifdef __cplusplus
}
#endif

#endif
