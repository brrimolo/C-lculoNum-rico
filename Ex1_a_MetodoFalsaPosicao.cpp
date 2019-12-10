//Declaracao de bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
//Constantes
//#define e 0.01
/*	___________________________________________

	Programa: 			Metodo da Falsa Posicao
	Autor:    			Bruno Ramalho Rimolo
	Materia:			Calculo Numerico
	Docente:			Isabela Rangel
	Data criacao:  		26/08/2019
	Ult. Atualizacao:   27/08/2019
	___________________________________________
*/

//Funcoes
float f(float x)
{
	//return x-2; 									// Intervalo de exemplo: 0 a 10
	//return pow(x,4)-26*pow(x,2)+24*x+21; 			// Intervalo de exemplo: 1 a 2
	return ((x*(log(x)))-3.2);
}

float media(float a, float b)
{
	return (a*fabs(f(b))+b*fabs(f(a)))/(fabs(f(a))+fabs(f(b)));
}

//Programa principal
int main(void)
{
	float a, b, x, erro;
	int cont=0; 									// Contador de Iteracoes
	printf("\n Selecione o erro [Ex.: 0.1]: ");
	scanf(" %f", &erro);
	printf("\n Intervalo 'a ------------ b'");
	printf("\n\n Entre com o valor de 'a': ");
	scanf(" %f", &a);
	printf("\n Entre com o valor de 'b': ");
	scanf(" %f", &b);
	printf("\n\n -------------------------------------------------");
	while(f(a)*f(b)>0) 								// Verifica se atende teorema de Bolzano
	{
		printf("\n Intervalo invalido !");
		printf("\n Entre com novo valor para o intervalo:\n\n'a'= ");
		scanf(" %f", &a);
		printf("\n'b'= ");
		scanf(" %f", &b);
	}
	x=media(a,b);
	cont++;
	printf("\nIteracao %d: a= %.4f b= %.4f f(x)= %.4f", cont,a,b,f(x));
	while(fabs(f(x))>erro)
	{
		if(f(a)*f(x)<0)
		{
			b=x;
		}
		else
		{
			a=x;
		}
		x=media(a,b);
		cont++;
		printf("\nIteracao %d: a= %.4f b= %.4f f(x)= %.4f", cont,a,b,f(x));
	}
	printf("\n -------------------------------------------------\n");
	printf("\n Iteracoes: %d", cont);
	printf("\n\n Ultimo x= %.4f\n\n a= %.4f, b= %.4f\n\n", x, a, b);
}


