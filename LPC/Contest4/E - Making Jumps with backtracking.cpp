#include <bits/stdc++.h>

using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int maxReach = 0;
int total = 0;

void backtrack(int x, int y, int countCasas, vector<vector<bool>> &board, vector<vector<bool>> &visited, int n, int m)
{
    maxReach = max(maxReach, countCasas);

    for (auto [dx, dy] : moves)
    {
        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] && !visited[nx][ny])
        {
            visited[nx][ny] = true;
            backtrack(nx, ny, countCasas + 1, board, visited, n, m);
            visited[nx][ny] = false;
        }
    }
}

int main()
{

    int n = 1, cases = 1;
    vector<vector<bool>> visited;

    while (cin >> n && n != 0)
    {

        vector<pair<int, int>> rows(n);
        int maxCol = 0;
        total = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> rows[i].first >> rows[i].second;
            maxCol = max(rows[i].first + rows[i].second, maxCol);
        }

        vector<vector<bool>> board(n, vector<bool>(maxCol, false));

        visited.assign(n, vector<bool>(maxCol, false));

        for (int i = 0; i < n; i++)
        {
            int space = rows[i].first;
            int cols = rows[i].second;

            for (int j = space; j < space + cols; j++)
            {
                board[i][j] = true;
                total++;
            }
        }

        maxReach = 0;

        bool started = false;
        for (int i = 0; i < n && !started; ++i)
        {
            for (int j = 0; j < maxCol && !started; ++j)
            {
                if (board[i][j])
                {
                    visited[i][j] = true;
                    backtrack(i, j, 1, board, visited, n, maxCol);
                    visited[i][j] = false;
                    started = true;
                }
            }
        }

        int ans = total - maxReach;

        if (ans == 1)
        {
            cout << "Case " << cases << ", " << ans << " square can not be reached.\n";
        }
        else
        {
            cout << "Case " << cases << ", " << ans << " squares can not be reached.\n";
        }

        cases++;
    }
}