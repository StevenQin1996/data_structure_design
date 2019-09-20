  #include <cstddef>

    template <typename T>
    struct Node {
        T     data;
        Node<T>* left;
        Node<T>* right;
    };
    
    template <typename T>
    struct Tree {
        Node<T>* root;
    };

    template <typename T>
    void initialize(Tree<T> & t)
    {
        t.root = NULL;
    }

    template <typename T>
    void destroy(Tree<T>& t)
    {   
        destory(t.root);
        t.root = NULL;
    }

    template <typename T>
    void destory(Node<T>* n)
    {
        if (n==NULL)
            return;
        destory(n->left);
        destory(n->right);
        delete n;
    }


    template <typename T>
    void insert(Tree<T> &t, T value)
    {
        Node<T>* newnode = new Node<T>;
        newnode -> data = value;
        newnode -> left = NULL;
        newnode -> right = NULL;

        if(t.root == NULL)
        {
            t.root = newnode;
            return;
        }

        Node<T>* walker = t.root;
        while(true)
        {
            if( value > walker->data )
            {
                if(walker -> right ==NULL)
                {
                    walker -> right = newnode;
                    return;
                }
                else 
                    walker = walker -> right;
            }
            else 
            {
                if (walker -> left == NULL)
                {
                    walker -> left = newnode;
                    return;
                }
                else 
                    walker = walker -> left;
            }
        }
    }

    template <typename T>
    int  contains(Tree<T> &t, T value)
    {
        Node<T>* walker = t.root;
        int depth = 0;
        while (walker != NULL)
        {
            if (walker -> data == value)
                return depth;
            else if (value > walker -> data)
                walker = walker -> right;
            else 
                walker = walker -> left;
            depth++;
        }
        return -1;
    }

    template <typename T>
    int countNodes(Tree<T> t)
    {
        return countNodes(t.root);  
    }

    template <typename T>
    int countNodes(Node<T>* x)
    {
        if (x == NULL)
            return 0;
        return 1 + countNodes(x -> left) + countNodes(x -> right);
    }

    template <typename T>
    int  height(Tree<T> t)
    { 
        return height(t.root);
    }

    template <typename T>
    int height(Node<T>* x)
    {
        if (x == NULL)
            return -1;

        int L = height(x->left);
        int R = height(x->right);

        if(L > R)
            return(L + 1);
        return(R + 1);
    }

    template <typename T>
    T    minValue(Tree<T> t)
    {
        Node<T>* walker = t.root;
        while(walker -> left != NULL)
            walker = walker-> left;
        return walker -> data;
    }

    template <typename T>
    T    maxValue(Tree<T> t)
    {
        Node<T>* walker = t.root;
        while(walker -> right != NULL)
            walker = walker -> right;
        return walker -> data;
    }

    int  countLeaf(Tree<T> t);
    int  countSingle(Tree<T> t);
    int  countDouble(Tree<T> t);
    T    kthValue(Tree<T> t, int k);
