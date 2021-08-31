#include <stdio.h>

int main(){

	int NUMBER, numero_de_horas_trabalhadas;
	float SALARY, valor_por_hora_trabalhada;

	scanf("%d", &NUMBER);
	scanf("%d", &numero_de_horas_trabalhadas);
	scanf("%f", &valor_por_hora_trabalhada);
	SALARY = (numero_de_horas_trabalhadas * valor_por_hora_trabalhada);
	printf("NUMBER = %d\n", NUMBER);
	printf("SALARY = U$ %.2f\n", SALARY);
	
	return 0;
}