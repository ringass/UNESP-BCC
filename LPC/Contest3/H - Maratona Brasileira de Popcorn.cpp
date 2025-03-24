#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool verifica(const vector<int> &sacos, int C, int T, ll max_time) {
    ll max_pipocas = T * max_time;
    int count = 1;
    ll sum = 0;

    for (int end = 0; end < sacos.size(); ++end) {
        if (sacos[end] > max_pipocas) {
            return false;
        }
        if (sum + sacos[end] > max_pipocas) {
            count++;
            sum = sacos[end];
            if (count > C) {
                return false;
            }
        } else {
            sum += sacos[end];
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C, T;
    cin >> N >> C >> T;

    vector<int> sacos(N);
    ll left = 1;
    ll right = 0;

    for (int i = 0; i < N; ++i) {
        cin >> sacos[i];
        right += sacos[i];
    }

    ll ans = right;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (verifica(sacos, C, T, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}