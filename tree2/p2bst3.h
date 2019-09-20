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

template <class T>
int  countLeaf(Tree<T> t)
{
    int value = countLeaf(t.root);
    return value;
}

template <class T>
int countLeaf(Node<T>* n)
{
    if(n == NULL)
        return 0;
    if(n->left == NULL && n->right == NULL)
        return 1 + countLeaf(n->left) + countLeaf(n->right);
    return countLeaf(n->left) + countLeaf(n->right);
}


template <class T>
int  countSingle(Tree<T> t)
{
    int value = countSingle(t.root);
    return value;
}

template <class T>
int countSingle(Node<T>* n)
{
    if(n == NULL)
        return 0;
    if (n->left != NULL && n->right == NULL)
        return 1+countSingle(n->left);
    if(n->left == NULL && n->right != NULL)
        return 1+ countSingle(n->right);
    return countSingle(n->left) + countSingle(n->right);
}

template <class T>
int  countDouble(Tree<T> t)
{
    int value = countDouble(t.root);
    return value;
}

template <class T>
int countDouble(Node<T>* n )
{
    if(n == NULL)
        return 0;
    if(n->left != NULL && n-> right != NULL)
        return 1+countDouble(n->left) + countDouble(n->right);
    return countDouble(n->left) + countDouble(n->right);
}

template<class T>
T    kthValue(Tree<T> t, int k)
{
     Node<T>* walker = t.root;
    while(walker)
    {
        if(k == countNodes(walker->left) + 1)
            return walker->data;
        else if(k > countNodes(walker->left) + 1)
        {
            k = k - (countNodes(walker->left) + 1);
            walker = walker->right;
        }
        else
        {
            walker = walker->left;
        }
    }
    return 0;
}

 // Visualization recursive call per Node
    template <typename T>
    std::string visualize(Node<T>* N)
    {
        std::stringstream s;
        if (N->left) {
            s << "\t" << N->data << " -> " << N->left->data << ";\n"
              << visualize(N->left);    
        }
        else
        {
            s << "\tNLC" << N->data << " [shape=point];\n";
            s << "\t" << N->data << " -> NLC" << N->data << ";\n";
        }
        if (N->right) {
            s << "\t" << N->data << " -> " << N->right->data << ";\n"
              << visualize(N->right);    
        }
        else
        {
            s << "\tNRC" << N->data << " [shape=point];\n";
            s << "\t" << N->data << " -> NRC" << N->data << ";\n";
        }
        return s.str();
    }

    // Output BST as graph (DOT notation) to given filename
    template <typename T>
    void visualize(Tree<T> t, std::string filename)
    {
        std::ofstream fout;
        fout.open(filename.c_str());
        if( fout.is_open() )
        {
            if( !t.root ) //tree empty
                fout << "digraph G {\n"
                     << "\tempty [label=\"Tree empty\"]\n}";
            else //tree not empty
                fout << "digraph G {\n"
                     << "\tgraph [ordering = \"out\"];\n"
                     << "\tnode [shape = circle];\n"
                     << visualize(t.root)
                     << "}\n";
        }
        fout.close();
    }