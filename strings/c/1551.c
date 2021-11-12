#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char frase[1100];
    int *alfabeto;
    int N, i, j, esta_na_lista = 0, tam_frase, pos_alfabeto;
    fgets(frase, 1100, stdin);
    sscanf(frase, "%d", &N);
    for (i=0; i<N; i++){
        fgets(frase, 1100, stdin);
        tam_frase = strlen(frase);
        alfabeto = (int *) calloc(26, sizeof(int));
        pos_alfabeto = 0;
        for (j=0; j < tam_frase; j++){
            if (frase[j] >= 'a' && frase[j] <= 'z') {
                esta_na_lista = (alfabeto[frase[j]-'a']>0);
                if (esta_na_lista == 0){
                    alfabeto[frase[j]-'a'] = 1;
                    pos_alfabeto += 1;
                }
            }
        }
        if (pos_alfabeto == 26){
            printf("frase completa\n");
        }else if (pos_alfabeto >= 13){
            printf("frase quase completa\n");
        }else{
            printf("frase mal elaborada\n");
        }
        free(alfabeto);
    }

    return 0;
}