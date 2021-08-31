#include <stdio.h>

int main()
{
    char nome_do_vendedor[20];
    double salario_fixo, montante_total, TOTAL;
    
    scanf("%s", nome_do_vendedor);
    scanf("%lf", &salario_fixo);
    scanf("%lf", &montante_total);
    TOTAL = salario_fixo + (0.15 * montante_total);
    printf("TOTAL = R$ %.2lf\n", TOTAL);
    
    return 0;
}

