//
// MATLAB Compiler: 3.0
// Date: Sat Sep 04 16:38:32 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-p" "-W" "main" "-L"
// "Cpp" "-t" "-T" "link:exe" "-h" "libmmfile.mlib" "gasket.m" 
//
#ifndef __gasket_hpp
#define __gasket_hpp 1

#include "libmatlb.hpp"

extern void InitializeModule_gasket();
extern void TerminateModule_gasket();
extern _mexLocalFunctionTable _local_function_table_gasket;

extern mwArray gasket(mwArray numPoints = mwArray::DIN);
#ifdef __cplusplus
extern "C"
#endif
void mlxGasket(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]);

#endif
