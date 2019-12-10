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
	
	Programa: 			Derivada Numerica
	Autor:    			Bruno Ramalho Rimolo
	Materia:			Calculo Numerico
	Docente:			Isabela Rangel
	Data criacao:  		22/10/2019
	Ult. Atualizacao:   22/10/2019
	___________________________________________
*/

//Funcoes
double f(double x)
{
	return (pow(x, 3));
}

double flinha(double x)
{
	return (3*pow(x,2));
}

double flinha2(double x, double deltax)
{
	return ((f(x+deltax)-f(x))/deltax);
}

double regra3pontos(double x, double deltax)
{
	return (1/(2*deltax))*(((-3)*(f(x)))+(4*f(x+deltax))-(f(x+(2*deltax))));
}

double regra5pontos(double x, double deltax)
{
	return (1/(12*deltax))*((f(x-(2*deltax)))-(8*f(x-deltax))+(8*f(x+deltax))-(f(x+(2*deltax))));
}

//Programa principal
int main(void)
{
	double x;
	double deltax;
	printf("\n Entre com o valor de x: ");
	scanf(" %lf", &x);
	printf("\n Agora entre com Delta x: ");
	scanf(" %lf", &deltax);
	printf("\n f(x)  = x^3:  %.2lf", f(x));
	printf("\n f'(x) = 3x^2: %.2lf", flinha(x));
	printf("\n-----------------------------------------------");
	printf("\n f'(x) = f(%.4lf)-f(%.0lf)/%.4lf = %.8lf", x+deltax, x, deltax, flinha2(x,deltax));
	printf("\n Regra dos 3 pontos = %.8lf", regra3pontos(x,deltax));
	printf("\n Regra dos 5 pontos = %.8lf", regra5pontos(x,deltax));
}


