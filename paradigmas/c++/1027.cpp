#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>
#include <utility>
#define fori(i, n) for(int i=0; i<n; i++)
#define endl '\n'
#define INF 1e4
using namespace std;

int memo[1001][2], n;

int f(vector<pair<int, int>>& points, int i, int pos){
    if (i == n) return 0;
    if (memo[i][pos] != -1) return memo[i][pos];
    memo[i][pos] = 1;
    
    for(int j=i+1; j<n; j++){
        if (points[j].first != points[i].first && abs(points[j].second - points[i].second) == 2){
            // verifica se é positivo ou negativo para dar continuidade em a-1, a+1
            int a = (points[i].second - points[j].second);
            if (a > 0 && pos == 1){
                // 0 para procurar um menor
                memo[i][1] = max(memo[i][1], 1+f(points, j, 0));
            }
            else if(a < 0 && pos == 0){
                // 1 pra procurar um maior
                memo[i][0] = max(memo[i][0], 1+f(points, j, 1));
            }
        }
    }
    return memo[i][pos];
}

int main()
{
    ios_base::sync_with_stdio(false);
    int x, y, sol;
    
    while (cin >> n){
        vector<pair<int, int>> points(n);
        sol = 0;
        fori(i, n){
            cin >> x>> y;
            points[i].first = x;
            points[i].second = y;
        }
        memset(memo, -1, sizeof memo);
        sort(points.begin(), points.end());
        
        fori(i, n){
            sol = max(sol, f(points, i, 0));
            sol = max(sol, f(points, i, 1));
        }
        
        cout<< sol<< endl;
    }
    
    return 0;
}