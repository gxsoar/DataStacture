template <typename T> void permute( vector<T>& v) {
    for (int i = v.size(); i > 0 ; i--) {
        swap( v[i - 1], v[rand() % i]);
    }
}