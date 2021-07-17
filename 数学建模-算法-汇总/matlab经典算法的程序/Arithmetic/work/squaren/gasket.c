/*
 * MATLAB Compiler: 3.0
 * Date: Sat Sep 04 16:28:02 2004
 * Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
 * "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
 * "array_indexing:on" "-O" "optimize_conditionals:on" "-x" "-W" "mex" "-L" "C"
 * "-t" "-T" "link:mexlibrary" "libmatlbmx.mlib" "gasket" 
 */
#include "gasket.h"
#include "libmatlbm.h"
static mxArray * _mxarray0_;

static double _array2_[6] = { 866.0, 1.0, 866.0, 1.0, 500.0, 1000.0 };
static mxArray * _mxarray1_;

static double _array4_[2] = { 866.0, 1.0 };
static mxArray * _mxarray3_;
static mxArray * _mxarray5_;
static mxArray * _mxarray6_;
static mxArray * _mxarray7_;
static mxArray * _mxarray8_;

void InitializeModule_gasket(void) {
    _mxarray0_ = mclInitializeDouble(1000.0);
    _mxarray1_ = mclInitializeDoubleVector(3, 2, _array2_);
    _mxarray3_ = mclInitializeDoubleVector(1, 2, _array4_);
    _mxarray5_ = mclInitializeDouble(1.0);
    _mxarray6_ = mclInitializeDouble(3.0);
    _mxarray7_ = mclInitializeDoubleVector(0, 0, (double *)NULL);
    _mxarray8_ = mclInitializeDouble(2.0);
}

void TerminateModule_gasket(void) {
    mxDestroyArray(_mxarray8_);
    mxDestroyArray(_mxarray7_);
    mxDestroyArray(_mxarray6_);
    mxDestroyArray(_mxarray5_);
    mxDestroyArray(_mxarray3_);
    mxDestroyArray(_mxarray1_);
    mxDestroyArray(_mxarray0_);
}

static mxArray * Mgasket(int nargout_, mxArray * numPoints);

_mexLocalFunctionTable _local_function_table_gasket
  = { 0, (mexFunctionTableEntry *)NULL };

/*
 * The function "mlfGasket" contains the normal interface for the "gasket"
 * M-function from file "d:\work\squaren\gasket.m" (lines 1-10). This function
 * processes any input arguments and passes them to the implementation version
 * of the function, appearing above.
 */
mxArray * mlfGasket(mxArray * numPoints) {
    int nargout = 1;
    mxArray * theImage = NULL;
    mlfEnterNewContext(0, 1, numPoints);
    theImage = Mgasket(nargout, numPoints);
    mlfRestorePreviousContext(0, 1, numPoints);
    return mlfReturnValue(theImage);
}

/*
 * The function "mlxGasket" contains the feval interface for the "gasket"
 * M-function from file "d:\work\squaren\gasket.m" (lines 1-10). The feval
 * function calls the implementation version of gasket through this function.
 * This function processes any input arguments and passes them to the
 * implementation version of the function, appearing above.
 */
void mlxGasket(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    mxArray * mprhs[1];
    mxArray * mplhs[1];
    int i;
    if (nlhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: gasket Line: 1 Column: "
            "1 The function \"gasket\" was called with mor"
            "e than the declared number of outputs (1)."),
          NULL);
    }
    if (nrhs > 1) {
        mlfError(
          mxCreateString(
            "Run-time Error: File: gasket Line: 1 Column: "
            "1 The function \"gasket\" was called with mor"
            "e than the declared number of inputs (1)."),
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
    mplhs[0] = Mgasket(nlhs, mprhs[0]);
    mlfRestorePreviousContext(0, 1, mprhs[0]);
    plhs[0] = mplhs[0];
}

/*
 * The function "Mgasket" is the implementation version of the "gasket"
 * M-function from file "d:\work\squaren\gasket.m" (lines 1-10). It contains
 * the actual compiled code for that M-function. It is a static function and
 * must only be called from one of the interface functions, appearing below.
 */
/*
 * function theImage=gasket(numPoints)
 */
static mxArray * Mgasket(int nargout_, mxArray * numPoints) {
    mexLocalFunctionTable save_local_function_table_
      = mclSetCurrentLocalFunctionTable(&_local_function_table_gasket);
    mxArray * theImage = NULL;
    mxArray * i = NULL;
    mxArray * theRand = NULL;
    mxArray * startPoint = NULL;
    mxArray * corners = NULL;
    mclCopyArray(&numPoints);
    /*
     * theImage =zeros(1000,1000);
     */
    mlfAssign(&theImage, mlfZeros(_mxarray0_, _mxarray0_, NULL));
    /*
     * corners=[866 1;1 500;866 1000];
     */
    mlfAssign(&corners, _mxarray1_);
    /*
     * startPoint=[866 1];
     */
    mlfAssign(&startPoint, _mxarray3_);
    /*
     * theRand=rand(numPoints,1);
     */
    mlfAssign(
      &theRand, mlfNRand(1, mclVa(numPoints, "numPoints"), _mxarray5_, NULL));
    /*
     * theRand=ceil(theRand*3);
     */
    mlfAssign(
      &theRand, mlfCeil(mclMtimes(mclVv(theRand, "theRand"), _mxarray6_)));
    /*
     * for i=1:numPoints
     */
    {
        int v_ = mclForIntStart(1);
        int e_ = mclForIntEnd(mclVa(numPoints, "numPoints"));
        if (v_ > e_) {
            mlfAssign(&i, _mxarray7_);
        } else {
            /*
             * startPoint=floor((corners(theRand(i),:)+startPoint)/2);
             * theImage(startPoint(1),startPoint(2))=1;
             * end
             */
            for (; ; ) {
                mlfAssign(
                  &startPoint,
                  mlfFloor(
                    mclMrdivide(
                      mclPlus(
                        mclArrayRef2(
                          mclVv(corners, "corners"),
                          mclIntArrayRef1(mclVv(theRand, "theRand"), v_),
                          mlfCreateColonIndex()),
                        mclVv(startPoint, "startPoint")),
                      _mxarray8_)));
                mclArrayAssign2(
                  &theImage,
                  _mxarray5_,
                  mclIntArrayRef1(mclVv(startPoint, "startPoint"), 1),
                  mclIntArrayRef1(mclVv(startPoint, "startPoint"), 2));
                if (v_ == e_) {
                    break;
                }
                ++v_;
            }
            mlfAssign(&i, mlfScalar(v_));
        }
    }
    mclValidateOutput(theImage, 1, nargout_, "theImage", "gasket");
    mxDestroyArray(corners);
    mxDestroyArray(startPoint);
    mxDestroyArray(theRand);
    mxDestroyArray(i);
    mxDestroyArray(numPoints);
    mclSetCurrentLocalFunctionTable(save_local_function_table_);
    return theImage;
}
