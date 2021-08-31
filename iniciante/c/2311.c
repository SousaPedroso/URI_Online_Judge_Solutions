#include <stdio.h>

int main()
{
    struct Atletas{
        char nome[50];
        float N[7],GD, pontuacao, nota_mais_alta, nota_mais_baixa;
    };
    int N,i,j, contador_auxiliar4, limite_de_nota_baixa, limite_de_nota_alta,contador_auxiliar, contador_auxiliar2, contador_auxiliar3;
    float auxiliador;
    
    scanf("%d", &N);
    i = 0;
    struct Atletas Atleta[N];
    if (N >= 0 && N <= 100){
        for (i=0; i <N; i++){
            limite_de_nota_alta = 1;
            limite_de_nota_baixa = 1;
            contador_auxiliar = 1;
            contador_auxiliar4 = 1;
            scanf("%s", Atleta[i].nome);
            setbuf(stdin, NULL);
            scanf("%f", &Atleta[i].GD);
            setbuf(stdin, NULL);
            for (j=0; j < 7; j++){
                scanf("%f", &Atleta[i].N[j]);
                setbuf(stdin, NULL);
            }
            auxiliador = Atleta[i].N[0];
            Atleta[i].nota_mais_baixa = Atleta[i].N[0];
            Atleta[i].nota_mais_alta = Atleta[i].N[0];
            for (j=1; j < 7; j++){
                if (Atleta[i].nota_mais_alta <= Atleta[i].N[j]){
                    if (Atleta[i].nota_mais_alta == Atleta[i].N[j]){
                        Atleta[i].nota_mais_alta = Atleta[i].N[j];
                        contador_auxiliar4 += 1;
                    }
                    if (Atleta[i].nota_mais_alta < Atleta[i].N[j]){
                        Atleta[i].nota_mais_alta = Atleta[i].N[j];
                        contador_auxiliar4 = 1;
                    }
                }
                if (Atleta[i].nota_mais_baixa >= Atleta[i].N[j] && Atleta[i].nota_mais_alta != Atleta[i].N[j]){
                    if (Atleta[i].nota_mais_baixa == Atleta[i].N[j]){
                        Atleta[i].nota_mais_baixa = Atleta[i].N[j];
                        contador_auxiliar += 1;
                    }
                    if (Atleta[i].nota_mais_baixa > Atleta[i].N[j]){
                        Atleta[i].nota_mais_baixa = Atleta[i].N[j];
                        contador_auxiliar = 1;
                    }
                }
            }
            Atleta[i].pontuacao  = 0;
            contador_auxiliar2 = 1;
            contador_auxiliar3 = 1;
            for (j=0; j <7; j++){
                if (Atleta[i].N[j] == Atleta[i].nota_mais_baixa){
                    if (contador_auxiliar2 < contador_auxiliar){
                        Atleta[i].pontuacao += Atleta[i].GD * Atleta[i].N[j];
                        contador_auxiliar2 += 1;
                    }
                }
                if (Atleta[i].N[j] == Atleta[i].nota_mais_alta){
                    if (contador_auxiliar3 < contador_auxiliar4){
                        Atleta[i].pontuacao += Atleta[i].GD * Atleta[i].N[j];
                        contador_auxiliar3 += 1;
                    }
                }
                if ((Atleta[i].N[j] != Atleta[i].nota_mais_alta) && (Atleta[i].N[j] != Atleta[i].nota_mais_baixa )){
                    Atleta[i].pontuacao += Atleta[i].GD * Atleta[i].N[j];
                }
            }
        }
        for (i =0; i < N; i++){
            printf("%s %.2f\n", Atleta[i].nome, Atleta[i].pontuacao);
        }
        
        
    }
    return 0;
}

