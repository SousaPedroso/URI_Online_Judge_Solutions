#include <stdio.h>
 
int main() {

	double A, B, C, aux;
	int i;
	
	scanf("%lf", &A);
	scanf("%lf", &B);
	scanf("%lf", &C);

	if (A < B){
		aux = A;
		A = B;
		B = aux;
	}
	if (A < C){
		aux = A;
		A = C;
		C = aux;
	}
	if (A >= B+C){
		printf("NAO FORMA TRIANGULO\n");
	}else{
		if ((A*A) == (B*B)+ (C*C)){
			printf("TRIANGULO RETANGULO\n");
		}
		if ((A*A) > (B*B)+ (C*C)){
			printf("TRIANGULO OBTUSANGULO\n");
		}
		if ((A*A)< (B*B)+ (C*C)){
			printf("TRIANGULO ACUTANGULO\n");
		}
		if (A == B && A==C){
			printf("TRIANGULO EQUILATERO\n");
		}
		if ((A == B && A!= C) ||(A == C && A!=B) || (B==C && B != A)){
			printf("TRIANGULO ISOSCELES\n");
		}
	}
 
    return 0;
}