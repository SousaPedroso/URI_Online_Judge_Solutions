#include <stdio.h>

int main()
{
    int H, P; 
    float auxiliar_H, auxiliar_P, consumo_medio;
    scanf("%d", &H);
    scanf("%d", &P);
    if (H >= 1 && P <= 1000){
        auxiliar_H = H;
        auxiliar_P = P;
        consumo_medio = auxiliar_H / auxiliar_P;
        printf("%.2f\n", consumo_medio);
    }

    return 0;
}
