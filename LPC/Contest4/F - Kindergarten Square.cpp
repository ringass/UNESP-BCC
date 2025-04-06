#include <iostream>
#include <vector>
using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b != a + 1 || d != c + 1)
    {
        cout << -1 << endl;
        return;
    }

    int l = c - a;

    if (l <= 1 || (a - 1) % l == l - 1)
    {
        cout << -1 << endl;
        return;
    }

    int max_ = max(b, d);
    int h = (max_ + l - 1) / l;
    if (h < 2)
        h = 2;

    cout << h << " " << l << endl;
}

int main()
{

    fast();

    int n;

    cin >> n;

    while (n--)
    {

        solve();

    }
    return 0;
}