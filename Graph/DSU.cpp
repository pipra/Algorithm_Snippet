const int N = 2e5 + 5;
vector<int> sz(N), parent(N);
int find(int node){
	if(node == parent[node]) return node;
	return parent[node] = find(parent[node]);
}
void Union(int u, int v){
	u = find(u); v = find(v);
	if(u != v){
		if(sz[u] < sz[v])	swap(u, v);
		sz[u] += sz[v];
		parent[v] = u;
	}
}
// First set i=0,1,2...N  parent[i] = i
