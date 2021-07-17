#include "mex.h"
#include <math.h>
void squarenumber(double y[],double x[])
{
	y[0]=x[0]*x[0];
	return;
}
void mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[])
{
	double *y;
	double *x;
	unsigned int m,n;
	m=mxGetM(prhs[0]);                                                                                                                                                                                                                                                                                                             
	n=mxGetN(prhs[0]);
	plhs[0]=mxCreateDoubleMatrix(m,n,mxREAL);//mxCreateFull???
	y=mxGetPr(plhs[0]);
	x=mxGetPr(prhs[0]);
	squarenumber(y,x);
}