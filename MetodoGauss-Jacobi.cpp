//Declaracao de bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
/*  ___________________________________________
	
	Programa: 			Metodo Gauss-Jacobi
	Autor:    			Bruno Ramalho Rimolo
	Materia:			Calculo Numerico
	Docente:			Isabela Rangel
	Data criacao:  		23/09/2019
	Ult. Atualizacao:   24/09/2019
	___________________________________________
*/

//Programa principal
int main(void)
{
	int d, i, j, cont=0;
	printf("\nEntre com a dimensao da matriz: ");
	scanf(" %d", &d);
	float coeficientes[d][d], resultado[d], chute[d], aux[d], soma=0, div=0, maior1=0, maior2=0, valor=0, erro;
	printf("\n*****************   Matriz %dx%d   *****************\n", d, d);
	printf("\n Selecione o erro [Ex.: 0.1]: ");
	scanf(" %f", &erro);
	valor=erro+1;
	printf("\nEntre com os elementos da matriz dos coeficientes: \n");
	for(i=0; i<d; i++)
	{
		for(j=0; j<d; j++)
		{
			printf("  Elemento A[%d,%d]: ", i+1, j+1);
			scanf(" %f", &coeficientes[i][j]);
		}
	}
	printf("\nEntre com os elementos do vetor da matriz resultante: \n");	
	for(i=0; i<d; i++)
	{
		printf("  Elemento B[%d,%d]: ", i+1, 1);
		scanf(" %f", &resultado[i]);
	}
	printf("\nEntre com o valor inicial (chute): \n");	
	for(i=0; i<d; i++)
	{
		printf("  Elemento C[%d,%d]: ", i+1, 1);
		scanf(" %f", &chute[i]);
	}
	//Exibe a matriz inicial
	printf("\n\n-------------------------------------------------------------------");
	for(i=0; i<d; i++)
	{
		printf("\n|");
		for(j=0; j<d; j++)
		{
			printf(" A[%d,%d]=%.2fx%d ", i+1, j+1, coeficientes[i][j], j+1);
		}
		printf("  =  B[%d,%d]=%.2f  |  C[%d,%d]=%.2f |\n", i+1, 1, resultado[i], i+1, 1, chute[i]);
	}
	printf("-------------------------------------------------------------------\n");
	
	//Iguala vetor auxiliar ao vetor chute
	for(i=0; i<d; i++)
	{
		aux[i]=chute[i];
	}
	while(valor>erro)
	{
		//Calcula o m�todo
		for(i=0; i<d; i++)
		{
			for(j=0; j<d; j++)
			{
				if(i!=j)
				{
					soma=soma+((-1)*coeficientes[i][j]*chute[j]);
				}
				else
				{
					div=coeficientes[i][j];
				}
			}
			aux[i]=(resultado[i]+soma)/div;
			soma=0;
		}
		//Atualiza valor para ser comparado com erro
		maior1=0;
		maior2=0;
		for(i=0; i<d; i++)
		{
			if((fabs(aux[i]-chute[i]))>maior1)
			{
				maior1=(fabs(aux[i]-chute[i]));
			}
			if(fabs(aux[i])>maior2)
			{
				maior2=fabs(aux[i]);
			}
		}
		valor=maior1/maior2;
		printf("\n\n** Maior1=%.4f / Maior2=%.4f =", maior1, maior2);
		printf(" Valor=%.4f**\n", valor);
		//Armazena o vetor atual no vetor chute
		for(i=0; i<d; i++)
		{
			printf("\n Vetor Anterior[%d]=%.4f ------- Vetor Atual[%d]=%.4f", i+1, chute[i], i+1, aux[i]);
			chute[i]=aux[i];
		}
		cont++;
	}
		
	//Exibe a Matriz e Resultado
	printf("\n\n ITERACOES: %d ", cont);
	printf("\n\n-------------------------------------------------------------------");
	for(i=0; i<d; i++)
	{
		printf("\n|");
		for(j=0; j<d; j++)
		{
			printf(" A[%d,%d]=%.2fx%d ", i+1, j+1, coeficientes[i][j], j+1);
		}
		printf("  =  B[%d,%d]=%.2f  |  AUX[%d,%d]=%.2f |\n", i+1, 1, resultado[i], i+1, 1, aux[i]);
	}
	printf("-------------------------------------------------------------------\n");

}


