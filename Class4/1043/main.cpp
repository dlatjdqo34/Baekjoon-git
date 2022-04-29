#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> party[50];
vector<int> adj[50];
bool p[50];
bool visited[50];
int n,m,ans;
void isConnected(int u, int v){
    auto i = party[u].begin(), j = party[v].begin();
    while(i != party[u].end() && j != party[v].end()){
        if(*i > *j) j++;
        else if(*i < *j) i++;
        else {
            adj[u].push_back(v);
            adj[v].push_back(u);
            break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<int> q;
    bool know[51]={};
    int c;
    cin>>n>>m>>c;
    for(int i=0;i<c;i++){
        int h;
        cin>>h;
        know[h]=true;
    }
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1;
        for(int j=0;j<v1;j++){
            cin>>v2;
            party[i].push_back(v2);
            if(know[v2]) p[i]=true;
        }
        if(p[i]) {
            q.push(i);
            visited[i]=true;
        }
        sort(party[i].begin(),party[i].end());
    }
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            isConnected(i, j);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v]=true;
                q.push(v);
                if(p[u]) p[v]=true;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(!p[i]) ans++;
    }
    cout<<ans;
}