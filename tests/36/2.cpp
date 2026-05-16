// 前缀和

#include <bits/stdc++.h>

int n;

int main(){
    std::cin >> n;
    std::vector<int> a(n + 1, 0);
    std::vector<int> b(n + 1, 0);
    
    for(int i = 0; i <= n; ++i){
        std::cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        std::cin >> b[i];
    }

    std::vector<int> need(n + 1);

    int sumA = 0, sumB = 0;
    for (int i = 0; i <= n; i++)
    {
        sumA += a[i];
        if (i >= 1) sumB += b[i];
        need[i] = sumA - sumB;
    }

    std::vector<int> pre(n+1), suf(n+1);

    pre[0] = need[0];
    for (int i = 1; i <= n; i++)
    {
        pre[i] = std::max(pre[i - 1], need[i]);
    }
    suf[n] = need[n];
    for (int i = n - 1; i >= 1; --i)
    {
        suf[i] = std::max(suf[i + 1], need[i]);
    }
    
    for (int i = 1; i <= n; i++)
    {
        int ans = std::max(pre[i - 1], suf[i] + b[i]);
        std::cout << ans << ( i == n ? '\n' : ' ');
    }
    


}