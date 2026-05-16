#include <bits/stdc++.h>

int k;

double compute(int a, int b, int n){
    return ((double)n - a) / b;
}

signed main(){
    std::cin >> k;
    std::vector<int> a(k);   // 均值
    std::vector<int> b(k);   // 方差
    std::vector<int> n(k);   // 整数n
    for (size_t i = 0; i < k; i++)
    {
        std::cin >> a[i] >> b[i] >> n[i];
    }

    // 分成小数点后第二位和其余部分
    for (int i = 0; i < k; i++)
    {
        int res = floor(compute(a[i], b[i], n[i]) * 100 + 1e-9);
        int first = res / 10 + 1, second = res % 10 + 1;
        std::cout << first << ' ' << second << std::endl;
    }
    
}