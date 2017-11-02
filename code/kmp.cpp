
vector<int> kmp(string T,string P){
	int n = T.size();
	int m = P.size();
	vector<int> prefix(m,-1);
        int j = -1;
        for(int i = 1;i<m;i++){
            while(j != -1 && P[i] != P[j+1])
                j = prefix[j];
            if(P[i] == P[j+1])
                j++;
            prefix[i] = j;
        }
        j = -1;
	vector<int> pos;
        for(int i = 0;i<n;i++){
            while(j!=-1 && T[i] != P[j+1])
                j = prefix[j];
            if(T[i] == P[j+1])
                j++;
            if(j == m-1)
                pos.push_back(i),j = prefix[j];
        }
	return pos;
}
