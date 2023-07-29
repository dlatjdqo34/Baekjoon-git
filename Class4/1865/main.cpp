#include <bits/stdc++.h>
using namespace std;
int maxD = 100000000;
struct Edge {
  int s, e, t;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int TC;
  cin >> TC;
  for (int i = 0; i < TC;i++) {
    int N, M, W;
    cin >> N >> M >> W;
    int e = 2 * M + W;
    int v[502];
    for (int j = 1; j <= N;j++){
      v[j] = maxD;
    } 
    Edge edge[5200];
    for (int j = 0; j < M;j++){
      int S, E, T;
      cin >> S >> E >> T;
      edge[2 * j] = {S, E, T};
      edge[2 * j + 1] = {E, S, T};
    } 
    for (int j = 0; j < W;j++){
      int S, E, T;
      cin >> S >> E >> T;
      edge[2 * M + j] = {S, E, -T};
    }
    v[1] = 0;
    bool ans = false;
    for (int j = 1; j <= N; j++){
      for (int k = 0; k < e;k++){
        Edge cur = edge[k];
        if (v[cur.e] > v[cur.s] + cur.t) {
          if (j == N) ans = true;
          v[cur.e] = v[cur.s] + cur.t;
        }
      } 
    }
    if (ans) cout << "YES\n";
    else
      cout << "NO\n";
  }
}