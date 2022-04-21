#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int N, i, j, k, overtakes, k_starting, k_finishing, competitor;
    int *starting_grid, *finishing_grid;
    
    while (scanf("%d", &N) != EOF){
        overtakes = 0;
        
        starting_grid = (int*) malloc((N+1)*sizeof(int));
        finishing_grid = (int*) malloc((N+1)*sizeof(int));
        
        for (int j = 0; j < N; j++){
            scanf("%d", &competitor);
            starting_grid[j] = competitor;
        }
        
        for (int j = 0; j < N; j++){
            scanf("%d", &competitor);
            finishing_grid[j] = competitor;
        }
        
        for (j=0; j < N; j++){
            if (starting_grid[j] != finishing_grid[j]){
                for (k=0; k < N; k++){
                    if (starting_grid[k] == finishing_grid[j]){
                        k_finishing = starting_grid[k];
                        // Empurrar todo mundo pra direita
                        for (int i = j+1; i < N+1; i++){
                            starting_grid[i] = starting_grid[i-1];
                        }
                        starting_grid[j] = k_finishing;
                        // Puxar todo mundo pra esquerda
                        for (int i = k+1; i < N-1; i++){
                            starting_grid[i] = starting_grid[i+1];
                        }
                        overtakes += abs(j-k);
                        break;
                    }
                }
            }
        }
        printf("%d\n", overtakes);
        free(starting_grid);
        free(finishing_grid);
    }
    
    return 0;
}