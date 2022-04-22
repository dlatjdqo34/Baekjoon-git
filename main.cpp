#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int adj[101];
queue<pair<int,int>> q;
bool visited[101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<n+m;i++){
        cin>>u>>v;
        adj[u]=v;
    }
    q.push({1,0});
    while(!q.empty()){
        auto x = q.front();
        int num=x.first,d=x.second;
        q.pop();
        if(!visited[num]) visited[num]=true;
        else continue;
        if(num==100){
            cout<< d;
            return 0;
        }
        for(int i=1;i<7;i++){
            if(num+i<101){
                if(adj[num+i]>0){
                    q.push({adj[num+i],d+1});
                }else{
                    q.push({num+i,d+1});
                }
            }
        }
    }
}