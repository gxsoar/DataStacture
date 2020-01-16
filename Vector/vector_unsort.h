template <typename T> void vector<T> :: unsort (Rank lo, Rank hi) {
    T* v = _elem + lo;
    for ( Rank i = hi - lo; i > 0 ; i--) {
        swap(v[i - 1], v[rand() % i]);
    }
}