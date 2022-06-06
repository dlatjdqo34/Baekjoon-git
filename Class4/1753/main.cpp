#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[20001];
int maxD = 100000000;
void dijkstra(int start, int* arr){
    arr[start]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        int cur = pq.top().second;
        int d = -pq.top().first;
        pq.pop();
        if(arr[cur]<d) continue;
        for(auto& i : adj[cur]){
            int next = i.first;
            int nextd = i.second + d;
            if(nextd < arr[next]){
                arr[next]=nextd;
                pq.push({-nextd, next});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans[20001];
    int v,e,k;
    cin>>v>>e>>k;
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }
    for(int i=1;i<=v;i++){
        ans[i] = maxD;
    } 
    dijkstra(k, ans);
    for(int i=1;i<=v;i++){
        if(ans[i]==maxD)
            cout<<"INF\n";
        else
            cout<<ans[i]<<'\n';
    }
}