#include <bits/stdc++.h>
#define endl '\n'
#define fori(i, n) for(int i=0; i<n; i++)
using namespace std;

bool cmpPair(pair<int, int>p1, pair<int, int>p2){
    if (p1.first != p2.first) return p1.first > p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, id, greatestScore;
    
    while (cin >> n >> m && n !=0){
        vector<pair<int, int>> ranking(10000, {0, 0});
        for (int i = 0; i < 10000; i++) ranking[i].second = i+1;

        fori(i, n){
            fori(j, m){
                cin >> id; id--;
                ranking[id].first++;
                // ranking[id].second = ranking[id].second;
            }
        }
        sort(ranking.begin(), ranking.end(), cmpPair);

        greatestScore = ranking[1].first;
        // for (int i = 0; i < 24; i++) cout << ranking[i].first << " ";
        // cout << endl;
        // for (int i = 0; i < 24; i++) cout << ranking[i].second << " ";
        // cout << endl;
        // cout << greatestScore << endl;

        int i=1;
        
        while (i < 10000 && ranking[i].first == greatestScore){
            cout<< ranking[i].second<< " ";
            i++;
        }
        cout<< endl;
    }

    return 0;
}