#include <stdio.h>
void matriz_par_impar(int tamanho);

int matriz[100][100], i, j;

int main()
{
    
    int N;
    
    N = 1;
    while (N != 0){
        scanf("%d", &N);
        if (N != 0){
            matriz_par_impar(N);
        }
    }
    return 0;
}

void matriz_par_impar(int tamanho){
    int iteracoes, posi_inic, posi_final, valor_para_tal_iteracao, meio;
    
    iteracoes = tamanho / 2;
    posi_inic = 0;
    posi_final = tamanho-1;
    valor_para_tal_iteracao = 1;
    while (iteracoes > 0){
        for (j=posi_inic; j <=posi_final; j++){
            matriz[posi_inic][j] = valor_para_tal_iteracao;
        }
        for (i=posi_inic+1; i<=posi_final; i++){
            matriz[i][posi_final] = valor_para_tal_iteracao;
        }
        for (j= posi_final-1; j >posi_inic-1; j--){
            matriz[posi_final][j] = valor_para_tal_iteracao;
        }
        for (i=posi_final-1; i > posi_inic; i--){
            matriz[i][posi_inic] = valor_para_tal_iteracao;
        }
        iteracoes -= 1;
        valor_para_tal_iteracao += 1;
        posi_final -= 1;
        posi_inic +=1;
    }if (tamanho % 2 == 1){
        meio = (tamanho-1) /2;
        matriz[meio][meio]= meio+1;
    }
    for (i= 0; i< tamanho; i++){
        for (j=0; j <tamanho;j++){
            if (j!= tamanho-1){
                printf("%3d ", matriz[i][j]);
            } else{
                printf("%3d", matriz[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
