#include <stdio.h>
#include <stdlib.h>
int main(){

	int A, B, C, MaiorAB;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	MaiorAB = (A + B + abs(A - B))/2;
	MaiorAB = (MaiorAB + C + abs(MaiorAB - C))/2;
	printf("%d eh o maior\n", MaiorAB);
}