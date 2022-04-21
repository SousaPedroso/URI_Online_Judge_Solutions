#include <stdio.h>

unsigned int_to_int(unsigned k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return (k % 2) + 10 * int_to_int(k / 2);
}

int main(){
    
    int A, B, C;

    while (scanf("%d", &A) != EOF){
        scanf("%d", &B);
        if (A < B){
            C = A;
            A = B;
            B = C;
        }
        
    }

    return 0;
}