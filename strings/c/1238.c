#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char string1[50], string2[50];
    int i, tamanho_string_1, tamanho_string_2, N,k;
    scanf("%d", &N);
    setbuf(stdin, NULL);
    for (i=0; i<N; i++){
        tamanho_string_1 = 0;
        tamanho_string_2 = 0;
        scanf("%s", &string1);
        scanf("%s", &string2);
        // repartir as duas strings
        tamanho_string_1 = strlen(string1);
        tamanho_string_2 = strlen(string2);
        //indices
        for (k=0; k < tamanho_string_1 + tamanho_string_2; k++){
            if (k < tamanho_string_1){
                printf("%c", string1[k]);
            }
            if (k < tamanho_string_2){
                printf("%c", string2[k]);
            }
        }
        printf("\n");
    }
    return 0;
}