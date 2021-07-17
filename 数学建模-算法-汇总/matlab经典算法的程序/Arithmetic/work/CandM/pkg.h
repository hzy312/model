/*
 * MATLAB Compiler: 3.0
 * Date: Sat Sep 04 22:31:38 2004
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-W" "lib:Pkg" "-T"
 * "link:exe" "-h" "mrank" "mrankp.c" "libmmfile.mlib" 
 */

#ifndef MLF_V2
#define MLF_V2 1
#endif

#ifndef __pkg_h
#define __pkg_h 1

#ifdef __cplusplus
extern "C" {
#endif

#include "libmatlb.h"

extern void InitializeModule_pkg(void);
extern void TerminateModule_pkg(void);
extern mxArray * mlfMrank(mxArray * n);
extern void mlxMrank(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);
extern void PkgInitialize(void);
extern void PkgTerminate(void);

#ifdef __cplusplus
}
#endif

#endif
