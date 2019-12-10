//Declaracao de bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<math.h>
//Constantes
//#define e 0.1
/*  ___________________________________________

	Programa: 			Metodo Newton - Raphson
	Autor:    			Bruno Ramalho Rimolo
	Materia:			Cclculo Numerico
	Docente:			Isabela Rangel
	Data criacao:  		27/08/2019
	Ult. Atualizacao:   27/08/2019
	___________________________________________
*/

//Funcoes
float f(float x)
{
	// return pow(x,3)-5*pow(x,2)+x+3;  // 0 e 1
	return ((x*(log(x)))-3.2);
}

float flinha(float x)
{
	//return 3*pow(x,2)-10*x+1;
	return (log(x)+1);
}

float xm(float x)
{
	return x-(f(x)/flinha(x));
}

//Programa principal
int main(void)
{	
	float x0, x1, erro;
	int cont=1;
	printf("\n Selecione o erro [Ex.: 0.1]: ");
	scanf(" %f", &erro);
	printf("\n Entre com x0: ");
	scanf(" %f", &x0);
	x1=xm(x0);
	printf("\n Iteracao: %d -> f(%.4f) %.4f", cont, x1,f(x1));
	while(fabs(f(x1))>erro)
	{
		x1=xm(x1);
		cont++;
		printf("\n Iteracao: %d -> f(%.4f) %.4f", cont, x1,f(x1));
	}
}


