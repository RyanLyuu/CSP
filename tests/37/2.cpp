// 完全背包

#include <bits/stdc++.h>

const int M = 10001;
int n, m;
int f[M];

signed main(){
    std::cin >> n >> m;
    std::vector<int> nums(m+1, 0);
    for(int i = 1; i <= m; ++i){
        std::cin >> nums[i];
    }

    // 01背包，重量1到m, 价值nums[i]
    for(int i = 1; i <= m; i++){
        for(int j = i; j <= n; j++){
            f[j] = std::max(f[j], f[j - i] + nums[i]);
        }
    }

    std::cout << f[n] << std::endl;
}