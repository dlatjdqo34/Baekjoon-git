#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int ans[1000000],res = 50000000,n,m;
vector<int> v;
void DFS(int g, int d){
    if(g==0){
        ans[0] = 1 + n;
        if(res > ans[0]) res = ans[0];
        return;
    }
    if(g != 100){
        ans[g] = d + abs(n-g);
        if(res > ans[g]) res = ans[g];
    }
    if(d<6){
        for(int i : v){
            DFS(10*g+i,d+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    bool button[10]={};
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        button[b]=true;
    }
    for(int i=0;i<10;i++){
        if(!button[i])
            v.push_back(i);
    }
    ans[100] = abs(n-100);
    if(res > ans[100]) res = ans[100];
    for(int i : v){
        DFS(i, 1);
    }
    cout << res;
}