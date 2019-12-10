//Declaracao de bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<math.h>
//Constantes
//#define e 0.1
/*  ___________________________________________

	Programa: 			Metodo Secantes
	Autor:    			Bruno Ramalho Rimolo
	Materia:			Calculo Numerico
	Docente:			Isabela Rangel
	Data criacao:  		02/09/2019
	Ult. Atualizacao:   02/09/2019
	___________________________________________
*/

//Funcoes
float f(float x)
{
	//return (cos(x)-x);
	return ((x*(log(x)))-3.2);
}

float xm(float x0, float x1)
{
	return (x1-((f(x1)*(x1-x0))/(f(x1)-f(x0))));
}

//Programa principal
int main(void)
{	
	float x0, x1, x2, erro;
	int cont=0;	
	printf("\n Selecione o erro [Ex.: 0.1]: ");
	scanf(" %f", &erro);
	printf("\n Intervalo 'x0 ------------ x1'");
	printf("\n\n Entre com o valor de 'x0': ");
	scanf(" %f", &x0);
	printf("\n Entre com o valor de 'x1': ");
	scanf(" %f", &x1);
	printf("\n\n -------------------------------------------------");	
	while(f(x0)*f(x1)>0) 								// Verifica se atende teorema de Bolzano
	{
		printf("\n Entre com novo valor para o intervalo:\n\n'x0'= ");
		scanf(" %f", &x0);
		printf("\n'x1'= ");
		scanf(" %f", &x1);
	}
	x2=xm(x0,x1);
	cont++;
	printf("\n x0=%.6f, x1=%.6f,\n f(x0)=%.6f, f(x1)=%.6f,\n x2=%.6f, f(x2)=%.6f", x0, x1, f(x0), f(x1), x2, f(x2));
	printf("\n\n Iteracao: %d -> f(%.6f) %.6f\n", cont, x2,f(x2));
	x0=x1;
	x1=x2;
	while(fabs(f(x2))>erro)
	{
		x2=xm(x0,x1);
		cont++;
		printf("\n x0=%.6f, x1=%.6f,\n f(x0)=%.6f, f(x1)=%.6f,\n x2=%.6f, f(x2)=%.6f", x0, x1, f(x0), f(x1), x2, f(x2));
		printf("\n\n Iteracao: %d -> f(%.6f) %.6f", cont, x2,f(x2));
		x0=x1;
		x1=x2;
	}
}

