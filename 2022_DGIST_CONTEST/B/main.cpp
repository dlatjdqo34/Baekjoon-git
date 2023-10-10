#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    ll a[200000], b[200000];
    cin>>n>>m;
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<m;i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    ll x = n-1, y = 0, asum=0, bsum=0;
    while(x>=0&&y<m){
        if(a[x]>b[y]){
            asum += a[x--];
            bsum += b[y++];
        }
        else break;
    }
    ll ans = asum - bsum;
    cout<<ans;
}