#include <bits/stdc++.h>
using namespace std;
int n, m;

int main()
{
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int x = -1, y = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                x = i;
                y = j;
            }
        }
    }
    if (x == -1 && y == -1)
    {
        cout << "NO";
        return 0;
    }
    int delx[] = {-1, 1, 0, 0};
    int dely[] = {0, 0, -1, 1};
    char paths[] = {'U', 'D', 'L', 'R'};
    string ans = "";
    queue<pair<string, pair<int, int>>> q;
    q.push({ans, {x, y}});
    while (!q.empty())
    {
        auto it = q.front();
        string path = it.first;
        int x = it.second.first;
        int y = it.second.second;
        q.pop();
        if(grid[x][y]=='B'){
            ans = path;
            break;
        }
        for (int k = 0; k < 4; k++)
        {
            int newX = x + delx[k];
            int newY = y + dely[k];
            char dir = paths[k];
            if (newX >= 0 && newY >= 0 && newX < n && newY < m && (grid[newX][newY] == '.' || grid[newX][newY] == 'B') && !vis[newX][newY])
            {
                path.push_back(dir);
                q.push({path, {newX, newY}});
                path.pop_back();
            }
        }
    }
  
   if(ans.size()==0){
    cout << "NO";
   }
   else{
    cout <<"YES\n" <<  ans.length()
    <<"\n" <<ans << "\n";
   }
}