#include <bits/stdc++.h>

int n, k;
int x, y;

struct PairHash {
    size_t operator()(const std::pair<int,int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};


std::unordered_set<std::pair<int, int>, PairHash> reachable;

bool inbound(int x, int y){
    return (x >= 1 && y >= 1 && x <= n && y <= n);
}

void lighten(int x, int y, int k){
    if(k < 0) return;

    if(!inbound(x, y)) return;


    if(reachable.count({x, y})) return;
    reachable.insert({x, y});

    int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    int dy[8] = { 2, 2,  1, 1, -1,-1, -2,-2};

    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(inbound(nx, ny)){
            lighten(nx, ny, k-1);
        }
    }
}

signed main(){
    std::cin >> n >> k;
    std::cin >> x >> y;
    
    lighten(x, y, k);

    std::cout << reachable.size();
}