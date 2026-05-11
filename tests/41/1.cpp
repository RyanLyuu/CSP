#include <bits/stdc++.h>

int compute_digits(int n){
    int cnt = 1;
    while(n/=2){
        cnt++;
    }
    return cnt;
}

bool is_balanced(int n, int digits){
    if(digits%2 != 0) return false;

    int mol = n%2;
    int cnt = mol == 0 ? 1 : 0;
    while(n/=2){
        mol = n%2;
        cnt += mol == 0? 1 : 0;
    }

    return cnt*2 == digits;
}


int main(){
    int n{};
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    int sum{};
    for (int i = 0; i < n; i++)
    {
        sum += is_balanced(nums[i], compute_digits(nums[i]));
    }
    std::cout << sum << std::endl;

    return 0;
}