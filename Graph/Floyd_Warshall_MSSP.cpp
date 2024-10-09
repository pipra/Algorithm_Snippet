const int N = 505;
int inf = 1e18;
vector<vector<int>> d(N, vector<int>(N, inf));

void ae(int u, int v, int w){
    d[u][v] = min(d[u][v], w);
    d[v][u] = min(d[v][u], w);
}
void gen(){
    for(int k = 1; k<N ; k++)
        for(int i=1; i<N ; i++)
            for(int j=1; j<N ; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
// Firstly set       d[i][i] = 0;
// Multi Source Shortest Path
// n times work == - weighted cycle exist
