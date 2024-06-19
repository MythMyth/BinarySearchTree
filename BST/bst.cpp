#include "bst.h"

BST::BST() : root(NULL), m_size(0U){}
BST::BST(const BST& another){
    deepCopy(&root, &(another.root));
    size = another.size;
}
BST::BST(BST&& another){
    root = another.root;
    size = another.size;
    another.root = NULL;
    another.size = 0U;
}
BST& BST::operator=(const BST& another){
    deepCopy(&root, &(another.root));
    size = another.size;
    return *this;
}
BST& BST::operator=(BST&& another){
    root = another.root;
    size = another.size;
    another.root = NULL;
    another.size = 0;
    return *this;
}
BST::~BST(){ if(root != NULL) delete root; }

void BST::insert(T&& element){
    BST* pos;
    findPosForNewElement(&pos, element);
    if(pos == NULL) {
        pos = new BSTNode(element);
    }
}
size_t BST::size(){ return size; }

void BST::deepCopy(BSTNode** copyto, BSTNode** copyfrom) {
    if(*copyfrom != NULL) {
        (*copyto) = new BSTNode();
        (*copyto)->content = (*copyfrom)->content;
        deepCopy(&((*copyto)->left), &((*copyfrom)->left));
    }
}

const T* BST::find(T&& element) {
    BTS* pos;
    findPosForNewElement(&pos, element);
    if(pos == NULL) return NULL;
    return &(pos->content);
}

void BST::findPosForNewElement(BST** pos, T &&val) {
    *pos = root;
    while(*pos != NULL) {
        if(*pos -> content == val) return;
        if(*pos -> content > val) {
            *pos = *pos -> right;
        } else {
            *pos = *pos -> left;
        }
    }
}