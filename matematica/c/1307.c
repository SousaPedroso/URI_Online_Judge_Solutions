#include <stdio.h>
#include <math.h>
#include <string.h>

int binario_decimal(int tam,char* bin);
int * maior_numero(int num1, int num2);
int mdc_dois_numeros(int num1, int num2);

int main()
{
    int N, i, decimal1, decimal2, tudo_amor, tam1, tam2;
    char binario1[50], binario2[50];
    
    scanf("%d", &N);
    setbuf(stdin, NULL);
    for (i=0; i <N; i++){
        scanf("%s", binario1);
        setbuf(stdin, NULL);
        scanf("%s", binario2);
        setbuf(stdin, NULL);
        tam1 =strlen(binario1);
        tam2 =strlen(binario2);
        decimal1 = binario_decimal(tam1, binario1);
        decimal2 = binario_decimal(tam2, binario2);
        tudo_amor = mdc_dois_numeros(decimal1, decimal2);
        if (tudo_amor > 1){
            printf("Pair #%d: All you need is love!\n", (i+1));
        }else{
            printf("Pair #%d: Love is not all you need!\n", (i+1));
        }
    }

    return 0;
}

int binario_decimal(int tam, char *bin){
    int i, decimal=0;
    for (i=0; i< tam; i++){
        decimal += pow(2, strlen(bin)-(i+1)) * (bin[i] - '0');
    }
    return decimal;
}

int mdc_dois_numeros(int num1, int num2){
    int maior_num, menor_num, *maior_menor;
    maior_menor = maior_numero(num1, num2);
    maior_num = maior_menor[0];
    menor_num = maior_menor[1];
    num1 = maior_num;
    num2 = menor_num;
    if (num1 != num2){
        while (num2 != 0){
            //para multiplos valores,
            //numeros primos se tornam uma solução
            //melhor, desta forma, somente para 2 valores
            //tem a vantagem em grandes numeros em que pelo
            //menos um é primo
            num1 = menor_num;
            num2 = maior_num % num2;
            maior_num = num1;
            menor_num = num2;
        }
        return num1;
    }else{
        return num1;
    }
}

int * maior_numero(int num1, int num2){
    static int vetor_maior_menor[2];
    
    if (num1 >= num2){
        vetor_maior_menor[0] = num1;
        vetor_maior_menor[1] = num2;
    }else{
        vetor_maior_menor[0] = num2;
        vetor_maior_menor[1] = num1;
    }
    return vetor_maior_menor;
}