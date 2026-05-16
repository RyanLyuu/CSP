- bfs

```cpp
std::vector<int> g;
std::vector<int> dist;

void bfs(int s){
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
```
