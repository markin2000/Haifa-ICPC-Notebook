#define inf 1e9

struct segmentTree{
	vector<int> tree;
	int size;
	segmentTree(int n){
		for(size = 2;n/=2;size+=size);
		tree.resize(size+size,inf);
	}
	void fix(int i){
		tree[i] = min(tree[i+i],tree[i+i+1]);
	}
	void update(int x,int v){
		for(tree[x+=size] = v;x/=2;fix(x));
	}
	int query(int a,int b){
		int res = inf;
		for(a += size,b+=size;a<b;a/=2,b/=2){
			if(a % 2 == 1) res = min(res,tree[a++]);
			if(b % 2 == 0) res = min(res,tree[b--]);
		}
		return (a==b? min(res,tree[a]) : res);
	}
};
