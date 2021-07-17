#include <stdio.h>
#include <math.h>
#include "matlab.h"
extern mxArray*mlfMrank(mxArray*);
main(int argc,char **argv)
{
mxArray *N;
mxArray *R;
int n;
if(argc>=2){
n=atoi(argv[1]);
}else {
n=12;
}
PkgInitialize();
N=mlfScalar(n);
R=mlfMrank(N);
mlfPrintMatrix(R);
mxDestroyArray(N);
mxDestroyArray(R);
PkgTerminate();


}
