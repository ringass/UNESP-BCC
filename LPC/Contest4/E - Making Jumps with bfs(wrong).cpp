#include <bits/stdc++.h>

using namespace std;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
// maximo de movimentos possiveis = 8;

// learning bfs

int bfs(vector<vector<bool>> &visited, vector<vector<bool>> &board, int n, int maxCol)
{
    queue<pair<int, int>> fila;
    int possible = 0, total = 0;
    bool flag = false;

    // verificacao do total "casas" que consiguiremos andar 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            if (board[i][j])
            {
                total++;
                if (flag == false)// primeira adiçao -> semelhante a adicao do primeiro nó em uma bst, porem verificando como dito no exercicio que a primeira casa deve ser a casa acessivel mais a esquerda, portanto nao a {0,0} como eu estava errando!!
                {
                    flag = true;
                    fila.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
    }

    

    while (!fila.empty())
    {

        pair<int, int> atual = fila.front();
        fila.pop(); // popa legal

        possible++;

        int row = atual.first;
        int column = atual.second;

        for (int i = 0; i < 8; i++)
        { // verificar todas as possibilidades de movimentos :), no exercicio da Roberta de colorir ela faz com ifs, usando o for fica mais enxuto, porem é a mesma ideia;

            int rowAtual = row + moves[i].first;
            int columnAtual = column + moves[i].second;

            if ((rowAtual >= 0 && rowAtual < n) && (columnAtual >= 0 && columnAtual < maxCol))
            { // importante verificacao para que nao ultapasse os limites do nosso tabuleiro; (em outras ocasioes, imagino que tambem ocorra umma verificacao desse tipo);

                if (board[rowAtual][columnAtual] == true && visited[rowAtual][columnAtual] == false)
                { // voltando ao nosso board e verificando se é uma possicao valida, caso seja e ainda nao tenha sido visitado é pra dale;

                    visited[rowAtual][columnAtual] = true;
                    fila.push({rowAtual, columnAtual}); // pushando para a fila, continua processo;
                }
            }
        }
    }

    int impossible = total - possible; // toda vez que entravamos no processo marcavamos a "casa" como possivel!!! no entanto aquelas que pararam no nosso "if" dentro do "for", foram deixadas para tras, resumindo é esse "gap" que o exercicio queria!!

    return impossible;
}

int main()
{

    int n = 1, cases = 1;
    vector<vector<bool>> visited;

    while (cin >> n && n != 0)
    {

        vector<pair<int, int>> rows(n);
        int maxCol = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> rows[i].first >> rows[i].second;
            maxCol = max(rows[i].first + rows[i].second, maxCol);
        }

        // vetor para o tabuleiro, vetor para verificar se já foi visitado, fila para bfs;
        vector<vector<bool>> board(n, vector<bool>(maxCol, false));

        visited.assign(n, vector<bool>(maxCol, false));

        // preenchendo o tabuleiro para que somente as posicoes possiveis recebam o valor true;
        for (int i = 0; i < n; i++)
        {
            int space = rows[i].first;
            int cols = rows[i].second;

            for (int j = space; j < space + cols; j++)
            {   
                board[i][j] = true;
            }
        }

        int ans = bfs(visited, board, n, maxCol);

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