// Strictly increasing or not?

vector<int> find_LIS(vector<int> &A){
    vector<int> best,ind(A.size(),-1);
    int last = 0;
    for(int i = 0;i<A.size();i++){
        int low = 0,high = best.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(A[best[mid]]<=A[i])
                ind[i] = mid,low = mid+1;
            else
                high = mid-1;
        }
        int p = ind[i]; if(ind[i] != -1) ind[i] = best[ind[i]];
        if(p+1 == best.size())
            best.push_back(i),last = i;
        else
            best[p+1] = i;
    }
    stack<int> res;
    while(last != -1)
        res.push(A[last]),last = ind[last];
    vector<int> ans;
    while(!res.empty())
        ans.push_back(res.top()),res.pop();
    return ans;
}
