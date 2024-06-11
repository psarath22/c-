#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

#define vi vector<ll>
#define pii pair<ll, ll>
#define all(x) x.begin(), x.end()
#define rep(i, n) for (int i = 0; i < n; i++)
const ll N = 1;
ll mod = 998244353;
ll inf = 2e18;
#define ff first
#define ss second

/*********************************************************************************/
ll fact[N];
ll ifact[N];
ll exp(ll a, ll b, ll m = mod)
{
    ll ret = 1;
    while (b > 0)
    {
        if (b & 1)
            ret = (ret * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return (ret + m) % m;
}
ll mod_add(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return ((a + b) % m + m) % m;
}
ll mod_sub(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return ((a - b) % m + m) % m;
}
ll mod_mul(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return ((a * b) % m + m) % m;
}
ll mod_div(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, exp(b, m - 2, m), m));
}
ll ncr(ll a, ll b, ll m = mod)
{
    return mod_mul(mod_mul(fact[a], ifact[b], m), ifact[a - b], m);
}
/*************************************************************************************/


int main()
{
    int t = 1;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> dp(n + 1), ans(n + 1);
        ll start = 0;
        dp[0]=1;
        while (start <= n)
        {
            vector<ll> sum(k, 0);
            for (int i = start; i <= n; i++)
            {
                ll cur = dp[i];
                dp[i] = sum[i % k];
                (sum[i % k] += cur) %= mod;
                (ans[i] += dp[i]) %= mod;
            }
            start += k;
            k++;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
