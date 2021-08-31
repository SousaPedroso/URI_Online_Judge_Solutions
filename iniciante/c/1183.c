#include <stdio.h>

int main(){

	char O;
	int i,j, contador_operacoes, onde_ira_comecar;
	float M[12][12], soma, media;

	scanf("%c", &O);
	for (i=0; i<12; i++){
		for (j=0; j<12; j++){
			scanf("%f", &M[i][j]);
		}
	}
	onde_ira_comecar = 1;
	contador_operacoes = 0;
	soma = 0;
	if (O == 'S'){
		for (i=0; i <12; i++){
			for (j= onde_ira_comecar; j <12; j++){
				soma += M[i][j];
			}
			onde_ira_comecar += 1;
		}
		printf("%.1f\n",soma);
	}
	if (O == 'M'){
	    media = 0;
		for (i=0; i <12; i++){
			for (j= onde_ira_comecar; j <12; j++){
				soma += M[i][j];
				contador_operacoes += 1;
			}
			onde_ira_comecar += 1;
		}
		media = soma / contador_operacoes;
		printf("%.1f\n",media);
	}

    return 0;
}