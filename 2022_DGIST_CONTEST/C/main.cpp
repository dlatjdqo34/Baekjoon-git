#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr[18][18];
ll colsum[18];
bool selected[18];
ll n,ans;
void GetScore(){
    ll c[18]={}, score=0;
    for(int i=0;i<n;i++){
        if(selected[i]) {
            for(int j=0;j<n;j++){
                c[j] += arr[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        int alt = colsum[i]-c[i];
        if(c[i]>alt) score += alt;
        else score += c[i];
    }
    if(score > ans) ans = score;
}
void DFS(int d, bool flag){
    selected[d]=flag;
    if(d == n-1){
        GetScore();
    }
    else {
        DFS(d+1, true);
        DFS(d+1, false);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            colsum[j] += arr[i][j];
        }
    }
    DFS(0, true);
    DFS(0, false);
    cout<<ans;
}