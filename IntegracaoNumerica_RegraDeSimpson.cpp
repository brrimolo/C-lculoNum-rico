//Declaracao de bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
#include<math.h>
//Constantes
#define tot 3
/*  ___________________________________________
	
	Programa: 			Integracao Numerica
	Autor:    			Bruno Ramalho Rimolo
	Materia:			Calculo Numerico
	Docente:			Isabela Rangel
	Data criacao:  		28/10/2019
	Ult. Atualizacao:   28/10/2019
	___________________________________________
*/

//Funcoes
double f(double b)
{
	return (pow(b, 2));
}

double flinha(double b)
{
	return ((pow(b, 3))/3);
}


double flinha2(double a, double b, int qtd)
{
	int i=0;
	double soma=0, acum=0, h=0;
	h=(b-a)/qtd;
	soma=f(a)+f(b);
	for(i=0; i<qtd-1; i++)
	{
		acum+=h;
		if(i%2==0)
		{
			soma+=4*f(acum);
		}
		else
		{
			soma+=2*f(acum);
		}
	}
	return ((h/3)*(soma));
}

//Programa principal
int main(void)
{
	int qtd;
	double a, b;
	printf("\n Integracao Numerica - Regra de Simpson ");
	printf("\n ********************************************\n");
	printf("\n Entre com o limite inferior (a): ");
	scanf(" %lf", &a);
	printf("\n Entre com o limite superior (b): ");
	scanf(" %lf", &b);
	printf("\n   a=%.0lf |--------------------------| b=%.0lf\n", a, b);	
	printf("\n Entre com a quantidade de intervalos [par]: ");
	scanf(" %d", &qtd);
	while(qtd%2!=0)
	{
		printf("\n Intervalo invalido! Entre com um intervalo par: ");
		scanf(" %d", &qtd);
	}
	printf("\n f(b)  =  x%c :  %.2lf", 253, f(b));
	printf("\n f'(b) = x%c/3:  %.2lf", 252, flinha(b));
	printf("\n-----------------------------------------------");
	printf("\n Resposta = %.8lf", flinha2(a, b, qtd));
}


