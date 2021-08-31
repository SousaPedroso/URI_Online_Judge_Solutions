#include <stdio.h>
 
int main() {
   
    int N = 1, i, j,aux;
    do {
        scanf("%d", &N);
        if (N != 0){
            for (i=0; i <N; i++){
                for (j=0; j <N; j++){
                    if (j>0) {
                        printf(" ");
                    }
                    if (i == j){
                        printf("%3d", (i-j)+1);
                    }else{
                        if (j < i){
                            printf("%3d", (i+1)-(j));
                        }if ((j > i && (j -1)== i &&(j <= N-1))){
                            if (i == N-2 && j==N-1){
                                printf("%3d", 2);
                            }else{
                                printf("%3d", 2);
                                aux = 2;
                            }
                        }if ((j > i && (j-1)>i) &&  (j < N-1 && i < N-1)){
    if (i != N-2 && j != N-1){
                                printf("%3d", aux+1);
                                aux +=1;
        }
                        }if (j==N-1){
    if (i < N-2 && j <= N-1){
                            printf("%3d", aux+1);
        }
                        }
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
       
    } while (N != 0);

    return 0;
}