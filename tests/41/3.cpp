#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = (1LL << 60);

struct FreeSeg {
    ll len, l, r;

    bool operator<(const FreeSeg& other) const {
        if (len != other.len) return len < other.len;
        return l < other.l;
    }
};

struct QueueInfo {
    ll l, r;
    ll pos; // 下一次 send 要写的位置
};

set<FreeSeg> byLen;
map<ll, ll> byLeft;

vector<vector<QueueInfo>> proc;

ll getLen(ll l, ll r) {
    return r - l + 1;
}

void addFree(ll l, ll r) {
    if (l > r) return;
    byLeft[l] = r;
    byLen.insert({getLen(l, r), l, r});
}

void removeFree(ll l, ll r) {
    byLeft.erase(l);
    byLen.erase({getLen(l, r), l, r});
}

ll allocate(ll L) {
    auto it = byLen.lower_bound({L, -1, -1});

    auto cur = *it;
    byLen.erase(it);
    byLeft.erase(cur.l);

    ll start = cur.l;
    ll end = cur.l + L - 1;

    if (end + 1 <= cur.r) {
        addFree(end + 1, cur.r);
    }

    return start;
}

void release(ll l, ll r) {
    ll nl = l, nr = r;

    auto it = byLeft.lower_bound(l);

    // 合并左边
    if (it != byLeft.begin()) {
        auto pre = prev(it);
        if (pre->second + 1 == l) {
            nl = pre->first;
            removeFree(pre->first, pre->second);
        }
    }

    // 合并右边
    it = byLeft.lower_bound(l);
    if (it != byLeft.end() && r + 1 == it->first) {
        nr = it->second;
        removeFree(it->first, it->second);
    }

    addFree(nl, nr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    proc.resize(n + 1);

    // 初始整段内存都是空闲的
    addFree(0, INF);

    while (q--) {
        string op;
        cin >> op;

        if (op == "new") {
            int p;
            ll L;
            cin >> p >> L;

            ll a = allocate(L);
            ll b = a + L - 1;

            proc[p].push_back({a, b, a});

            cout << a << '\n';
        }
        else if (op == "send") {
            int p;
            cin >> p;

            ll sum = 0;

            for (auto& que : proc[p]) {
                sum += que.pos;

                que.pos++;
                if (que.pos > que.r) {
                    que.pos = que.l;
                }
            }

            cout << sum << '\n';
        }
        else if (op == "delete") {
            int p, i;
            cin >> p >> i;

            i--; // 转成 0 下标

            QueueInfo que = proc[p][i];

            release(que.l, que.r);

            proc[p].erase(proc[p].begin() + i);
        }
    }

    return 0;
}