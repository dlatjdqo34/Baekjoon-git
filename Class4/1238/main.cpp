#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
const int maxT = 100001;
int n, m, x,ans;
vector<pair<int,int>> adj[1001];
bool visited[1001];
int ntox[1001], xton[1001];
void dijkstra(int start, int* arr){
    arr[start]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({start,0});
    while(!pq.empty()){
        int cur = pq.top().first;
        int d = -pq.top().second;
        pq.pop();
        if(arr[cur]<d) continue;
        for(auto& i : adj[cur]){
            int next = i.first;
            int nextd = i.second + d;
            if(nextd < arr[next]){
                arr[next]=nextd;
                pq.push({next, -nextd});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>x;
    int u,v,t;
    for(int i=0;i<m;i++){
        cin>>u>>v>>t;
        adj[u].push_back({v,t});
    }
    for(int i=1;i<=n;i++){
        xton[i]=maxT;
        ntox[i]=maxT;
    }
    dijkstra(x, xton);
    int itoj[1001];
    for(int i=1;i<=n;i++){
        if(i==x) {ntox[i]=0; continue;}
        for(int j=1;j<=n;j++) itoj[j]=maxT;
        dijkstra(i, itoj);
        ntox[i]=itoj[x];
    }
    for(int i=1;i<=n;i++){
        int d = ntox[i] + xton[i];
        if(d > ans) ans =d;
    }
    cout<<ans;
}