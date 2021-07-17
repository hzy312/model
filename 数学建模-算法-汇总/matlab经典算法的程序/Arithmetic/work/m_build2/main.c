/*
 * MATLAB Compiler: 3.0
 * Date: Sat Sep 04 22:04:33 2004
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-m" "-W" "main" "-L"
 * "C" "-t" "-T" "link:exe" "-h" "libmmfile.mlib" "main.m" "my_rank.m"
 * "mrank.m" 
 */
#include "main.h"
#include "mrank.h"
static mxArray * _mxarray0_;

void InitializeModule_main(void) {
    _mxarray0_ = mclInitializeDouble(5.0);
}

void TerminateModule_main(void) {
    mxDestroyArray(_mxarray0_);
}

static void Mmain(void);

_mexLocalFunctionTable _local_function_table_main
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfMain" contains the normal interface for the "main"
 * M-function from file "d:\work\m_build2\main.m" (lines 1-2). This function
 * processes any input arguments and passes them to the implementation version
 * of the function, appearing above.
 */
void mlfMain(void) {
    mlfEnterNewContext(0, 0);
    Mmain();
    mlfRestorePreviousContext(0, 0);
}

/*
 * The function "mlxMain" contains the feval interface for the "main"
 * M-function from file "d:\work\m_build2\main.m" (lines 1-2). The feval
 * function calls the implementation version of main through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxMain(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    if (nlhs > 0) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: main Line: 1 Column: 1 The function \"main\""
            " was called with more than the declared number of outputs (0)."),
          NULL);
    }
    if (nrhs > 0) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: main Line: 1 Column: 1 The function \"main"
            "\" was called with more than the declared number of inputs (0)."),
          NULL);
    }
    mlfEnterNewContext(0, 0);
    Mmain();
    mlfRestorePreviousContext(0, 0);
}

/*
 * The function "Mmain" is the implementation version of the "main" M-function
 * from file "d:\work\m_build2\main.m" (lines 1-2). It contains the actual
 * compiled code for that M-function. It is a static function and must only be
 * called from one of the interface functions, appearing below.
 */
/*
 * function main
 */
static void Mmain(void) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_main);
    mxArray * r = NULL;
    /*
     * r=mrank(5);
     */
    mlfAssign(&r, mlfMrank(_mxarray0_));
    mxDestroyArray(r);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
}
