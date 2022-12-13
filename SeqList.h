#include<iostream>
#include<cstring>
using namespace std;    
#define NotFound NULL
#define NotFoundIndex -1
typedef size_t size_type;
template<class T>
class SeqList{
private:
    T *start;
    T *finish;
    T *end_of_storage;
public:
    SeqList();
    SeqList(size_type size);
    T* begin(){return start;};
    T* end(){return finish;}
    size_type size(){return size_type(end()-begin());};
    size_type capacity(){return size_type(end_of_storage-begin());};
    T& operator[](size_type index);
    void push_back(const T& x);
    //1.插入
    void insertAfter(const T& target,const T& x);
    void insertBefore(const T& target,const T& x);
    void insert(const T& index,const T& x);
    //2.删除
    void deleteByValue(const T& value);
    void deleteByIndex(size_type index);
    //3.显示
    void show();
    //4.查找
    T* getByValue(const T& value);
    //5.定位
    size_type getIndex(const T& value);
    //6.更新
    void set(size_type index,const T& x){*(start+index)=x;}
};


template<class T>
SeqList<T>::SeqList()
{   
    start=finish=end_of_storage=NULL;
}
template<class T>
SeqList<T>::SeqList(size_type size)
{   
    start=new T[size*sizeof(T)];
    finish=start;
    end_of_storage=start+size;
}
template<class T>
T& SeqList<T>::operator[](size_type index)
{
    return *(start+index);
}
template<class T>
void SeqList<T>::push_back(const T& x)
{
    if(finish!=end_of_storage)
    {
        *finish=x;
        finish++;
    }
    else 
    {
        const size_type old_size=size();
        const size_type len=old_size!=0?old_size*2:1;

        T* new_start=new T[len];
        T* new_finish=new_start+size();
        T* new_storage=new_start+len;
        
        memcpy(new_start,start,sizeof(T)*size());
        delete[] start;
        
        start=new_start;
        finish=new_finish;
        end_of_storage=new_storage;
        
        push_back(x);
    }
}
//3.显示
template<class T>
void SeqList<T>::show()
{
    cout<<"{"<<'\n';
    cout<<"  size: "<<size()<<'\n';
    cout<<"  capacity: "<<capacity()<<'\n';
    for(T* s=begin();s!=end();s++)
        cout<<"  "<<*s<<'\n';
    cout<<"}"<<'\n';
};
//4.查找
template<class T>
T* SeqList<T>::getByValue(const T& value)
{
    for(T* s=begin();s!=end();s++)
    {
        if(*s==value)return s;
    }
    return NotFound;
}
//5.定位
template<class T>
size_type SeqList<T>::getIndex(const T& value)
{
    T* reference=getByValue(value);
    if(reference!=NotFound)
        return size_type(reference-start);
    return size_type(NotFoundIndex);
}
//1.插入
//tip:没有对插入的成功与否进行返回.
//    插入目标无重复且插入目标存在的情况下可以保证插入成功.
template<class T>
void SeqList<T>::insertAfter(const T& target,const T& x)
{
    T* reference=getByValue(target);
    if(reference!=end()-1)
    {
        T temp=*(end()-1);
        for(T* e=end()-1;e!=reference+1;e--)
            *e=*(e-1);
        *(reference+1)=x;
        push_back(temp);
    }
    else push_back(x);
}
template<class T>
void SeqList<T>::insertBefore(const T& target,const T& x)
{
    T* reference=getByValue(target);
    T temp=*(end()-1);
    T* e=end()-1;
    for(;e!=reference;e--)
        *e=*(e-1);
    *e=x;
    push_back(temp);
}
template<class T>
void SeqList<T>::insert(const T& index,const T& x)
{
    insertBefore(*(start+index-1),x);
}

//2.删除
template<class T>
void SeqList<T>::deleteByValue(const T& value)
{
    for(T* s=begin();s!=end();s++)
    {
        if(*s==value)
        {
            while(s!=end()-1)
            {
                *s=*(s+1);
                s++;
            }
            finish--;
            return ;
        }
    }
}
template<class T>
void SeqList<T>::deleteByIndex(size_type index)
{
    deleteByValue(*(start+index-1));
}


