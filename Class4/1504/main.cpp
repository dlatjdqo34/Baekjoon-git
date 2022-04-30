#include <bits/stdc++.h>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define maxd 10000000
using namespace std;
vector<pair<int,int>> adj[801];
int n;
void Dij(int start, int* d){
    for(int i=1;i<=n;i++){
        *(d+i)=maxd;
    }
    *(d+start) = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        auto& u = pq.top();
        int num = u.second;
        int distance = -u.first;
        pq.pop();
        if(*(d+num)<distance) continue;
        for(auto& i : adj[num]){
            int v = i.first, l = distance + i.second;
            if(*(d+v) > l){
                *(d+v) = l;
                pq.push({-l, v});
            }
        }
    }
}
int main(){
    fastIO();
    int e,u,v,d,v1,v2,tv1,v1t2,v2t1,tv2,v1tn,v2tn;
    int arr[801];
    cin>>n>>e;
    for(int i=0;i<e;i++){
        cin>>u>>v>>d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    cin>>v1>>v2;
    Dij(1, arr);
    tv1 = arr[v1], tv2 = arr[v2]; 
    Dij(v1, arr);
    v1t2 = arr[v2], v1tn = arr[n];
    Dij(v2, arr);
    v2t1 = arr[v1], v2tn = arr[n];

    int ans1 = tv1 + v1t2 + v2tn;
    int ans2 = tv2 + v2t1 + v1tn;
    if(ans1 >= maxd && ans2 >= maxd)
        cout<<-1;
    else {
        int ans = (ans1 < ans2)?ans1:ans2;
        cout<< ans;
    }
}