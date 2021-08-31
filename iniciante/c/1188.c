#include <stdio.h>

int main(){

	char O;
	double M[12][12], soma, media;
	int i, j, onde_comeca_linha,onde_comeca_coluna, meio_da_matriz, total_iteracoes, onde_termina_coluna, contador_de_linhas;

	scanf("%c", &O);
	for (i=0; i <12; i++){
		for (j=0; j <12; j++){
			scanf("%lf", &M[i][j]);
		}
	}
	contador_de_linhas = 12;
	onde_comeca_linha = 7;
	onde_comeca_coluna = 5;
	soma = 0;
	onde_termina_coluna = 7;
	total_iteracoes = 0;
	if (O == 'S'){
		for (i=onde_comeca_linha; i < contador_de_linhas; i++){
			for (j=onde_comeca_coluna; j < (onde_termina_coluna); j++){
				soma += M[i][j];
			}
			onde_comeca_coluna -=  1;
			onde_termina_coluna +=1;
		}
		printf("%.1lf\n", soma);
	}
	if (O == 'M' && contador_de_linhas !=2){
	    media = 0;
		for (i=onde_comeca_linha; i < contador_de_linhas; i++){
			for (j=onde_comeca_coluna; j <(onde_termina_coluna) ; j++){
				soma = soma + M[i][j];
				total_iteracoes += 1;
			}
			onde_comeca_coluna -=1;
			onde_termina_coluna +=1;
			
		}
		media = soma / total_iteracoes;
		printf("%.1lf\n", media);
	}
	
	return 0;
}