#include <stdio.h>
#include <math.h>
#define Maxlength 20

// Khai bao cau truc danh sach
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements [Maxlength];
	int Last;
}List;


// ham khoi tao List rong
void makenullList(List *pL){
	(*pL).Last=0;

}



int fullList(List L){
	return L.Last==Maxlength;
}


// Ham kiem tra danh sach day
int emptyList(List L){
	return L.Last==0;
}


// Ham tra ve vi tri dau tien trong danh sach
Position first (List L){
	return 1;
}


// Ham tra ve vi tri cuoi cung trong danh sach
Position endList(List L){
    return L.Last+1;
}


// vi tri ke tiep
Position next(Position P, List L){
    return P+1;
}

// tra ve vi tri truoc vi tri thu p trong danh sach
Position previous(Position P, List L){
    return P-1;
}


// tra ve Element tai vi tri thu P
ElementType retrieve(Position P, List L){
    return L.Elements[P-1];
}


// chen Element X vao vi tri p trong danh sach
void insertList(ElementType x, Position p, List *pL){
	if (fullList(*pL))
		printf("Danh sach day");
  	else if ((p<1) || (p>pL->Last+1))
	    printf("Vi tri khong hop le");
	else
	{
	  Position q;
	  for(q=pL->Last; q>=p; q--)
		 pL->Elements[q]=pL->Elements[q-1];
	  pL->Elements[p-1]=x;
	  pL->Last++;
	 }
}

// Ham xoa phan tu
void deleteList(Position P, List *L){
    if((P > L->Last) || (P<1))
	printf("\nVi tri khong hop le !!!");
    else
	if(emptyList(*L))
	  printf("\nDanh sach rong !");
	else{
	  Position i;
	  for(i=P; i<L->Last; i++)
	  {
	     L->Elements[i-1] = L-> Elements[i];
	  }
	  L->Last--;
	}
}

// Tim vi tri dau tien chua x
Position locate (ElementType x, List L){
	Position p=first(L);
	int f=0;
	while (p!=endList(L)&& f==0)
	{
		if (retrieve (p,L)==x)
			f=1;
		else
			p=next(p,L)	;
	}
	return p;
}
