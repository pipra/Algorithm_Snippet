const int N = 2e5 + 5;
const int inf = 1e18;

vector<tuple<int,int,int>> edges;
vector<int> d, cycle;
void init(int _N){
    N = _N;
    d.resize(N, inf);
}
void ae(int u, int v, int w){ edges.pb({u, v, w}); }
void gen(int _N, int s){
    d[s] = 0;
    for(int i=1 ; i<_N ; i++){
        for(auto &e: edges){
            int u, v, w;    tie(u, v, w) = e;
            if(d[u] == inf) continue;

            if(d[v] > (d[u] + w)){
                d[v] = d[u] + w;
            }
        }
    }
    for(auto &e: edges){
        int u, v, w;  tie(u, v, w) = e;
        if(d[u] == inf) continue;
        
        if(d[v] > (d[u] + w)){
            d[v] = d[u] + w;
            cycle.pb(u);
        }
    }
}
