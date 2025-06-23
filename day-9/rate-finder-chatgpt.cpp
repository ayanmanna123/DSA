#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printGridPath(vector<vector<int>> &maze, string path)
{
    int n = maze.size();
    vector<vector<char>> display(n, vector<char>(n, '.'));
    int x = 0, y = 0;
    display[x][y] = 'S'; // Start

    for (char dir : path)
    {
        if (dir == 'D')
            x++;
        else if (dir == 'U')
            x--;
        else if (dir == 'L')
            y--;
        else if (dir == 'R')
            y++;

        if (x == n - 1 && y == n - 1)
            display[x][y] = 'E'; // End
        else
            display[x][y] = '*'; // Path
    }

    // Print grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << display[i][j] << ' ';
        }
        cout << endl;
    }
}

bool issafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
    }
    visited[x][y] = 1;
    int newx = x + 1;
    int newy = y;
    if (issafe(newx, newy, n, visited, m))
    {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    newx = x;
    newy = y - 1;
    if (issafe(newx, newy, n, visited, m))
    {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    newx = x;
    newy = y + 1;
    if (issafe(newx, newy, n, visited, m))
    {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    newx = x - 1;
    newy = y;
    if (issafe(newx, newy, n, visited, m))
    {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    visited[x][y] = 0;
}

int main()
{
   vector<vector<int>> m = {
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
    {0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0},
    {0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1}
};

    vector<string> ans;
    if (m[0][0] == 0)
    {
        return 0;
    }
    int n = m.size();
    int srcx = 0;
    int srcy = 0;
    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    for (const string &p : ans)
    {
        cout << "Path: " << p << endl;
        printGridPath(m, p);
        cout << endl;
    }
}