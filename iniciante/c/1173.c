#include <stdio.h>

int main(){
	int i, V, N[10];
	scanf("%d", &V);
	for (i=0; i < 10; i++){
		N[i] = V;
		V = V * 2;
		printf("N[%d] = %d\n",i,N[i]);
	}

    return 0;
}