#include <iostream>
#define endl '\n'
#define fori(i, s, n) for(long long i=s; i<n; i++)
using namespace std;

long long mdc(long long a, long long b){
    return b == 0? a: mdc(b, a%b);
}

long long mmc(long long a, long long b){
    return a*b/mdc(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    long long n, l, curMmc=1, c, maxMmc, oriMmc, ans;
    cin >> n >> l;
    
    fori(i, 0, n){
        cin >> c;
        curMmc = mmc(curMmc, c);
    }
    maxMmc = curMmc;
    oriMmc = curMmc;
    ans=1;
    fori(i, 1, l+1){
        curMmc = mmc(oriMmc, i);
        if (curMmc > maxMmc && curMmc <= l){
            ans = i;
            maxMmc = curMmc;
        }
    }
    
    cout<< min(ans, l)<<endl;
    return 0;
}