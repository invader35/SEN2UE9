///////////////////////////////////////
// Workfile    : BinarySearchTree.h
// Author      : Matthias Schett
// Date        : 04-06-2013
// Description : BinarySearch Tree
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

template <typename TValue, typename TPred = std::less<TValue> >
class BinarySearchTree {

    struct TNode {
        TValue value;
        TNode *pLeft;
        TNode *pRight;
    };

private:
    TNode *pRoot;

    TNode* MakeNode(TValue const &val);
    bool InsertSorted(TNode* &pLeaf, TValue const &value);
    template <typename TVisitor> void PrintInOrder (TNode * pLeaf, TVisitor visitor) const;
    template <typename TVisitor> void PrintPreOrder (TNode *pLeaf, TVisitor visitor) const;
    template <typename TVisitor> void PrintPostOrder (TNode *pLeaf, TVisitor visitor) const;
    void Flush (TNode * & pRoot);
    TNode* copyTree(TNode* other);

public:

    BinarySearchTree();
    BinarySearchTree(BinarySearchTree<TValue, TPred> const &tree);
    BinarySearchTree<TValue, TPred> &operator=(BinarySearchTree<TValue, TPred> const &tree);
    ~BinarySearchTree();

    bool Insert(TValue const &value); // returns false if already contained

    template <typename TVisitor> void VisitPreOrder(TVisitor visitor) const;
    template <typename TVisitor> void VisitInOrder(TVisitor visitor) const;
    template <typename TVisitor> void VisitPostOrder(TVisitor visitor) const;

};

template <typename TValue, typename TPred>
BinarySearchTree<TValue, TPred>::BinarySearchTree() : pRoot(NULL) {
}

template <typename TValue, typename TPred>
BinarySearchTree<TValue, TPred>::BinarySearchTree(BinarySearchTree<TValue, TPred> const &tree){
    pRoot = copyTree(tree.pRoot);
}

template <typename TValue, typename TPred>
typename BinarySearchTree<TValue, TPred>::TNode* BinarySearchTree<TValue, TPred>::copyTree(typename BinarySearchTree<TValue, TPred>::TNode* other) {
    //if node is empty (at bottom of binary tree)
    /*
    This creates a shallow copy which in turn causes a problem 
    with the deconstructor, could not work out how to create a 
    deep copy.
    */
    if (other == NULL) {
        return NULL;
    }

    typename BinarySearchTree<TValue, TPred>::TNode* newNode = new BinarySearchTree<TValue, TPred>::TNode;

    newNode->value = other->value;

    newNode->pLeft = copyTree(other->pLeft);
    newNode->pRight = copyTree(other->pRight); 

    return newNode;
}

template <typename TValue, typename TPred>
BinarySearchTree<TValue, TPred> &BinarySearchTree<TValue, TPred>::operator=(BinarySearchTree<TValue, TPred> const &tree){
    if (this == &tree) {
        return *this;
    }
    Flush(pRoot);
    pRoot = copyTree(tree.pRoot);
    return *this;
}

template <typename TValue, typename TPred>
BinarySearchTree<TValue, TPred>::~BinarySearchTree(){
    Flush(pRoot);
}

template <typename TValue, typename TPred>
typename BinarySearchTree<TValue, TPred>::TNode *BinarySearchTree<TValue, TPred>::MakeNode(TValue const &val){
    BinarySearchTree<TValue, TPred>::TNode *pNewNode = new BinarySearchTree<TValue, TPred>::TNode;

    pNewNode->value = val;
    pNewNode->pRight = 0;
    pNewNode->pLeft = 0;

    return pNewNode;
}

template <typename TValue, typename TPred>
void BinarySearchTree<TValue, TPred>::Flush (TNode * & pNode){
    if (pNode != 0) {
        Flush (pNode->pLeft);
        Flush (pNode->pRight);
        delete pNode;
        pNode = 0;
    }
}

template<typename TValue, typename TPred>
bool BinarySearchTree<TValue, TPred>::Insert(TValue const &value) {
    if(pRoot != 0){
        return InsertSorted(pRoot, value);
    } else {
        pRoot = MakeNode(value);
        return true;
    }

}

template <typename TValue, typename TPred>
bool BinarySearchTree<TValue, TPred>::InsertSorted(typename BinarySearchTree<TValue, TPred>::TNode* & pLeaf, TValue const &value){
    if(pLeaf != 0){
        if(pLeaf->value == value){
            return false;
        } else {
            if(TPred()(value, pLeaf->value)) {
                return InsertSorted(pLeaf->pLeft, value);
            } else {
                return InsertSorted(pLeaf->pRight, value);
            }
        }
    } else {
        pLeaf = MakeNode(value);
        return true;
    }

}

template <typename TValue, typename TPred>
template <typename TVisitor>
void BinarySearchTree<TValue, TPred>::PrintInOrder (TNode * pLeaf, TVisitor visitor) const {
    if(pLeaf != 0){
        if(pLeaf->pLeft != 0){
            PrintInOrder(pLeaf->pLeft, visitor);
        }

        visitor(pLeaf->value);

        if(pLeaf->pRight != 0){
            PrintInOrder(pLeaf->pRight, visitor);
        }
    }
}

template <typename TValue, typename TPred>
template <typename TVisitor>
void BinarySearchTree<TValue, TPred>::VisitInOrder(TVisitor visitor) const {
    if(pRoot != 0){
        if(pRoot->pLeft != 0){
            PrintInOrder(pRoot->pLeft, visitor);
        }

        visitor(pRoot->value);

        if(pRoot->pRight != 0){
            PrintInOrder(pRoot->pRight, visitor);
        }
    }
}

template <typename TValue, typename TPred>
template <typename TVisitor>
void BinarySearchTree<TValue, TPred>::PrintPreOrder (TNode *pLeaf, TVisitor visitor) const {
    if(pLeaf != 0){
        visitor(pLeaf->value);

        if(pLeaf->pLeft != 0){
            PrintPreOrder(pLeaf->pLeft, visitor);
        }

        if (pLeaf->pRight != 0) {
            PrintPreOrder(pLeaf->pRight, visitor);
        }
    }
}

template <typename TValue, typename TPred>
template <typename TVisitor>
void BinarySearchTree<TValue, TPred>::VisitPreOrder(TVisitor visitor) const{
    if(pRoot != 0){
        visitor(pRoot->value);

        if(pRoot->pLeft != 0){
            PrintPreOrder(pRoot->pLeft, visitor);
        }

        if (pRoot->pRight != 0) {
            PrintPreOrder(pRoot->pRight, visitor);
        }
    }
}

template <typename TValue, typename TPred>
template <typename TVisitor>
void BinarySearchTree<TValue, TPred>::PrintPostOrder(TNode *pLeaf, TVisitor visitor) const {
    if(pLeaf != 0){
        if(pLeaf->pLeft != 0){
            PrintPostOrder(pLeaf->pLeft, visitor);
        }

        if(pLeaf->pRight != 0){
            PrintPostOrder(pLeaf->pRight, visitor);
        }

        visitor(pLeaf->value);
    }
}

template <typename TValue, typename TPred>
template <typename TVisitor>
void BinarySearchTree<TValue, TPred>::VisitPostOrder(TVisitor visitor) const {
    if(pRoot != 0){
        if(pRoot->pLeft != 0){
            PrintPostOrder(pRoot->pLeft, visitor);
        }

        if(pRoot->pRight != 0){
            PrintPostOrder(pRoot->pRight, visitor);
        }

        visitor(pRoot->value);
    }
}