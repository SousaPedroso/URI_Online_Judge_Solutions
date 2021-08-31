#include <stdio.h>
 
int main() {

	int M, N, i, Sum;

	M = 1;
	N = 1;
	while (M > 0 && N > 0){
		scanf("%d", &M);
		scanf("%d", &N);
		Sum = 0;
		if (M > N && (M > 0 && N > 0)){
			for (i =N; i <= M; i++){
				printf("%d ", i);
				Sum += i;
				if (i == M){
					printf("Sum=%d\n", Sum);
				}
			}
		}
		if (N > M  && (M > 0 && N > 0)){
			for (i=M; i<= N; i++){
				printf("%d ", i);
				Sum += i;
				if (i == N && (M > 0 && N > 0)){
					printf("Sum=%d\n", Sum);
				}
			}
		}
	}


    return 0;
}