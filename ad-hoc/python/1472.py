# -*- coding: utf-8 -*-

def binary_search(key, left, right, points):

    while left <= right:
 
        middle = (right + left) // 2
 
        if points[middle] < key:
            left = middle + 1
        elif points[middle] > key:
            right = middle - 1
        else:
            return middle
 
    return -1



while True:

    try:
        N = int(input())
    except EOFError:
        break
    
    points = input().split()
    points = list(map(int, points))
    
    selectedPoints = [0] * N
    num_triangles = 0
    arc_length = points[0]

    n = N 
    
    for point in range(1,N):
        arc_length += points[point]
        points[point] = arc_length
       
    arc_length = int(arc_length/3)
    searchStartP1 = 1
    searchStartP2 = 1

    for idxPoint in range(N):

        if idxPoint >= n or points[idxPoint] > arc_length:
            break

        if idxPoint > searchStartP1:
            searchStartP1 = idxPoint

        point = points[idxPoint]
        
        p1 = binary_search(point+arc_length, searchStartP1, n-1, points)
        
        if p1 != -1:
            searchStartP1 = p1
            searchStartP2 = searchStartP2 - 1
            points.pop(p1)
            n = n - 1

            if p1 > searchStartP2:
                searchStartP2 = p1

            p2 = binary_search(point+(2*arc_length), searchStartP2, n-1, points)

            if p2 != -1:
                searchStartP2 = p2
                points.pop(p2)
                n = n - 1
                num_triangles += 1

    print(num_triangles)
