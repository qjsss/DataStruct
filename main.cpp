#include <iostream>
#include<algorithm>// using sort to binary search
#include<ctime>//generate random number

#include"SeqList.h"//线性表
#include"List.h"//循环双链表
#include"BinarySearchTree.h"//二叉搜索树
#include"MySort.h"//自己的排序


using namespace std;

void testSeqList();
void testMyList();
void testBinary(int);
void testTree(int);
void testMySort();


signed main()
{
    srand(time(0));
//    testSeqList();
//    testMyList();
    testBinary(10);
    testTree(10);
    testMySort();
}


//检查排序是否出错,
// a[]:数组  n:大小 cmp:排序规则
template <class T>
bool checkAndPrint(int a[],int n,T cmp=MySort<>::compare)
{
    bool flag=1;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
        if(i&&cmp(a[i],a[i-1]))flag=false;
    }
    cout<<'\n';
    if(!flag)cout<<"Sort Erorr!!!\n";
    return flag;
}
template <class T>
bool check(int a[],int n,T cmp=MySort<>::compare)
{
    bool flag=1;
    for(int i=0;i<n;i++)
    {
        if(i&&cmp(a[i],a[i-1]))flag=false;
    }
    if(!flag)cout<<"Sort Erorr!!!\n";
    return flag;
}
void testMySort()
{
    const int N=5000;
    int *a=new int[N];
    cout<<"随机生成的"<<N<<"个数:\n";
    for(int i=0;i<N;i++)a[i]=rand()%(N*1000);
//    for(int i=0;i<N;i++)cout<<a[i]<<" ";
//    cout<<'\n';


    using MySort=MySort<>;
    auto cmp=[](int a,int b){
        return a<b;
    };


    clock_t start=clock();
    MySort::mergeSort(a,N);
    clock_t end=clock();
    cout<<"归并排序花费了: "<<(double)(end-start)/CLOCKS_PER_SEC<<" 秒\n";
    check(a,N,cmp);

    for(int i=0;i<N;i++)a[i]=rand()%(N*1000);
    start=clock();
    MySort::insertSort(a,N);
    end=clock();
    cout<<"插入排序花费了: "<<(double)(end-start)/CLOCKS_PER_SEC<<" 秒\n";
    check(a,N,cmp);

    for(int i=0;i<N;i++)a[i]=rand()%(N*1000);
    start=clock();
    MySort::shellSort(a,N);
    end=clock();
    cout<<"希尔排序花费了: "<<(double)(end-start)/CLOCKS_PER_SEC<<" 秒\n";
    check(a,N,cmp);

    for(int i=0;i<N;i++)a[i]=rand()%(N*1000);
    start=clock();
    MySort::exchangeSort(a,N);
    end=clock();
    cout<<"交换排序花费了: "<<(double)(end-start)/CLOCKS_PER_SEC<<" 秒\n";
    check(a,N,cmp);

    for(int i=0;i<N;i++)a[i]=rand()%(N*1000);
    start=clock();
    MySort::quickSort(a,N);
    end=clock();
    cout<<"快速排序花费了: "<<(double)(end-start)/CLOCKS_PER_SEC<<" 秒\n";
    check(a,N,cmp);

    for(int i=0;i<N;i++)a[i]=rand()%(N*1000);
    start=clock();
    MySort::selectSort(a,N);
    end=clock();
    cout<<"选择排序花费了: "<<(double)(end-start)/CLOCKS_PER_SEC<<" 秒\n";
    check(a,N,cmp);
    delete[] a;

}
void testSeqList()
{
    cout<<"test for Sequence List :\n";
    cout<<"SeqList b:"<<'\n';
    SeqList<int>b;
    for(int i=0;i<5;i++)b.push_back(i+1);
    b[3]=1;
    b.show();
    cout<<"\ntest for insertAfter:\n";
    b.insertAfter(1,51);
    b.insertAfter(5,11);
    b.show();
    cout<<"\ntest for insertBefore:\n";
    b.insertBefore(51,2);
    b.insertBefore(1,33);
    b.show();
    cout<<"\ntest for insert:\n";
    b.insert(1,22);
    b.insert(3,44);
    b.show();
    cout<<"\ntest for deleteByValue:\n";
    b.deleteByValue(44);
    b.deleteByValue(22);
    b.show();
    cout<<"\ntest for deleteByIndex:\n";
    b.deleteByValue(2);
    b.deleteByValue(33);
    b.show();
    cout<<"-------------------------\n";
}
void testMyList()
{
    cout<<"test for Sequence List :\n";
    cout<<"List b:"<<'\n';
    List<int>b;
    cout<<"test for push_back function add 1 2 3 4 5\n";
    for(int i=0;i<5;i++)b.push_back(i+1);
    cout<<b<<endl;
    cout<<"add 1 after 4\n";
    b.insertAfter(4,1);
    cout<<b<<endl;
    cout<<"\ntest for insertAfter function:\n";
    b.insertAfter(1,51);
    b.insertAfter(5,11);
    cout<<"add 51 after 1 , 11 after 5\n";
//    b.show();
    cout<<b<<endl;
    cout<<"\ntest for insertBefore function:\n";
    b.insertBefore(51,2);
    b.insertBefore(1,33);
    cout<<"add 2 before 51, add 33 before 1\n";
    cout<<b<<'\n';
    cout<<"test for push_front function\n";
    cout<<"push 100 101 102 103 front\n";
    b.push_front(100);
    b.push_front(101);
    b.push_front(102);
    b.push_front(103);
    cout<<b<<'\n';
    cout<<"\ntest for eraseOne function:\n";
    cout<<"erase the first 103 and the first 51 in list \n";
    b.eraseOne(103);
    b.eraseOne(51);
    cout<<b<<'\n';
    cout<<"\ntest for twice pop_back function:\n";
    b.pop_back();
    b.pop_back();
    cout<<b<<'\n';
    cout<<"\ntest for twice pop_front function:\n";
    b.pop_front();
    b.pop_front();
    cout<<b<<'\n';
    cout<<"\ntest for modify function:\n";
    cout<<"update into 1 in 1,8 in 8, 3 in 3 ,10 in 10\n";
    b.modify(1,1);
    b.modify(8,8);
    b.modify(3,3);
    b.modify(10,10);
    cout<<b<<'\n';
    cout<<"\ntest for clear function:\n";
    b.clear();
    cout<<b<<'\n';
    cout<<"-------------------------\n";
}

int testSort()
{

    const static int N=1000;
    static int a[N+10];
    static bool st[N*10+10];
    memset(st,0,sizeof st);
    for(int i=1;i<=N;i++)
    {
        int t =(rand()*i)%(N*10);
        while(st[t])
        {
            t=(rand()*i)%(N*10);
        }
        a[i]=t;
        st[t]=1;
    }
    sort(a+1,a+N+1);
    int x=a[rand()%N+1];
    int l=1,r=N;
    int cnt=0;
    while(l<=r)
    {
        cnt++;
        int mid=(l+r)>>1;
        if(a[mid]>x)r=mid-1;
        else if(a[mid]<x)l=mid+1;
        else
        {
            l=mid;
            break;
        }
    }
    if(a[l]==x)
    {
        cout<<"Run success"<<"  "<<cnt<<'\n';
        return cnt;
    }
    else
    {
        cout<<"Run error\n";
        return (int)(-1e5);
    }

}
int testBST()
{
    const static int N=1000;
    BST<int>bst;
    static bool st[N*10+10];
    memset(st,0,sizeof st);
    for(int i=1;i<=N;i++)
    {

        int t =(rand()*i)%(N*10);
        while(st[t])
        {
            t=(rand()*i)%(N*10);
        }
        bst.insert(t);
        st[t]=1;
    }
    int x=(rand())%(N*10);
    while(!st[x])x=(rand())%(N*10);
    int cnt=0;
    BTNode<int>* temp_node=bst.find(bst.root,x,cnt);
    if(temp_node!=NULL&&temp_node->data==x)
    {
        cout<<"Run success"<<"  "<<cnt<<'\n';
        return cnt;
    }
    else
    {
        cout<<"Run error\n";
        return (int)(-1e5);
    }

}
void testBinary(int cnt)
{
    cout<<"Test Binary Search:\n";
    int sum=0;
    for(int i=0;i<cnt;i++)
    {
        sum+=testSort();
    }
    cout<<cnt<<" times Binary Search tot count: "<<sum<<" "<<"  avg count: "<<(double)(sum*1.0/cnt)<<'\n';
}
void testTree(int cnt)
{
    cout<<"Test Binary Search Tree:\n";
    int sum=0;
    for(int i=0;i<cnt;i++)
    {
        sum+=testBST();
    }
    cout<<cnt<<" times Binary Search Tree tot count: "<<sum<<" "<<"  avg count: "<<(double)(sum*1.0/cnt)<<'\n';
}
