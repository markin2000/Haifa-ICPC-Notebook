vector<int> LIS(vector<int> arr, bool strict = true){
    static const int inf = 2e9;
    vector<int> best(arr.size(), arr.size());
    arr.push_back(inf);
    vector<int> back(arr.size(), -1);

    #define line(func) j = func(best.begin(), best.end(), i, [&arr](int a, int b){return arr[a] < arr[b];}) - best.begin()

    loop(i, 0, arr.size() - 1){
        int j;
        if (strict) line(lower_bound);
        else line(upper_bound);
        if (j != 0) back[i] = best[j - 1];
        best[j] = i;
    }

    #undef line

    int pos = 0;
    while (pos < int(best.size()) - 1 && best[pos + 1] != int(arr.size()) - 1) ++pos;
    pos = best[pos];
    vector<int> ret;
    while (pos != -1) ret.push_back(pos), pos = back[pos];
    reverse(ret.begin(), ret.end());
    return ret;
}
