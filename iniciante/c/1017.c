#include <stdio.h>

int main(){

	int tempo_gasto_na_viagem_em_horas, velocidade_media;
	float kilometragem_total, litros_necessarios;
	scanf("%d", &tempo_gasto_na_viagem_em_horas);
	scanf("%d", &velocidade_media);
	kilometragem_total = tempo_gasto_na_viagem_em_horas * velocidade_media;
	litros_necessarios = kilometragem_total / 12;
	printf("%.3f\n", litros_necessarios);
}