#include <malloc.h>
#include <stdio.h>

/* ==== Khai bao danh sach kieu con tro ====*/
typedef int ElementType;
struct Node{
 ElementType  Element;
 struct Node* Next;
};

typedef struct Node*    Position;
typedef Position List;


/*==== Cac phep toan tren danh sach ====*/
/*== Ham tao danh sach rong ==*/
void makenullList(List *Header){
 (*Header)       = (struct Node*)malloc(sizeof(struct Node));
 (*Header)->Next = NULL;
}


// Kiem tra danh sach rong
int emptyList(List L)
{
	return (L->Next==NULL);
}


// Ham lay noi dung phan tu tai vi tri p trong DS
ElementType retrieve (Position p, List L)
{
	if (p->Next!=NULL)
		return p->Next->Element;
	else
		return -10000;
}


Position first (List L)
{
	return L;
}


// Ham lay vi tri ke tiep
Position next (Position p, List L)
{
	return p->Next;
}


// Lam lay vi tri cuoi
Position endList (List L)
{
	Position p=L;
	while (p->Next!=NULL)
		p=p->Next;
	return p;
}


/*== Ham chen phan tu X vao vi tri P ==*/
void insertList(ElementType X, Position P, List *L){
 Position T;
 T = (struct Node*)malloc(sizeof(struct Node));
 T->Element = X;
 T->Next    = P->Next;
 P->Next    = T;
}


/*== Ham xoa phan tu tai vi tri P ==*/
void deleteList(Position P, List *L){
	 Position T;
	 if(P->Next != NULL){
		T = P->Next;
		P->Next = P->Next->Next;//T->Next;
		free(T);
	 }
	 else printf("\nLoi ! Khong the xoa");
}


/*== Ham tim vi tri phan tu dau tien co noi dung X ==*/
Position locate(ElementType X, List L){
 Position P=L;
 int found = 0;
 while ((P->Next != NULL) && (found ==0)){
	if(P->Next->Element == X)
	  found=1;
	else P=P->Next;
 }
 return P;
}

void enterValue(List *L){
    makenullList(&(*L));
    int n, i, temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &temp);
        insertList(temp,endList(*L),&(*L));
    }
    return;
}

void printList(List L){
	while(L->Next != NULL){
		printf("%d ",L->Next->Element);
		L=L->Next;
	}
}
// === in So le trong danh sach ra man hinh ====
void printOddNumbers(List L){
	while(L->Next != NULL){
		if(L->Next->Element % 2 == 1)
		printf("%d ",L->Next->Element);
		L=L->Next;
	}
}





