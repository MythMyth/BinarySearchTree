#include<utility>

template<typename T>
class BST {
public:
    BST();
    BST(const BST& another);
    BST(BST&& another);
    BST& operator=(const BST& another);
    BST& operator=(BST&& another);

    void insert(T& element);
    const T* find(T&& element);
    size_t size();
    virtual ~BST();
private:
    struct BSTNode {
        T content;
        BSTNode* left;
        BSTNode* right;
        BSTNode() :left(NULL), right(NULL) {}
        BSTNode(T&& val) : content(val), left(NULL), right(NULL) {} 
        ~BSTNode() { if(left != NULL) delete left; if(right != NULL) delete right;}
    }
    BSTNode *root;
    size_t m_size;

    void deepCopy(BSTNode** copyto, BSTNode** copyfrom);
    void findPosForNewElement(BST** pos, T &val);
}