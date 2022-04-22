#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n,ans,shark=2,cnt;
int map[20][20];
bool visited[20][20];
struct Point{
    int x,y,depth;
    Point(int i, int j, int d) : x(i),y(j),depth(d){}
    bool operator<(const Point& p) const {
        if(x == p.x)
            return y < p.y;
        return x < p.x;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    queue<Point> q;
    vector<Point> v;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j]==9){
                q.push(Point(i,j,0));
                visited[i][j]=true;
                map[i][j]=0;
            }
        }
    }
    while(true){
        int mind = 401;
        while(!q.empty()){
            auto p = q.front();
            int x=p.x,y=p.y,d=p.depth;
            q.pop();
            if(map[x][y]<shark && map[x][y]>0 && d <= mind){
                v.push_back(Point(x,y,d));
                mind=d;
                continue;
            }
            if(d>mind) continue;
            if(x-1>=0)
                if(!visited[x-1][y] && map[x-1][y]<=shark){
                    visited[x-1][y]=true;
                    q.push(Point(x-1,y,d+1));
                }
            if(x+1<n)
                if(!visited[x+1][y] && map[x+1][y]<=shark){
                    visited[x+1][y]=true;
                    q.push(Point(x+1,y,d+1));
                }
            if(y-1>=0)
                if(!visited[x][y-1] && map[x][y-1]<=shark){
                    visited[x][y-1]=true;
                    q.push(Point(x,y-1,d+1));
                }
            if(y+1<n)
                if(!visited[x][y+1] && map[x][y+1]<=shark){
                    visited[x][y+1]=true;
                    q.push(Point(x,y+1,d+1));
                }
        }
        if(v.empty()) break;
        sort(v.begin(),v.end());
        auto& p = v[0];
        map[p.x][p.y]=0;
        ans += p.depth;
        if(++cnt == shark) {
            shark++;
            cnt=0;
        }
        v.clear();
        q.push(Point(p.x,p.y,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=false;
            }
        }
        visited[p.x][p.y]=true;
    }
    cout<<ans;
}