#include <stdio.h>
 
int main() {

	int N,i,total_de_coelhos, total_de_ratos, total_de_sapos, quantidade_de_leituras, Quantia, total_de_cobaias;
	float percentual_de_coelhos, percentual_de_sapos, percentual_de_ratos, auxiliar_total_cobaias, auxiliar_total_de_coelhos, auxiliar_total_de_sapos, auxiliar_total_de_ratos;
	char Tipo;
 	
 	scanf("%d", &N);
 	total_de_sapos= 0;
 	total_de_ratos= 0;
 	total_de_coelhos = 0;
 	total_de_cobaias = 0;
 	auxiliar_total_cobaias = 0;
 	Quantia = 0;
 	i = 0;
 	quantidade_de_leituras = N * 2;
 	while (i < quantidade_de_leituras){
 		scanf("%d", &Quantia);
  	 	total_de_cobaias = total_de_cobaias + Quantia;
 		auxiliar_total_cobaias = total_de_cobaias;
 		i +=1;
 		scanf("%c", &Tipo);
		if (Tipo == 'C'){
 			total_de_coelhos += Quantia;
 			auxiliar_total_de_coelhos = total_de_coelhos;
 		}
 		if (Tipo == 'S'){
 			total_de_sapos += Quantia;
 			auxiliar_total_de_sapos = total_de_sapos;
 		}
 		if (Tipo == 'R'){
 			total_de_ratos += Quantia;
 			auxiliar_total_de_ratos = total_de_ratos;
 		}
 	}
 		total_de_cobaias = total_de_cobaias / 2;
 		auxiliar_total_cobaias = total_de_cobaias;
 		printf("Total: %d cobaias\n", total_de_cobaias);
 		printf("Total de coelhos: %d\n", total_de_coelhos);
 		printf("Total de ratos: %d\n", total_de_ratos);
 		printf("Total de sapos: %d\n", total_de_sapos);
 		percentual_de_coelhos = (auxiliar_total_de_coelhos / auxiliar_total_cobaias) * 100;
 		printf("Percentual de coelhos: %.2f %%\n", percentual_de_coelhos);
 		percentual_de_ratos = (auxiliar_total_de_ratos / auxiliar_total_cobaias) * 100;
 		printf("Percentual de ratos: %.2f %%\n", percentual_de_ratos);
 		percentual_de_sapos = (auxiliar_total_de_sapos / auxiliar_total_cobaias) * 100;
 		printf("Percentual de sapos: %.2f %%\n", percentual_de_sapos);

    return 0;
    
}