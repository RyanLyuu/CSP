#include <bits/stdc++.h>

int b, c, l, r;

int f(int x){
    return x*x + b*x + c;
}

signed main(){
    std::cin >> b >> c >> l >> r;

    int sum{};
    for(int i = l + l%2; i <= r; i+=2){
        sum += f(i);
    }

    std::cout << 2*sum << std::endl;
}