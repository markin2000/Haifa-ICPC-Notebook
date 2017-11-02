//Not Tested

vector<int> parent;

void init(int n){
	parent.resize(n);
	for(int i = 0;i<n;i++) parent[i] = i;
}

int find(int u){
	return u == parent[u] ? u : parent[u] = find(parent[u]);
}

void uni(int u, int v){
	parent[find(u)] = find(v);
}