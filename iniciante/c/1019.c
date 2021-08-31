#include <stdio.h>

int main(){

	int segundos_iniciais, horas, minutos, segundos_finais;

	scanf("%d", &segundos_iniciais);
	horas = segundos_iniciais / 3600;
	minutos = (segundos_iniciais % 3600) / 60;
	segundos_finais = (segundos_iniciais % 3600) % 60;
	printf("%d:%d:%d\n", horas, minutos, segundos_finais);
}