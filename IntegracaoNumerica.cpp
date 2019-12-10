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
	Data criacao:  		22/10/2019
	Ult. Atualizacao:   25/10/2019
	___________________________________________
*/

//Funcoes
double f(double b)
{
	return (pow(b, 2));
}

double flinha(double b)  					//flinha original para comparacao
{
	return ((pow(b, 3))/3);
}

double flinha2(double a, double b, int qtd) //flinha do metodo
{
	int i=0;
	double soma=0, acum=0, h=0;
	h=(b-a)/qtd;
	soma=f(a)+f(b);
	for(i=0; i<qtd-1; i++)
	{
		acum+=h;
		soma+=2*f(acum);
	}
	return ((h/2)*(soma));
}

//Programa principal
int main(void)
{
	int qtd;
	double a, b;
	printf("\n Entre com o limite inferior (a): ");
	scanf(" %lf", &a);
	printf("\n Entre com o limite superior (b): ");
	scanf(" %lf", &b);
	printf("\n Entre com a quantidade de intervalos: ");
	scanf(" %d", &qtd);
	printf("\n f(b)  = x^2:  %.2lf", f(b));
	printf("\n f'(b) = 3x^2: %.2lf", flinha(b));
	printf("\n\n-----------------------------------------------");
	printf("\n\n Resposta = %.8lf\n\n", flinha2(a, b, qtd));
}


