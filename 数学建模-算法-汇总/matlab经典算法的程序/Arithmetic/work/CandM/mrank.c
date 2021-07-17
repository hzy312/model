/*
 * MATLAB Compiler: 3.0
 * Date: Sat Sep 04 22:31:38 2004
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-t" "-W" "lib:Pkg" "-T"
 * "link:exe" "-h" "mrank" "mrankp.c" "libmmfile.mlib" 
 */
#include "mrank.h"
#include "libmatlbm.h"
#include "libmmfile.h"
static mxArray * _mxarray0_;
static mxArray * _mxarray1_;

void InitializeModule_mrank(void) {
    _mxarray0_ = mclInitializeDouble(1.0);
    _mxarray1_ = mclInitializeDoubleVector(0, 0, (double *)NULL);
}

void TerminateModule_mrank(void) {
    mxDestroyArray(_mxarray1_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mmrank(int nargout_, mxArray * n);

_mexLocalFunctionTable _local_function_table_mrank
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfMrank" contains the normal interface for the "mrank"
 * M-function from file "d:\work\candm\mrank.m" (lines 1-6). This function
 * processes any input arguments and passes them to the implementation version
 * of the function, appearing above.
 */
mxArray * mlfMrank(mxArray * n) {
    int nargout = 1;
    mxArray * r = NULL;
    mlfEnterNewContext(0, 1, n);
    r = Mmrank(nargout, n);
    mlfRestorePreviousContext(0, 1, n);
    return mlfReturnValue(r);
}

/*
 * The function "mlxMrank" contains the feval interface for the "mrank"
 * M-function from file "d:\work\candm\mrank.m" (lines 1-6). The feval function
 * calls the implementation version of mrank through this function. This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
void mlxMrank(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: mrank Line: 1 Column: 1 The function \"mrank"
            "\" was called with more than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: mrank Line: 1 Column: 1 The function \"mrank"
            "\" was called with more than the declared number of inputs (1)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    for (i = 0; i < 1 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 1; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 1, mprhs[0]);
    mplhs[0] = Mmrank(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mmrank" is the implementation version of the "mrank"
 * M-function from file "d:\work\candm\mrank.m" (lines 1-6). It contains the
 * actual compiled code for that M-function. It is a static function and must
 * only be called from one of the interface functions, appearing below.
 */
/*
 * function r=mrank(n)
 */
static mxArray * Mmrank(int nargout_, mxArray * n) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_mrank);
    mxArray * r = NULL;
    mxArray * k = NULL;
    mclCopyArray(&n);
    /*
     * r=zeros(n,1);
     */
    mlfAssign(&r, mlfZeros(mclVa(n, "n"), _mxarray0_, NULL));
    /*
     * for k=1:n
     */
    {
        int v_ = mclForIntStart(1);
        int e_ = mclForIntEnd(mclVa(n, "n"));
        if (v_ > e_) {
            mlfAssign(&k, _mxarray1_);
        } else {
            /*
             * r(k)=rank(magic(k));
             * end
             */
            for (; ; ) {
                mclIntArrayAssign1(
                  &r, mlfRank(mlfMagic(mlfScalar(v_)), NULL), v_);
                if (v_ == e_) {
                    break;
                }
                ++v_;
            }
            mlfAssign(&k, mlfScalar(v_));
        }
    }
    mclValidateOutput(r, 1, nargout_, "r", "mrank");
    mxDestroyArray(k);
    mxDestroyArray(n);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return r;
}
