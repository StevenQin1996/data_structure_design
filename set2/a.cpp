#include <cstddef>
#include <iostream>
#include <cassert>
using namespace std;

template <class T>
struct Set {
    T* data;
    int size;        
    int count;
};

template <class T>
void initialize(Set<T>& S)
{
    
    S.size = 2;
    S.data = new T[S.size];
    S.count = 0;
}

template <class T>
void destroy(Set<T>& S)
{
    
    delete[] S.data;
    S.data = NULL;
    S.size = 2;
    S.count = 0;
}

template <class T>
bool isEmpty(Set<T> S)
{
    if(S.count==0)
        return true;
    else
        return false;
}

template <class T>
void insert(Set<T>& S, T value)
{
    if (S.count==0)
    {
        S.data[S.count]=value;
        S.count++;
    }
        
    else
    {
        int flag=0;
        for (int n=0; n<S.count; n++)
        {
            if(S.data[n]==value)
            {
                flag=1;
                //cout<<flag;
                break;
            }
        }
        if (flag==0)
            {
                if (S.count==S.size)
                {
                   T* stupid = new T[S.size*2];
                   S.size *= 2;
                   for (int n=0; n<S.count; n++)
                    {
                        stupid[n]=S.data[n];
                    }
                    
                    delete [] S.data;
                    S.data = stupid;
                }

                S.data[S.count]=value;
                S.count++;
            }
    }
}

template <class T>
bool contains(Set<T>S, T value)
{
    for (int n=0; n<S.count;n++)
    {
        if (S.data[n]==value)
            return true;
    }
    return false;
}

template <class T>
void remove(Set<T>& S, T value)
{
    for (int n=0; n<S.count;n++)
    {
        if (S.data[n]==value)
        {
            S.data[n]=S.data[S.count-1];
            S.count--;
            break;
        }
   }
}

template <class T>
int  getSize(Set<T> S)
{
    return S.count;
}    

template <class T>
Set<T> operator&&(Set<T> A,Set<T> B)  // intersection
{
   Set<T> C;
   
    for(int a=0;a<A.count;a++)
    {
        for(int b=0;b<B.count;b++)
        {
            if(A.data[a]==B.data[b])
                {
                    out<<A.data[a];
                    int aldo=a;
                }
        }
    }

    for(int a=aldo;a<A.count;a++)
    {
        for(int b=0;b<B.count;b++)
        {
            if(A.data[a]==B.data[b])
                {
                    cout<<",";
                    out<<A.data[a];
                }
        }
    }
    cout<<"}"<<endl;
    return out;
}

//Set<T> operator||(Set<T>,Set<T>);  // union
//Set<T> operator-(Set<T>,Set<T>);   // difference


int main()
{
    Set<int> A;
    Set<int> B;
    
    initialize(A);
    initialize(B);
    
    insert(A,1);
    insert(A,2);
    insert(A,3);
    insert(A,4);
    insert(A,5);
    
    insert(B,2);
    insert(B,4);
    insert(B,6);
    insert(B,8);
    insert(B,10);
    
    Set<int> C = A && B;
    // What assertions can you make?

 // Set<int> D = A || B;
    // What assertions can you make?
    
   // Set<int> E = A - B;
    // What assertions can you make?
    
  //  Set<int> F = B - A;
    // What assertions can you make?
    
    destroy(A);
    destroy(B);
    destroy(C);
    //destroy(D);
    //destroy(E);
    //destroy(F);
}