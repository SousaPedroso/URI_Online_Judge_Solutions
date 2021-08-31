#include <stdio.h>
 
int main() {

	float M[12][12], soma, media;
	int i, j, contagem, diagonal;
	char O;

	scanf("%c", &O);
	for (i=0; i < 12;i++){
		for (j=0; j<12; j++){
			scanf("%f", &M[i][j]);
		}
	}
	soma = 0;
	contagem = 0;
	if (O == 'S'){
		for (i =0; i<12;i++){
			diagonal = i;
			for (j=0;j<12; j++){
				if (j < diagonal){
					soma += M[i][j];
					contagem += 1;
				}
			}
		}
		printf("%.1f\n", soma);
	}
	if (O == 'M'){
		for (i =0; i<12;i++){
			diagonal = i;
			for (j=0;j<12; j++){
				if (j < diagonal){
					soma += M[i][j];
					contagem += 1;
				}
			}
		}
		media = soma / contagem;
		printf("%.1f\n", media);
	}


    return 0;
}