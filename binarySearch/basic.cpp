#include <bits/stdc++.h>

int lower(std::vector<int>& a, int target){
    int lo = 0, hi = a.size();
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(a[mid] < target) lo = mid + 1;
        else                hi = mid;
    }
    return lo;
}

int upper(std::vector<int>& a, int target){
    int l = 0, r = a.size();
    while(l < r){
        int mid = l + (r - l)/2;
        if(a[mid] <= target)  l = mid + 1;
        else                  r = mid;
    }
    return l;
}


// 求满足条件的最小值
bool check(int mid) { return true;}; //判断mid是否可行, 小了false, 大了true

int binary_search(std::vector<int>& a, int target){
    int l = 0, r = a.size();
    while(l < r){
        int mid = l + (r - l)/2;
        if(check(mid)) r = mid;
        else           l = mid + 1;
    }
}

//答案一定在[l, r)中, 所以不断缩小[l, r), 直到l = r
//lowerbound 找第一次出现的位置, upperbound找最后一次出现的位置的下一位