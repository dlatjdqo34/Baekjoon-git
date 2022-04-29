#include <iostream>
#include <vector>
using namespace std;
int n,ans,farv;
vector<pair<int, int>> adj[100001];
bool visited[100001];
void DFS(int u, int l){
    visited[u]=true;
    if(l > ans) {
        ans = l;
        farv = u;
    }
    auto& a = adj[u];
    for(auto& v : a){
        if(!visited[v.first]){
            DFS(v.first, l+v.second);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int u,v,len;
    for(int i=0;i<n;i++){
        cin>>u;
        while(true){
            cin>>v;
            if(v==-1) break;
            cin>>len;
            adj[u].push_back({v,len});
        }
    }
    DFS(1, 0);
    for(int i=1;i<=n;i++) visited[i]=false;
    DFS(farv, 0);
    cout<<ans;
}