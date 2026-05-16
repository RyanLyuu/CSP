## 前缀和

- 处理反复计算区间和的问题

```cpp
std::vector<int> prefix(n);
for(int i = 0; i < n; i++){
    if(i) prefix[i] = prefix[i - 1];
    prefix[i] += arr[i];
}
```

- 可变形为前缀积、前缀异或等泛前缀和(满足结合律)
  `xor[L, R) = prefix[R] ^ prefix[L -1]`

## 差分

- 处理反复增减区间值的问题

```cpp
for(int i = 0; i < n; --i){
    if(i == 0) d[i] = a[i];
    else d[i] = a[i] - a[i - 1];
}
```

- 增减原数组区间的值时等价于加减差分数组头尾两个元素， 如果需要原数组，就在差分数组上修改，改完再做一次前缀和
  a[l, r] + k <=> d[l] + k, d[r + 1] - k

- 快速幂:

```cpp
long long power(long long a, long long b, long long mod){
    long long res = 1;
    a %= mod;
    while(b > 0){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >> = 1;
    }
    return res;
}
```
