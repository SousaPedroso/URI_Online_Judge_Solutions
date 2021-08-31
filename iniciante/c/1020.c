#include <stdio.h>

int main(){

	int idade_em_dias, ano, mes, dias;

	scanf("%d", &idade_em_dias);
	ano = idade_em_dias / 365;
	mes = (idade_em_dias % 365) / 30;
	dias = (idade_em_dias % 365) % 30;
	printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dias);
}