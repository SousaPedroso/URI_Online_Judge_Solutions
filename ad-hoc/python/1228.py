# -*- coding:utf-8 -*-

while True:
    try:
        N = int(input())
    except:
        exit()
        
    starting_grid = input().split(" ")
    finishing_grid = input().split(" ")
    overtakes = 0
    
    for j in range(N):
        if starting_grid[j] != finishing_grid[j]:
            for k in range(N):
                if starting_grid[k] == finishing_grid[j]:
                    k_finishing = starting_grid[k]
                    starting_grid.insert(j, k_finishing)
                    del starting_grid[k+1]
                    overtakes += abs(j-k)
                    break
                
    print(overtakes)