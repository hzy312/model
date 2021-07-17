//
// MATLAB Compiler: 3.0
// Date: Sat Sep 04 16:38:32 2004
// Arguments: "-B" "macro_default" "-O" "all" "-O" "fold_scalar_mxarrays:on"
// "-O" "fold_non_scalar_mxarrays:on" "-O" "optimize_integer_for_loops:on" "-O"
// "array_indexing:on" "-O" "optimize_conditionals:on" "-p" "-W" "main" "-L"
// "Cpp" "-t" "-T" "link:exe" "-h" "libmmfile.mlib" "gasket.m" 
//
#include "gasket.hpp"
#include "libmatlbm.hpp"
static mwArray _mxarray0_ = mclInitializeDouble(1000.0);

static double _array2_[6] = { 866.0, 1.0, 866.0, 1.0, 500.0, 1000.0 };
static mwArray _mxarray1_ = mclInitializeDoubleVector(3, 2, _array2_);

static double _array4_[2] = { 866.0, 1.0 };
static mwArray _mxarray3_ = mclInitializeDoubleVector(1, 2, _array4_);
static mwArray _mxarray5_ = mclInitializeDouble(1.0);
static mwArray _mxarray6_ = mclInitializeDouble(3.0);
static mwArray _mxarray7_ = mclInitializeDoubleVector(0, 0, (double *)NULL);
static mwArray _mxarray8_ = mclInitializeDouble(2.0);

void InitializeModule_gasket() {
}

void TerminateModule_gasket() {
}

static mwArray Mgasket(int nargout_, mwArray numPoints);

_mexLocalFunctionTable _local_function_table_gasket
  = { 0, (mexFunctionTableEntry *)NULL };

//
// The function "gasket" contains the normal interface for the "gasket"
// M-function from file "d:\work\squaren\gasket.m" (lines 1-10). This function
// processes any input arguments and passes them to the implementation version
// of the function, appearing above.
//
mwArray gasket(mwArray numPoints) {
    int nargout = 1;
    mwArray theImage = mwArray::UNDEFINED;
    theImage = Mgasket(nargout, numPoints);
    return theImage;
}

//
// The function "mlxGasket" contains the feval interface for the "gasket"
// M-function from file "d:\work\squaren\gasket.m" (lines 1-10). The feval
// function calls the implementation version of gasket through this function.
// This function processes any input arguments and passes them to the
// implementation version of the function, appearing above.
//
void mlxGasket(int nlhs, mxArray * plhs[], int nrhs, mxArray * prhs[]) {
    MW_BEGIN_MLX();
    {
        mwArray mprhs[1];
        mwArray mplhs[1];
        int i;
        mclCppUndefineArrays(1, mplhs);
        if (nlhs > 1) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: gasket Line: 1 Column: 1"
                  " The function \"gasket\" was called with more "
                  "than the declared number of outputs (1).")));
        }
        if (nrhs > 1) {
            error(
              mwVarargin(
                mwArray(
                  "Run-time Error: File: gasket Line: 1 Column: "
                  "1 The function \"gasket\" was called with mor"
                  "e than the declared number of inputs (1).")));
        }
        for (i = 0; i < 1 && i < nrhs; ++i) {
            mprhs[i] = mwArray(prhs[i], 0);
        }
        for (; i < 1; ++i) {
            mprhs[i].MakeDIN();
        }
        mplhs[0] = Mgasket(nlhs, mprhs[0]);
        plhs[0] = mplhs[0].FreezeData();
    }
    MW_END_MLX();
}

//
// The function "Mgasket" is the implementation version of the "gasket"
// M-function from file "d:\work\squaren\gasket.m" (lines 1-10). It contains
// the actual compiled code for that M-function. It is a static function and
// must only be called from one of the interface functions, appearing below.
//
//
// function theImage=gasket(numPoints)
//
static mwArray Mgasket(int nargout_, mwArray numPoints) {
    mwLocalFunctionTable save_local_function_table_
      = &_local_function_table_gasket;
    mwArray theImage = mwArray::UNDEFINED;
    mwArray i = mwArray::UNDEFINED;
    mwArray theRand = mwArray::UNDEFINED;
    mwArray startPoint = mwArray::UNDEFINED;
    mwArray corners = mwArray::UNDEFINED;
    //
    // theImage =zeros(1000,1000);
    //
    theImage = zeros(mwVarargin(_mxarray0_, _mxarray0_));
    //
    // corners=[866 1;1 500;866 1000];
    //
    corners = _mxarray1_;
    //
    // startPoint=[866 1];
    //
    startPoint = _mxarray3_;
    //
    // theRand=rand(numPoints,1);
    //
    theRand
      = Nrand_func(1, mwVarargin(mwVa(numPoints, "numPoints"), _mxarray5_));
    //
    // theRand=ceil(theRand*3);
    //
    theRand = ceil(mwVv(theRand, "theRand") * _mxarray6_);
    //
    // for i=1:numPoints
    //
    {
        int v_ = mclForIntStart(1);
        int e_ = mclForIntEnd(mwVa(numPoints, "numPoints"));
        if (v_ > e_) {
            i = _mxarray7_;
        } else {
            //
            // startPoint=floor((corners(theRand(i),:)+startPoint)/2);
            // theImage(startPoint(1),startPoint(2))=1;
            // end
            //
            for (; ; ) {
                startPoint
                  = floor(
                      (mclArrayRef(
                         mwVv(corners, "corners"),
                         mclIntArrayRef(mwVv(theRand, "theRand"), v_),
                         colon())
                       + mwVv(startPoint, "startPoint"))
                      / _mxarray8_);
                mclArrayAssign(
                  &theImage,
                  _mxarray5_,
                  mclIntArrayRef(mwVv(startPoint, "startPoint"), 1),
                  mclIntArrayRef(mwVv(startPoint, "startPoint"), 2));
                if (v_ == e_) {
                    break;
                }
                ++v_;
            }
            i = v_;
        }
    }
    mwValidateOutput(theImage, 1, nargout_, "theImage", "gasket");
    return theImage;
}
