#include <bits/stdc++.h>

int n, k;
int x, y;

int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = { 2, 2,  1, 1, -1, -1,-2,-2};

bool inbound(int x, int y){
    return (x >= 1 && y >= 1 && x <= n && y <= n);
}



signed main(){
    std::cin >> n >> k;
    std::cin >> x >> y;
    
    std::vector<std::vector<int>> dist(n + 1, std::vector<int>(n + 1, -1));
    std::queue<std::pair<int, int>> q;
    
    q.push({x, y});
    dist[x][y] = 0;

    int ans = 1;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(dist[x][y] == k) continue;

        for(int i = 0; i < 8; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!inbound(nx, ny)) continue;
            if(dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            ans++;
            q.push({nx, ny});
        }
    }

    std::cout << ans << std::endl;
}