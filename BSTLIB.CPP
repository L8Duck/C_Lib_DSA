#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef int KeyType;
struct Node{
	KeyType Key;
	struct Node *Left, *Right;
};
typedef struct Node* Tree;

void makenullTree(Tree *T){
	(*T)=NULL;
}
int emptyTree(Tree T){
	return T==NULL;
}
//helper fn
Tree leftChild(Tree T){
	if(T!=NULL) return T->Left;
	else return NULL;
}
Tree rightChild(Tree T){
	if(T!=NULL) return T->Right;
	else return NULL;
}

int isLeaf(Tree T){
	if(T!=NULL && T->Left==NULL && T->Right==NULL) return 1;
	else return NULL;
}
Tree search(KeyType x, Tree T){
	if(T==NULL) return NULL;
	else if(T->Key==x) return T;
	else if(T->Key<x) return search(x,T->Right);
	else return search(x,T->Left);
}
void insertNode(KeyType x, Tree *T){
	if((*T)==NULL){
		(*T)=(struct Node*)malloc(sizeof(struct Node));
		(*T)->Key = x;
		(*T)->Left = NULL;
		(*T)->Right = NULL;
	}
	else if((*T)->Key == x) printf("Da ton tai khoa x");
	else if((*T)->Key > x) insertNode(x,&(*T)->Left);
	else insertNode(x,&(*T)->Right);
}
KeyType deleteMin(Tree *T){
	KeyType k;
	if((*T)->Left==NULL){
		k=(*T)->Key;
		(*T)=(*T)->Right;
		return k;
	}
	else return deleteMin(&(*T)->Left);
}
void deleteNode(KeyType x, Tree *T){
	if((*T)!=NULL){
		if(x < (*T)->Key) deleteNode(x,&(*T)->Left);
		else if(x > (*T)->Key) deleteNode(x,&(*T)->Right);
		// if x is leaf then make null x
		else if(((*T)->Left==NULL) && ((*T)->Right)==NULL) (*T)=NULL;
		//if x contain 1 child so parent = child
		else if((*T)->Left==NULL) (*T)=(*T)->Right;
		else if((*T)->Right==NULL) (*T)=(*T)->Left;
		//if x is tree to deleteMin and assign min
		else (*T)->Key = deleteMin(&(*T)->Right);
	}
}
void NLR(Tree T){
	if(!emptyTree(T)){
		printf("%d ",T->Key);
		NLR(leftChild(T));
		NLR(rightChild(T));
	}
}
void LNR(Tree T){
	if(!emptyTree(T)){
		LNR(leftChild(T));
		printf("%d ",T->Key);
		LNR(rightChild(T));
	}
}
void LRN(Tree T){
	if(!emptyTree(T)){
		LRN(leftChild(T));
		LRN(rightChild(T));
		printf("%d ",T->Key);
	}
}
// find height of node x in Tree T
int treeHeight(Tree T){
    if(T == NULL)
        return -1;
    else {
        int leftHeight = treeHeight(T ->Left);
        int rightHeight = treeHeight(T ->Right);
        return  (leftHeight > rightHeight ? leftHeight : rightHeight) +1;
    }
}

int hNode(int x, Tree T){
    //if !x return
    if (T== NULL) return -1;
    else if(T->Key > x) return hNode(x, T->Left);
    else if(T->Key < x) return hNode(x, T->Right);
    else return treeHeight(T);
}


// Function to find the right sibling of a node with key x given its parent
Tree rightSibling(int x, Tree parent) {
    if (parent == NULL || (parent->Left == NULL && parent->Right == NULL)) {
        return NULL; // No parent or parent has no children
    }

    if (parent->Left != NULL && parent->Left->Key == x) {
        // Node with key x is the left child, return the right child (may be NULL)
        return parent->Right;
    } else if (parent->Right != NULL && parent->Right->Key == x) {
        // Node with key x is the right child, find the right sibling
        return parent->Left; // If you want to return the left sibling, change to parent->Right
    } else if (x < parent->Key) {
        // Recursively search in the left subtree
        return rightSibling(x, parent->Left);
    } else {
        // Recursively search in the right subtree
        return rightSibling(x, parent->Right);
    }
}
//count node in Tree
int getNb_Nodes(Tree T){
    if(T==NULL) return 0;
    else return getNb_Nodes(T->Left) + getNb_Nodes(T->Right) + 1;
}
//getPrevious
Tree maxNode(Tree T){
    Tree p=T;
    while (p->Right!=NULL)
        p=p->Right;
    return p;
}
Tree getPrevious(int x,Tree T){
    Tree p=T,lleft=NULL;
    while (p!=NULL){
        if (p->Key==x){
            if (p->Left==NULL) return lleft;
            else return maxNode(p->Left);
        }
        else
            if (x<p->Key) {

                p=p->Left;}
            else {lleft=p;
                p=p->Right;
            }
    }
    return NULL;
}
//getNext()
Tree getNext( int x, Tree T){
    Tree Temp=NULL;
    while( T!=NULL){
        if( T->Key<=x){
            T=T->Right;
        }
        else{
            Temp=T;
            T=T->Left;
        }
    }
    return Temp;
}
//getParent()
Tree getParent(int x, Tree T){
    Tree parent = NULL;
    while (T != NULL){
        if(x > T->Key){
            parent = T;
            T = T->Right;
        }
        else if(x < T->Key){
            parent = T;
            T = T->Left;
        }
        else{
            return parent;
        }
    }
    return NULL;
}

//get node that contain 2 leaves
int getFullNodes(Tree T){
    if(T==NULL) return 0;
    else if (T->Left !=NULL && T->Right !=NULL)
        return getFullNodes(T->Left)+getFullNodes(T->Right)+1;
    else return getFullNodes(T->Left)+getFullNodes(T->Right);
}

///////////////////AVL Tree///////////////////
void printHeight(int height, AVLTree root){
    if(AVLTree !=NULL){
        printHeight(height, root ->Left);
        if(root->Height == height)
            printf("%d ", root->Key);
        printHeight(height, root ->Right);
    }
}
//
int isAVL(AVLTree root){
    if(getBalance(root) == )
}
