#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, tamanho_string,j, pos;
    char mensagem[1000], mensagem_oculta[1000];
    fgets(mensagem, 1000, stdin);
    sscanf(mensagem, "%d", &N);    
    for (i=0; i <N; i++){
        fgets(mensagem, 1000, stdin);
        tamanho_string = strlen(mensagem);
        pos = 0;
        for (j=0; j < tamanho_string-1; j++){
            if (j== 0){
                if (mensagem[j] != ' ' && mensagem[j] != '\n'){
                    mensagem_oculta[pos] = mensagem[j];
                    pos += 1;
                }
            }else{
                if (mensagem[j] != ' '  && mensagem[j-1] == ' ' && mensagem[j] != '\n' && mensagem[j] != '\0'){
                    mensagem_oculta[pos] = mensagem[j];
                    pos += 1;
                }
            }
        }
        mensagem_oculta[pos] = '\0';
        printf("%s", mensagem_oculta);
        printf("\n");
    }
    return 0;
}