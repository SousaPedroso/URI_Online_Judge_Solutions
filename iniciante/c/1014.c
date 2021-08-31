#include <stdio.h>
 
int main() {
	
	int X;
	double Y, consumo_medio;
	
	scanf("%d", &X);
	scanf("%lf", &Y);
	consumo_medio = X / Y;
	printf("%.3lf km/l\n", consumo_medio);
 
    return 0;
}
