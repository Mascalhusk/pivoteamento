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

	for(i=0;i<dim+1;i++)
    	{
	        aux = M[1][i];
	        M[1][i] = M[0][i];
	        M[0][i] = aux;
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
 	printf ("\nA matriz após o pivoteamento  é da primeira linha é:\n");
 	imprime(M, dim);
 	
}
