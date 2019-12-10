//Declaracao de bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
#include<math.h>
//Constantes
#define MAX 100
/*  ___________________________________________
	
	Programa: 			Quadrados mínimos  
	Autor:    			Bruno Ramalho Rímolo
	Materia:			Calculo Numerico
	Docente:			Isabela Rangel
	Data criacao:  		04/11/2019
	Ult. Atualizacao:   06/12/2019
	___________________________________________
	
	The following code matrix operations are based on the link bellow:
	https://repl.it/@GessicaSilva/MATRIZ-INVERSA-FINAL

*/

//Funcoes
void divideLinha()
{
	printf("\n ************************************************************");
}

void mostraTabela(int n, double *x, double *fx)
{
	divideLinha();
	printf("\n        ");
	for(int i=0;i<n;i++)
	{
		printf("   %d   ", i+1);
	}
	printf("\n  xi   |");
	for(int i=0;i<n;i++)
	{
		printf("  %.2lf ", x[i]);
	}
	printf("\n f(xi) |");
	for(int i=0;i<n;i++)
	{
		printf("  %.2lf ", fx[i]);
	}
}

// Criar matriz quadrada
double** criaMatriz(int ordem)
{
	double **matriz = (double **)malloc(ordem * sizeof(double*));
	for(int i=0; i<ordem; i++)
	{
	    matriz[i] = (double *)malloc(ordem * sizeof(double));
	}
	return(matriz);
}

// Liberar memoria
void destroiMatriz(double **mat, int ordem)
{
	for(int i=0; i<ordem; i++){
	    free(mat[i]);
	}
	free(mat);
}

// Calcula menor complementar
double** menorComp(int r, int s, int ordem, double** matriz)
{
	double** m=criaMatriz(ordem-1);
	for(int i=0; i<ordem; i++)
	{
		for(int j=0; j<ordem; j++)
		{
			if(i<r)
			{
				if(j<s)
				{
					m[i][j]=matriz[i][j];
				}
				else if(j>s)
				{
					m[i][j-1]=matriz[i][j];
				}
			}
			else if(i>r)
			{
				if(j<s)
				{
					m[i-1][j]=matriz[i][j];
				}
				else if(j>s)
				{
					m[i-1][j-1]=matriz[i][j];
				}
			}
		}
	}
	return(m);
}

// Calcular determinante da matriz
int detA(double **mat, int ordem)
{
	int j=0;
	int novaOrdem=ordem-1;
	double soma=0;
	double** mc;
	if(ordem==1)
	{
		return(mat[0][0]);
	}
	else if(ordem==2)
	{
		return((mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]));
	}
	else
	{
		for(int j=0; j<ordem; j++)
		{
			mc=menorComp(0, j, ordem, mat);
			soma=soma+pow((-1),j)*mat[0][j]*detA(mc, novaOrdem);
			destroiMatriz(mc, novaOrdem);
		}
		return(soma);
	}
}

double** cofatores(double** mat, int ordem)
{
	double** c=criaMatriz(ordem);
	double** mc;
	for(int i=0; i<ordem; i++)
	{
		for(int j=0; j<ordem; j++)
		{
			mc=menorComp(i, j, ordem, mat);
			c[i][j]=pow(-1, i+j) * detA(mc, ordem-1);
			destroiMatriz(mc, ordem-1);
		}
	}
	return(c);
}

double** adjunta(double** mat, int ordem)
{// Transposta da Matriz dos Cofatores
	double** a=criaMatriz(ordem);
	double** temp=criaMatriz(ordem);
	a=cofatores(mat, ordem);
	temp=cofatores(mat, ordem);
	for(int i=0; i<ordem; i++)
	{
		for(int j=0; j<ordem; j++)
		{
			a[i][j]=temp[j][i];
		}
	}
	return(a);
}

double** inversa(double** mat, int ordem)
{//Adjunta *1/det
	double** inv=criaMatriz(ordem);
	double det;
	inv=adjunta(mat, ordem);
	det=detA(mat, ordem);
	if(det!=0)
	{
		printf("\n");
		for(int i=0; i<ordem; i++)
		{
			for(int j=0; j<ordem; j++)
			{
				inv[i][j]=(inv[i][j])*(1/det);
			}
		}
		return(inv);
	}
	else
	{
		printf(" N�o existe inversa para essa matriz !");
		return(mat);
	}
}

// Exibir matriz
void exibeMatriz(double **mat, int ordem)
{
	for(int i=0; i<ordem; i++){
		printf("\n");
	    for(int j=0; j<ordem; j++)
		{
	        printf(" %2.4lf ", mat[i][j]);
		}
	}	
}

double soma_x_i(double *x, int i, int m)
{
	double soma=0;
	for(int j=0;j<m;j++)
	{
		soma+=pow(x[j],i);
	}
	return (soma);
}

double soma_x_fx_i(double *x, double *fx, int i, int m)
{
	double soma=0;
	for(int j=0;j<m;j++)
	{
		soma+=pow(x[j],i)*(fx[j]);
	}
	return (soma);
}

//Programa principal
int main(void)
{
	int n=0, m=0, i=0, j=0, lin=0, col=0, k=0, ordem;
	double x[MAX], fx[MAX], somafx[MAX], valor=0, resposta=0;
	char c[MAX];
	printf("\n Metodo dos quadrados minimos ");
	divideLinha();
	printf("\n Entre com a ordem do polinomio: ");
	scanf(" %d", &n);
	col=n+1;
	lin=col;
	ordem=col;
	double **soma=criaMatriz(ordem);
	double **alfa=criaMatriz(ordem);
	double **cof=criaMatriz(ordem);
	double **adj=criaMatriz(ordem);
	double **inv=criaMatriz(ordem);
	printf("\n Entre com os valores de x seguidos de 'ENTER'\n [digite 's' para Sair]\n\n");
	while((c[0]!='s') || (m<n+1))
	{
		fflush(stdin);
		printf(" x%d: ",m);
		gets(c);
		if(c[0]=='-')
		{
			x[m]=-strtod(c, NULL);
			x[m]=x[m]*(-1);
		}
		else if(isdigit(c[0]))
		{
			x[m]=strtod(c, NULL);
		}
		else
		{
			if((c[0]=='s')&&(m<n+1))
			{
				printf("\n O numero de pontos nao pode ser menor do que %d !!\n", n+1);
			}
			m--;
		}
		m++;
	}
	divideLinha();
	printf("\n Entre com os valores de f(x):\n\n");
	for(i=0;i<m;i++)
	{
		fflush(stdin);
		printf(" f(x%d): ",i);
		gets(c);
		if(c[0]=='-')
		{
			fx[i]=-strtod(c, NULL);
			fx[i]=fx[i]*(-1);
		}
		else if(isdigit(c[0]))
		{
			fx[i]=strtod(c, NULL);
		}
		else
		{
			i--;
		}
	}
	divideLinha();
	printf("\n");
	//Constroi a matriz de somatorios
	for(i=0; i<lin; i++)
	{
		for(j=0; j<col; j++)
		{
			soma[i][j]=soma_x_i(&x[0], j+i, m);
			printf("    x%d ^%d (%d,%d)= %5.2lf ", i, j+i, i+1, j+1, soma[i][j]);	
		}
		printf(" \n");	
	}
	//Acha o vetor das somas x * f(x)
	for(i=0; i<n+1; i++)
	{
		somafx[i]=soma_x_fx_i(&x[0], &fx[0], i, m);
		printf(" FX x%d ^%d*f(x%d)= %5.2lf ", i, i, i, somafx[i]);	
	}
	divideLinha();
	//Calculando a Matriz Inversa
	inv=inversa(soma, ordem);
	mostraTabela(m, &x[0], &fx[0]);
	divideLinha();
    //Resultado das Matrizes Soma e Inversa
    printf("\n Matriz Soma: \n");
    exibeMatriz(soma, ordem);
    divideLinha();
    printf("\n Matriz Inversa: \n");
	exibeMatriz(inv, ordem);
    for(i=0; i<lin; i++)
    {
    	for(j=0; j<col; j++)
    	{
    		alfa[i][0]+=inv[i][j]*somafx[j];
		}
	}
	divideLinha();
	printf("\n");
	for(i=0; i<lin; i++)
	{
		printf(" Alfa %d = %.4lf", i+1, alfa[i][0]);
	}
	printf("\n Agora entre com o valor a ser aplicado o Polinomio P[x]: ");
	scanf(" %lf", &valor);
	for(i=0; i<lin; i++)
	{
		resposta=resposta+(pow(valor, i)*alfa[i][0]);
	}
	printf("\n Resposta ---> P(%.2lf)= %.7lf", valor, resposta);

	getch();
}
