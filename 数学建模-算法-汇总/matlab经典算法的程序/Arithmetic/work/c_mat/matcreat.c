#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mat.h"
#define BUFSIZE 256
int main()
{
	MATFile *pmat;
	mxArray  *pa1,*pa2,*pa3;
	double data[9]={1.0,4.0,7.0,2.0,5.0,8.0,3.0,6.0,9.0};
	double data1[4]={1,2,3,4};
	const char *file="mattest.mat";
	char str[BUFSIZE];
	int status;
	pmat=matOpen(file,"w");

	pa1=mxCreateDoubleMatrix(3,3,mxREAL);
	mxSetName(pa1,"LocalDouble");
	pa2=mxCreateDoubleMatrix(2,2,mxREAL);
	mxSetName(pa2,"GlobalDouble");
	p3=mxCreateString("How to use mat files!");
	mxSetName(pa3,"LocalString");
	memcpy((void *)(mxGetPr(pa1)),(void *)data,sizeof(data));
	memcpy((void *)(mxGetPr(pa2)),(void *)data1,sizeof(data1));
	status=matPutArray(pmat,pa1);
	status=matPutArrayAsGlobal(pmat,pa2);
	status=matPutArray(pmat,pa3);
	mxDestroyArray(pa1);
	mxDestroyArray(pa2);
	mxDestroyArray(pa3);
	matClose(pmat);
	return (EXIT_SUCCESS);
}