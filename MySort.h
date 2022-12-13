#ifndef MYSORT_H
#define MYSORT_H
#include<iostream>
template <class T=int,class R=bool(T,T)>
class MySort{
public:
    //Ĭ�ϱȽ���
    static bool compare(T a,T b)
    {
        return a<b;
    }
    //����
    static void swap(T &a,T &b)
    {
        T t=a;
        a=b;
        b=t;
    }
    //��������  ʱ�临�Ӷ�n^2
    static void insertSort(T a[],int n,R cmp=compare)
    {
        for(int i=1;i<n;i++)
        {
            int t=a[i];
            int j=i-1;
            while(j>=0&&cmp(t,a[j]))
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=t;
        }
    }
    //ϣ������  ʱ�临�Ӷ�nlogn
    static void shellSort(T a[],int n,R cmp=compare)
    {
        for(int d=n>>1;d>=1;d>>=1)
        {
            for(int i=d;i<n;i++)
            {
                int t=a[i];
                int j=i-d;
                while(j>=0&&cmp(t,a[j]))
                {
                    a[j+d]=a[j];
                    j-=d;
                }
                a[j+d]=t;
            }
        }
    }
    //��������  ʱ�临�Ӷ�n^2
    static void exchangeSort(T a[],int n,R cmp=compare)
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=n-1;j>i;j--)
                if(cmp(a[j],a[j-1]))
                    swap(a[j],a[j-1]);
        }
    }
    //��������  ʱ�临�Ӷ�nlogn
    static void quickSort(T a[],int l,int r,R cmp=compare)
    {
        if(l>=r)return ;
        int i=l,j=r;
        int t=a[i];
        while(i<j)
        {
            while(i<j&&(cmp(t,a[j])||t==a[j]))
                j--;
            a[i]=a[j];
            while(i<j&&(cmp(a[i],t)||t==a[i]))
                i++;
            a[j]=a[i];
        }
        a[i]=t;
        quickSort(a,l,i-1,cmp);
        quickSort(a,i+1,r,cmp);
    }
    //������������������ͳһ������������ӿ�
    static void quickSort(T a[],int n,R cmp=compare)
    {
        quickSort(a,0,n-1,cmp);
    }
    //ѡ������ ʱ�临�Ӷ�n^2
    static void selectSort(T a[],int n,R cmp=compare)
    {
        for(int i=0;i<n;i++)
        {
            int t=i;
            for(int j=i+1;j<n;j++)
                t=(cmp(a[t],a[j])?t:j);
            if(t!=i)
                swap(a[t],a[i]);
        }
    }
    //�鲢���� ʱ�临�Ӷ�nlogn
    static void mergeSort(T a[],int l,int r,T temp[],R cmp=compare)
    {
        if(l>=r)return ;
        int mid=(l+r)>>1;
        mergeSort(a,l,mid,temp,cmp);
        mergeSort(a,mid+1,r,temp,cmp);
        int temp_index=0;
        int i=l,j=mid+1;
        while(i<=mid&&j<=r)
        {
            if(cmp(a[i],a[j]))temp[temp_index++]=a[i++];
            else temp[temp_index++]=a[j++];
        }
        while(i<=mid)temp[temp_index++]=a[i++];
        while(j<=r)temp[temp_index++]=a[j++];
        temp_index=0;
        for(i=l;i<=r;i++)
            a[i]=temp[temp_index++];
    }
    //�鲢����������������ͳһ������������ӿ�
    static void mergeSort(T a[],int n,R cmp=compare)
    {
        T *temp=new T[n];
        mergeSort(a,0,n-1,temp,cmp);
        delete[] temp;
    }
};

#endif // MYSORT_H
