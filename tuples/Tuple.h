#include <iostream>//65
#include <cstddef>
#include <cmath>
//#define DEBUG 1
// + * int, *tuple, *=, *=, +=
template <class T> class Tuple;

template <class T> Tuple<T> operator+(const Tuple<T>& t1, const Tuple<T>& other);//these arent member function. so it cant not be const
template <class T> Tuple<T> operator*(const Tuple<T>& t1, const Tuple<T>& other);
template <class T> Tuple<T> operator*(const Tuple<T>& t1, const T& n);
template <class T> Tuple<T> operator*=(Tuple<T>& t1, const Tuple<T>& other);
template <class T> Tuple<T> operator*=(Tuple<T>& t1, const T& n);
template <class T> Tuple<T> operator+=(Tuple<T>& t1, const Tuple<T>& other);

template <class T> class TupleData
{
    private:
        T* items;
        int count;
        int uses;
     
    public:
        TupleData(int s);
        TupleData(const TupleData <T>& other);
        TupleData(T x[], int n){items = x ; count = n; uses = 1;}
        ~TupleData(){if(items) delete [] items; items = NULL;}

        T& operator[](int i){return items[i];}
        const T& operator[](int i)const{return items[i];}
        int size()const{return count;}
        double magnitude();
        int useCount()const{return uses;}
        void incrementUse(){uses++;}
        void decrementUse(){uses--; if(uses == 0) delete this;}
        T* makeCopy(int length, const T* other);

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
        Tuple(const Tuple <T>& other){data = other.TD(); data->incrementUse();}//create other tuple and copy the data from other tupledata
        Tuple(T x[], int n){data = new TupleData<T>(x,n);}//x is a array with size n, make a new tuple data and hold the array
        ~Tuple(){data->decrementUse();}//deconstructor. 

        void TD(TupleData<T> *t){ data=t;}//TD getter
        TupleData<T>* TD()const{return data;}//TD setter

        int size()const{return data->size();}//return size
        double magnitude()const{return data-> magnitude();}//return magnitude

        T& operator[](int i);//overloads the []
        const T& operator[](int i)const{return (*data)[i];}//

        Tuple& operator = (Tuple const& other);
        bool operator == (const Tuple& t)const;
        bool operator != (const Tuple& t)const{return !(*this == t);}
        
            
    private:
        TupleData<T>* data;    
};

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

template<class T> double TupleData<T>::magnitude()
{
    double answer =0;
    for (int i=0; i<size(); i++)
    {
        answer += pow((double)items[i],2);
    }

    return sqrt(answer);
}

template <class T> T* TupleData<T>::makeCopy(int length, const T* other)
{
    count = length;
    other -> inrecementUses();
    return other->item;
}

template <class T> T& Tuple<T>::operator[](int i)
{
    TupleData<T> *temp = new TupleData<T>(*data);//creating a new tupledata pointer copies the data
    data -> decrementUse();
    TD(temp);
    return (*data)[i];
}//checked

template<class T> Tuple<T>& Tuple<T>:: operator = (const Tuple& other)
{
    data -> decrementUse();
    this -> TD(other.TD());
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
     if(t1.size() > other.size())
    {
        T* result = new T[t1.size()];
 
        for(int i = 0; i < t1.size(); i++)
        {
            result[i] = (*t1.TD())[i] + (*other.TD())[i];
        }
        return Tuple<T>(result, t1.size());
    }

        T* result = new T[other.size()];
 
        for(int i = 0; i < other.size(); i++)
        {
            result[i] = (*t1.TD())[i] + (*other.TD())[i];
        }
 
        return Tuple<T>(result, other.size());
}

template <class T> Tuple<T> operator*(const Tuple<T>& t1, const Tuple<T>& other)
{
    if(t1.size() < other.size())
        {
            T* result = new T[t1.size()];
 
            for(int i = 0; i < t1.size(); i++)
            {
                result[i] = (*t1.td())[i] * (*other.td())[i];
            }
 
            return Tuple<T>(result, t1.size());
        }
       
            T* result = new T[other.size()];
 
            for(int i = 0; i < other.size(); i++)
            {
                result[i] = (*t1.td())[i] * (*other.td())[i];
            }
            return Tuple<T>(result, other.size());
       
}

template <class T> Tuple<T> operator*(const Tuple<T>& t1, const T& n)
{
    T* result = new T[t1.size()];
 
    for(int i = 0; i < t1.size(); i++)
    {
        result[i] = (*t1.td())[i] * n;
    }
 
    return Tuple<T>(result, t1.size());
}

template <class T> Tuple<T> operator*=(Tuple<T>& t1, const Tuple<T>& other)
{
    return t1 = Tuple<T>(t1 * other);
}
template <class T> Tuple<T> operator*=(Tuple<T>& t1, const T& n)
{
    return t1 = Tuple<T>(t1 * n);
}
template <class T> Tuple<T> operator+=(Tuple<T>& t1, const Tuple<T>& other)
{
    return t1 = Tuple<T>(t1 + other);
}
