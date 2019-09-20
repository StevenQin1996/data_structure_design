   #include <cstddef>

    template <class K, class V>
    struct Node {
        K key;
        V value;
        Node<K,V>* next;
    };

    template <class K, class V>
    struct Map {
        Node<K,V>** table;
        int size;
    };

     int hash(int key, int size)
    { 
        return key % size;
    }

    int hash(char key, int size) 
    {
        return key % size;
    }

    template <class K, class V>
    void initialize(Map<K,V>& Mp, int n)
    {
       Mp.table = new Node<K,V>*[n];
       Mp.size = n;
        for (int x=0; x<n; x++)
            Mp.table[x] = NULL;
    }

    template <class K, class V>
    void destroy(Map<K,V>& Mp)
    {
        for (int x=0;x<Mp.size;x++)
        {
            Node<K,V>* del = Mp.table[x];
            while(Mp.table[x] != NULL)
            {
                del = Mp.table[x];
                Mp.table[x] = Mp.table[x] -> next;
                delete del;
            }

        }
        delete [] Mp.table;
        Mp.table = NULL;
        Mp.size = 0;
    }
    template <class K, class V>
    void assign(Map<K,V>& Mp,K k,V v)
    {
        Node<K,V>* newNode = new Node<K,V>;
        newNode -> key = k;
        newNode -> value = v;
        newNode -> next = NULL;
        
        int ky = hash(k,Mp.size);
        Node<K,V>* walker = Mp.table[ky];
        if (has_key(Mp,k))
        {
            while(walker -> key != k)
                walker = walker -> next;
            walker -> value = v;
            delete newNode;
        }
        else if (Mp.table[ky] == NULL)
        {
            Mp.table[ky] = newNode;
        }
        else
        {
            while(walker -> next != NULL)
            {
                walker = walker ->next;
            }
            walker -> next = newNode;
        }
    }
    template <class K, class V>
    void remove(Map<K,V>& Mp,K k)
    {
       int n = hash(k, Mp.size);
       Node<K,V>* walker = Mp.table[n];

        // First node in list is the one we're looking for
       if( walker -> key == k )
       {
            Mp.table[n] = Mp.table[n] -> next;
            delete walker;
            return;
       }

       // otherwise, it's somewhere after the one
       // find the node BEFORE the one we want to remove
       while(walker -> next -> key != k)
       {
            walker = walker-> next;
       }
    
        Node<K,V>* del = walker -> next;
        walker -> next = del -> next;
        delete walker;
    }

    template <class K, class V>
    bool has_key(Map<K,V> Mp,K k)
    {
       int a = hash(k,Mp.size);
        Node<K,V>* walker = Mp.table[a];
        while(walker != NULL)
        {
            if(walker -> key == k)
                return true;
            walker = walker -> next;
        }
        return false;
    }

    template <class K, class V>
    V  lookup(Map<K,V> Mp,K k)
    {
        V value;
        int x = hash(k, Mp.size);
        Node<K,V>* walker = Mp.table[x];
        while(walker != NULL)
            {
                if (walker -> key == k)
                    value = walker -> value;
                walker = walker ->next;
            }
        return value;
    }
  