const int mod = 2;

inline int mul(int a, int b){
    return (ll(a) * ll(b)) % mod;
}

int power(int a, int b){
    if (b == 0) return 1;
    int c = power(a, b / 2);
    return mul(mul(c, c), (b % 2 == 0 ? 1 : a));
}

inline int inv(int x){
    return power(x, mod - 2);
}

vector<int> operator-(vector<int> arr1, const vector<int>& arr2){
    loop(i, 0, arr1.size()) arr1[i] = (ll(arr1[i]) - ll(arr2[i]) + mod) % mod;
    return arr1;
}

vector<int> operator*(int k, vector<int> arr){
    for (auto& x : arr) x = (ll(x) * ll(k)) % mod;
    return arr;
}

#define N 2501
#define bool_array bitset<N>
const bool_array zero;

template<typename T>
void gauss(vector<T>& arr);

bool_array operator-(const bool_array& arr1, const bool_array& arr2){
    return arr1 ^ arr2;
}

bool_array operator*(int k, const bool_array& arr){
    return k == 1 ? arr : zero;
}

bool_array vector_int_to_bool_array(const vector<int>& arr){
    bool_array ret;
    loop(i, 0, arr.size()) ret[i] = arr[i];
    return ret;
}

vector<int> bool_array_to_vector_int(const bool_array& arr, int n){
    vector<int> ret(n);
    loop(i, 0, ret.size()) ret[i] = arr[i];
    return ret;
}

void gauss_com(vector<vector<int>>& arr){
    int m = arr.front().size();
    vector<bool_array> com(arr.size());
    loop(i, 0, com.size()) com[i] = vector_int_to_bool_array(arr[i]);
    gauss(com);
    arr.resize(com.size());
    loop(i, 0, com.size()) arr[i] = bool_array_to_vector_int(com[i], m);
}

template<typename T>
void gauss(vector<T>& arr){
    int row = 0;
    if (arr.size() == 0) return;
    loop(j, 0, arr[row].size()){
        int pos = -1;
        loop(k, row, arr.size()) if (arr[k][j] != 0){
            pos = k;
            break;
        }
        if (pos == -1) continue;
        swap(arr[pos], arr[row]);
        loop(k, row + 1, arr.size()) if (arr[k][j] != 0) arr[k] = arr[row][j] * arr[k] - arr[k][j] * arr[row];
        if (++row == (int)arr.size()) break;
    }

    while (arr.size() != 0){
        int b = true;
        loop(j, 0, arr.back().size()) if (arr.back()[j] != 0){
            b = false;
            break;
        }
        if (!b) break;
        arr.pop_back();
    }
    int col = -1;
    loop(i, 0, arr.size()){
        while (arr[i][++col] == 0);
        loop(k, 0, i) if (arr[k][col] != 0) arr[k] = arr[i][col] * arr[k] - arr[k][col] * arr[i];
    }
}
