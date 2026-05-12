#include <bits/stdc++.h>

int n, m;

int f(int x, int k){
    return (((x*x + k*k) % 8) ^ k);
}

signed main(){
    std::cin >> n >> m;
    std::vector<int> k(m);
    std::vector<int> a(n);
    std::vector<int> res(n);

    for(int i = 0; i < m; ++i){
        std::cin >> k[i];
    }
    for(int i = 0; i < n; ++i){
    std::cin >> a[i];
    }

    //1. 高三位为source b
    //2. 算出f(b)
    //3. 中三位^f(b)得到source c
    //4. 算出f(c)
    //5. 低三位^f(c)得到source a

    for (size_t i = 0; i < n ; i++)
    {
        int src{};
        int top = a[i] >> 6;
        int middle = (a[i] >> 3)&7;
        int tail = a[i] & 7;
        for (int j = m-1 ; j >= 0; j--)
        {
            int top_ = top;
            int middle_ = middle;
            int tail_ = tail;
            middle = top;
            tail = middle_ ^ f(middle, k[j]);
            top = tail_ ^ f(tail, k[j]);
        }
        src += (top << 6) + (middle << 3) + tail;
        res[i] = src;
    }
    
    for (int i = 0; i < n; i++)
    {
        std::cout << res[i] << ' ';
    }
    

    return 0;
}