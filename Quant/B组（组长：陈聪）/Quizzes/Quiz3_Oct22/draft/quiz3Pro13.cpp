int FindUniq(int vector<int> &vec) {
    res = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        res ^= vec[i];
    }
    return res;
}