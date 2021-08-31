#include <stdio.h>

int main(){

	float numeros[6], soma_dos_numeros_positivos, media;
	int i, valores_positivos;

	valores_positivos = 0;
	soma_dos_numeros_positivos = 0;
	for (i =0; i <6; i++){
		scanf("%f", &numeros[i]);
		if (numeros[i] >= 0){
			valores_positivos += 1;
			soma_dos_numeros_positivos += numeros[i];
		}
	}
	while (valores_positivos == 0){
		soma_dos_numeros_positivos = 0;
		for (i =0; i <6; i++){
			scanf("%f", &numeros[i]);
			if (numeros[i] >= 0){
				valores_positivos += 1;
				soma_dos_numeros_positivos += numeros[i];
			}
		}
	}
	media = soma_dos_numeros_positivos / valores_positivos;
	printf("%d valores positivos\n%.1f\n",valores_positivos,media);
}