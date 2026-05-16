// 位运算与预处理表

#include <bits/stdc++.h>

int n, m;

int f(int x, int k){
    return (((x*x + k*k) % 8) ^ k);
}

int inverse_once(int x, int k){
    int top = x >> 6;          // 高三位
    int middle = (x >> 3) & 7; // 中三位
    int tail = x & 7;          // 低三位

    int B = top;
    int C = middle ^ f(B, k);
    int A = tail ^ f(C, k);

    return (A << 6) | ( B << 3) | C; // 拼接
}

signed main(){
    std::cin >> n >> m;
    std::vector<int> k(m);
    std::vector<int> a(n);
    std::vector<int> res(512);

    for(int i = 0; i < m; ++i){
        std::cin >> k[i];
    }
    for(int i = 0; i < n; ++i){
    std::cin >> a[i];
    }

    for(int i = 0; i < 512; ++i){
        int cur = i;

        for(int j = m - 1; j >= 0; --j){
            cur = inverse_once(cur, k[j]);
        }

        res[i] = cur;
    }

    
    for (int i = 0; i < n; i++)
    {
        std::cout << res[a[i]] << ' ';
    }
    

    return 0;
}