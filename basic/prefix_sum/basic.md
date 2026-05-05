```cpp
std::vector<int> prefix(n);
for(int i = 0; i < n; i++){
    if(i) prefix[i] = prefix[i - 1];
    prefix[i] += arr[i];
}
```

- 可变形为前缀积、前缀异或等泛前缀和(满足结合律)
  `xor[L, R) = prefix[R] ^ prefix[L -1]`

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
