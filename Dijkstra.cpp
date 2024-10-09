const int N = 2e5 + 5;
const int inf = 1e18;
vector<vector<ii>> g(N);
vector<int> p(N), d(N, inf);

void generator(int s){
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    d[s] = 0;
    while(!q.empty()){
        auto [cost, u] = q.top(); q.pop();
        if(cost > d[u]) continue;

        for(auto &[v, w] : g[u]){
            if(d[v] > (d[u] + w)){
                d[v] = d[u] + w;    
                p[v] = u;
                q.push({d[v] , v});
            }
        }
     }
}
vector<int> restore_path(int s, int e){
    vector<int> path;
    for(int v=e ; v!=s; v = p[v])
        path.pb(v);
    path.pb(s);
    reverse(all(path));
    return path;
}
