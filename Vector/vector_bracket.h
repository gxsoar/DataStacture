
template <typename T>
vector<T>& vector<T>::operator=(vector<T> const& v) {
    if (_elem) delete[] _elem;
    copyFrom ( v._elem, 0, v.size() );
    return *this;
}

template <typename T> T& vector<T> :: operator[] (Rank r) const { return _elem[r];}
