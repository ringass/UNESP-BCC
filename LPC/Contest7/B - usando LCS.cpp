#include <bits/stdc++.h>
#define ll long long

using namespace std;

void fast()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


int main()
{
    fast();

    ll t;
    cin >> t;

    for (ll j = 1; j <= t; j++)
    {

        ll n, p, q;

        cin >> n >> p >> q;

        vector<ll> a(p + 1), b(q + 1);

        for (ll i = 0; i <= p; i++)
        {

            cin >> a[i];
        }

        for (ll i = 0; i <= q; i++)
        {

            cin >> b[i];
        }

        p = p + 1;
        q = q + 1;

        vector<ll> dp(q + 1, 0); //utilizando a otimização de espaço para O(n), bem confuso

        for (ll i = 1; i <= p; i++)
        {   
            ll prev = dp[0]; // guarda o valor anterior

            for (ll j = 1; j <= q; j++)
            {   

                ll temp = dp[j]; // autoexplicativo, preciso atualizar o prev no final do loop

                if (a[i - 1] == b[j - 1])
                {
                    dp[j] = 1 + prev;
                }
                else
                {
                    dp[j] = max(dp[j - 1], dp[j]);
                }

                prev = temp;
            }
        }

        cout << "Case " << j << ": " << dp[q] << "\n";
    }
}