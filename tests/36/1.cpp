#include <bits/stdc++.h>

int n, k;
int x, y;

std::map<char, std::pair<int, int>> table{
    {'f', {0, 1}},
    {'b', {0, -1}},
    {'l', {-1, 0}},
    {'r', {1, 0}}
};

bool inbound(int a, int b){
    return a >= 1 && b >= 1 && a <= n && b <= n;
}

signed main(){
    std::cin >> n >> k;

    while(k--){
        std::cin >> x >> y;
        std::string query;
        std::cin >> query;
        for(auto& letter : query){
            int nx = x + table[letter].first;
            int ny = y + table[letter].second;
            if(inbound(nx, ny)){
                x = nx;
                y = ny;
            }
        }

        std::cout << x << ' ' << y << std::endl;
    }
}