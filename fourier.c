#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE *arq;
main(int agrc, char **argv)
{
	double *an, *bn, *a0, *anbn, *fx, *y, *x, n, somaa=0, somab=0, soma0=0, somaf=0;
	int i=0, j, k;
	
	arq=fopen(argv[1], "r");
	
	x=malloc(3000*sizeof(double));
	y=malloc(3000*sizeof(double));
	
	while(fscanf(arq, "%lf\t %lf\n", &x[i], &y[i])!=EOF)
	{
		i++;
	}
	
	n=i;
	
	x=realloc(x, n*sizeof(*x));
	y=realloc(y, n*sizeof(*y));
	
	// Calculando coeficientes
	fx=malloc(n*sizeof(double));
	a0=malloc(n*sizeof(double));
	an=malloc(n*sizeof(double));
	bn=malloc(n*sizeof(double));
	anbn=malloc(n*sizeof(double));
	
	arq=fopen(argv[2], "w");
	
	for(j=0; j<n; j++)
	{
		for(k=0; k<2*-1; k++)
		{
			somat+=y[k];
			soma1+=y[k]*cos(j*x[k]);
			soma2+=y[k]*sin(j*x[k]);
		}
		
		a0[j]=(1/n)*somat;
		an[j]=(1/n)*soma1;
		bn[j]=(1/n)*soma2;
		
		anbn[j]=pow(an[j],2)+pow(bn[j],2);
		
		fprintf(arq, "%lf\t %lf\t %lf\t %lf\n", an[j], bn[j], anbn[j], x[j]);
	}
	
	fclose(arq);
}
	
	
	
