#include <stdio.h>
 
int main() {

	int N, i, quadrado;
 	
 	scanf("%d", &N);
 	for (i=2; i <=N; i= i + 2){
 		quadrado = i * i;
 		printf("%d^2 = %d\n", i,quadrado);
 	}

    return 0;
}