#include <stdio.h>

int main()
{
    int N, i, S, B, A, total_de_saques, total_de_bloqueios, total_de_ataque, S1, B1, A1, acertos_ataque, acertos_saques, acertos_bloqueios;
    double auxiliar_bloqueios, auxiliar_ataque, auxiliar_saques, auxiliar_saques_tentativa, auxiliar_ataque_tentativa, auxiliar_bloqueios_tentativa, percentual_sucesso_saques, percentual_sucesso_bloqueios, percentual_sucesso_ataque;
    char nome[20];
    
    scanf("%d", &N);
    total_de_ataque = 0;
    total_de_saques = 0;
    total_de_bloqueios = 0;
    acertos_ataque = 0;
    acertos_bloqueios = 0;
    acertos_saques = 0;
    for (i=0; i <N; i++){
        scanf("%s", nome);
        scanf("%d %d %d", &S, &B, &A);
        scanf("%d %d %d", &S1, &B1, &A1);
        total_de_ataque += A;
        total_de_saques += S;
        total_de_bloqueios += B;
        acertos_ataque += A1;
        acertos_saques += S1;
        acertos_bloqueios += B1;
    }
    auxiliar_saques = total_de_saques;
    auxiliar_saques_tentativa = acertos_saques;
    percentual_sucesso_saques = (auxiliar_saques_tentativa / auxiliar_saques)*100;
    auxiliar_bloqueios_tentativa = acertos_bloqueios;
    auxiliar_bloqueios = total_de_bloqueios;
    percentual_sucesso_bloqueios = (auxiliar_bloqueios_tentativa / auxiliar_bloqueios)* 100;
    auxiliar_ataque_tentativa = acertos_ataque;
    auxiliar_ataque = total_de_ataque;
    percentual_sucesso_ataque = (auxiliar_ataque_tentativa / auxiliar_ataque)*100;
    printf("Pontos de Saque: %.2lf %%.\n", percentual_sucesso_saques);
    printf("Pontos de Bloqueio: %.2lf %%.\n", percentual_sucesso_bloqueios);
    printf("Pontos de Ataque: %.2lf %%.\n", percentual_sucesso_ataque);
    
    return 0;
}
