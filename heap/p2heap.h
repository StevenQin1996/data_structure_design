    #include <cstddef>

    template <class T>
    struct Heap {
        T*  data;
        int size;
    };
    
    template<class T>
    void initialize(Heap<T>& Hp,int n)
    {
        Hp.data = new T[n];
        Hp.size = 0;
    }

    template<class T>
    void destroy(Heap<T>& Hp)
    {
        Hp.size = 0;
        delete[] Hp.data;
        Hp.data = NULL; 
    }

    template<class T>
    bool isEmpty(Heap<T> Hp)
    {
        return (Hp.size==0);
    } 

    template<class T>
    void put(Heap<T>& Hp,T input)
    {
        
        Hp.size++;
        Hp.data[Hp.size] = input;
        int x = Hp.size;          
             
        while((Hp.data[x] < Hp.data[x / 2]) && x / 2 != 0)
        {
            if(Hp.data[x] < Hp.data[x / 2])
            {
                T value = Hp.data[x];
                Hp.data[x] = Hp.data[x / 2];
                Hp.data[x / 2] = value;
                x = x / 2;
            }
        }
    }

    template<class T>
    T    get(Heap<T>& Hp)
    {
        T a = Hp.data[1];
        Hp.data[1] = Hp.data[Hp.size];
        Hp.size --; 
        int x =1;

        while((Hp.data[x] > Hp.data[x*2] || Hp.data[x] > Hp.data[2*x+1]) && (x *2 <= Hp.size) )
        { 
            T temp = Hp.data[x];
            if (x*2>Hp.size)
            {
                break;
            }
            else if (x*2 == Hp.size)
            {
                Hp.data[x] = Hp.data[x*2];
                Hp.data[x*2] = temp;
                break;
            }

            else
            {
                if(Hp.data[2*x] < Hp.data[2*x+1])
                {
                    Hp.data[x] = Hp.data[2*x];
                    Hp.data[2*x]= temp; 
                    x = 2*x;
                }

                else
                {
                    Hp.data[x] = Hp.data[2*x+1];
                    Hp.data[2*x+1]= temp; 
                    x = 2*x+1;
                }
            }
        }
        return a;
    }