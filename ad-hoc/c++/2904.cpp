#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define fori(i, n) for(int i=0; i<n; i++)
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, l, t=0, r, found=0;
    bool solved=false;
    
    cin >> n;
    
    vector<int> circunference(n);
    fori(i, n){
        cin >> l;
        t+=l;
        circunference[i] = t;
    }
    
    vector<int>::iterator itB = circunference.begin();
    vector<int>::iterator itE = circunference.end();
    set<int> points;
    
    if (t % 2 == 0){
        r = t/2;
        fori(i, n){
            if (circunference[i] <= r){
                if (binary_search(itB, itE, circunference[i]+r)) points.insert(circunference[i]+r);
                
                if (points.size() == 2){
                    solved=true;break;
                }
            }
            else break;
            
        }
    }
    if (solved) cout<< "Y"<<endl;
    else cout<< "N"<<endl;

    return 0;
}