#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE *arq;
double f1(double x)
{
	return(sin(3*x));
}
double f2(double x)
{
	return(sin(5*x));
}
main(int agrc, char **agrv)
{
	double x, dx, *y;
	int i=0, cont=0;
	
	arq=fopen(argv[1], "r");
	
	dx=2*M_PI/1024;
	
	arq=fopen(argv[1], "w");
	
	for(x=-M_PI; x<=M_PI; x+=dx)
		fprintf(arq, "%lf\t %lf\n", x, f1(x));
		
	fclose(arq);
	
	arq=fopen(argv[1], "w");
	
	for(x=-M_PI; x<=M_PI; x+=dx)
		fprintf(arq, "%lf\t %lf\n", x, f2(x));
		
	fclose(arq);
}
