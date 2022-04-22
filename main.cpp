#include <iostream>
#include <queue>
using namespace std;
int n,ans;
int map[20][20];
bool visited[20][20];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    queue<pair<int,int>> q;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j]==9){
                q.push({i,j});
                visited[i][j]=true;
            }
        }
    }
    while(true){
        return;
    }
}