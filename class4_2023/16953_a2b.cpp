#include <string>
#include <vector>
#include <queue>

using namespace std;

#define ll long long

typedef struct {
    ll num;
    ll depth;
} elem;

int main()
{
    ll a, b;
    queue<elem> q;

    scanf("%lld %lld", &a, &b);
    q.push({a, 1LL});

    while(!q.empty()) {
        elem cur = q.front();
        
        q.pop();

        if (cur.num > b) {
            continue;
        } else if (cur.num == b) {
            printf("%lld", cur.depth);
            return 0;
        }
        
        q.push({cur.num * 2LL, cur.depth + 1LL});
        q.push({cur.num * 10LL + 1, cur.depth + 1LL});
    }

    printf("-1");
    return 0;
}