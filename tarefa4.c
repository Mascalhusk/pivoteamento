#include<stdio.h>
#include<stdlib.h>

void imprime(double **M, int dim)
{	int i, j;

	for (i=0; i<dim; i++ )
   	{	 for ( j=0; j<dim+1; j++ )
    		{
       			printf ("%lf \t", M[ i ][ j ]);
    		}
		printf("\n\n");	
 	}
 	
}

void pivoteamento(double **M, int dim)
{	int i, j;
	double aux;

	if(M[0][0]<M[1][0])
	{	for(j=0;j<dim+1;j++)
    		{
	        	aux = M[1][j];
	        	M[1][j] = M[0][j];
	        	M[0][j] = aux;
   		}
	}

}

void pivoteamento1(double **M, int dim)
{	int j;
	double aux;

	if(M[2][2]<M[3][2])
	{	for(j=2;j<dim+1;j++)
    		{
	        	aux = M[3][j];
	        	M[3][j] = M[2][j];
	        	M[2][j] = aux;
   		}
	}

}
	
void escalonamento(double **M, int dim)
{	int j;

	for (j=0; j<dim+1; j++)
	{
		M[1][j] = M[1][j] - (M[1][j]/M[0][0])*M[0][j];
		M[2][j] = M[2][j] - (M[2][j]/M[0][0])*M[0][j];
		M[3][j] = M[3][j] - (M[3][j]/M[0][0])*M[0][j];

	}

}

void escalonamento2(double **M, int dim)
{	int i;
	for (i=0; i<dim+1; i++)
	{
		M[2][i+1] = M[2][i+1] + M[1][i+1];
		M[3][i+1] = M[3][i+1] - 2.0*M[1][i+1];

	}
}

void escalonamento3(double **M, int dim)
{	int i;
	for (i=2; i<dim+1; i++)
	{
		M[3][i] = M[3][i] + (1/3.0)*M[2][i];

	}
}


int main()
{	
	//contadores
	int i, j, dim;
	double **M, a;
	FILE *leitura;
	
	leitura = fopen("matriz.dat","r");
	i = fscanf(leitura, "%d", &dim);
	M = malloc(dim*sizeof(double *));
	for (i=0; i<dim; i++) 
	{
	 M[i] = malloc((dim+1)*sizeof(double));	
	}
	 
	i = j = 0;
	while(fscanf(leitura, "%lf", &a) != EOF) 
	{
		M[i][j] = a;
	 	j++;
	 	if(j==dim+1) 
	 	{	j=0; i++;	}
	
	}
	
	printf ("\nA matriz fornecida é:\n");
	imprime(M, dim);

 	pivoteamento(M, dim);
 	printf ("\nA matriz após o pivoteamento da primeira linha é:\n");
 	imprime(M, dim);

		
	escalonamento(M, dim);
	printf ("\nA matriz após o primeiro passo de escalonamento:\n");
 	imprime(M, dim);
	
 	escalonamento2(M, dim);
	printf ("\nA matriz após o segundo passo de escalonamento:\n");
	imprime(M, dim);

	pivoteamento1(M, dim);
 	printf ("\nA matriz após o pivoteamento da terceira linha é:\n");
 	imprime(M, dim);

	escalonamento3(M, dim);
	printf ("\nA matriz após o terceiro passo de escalonamento:\n");
	imprime(M, dim);
}
