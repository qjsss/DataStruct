#ifndef LIST_H
#define LIST_H


#include<iostream>

template<class T>
struct ListNode{
    T data;
    ListNode<T>* prev;
    ListNode<T>* next;
    T& value(){return data;};
};

typedef size_t size_type;


template<class T>
class List{
public:
    typedef ListNode<T>* ptr_node;
private:
    ptr_node node;
    T& operator[](size_type index)
    {
        for(auto s=begin();s!=end();s=s->next)
        {
            index--;
            if(index==0)return s->value();
        }
    }
public:
    List()
    {
        node=new ListNode<T>();
        node->next=node;
        node->prev=node;
    }
    ptr_node begin(){return node->next;};
    ptr_node end(){return node;};
    bool empty(){return node->next==node;};
    size_type size()
    {
        size_type count=0;
        for(ptr_node s=begin();s!=end();s=s->next)
            count++;
        return count;
    }
    //4.查找
    ptr_node find(const T& x)
    {
        ptr_node s=begin();
        for(;s!=end();s=s->next)
            if(x==s->value())break;
        return s;
    }
    //1.插入
    #pragma region 插入{
    //插入某个节点的后面
        ptr_node insert(ptr_node position,const T& x)
        {
            ptr_node temp=new ListNode<T>();
            temp->value()=x;
            ptr_node t=position->next;
            position->next=temp;
            temp->next=t;
            temp->prev=position;
            t->prev=temp;
            return temp;
        }
        ptr_node insertBefore(const T& target,const T&x)
        {
            ptr_node t=find(target);
            if(t!=end())
                return insert(t->prev,x);
            else
                return push_back(x);
        }
        ptr_node insertAfter(const T& target,const T&x)
        {
            ptr_node t=find(target);
            if(t!=end())
                return insert(t,x);
            else
                return push_back(x);
        }
        ptr_node push_back(const T&x)
        {
            return insert(end()->prev,x);
        }
        ptr_node push_front(const T&x)
        {
            return insert(node,x);
        }
    #pragma endregion}
    //2.删除
    #pragma region 删除{
        ptr_node erase(ptr_node position)
        {
            ptr_node next_node=position->next;
            ptr_node prev_node=position->prev;
            prev_node->next=next_node;
            next_node->prev=prev_node;
            delete position;
            return next_node;
        }
        //删除某个数 只删1次
        void eraseOne(const T&x)
        {
            ptr_node t=find(x);
            if(t!=end())erase(t);
        }
//        void erase(const T&x)
//        {
//            for(ptr_node s=begin();s!=end();s=s->next){
//                if(x==s->value()){
//                    ptr_node prev_node=s->prev;

//                   ptr_node next_node=s->next;
//                    prev_node->next=next_node;
//                   next_node->prev=prev_node;
//                    delete s;

//                    //erase function can replace by the above notes
//                    erase(s);
//                    s=prev_node;
//                }
//            }
//        }
        //删除所有数
        void clear()
        {
            ptr_node s=begin();
            while(s!=end()){
                ptr_node t=s;
                s=s->next;
                delete t;
            }
            node->next=node;
            node->prev=node;
        }
        void pop_front()
        {
            erase(begin());
        }
        void pop_back()
        {
            erase(end()->prev);
        }
    #pragma endregion}

    //6.更新
    bool modify(size_type index,const T&x)
    {
        if(index>size())return false;
        (*this)[index]=x;
        return true;
    }

    //3.显示
    void show()
    {
        std::cout<<*this;
    }
    template<typename R>
    friend std::ostream& operator<<(std::ostream& out,List<R> & list);
};
template<typename R>
std::ostream& operator<<(std::ostream& out,List<R> & list)
{
    out<<"{\n";
    out<<"   size: "<<list.size()<<"\n";
    for(ListNode<R>* s=list.begin();s!=list.end();s=s->next)out<<"  "<<s->value();
    out<<"\n}\n";
    return out;
}
#endif // LIST_H
