#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE *arq;
double f(double x)
{
	if(x<0)
		return(-1);
	else
		return(1);
}
main(int agrc, char **argv)
{
	double x, dx, *y;
	int i=0, cont=0;
	
	arq=fopen(argv[1], "r");
	
	dx=2*M_PI/1024;
	
	for(x=-M_PI; x<=M_PI; x+=dx)
		fprintf(arq, "%lf\t %lf\n", x, f(x));
	
	fclose(arq);
}
