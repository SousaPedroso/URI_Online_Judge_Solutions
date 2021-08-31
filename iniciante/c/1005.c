#include <stdio.h>

int main()
{
    double A,B, nota, MEDIA;
    
    scanf("%lf", &A);
    scanf("%lf", &B);
    nota = (3.5 * A) + (7.5 * B );
    MEDIA = nota / 11.0;
    printf("MEDIA = %.5lf\n", MEDIA);
    
    return 0;
}
