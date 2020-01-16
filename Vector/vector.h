typedef int Rank;

#define DEFAULT_CAPACITY 3  //vector的初始化容量

template <typename T> class vector {
protected:
    Rank _size; int _capacity; T* _elem; //规模，容量，数据区
    void copyFrom(T const* A, Rank lo, Rank hi); //复制数组A[lo, hi]
    void expand();  //扩容
    void shrink();  //缩容
    bool bubble( Rank lo, Rank hi); //扫描交换
    void bubbleSort(Rank lo, Rank hi);  //冒泡排序算法
    Rank max( Rank li, Rank ho);    //查找最大元素
    void selectionSort(Rank li, Rank ho);   //选择排序
    void merge(Rank li, Rank ho);   //归并排序
    Rank partition(Rank li, Rank ho);   //轴点构造算法
    void quickSort( Rank li, Rank ho);  //快速排序
    void heapSort( Rank li, Rank ho);   //堆排序
public:
    //构造函数
    vector (int c = DEFAULT_CAPACITY, int s = 0, T v = 0)   //容量为c,规模为s,所有元素初始化为v
    { _elem = new T[_capacity = c]; for( _size = 0; _size < s; _elem[_size++] = v); }
    vector (T const* A, Rank n) { copyFrom(A, 0, N); }  //数组整体复制
    vector (T const* A, Rank lo, Rank hi) {copyFrom(A, lo, hi); }   //区间复制
    vector (vector<T> const& v) {copyFrom(v._elem, 0, v._size); }   //向量整体复制
    vector (vector<T> const& v, Rank lo, Rank hi) { copyFrom( v._elem, lo, hi); }   //数组区间复制
    //析构函数
    ~vector() { delete [] _elem; }  //释放内部空间
    //只读访问接口
    Rank size() const { return _size; }     //返回向量规模
    bool empty() const { return !_size; }   //判空函数
    int disordered() const; //判断向量是否已经排序
    Rank find( T const& e) const { return find( e, 0, _size); } //无需向量整体查找
    Rand find( T const& e, Rank lo, Rank hi) const;
    Rand search( T const& e) const; //有序向量整体查找
    { reutrn ( 0 >= _size) ? -1 : search ( e, 0, _size); }
    Rank search( T const& e, Rank lo, Rank hi) const;   //有序向量区间查找
    //可写访问接口
    T& operator [] ( Rank r) const; //重载下标操作符
    vector<T> & operator= ( vector<T> const& );    //重载赋值操作符
    T remove( Rank r);  //删除秩为r的元素
    int remove( Rank lo, Rank hi);
    Rank insert( Rank r, T const& e); //插入元素
    Rank insert( T const& e ) { return insert( _size, e); } //作为莫元素插入
    void sort( Rank lo, Rank hi);   //对[lo, hi]排序
    void sort() { sort(0, _size); } //整体排序
    void unsort( Rank lo, Rank hi); //[lo, hi]治乱
    void unsort() { unsort(0, _size); }
    int deduplicate();  //去重
    int uniquify(); //有序去重
    //遍历
    void traverse( void (* ) ( T& ));   //遍历
    template <typename VST> void traverse( VST& );
};

#include "vector_implementation.h"