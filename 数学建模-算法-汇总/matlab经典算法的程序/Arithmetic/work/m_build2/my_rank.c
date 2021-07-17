/*
 * MATLAB Compiler: 3.0
 * Date: Sat Sep 04 22:04:33 2004
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-m" "-W" "main" "-L"
 * "C" "-t" "-T" "link:exe" "-h" "libmmfile.mlib" "main.m" "my_rank.m"
 * "mrank.m" 
 */
#include "my_rank.h"
#include "libmatlbm.h"
static mxArray * _mxarray0_;

void InitializeModule_my_rank(void) {
    _mxarray0_ = mclInitializeDouble(2.220446049250313e-16);
}

void TerminateModule_my_rank(void) {
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mmy_rank(int nargout_, mxArray * A, mxArray * tol);

_mexLocalFunctionTable _local_function_table_my_rank
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfMy_rank" contains the normal interface for the "my_rank"
 * M-function from file "d:\work\m_build2\my_rank.m" (lines 1-16). This
 * function processes any input arguments and passes them to the implementation
 * version of the function, appearing above.
 */
mxArray * mlfMy_rank(mxArray * A, mxArray * tol) {
    int nargout = 1;
    mxArray * r = NULL;
    mlfEnterNewContext(0, 2, A, tol);
    r = Mmy_rank(nargout, A, tol);
    mlfRestorePreviousContext(0, 2, A, tol);
    return mlfReturnValue(r);
}

/*
 * The function "mlxMy_rank" contains the feval interface for the "my_rank"
 * M-function from file "d:\work\m_build2\my_rank.m" (lines 1-16). The feval
 * function calls the implementation version of my_rank through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxMy_rank(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[2];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: my_rank Line: 1 Column: "
            "1 The function \"my_rank\" was called with mor"
            "e than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 2) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: my_rank Line: 1 Column:"
            " 1 The function \"my_rank\" was called with m"
            "ore than the declared number of inputs (2)."),
          NULL);
    }
    for (i = 0; i < 1; ++i) {
        mplhs[i] = NULL;
    }
    for (i = 0; i < 2 && i < nrhs; ++i) {
        mprhs[i] = prhs[i];
    }
    for (; i < 2; ++i) {
        mprhs[i] = NULL;
    }
    mlfEnterNewContext(0, 2, mprhs[0], mprhs[1]);
    mplhs[0] = Mmy_rank(nlhs, mprhs[0], mprhs[1]);
    mlfRestorePreviousContext(0, 2, mprhs[0], mprhs[1]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mmy_rank" is the implementation version of the "my_rank"
 * M-function from file "d:\work\m_build2\my_rank.m" (lines 1-16). It contains
 * the actual compiled code for that M-function. It is a static function and
 * must only be called from one of the interface functions, appearing below.
 */
/*
 * function r = my_rank(A,tol)
 */
static mxArray * Mmy_rank(int nargout_, mxArray * A, mxArray * tol) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_my_rank);
    int nargin_ = mclNargin(2, A, tol, NULL);
    mxArray * r = NULL;
    mxArray * s = NULL;
    mclCopyArray(&A);
    mclCopyArray(&tol);
    /*
     * %RANK   Matrix rank.
     * %   RANK(A) provides an estimate of the number of linearly
     * %   independent rows or columns of a matrix A.
     * %   RANK(A,tol) is the number of singular values of A
     * %   that are larger than tol.
     * %   RANK(A) uses the default tol = max(size(A)) * norm(A) * eps.
     * 
     * %   Copyright 1984-2002 The MathWorks, Inc. 
     * %   $Revision: 5.11 $  $Date: 2002/04/08 23:51:52 $
     * 
     * s = svd(A);
     */
    mlfAssign(&s, mlfSvd(NULL, NULL, mclVa(A, "A"), NULL));
    /*
     * if nargin==1
     */
    if (nargin_ == 1) {
        /*
         * tol = max(size(A)') * max(s) * eps;
         */
        mlfAssign(
          &tol,
          mclMtimes(
            mclMtimes(
              mlfMax(
                NULL,
                mlfCtranspose(
                  mlfSize(mclValueVarargout(), mclVa(A, "A"), NULL)),
                NULL,
                NULL),
              mlfMax(NULL, mclVv(s, "s"), NULL, NULL)),
            _mxarray0_));
    /*
     * end
     */
    }
    /*
     * r = sum(s > tol);
     */
    mlfAssign(&r, mlfSum(mclGt(mclVv(s, "s"), mclVa(tol, "tol")), NULL));
    mclValidateOutput(r, 1, nargout_, "r", "my_rank");
    mxDestroyArray(s);
    mxDestroyArray(tol);
    mxDestroyArray(A);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return r;
}
