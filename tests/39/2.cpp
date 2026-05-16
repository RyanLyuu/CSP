// 前缀和&差分

#include <bits/stdc++.h>

int n, L;
int csp[5][9] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0, 0}
};

signed main(){
    std::cin >> n >> L;
    std::vector<int> cnt(L);       // cnt[k] 表示在k阈值下有几个矩阵块满足
    std::vector<int> d(L + 1);
    std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            std::cin >> grid[i][j];
        }
    }
    
    //遍历所有矩阵块
    for(int i = 0; i <= n - 5; ++i){
        for(int j = 0; j <= n - 9; ++j){
            //遍历5x9区域
            int maxBlack = -1, minWhite = L;
            for(int x = i; x < i + 5; ++x){
                for(int y = j; y < j + 9; ++y){
                    if(csp[x - i][y - j])
                        minWhite = std::min(minWhite, grid[x][y]);
                    else
                        maxBlack = std::max(maxBlack, grid[x][y]);
                }
            }
            int l = maxBlack + 1, r = minWhite;
            //cnt[l, r] + 1
            if(l <= r){
            d[l] += 1;
            d[r + 1] -= 1;
            }
        }
    }
    
    for(int i = 0; i < L; ++i){
        if(i == 0) cnt[i] = d[i];
        else cnt[i] = cnt[i - 1] + d[i];
    }

    for(int i = 0; i < L; ++i){
        if(cnt[i] > 0) std::cout << i << std::endl;
    }

    return 0;
}

