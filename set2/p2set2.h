#include <cstddef>
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
Set<T> operator&&(Set<T> A,Set<T> B) // intersection
{
    Set<T> C;
    initialize(C);
    for(int a=0;a<A.count;a++)
    {
        for(int b=0;b<B.count;b++)
        {
            if(A.data[a]==B.data[b])
                {
                   insert(C,A.data[a]); 
                }
        }
    }
    return C;
}

template <class T>
Set<T> operator||(Set<T> A,Set<T> B)  // union
{
    Set<T> D;
    initialize(D);
    for(int a=0; a<A.count; a++)
    {
       insert(D,A.data[a]);
    }

    for(int b=0; b<B.count;b++)
    {
        int check=0;
        for(int d=0;d<A.count;d++)
        {
            if(B.data[b]==D.data[d])
                {
                    check=1;
                    break;
                }
        }
        if (check==0)
        {
            insert(D,B.data[b]);
         }
    }
    return D;
}

template <class T>
Set<T> operator-(Set<T> A,Set<T> B)
{
    Set<T> E;
    initialize(E);
    for(int a=0;a<A.count;a++)
    {
        int check=0;
        for (int b=0;b<B.count;b++)
        {
            
            if(A.data[a]==B.data[b])
                {
                    check=1;
                    break;
                }
        }
        if (check==0)
        {
            insert(E,A.data[a]);
        }
    }
    return E;
}   // difference