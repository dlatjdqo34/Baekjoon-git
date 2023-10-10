#include <string>

#define ll long long
int main()
{
    ll a, b;

    scanf("%lld %lld", &a, &b);
    printf("%lld", (a + b) * (a - b));
    
    return 0;
}