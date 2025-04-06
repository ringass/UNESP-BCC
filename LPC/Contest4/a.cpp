#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> moves = {
    {-2, -1}, {-2, 1},
    {-1, -2}, {-1, 2},
    {1, -2}, {1, 2},
    {2, -1}, {2, 1}
};

int bfs(vector<vector<bool>> &visited, vector<vector<bool>> &board, int n, int maxCol, int startRow, int startCol)
{
    queue<pair<int, int>> fila;
    int possible = 0, total = 0;

    // Contar casas válidas
    for (int i = 0; i < n; i++)
        for (int j = 0; j < maxCol; j++)
            if (board[i][j])
                total++;

    fila.push({startRow, startCol});
    visited[startRow][startCol] = true;

    while (!fila.empty())
    {
        auto [row, col] = fila.front();
        fila.pop();
        possible++;

        for (auto move : moves)
        {
            int newRow = row + move.first;
            int newCol = col + move.second;

            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < maxCol &&
                board[newRow][newCol] &&
                !visited[newRow][newCol])
            {
                visited[newRow][newCol] = true;
                fila.push({newRow, newCol});
            }
        }
    }

    return total - possible;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cases = 1;
    while (cin >> n && n != 0)
    {
        vector<pair<int, int>> rows(n);
        int maxCol = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> rows[i].first >> rows[i].second;
            maxCol = max(maxCol, rows[i].first + rows[i].second);
        }

        vector<vector<bool>> board(n, vector<bool>(maxCol, false));
        vector<vector<bool>> visited(n, vector<bool>(maxCol, false));

        // Preencher tabuleiro
        for (int i = 0; i < n; i++)
        {
            int start = rows[i].first;
            int count = rows[i].second;
            for (int j = start; j < start + count; j++)
                board[i][j] = true;
        }

        // Encontrar a primeira célula válida (de cima para baixo)
        int startRow = -1, startCol = -1;
        for (int i = 0; i < n && startRow == -1; i++)
        {
            for (int j = 0; j < maxCol; j++)
            {
                if (board[i][j])
                {
                    startRow = i;
                    startCol = j;
                    break;
                }
            }
        }

        int ans = 0;
        if (startRow != -1 && startCol != -1)
            ans = bfs(visited, board, n, maxCol, startRow, startCol);

        cout << "Case " << cases << ", " << ans << " square" << (ans == 1 ? "" : "s") << " can not be reached.\n";
        cases++;
    }
}
