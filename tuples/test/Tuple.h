
#include <iostream>//still have 3 allocation actived
#include <cstddef>
#include <cmath>
//#include <array>
//#define DEBUG 1
// + * int, *tuple, *=, *=, +=
template <class T> class Tuple;

template <class T> Tuple<T> operator+(const Tuple<T>& t1, const Tuple<T>& other);//these arent member function. so it cant not be const
// T* result = new T[t1.size()]; T* result = new T[other.size()];
template <class T> T operator*(const Tuple<T>& t1, const Tuple<T>& other);
//T* result = new T[t1.size()]; T* result = new T[other.size()];
template <class T> Tuple<T> operator*(const Tuple<T>& t1, const T& n);
//T* result = new T[t1.size()];
//template <class T> Tuple<T> operator*=(Tuple<T>& t1, const Tuple<T>& other);
template <class T> Tuple<T> operator*=(Tuple<T>& t1, const T& n);
template <class T> Tuple<T> operator+=(Tuple<T>& t1, const Tuple<T>& other);

template <class T> class TupleData
{
    private:
        T* items;
        int count;
        int uses;
     
    public:
        TupleData(int s);//    items = new T[s];
        TupleData(const TupleData <T>& other);//items = new T[count];
        TupleData(const T* array, int n);
        ~TupleData(){if(items) delete [] items;}

        T& operator[](int i){return items[i];}
        const T& operator[](int i)const{return items[i];}
        int size()const{return count;}
        T magnitude();
        int useCount()const{return uses;}
        void incrementUse(){uses++;}
        void decrementUse(){uses--; if(uses == 0) delete this;}
        //T* makeCopy(int length, const T* other);

};

template <class T> class Tuple
{
    public:
        #ifdef DEBUG
            TupleData<T> &implementation() const
            {
                return *data;
            }
        #endif
        

        Tuple(int i){data = new TupleData<T>(i);}//constructor
        Tuple(T x[], int n){data = new TupleData<T>(x,n); }//x is a array with size n, make a new tuple data and hold the array
        Tuple(Tuple const &other){data = other.data; data->incrementUse();}//create other tuple and copy the data from other tupledata
        ~Tuple(){data->decrementUse();}//deconstructor. 

        void TD(TupleData<T> *t){ data=t;}//TD getter
        TupleData<T>* TD()const{return data;}//TD setter

        int size()const{return data->size();}//return size
        T magnitude()const{return data-> magnitude();}//return magnitude

        T& operator[](int i);//overloads the []
        // TupleData<T> *temp = new TupleData<T>(*data);
        const T& operator[](int i)const;//

        Tuple& operator = (Tuple const& other);
        bool operator == (const Tuple& t)const;
        bool operator != (const Tuple& t)const{return !(*this == t);}
        
            
    private:
        TupleData<T>* data;    
};

template <class T> TupleData<T>::TupleData(const T* array, int n)
{
    count = n;
    items = new T[n];
    for(int x=0; x<n; x++)
    {
        items[x] = array[x];
    }
}
template <class T> TupleData<T>::TupleData(int s)
{
    count = s; uses =1;
    items = new T[s];
    for (int i =0; i<s; i++)
    {
        items[i] = 0;
    }
}//checked

template <class T> TupleData<T>::TupleData(const TupleData <T>& other)//make a new TD and copy all the data from other.
{
    count = other.size();
    uses = 1;
    items = new T[count];
    for (int i =0; i<count; i++)
    {
        items[i] = other[i];
    }
}//checked

template<class T> T TupleData<T>::magnitude()
{
    T answer =0;
    for (int i=0; i<size(); i++)
    {
        answer += pow((T)items[i],2);
    }

    return sqrt(answer);
}

template <class T> T& Tuple<T>::operator[](int i)
{
    static T name = T();
    if(i>=0 && i< this->size())
    {
        TupleData<T> *temp = new TupleData<T>(*data);//creating a new tupledata pointer copies the data
        data -> decrementUse();
        data = temp;
        return (*data)[i];
    }
    return name;
}//checked

template <class T> const T& Tuple<T>:: operator[](int i)const
{
    static T name = T();
    if (i>=0 && i < data->size())
    {
        return(*data)[i];
    }
    return name;
}

template<class T> Tuple<T>& Tuple<T>:: operator = (Tuple const& other)
{
    data -> decrementUse();
    this -> data = other.data;
    data -> incrementUse();
    return *this;
}

template<class T> bool Tuple<T>::operator == (const Tuple& t)const//compare if two tuple contain the same data;
{
    if(this ->size() != t.size())
        return false;
    else
    {
        for (int i = 0; i<t.size(); i++)
        {
            if((*this)[i] != t[i])
                return false;
        }
    }
    return true;
}

template <class T> Tuple<T> operator+(const Tuple<T>& t1, const Tuple<T>& other)
{
    Tuple<T> result(((t1.size() >other.size()) ? t1.size() : other.size()));
    if (t1.size()> other.size())
    {
        for( int i =0; i< t1.size(); i++)
        {
            result[i] = t1[i] + other[i];
        }
    }
    else
    {
        for( int i =0; i< other.size(); i++)
        {
            result[i] = t1[i] + other[i];
        }
    }

    return result;
}

template <class T> T operator*(const Tuple<T>& t1, const Tuple<T>& other)
{
    T result = 0;
    if (t1.size()<= other.size())
    {
        for( int i =0; i< t1.size(); i++)
        {
            //std::cout<<1<<std::endl;
            result += (*t1.TD())[i] * (*other.TD())[i];
        }
        return result;
    }
    else{
        for( int i =0; i< other.size(); i++)
        {
            result += (*t1.TD())[i] * (*other.TD())[i];
        }

        return result;
    }
}

template <class T> Tuple<T> operator*(const Tuple<T>& t1, const T& n)
{
    Tuple<T> temp(t1);
    for( int i =0; i< t1.size(); i++)
    {
        temp[i] *=n;
    }
    return temp;
}

template <class T> Tuple<T> operator*=(Tuple<T>& t1, const T& n)
{
    Tuple<T>* result = new Tuple<T>(t1 * n);
    t1 = *result;
    return t1;
}
template <class T> Tuple<T> operator+=(Tuple<T>& t1, const Tuple<T>& other)
{
    return t1 = Tuple<T>(t1+other);
}