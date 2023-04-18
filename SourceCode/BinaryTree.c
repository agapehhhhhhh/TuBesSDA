/** Nama File : BinaryTree.c
 *  Deskripsi : File Body Binary Tree
 *  Oleh      : Lamda Richo Vanjaya Sumaryadi
 *  Tanggal   : 21 Juli 2021
 * 	Tanggal Modifikasi : 31 Juli 2021 
 */

#include "BinaryTree.h"

/* Return true jika ekspresi tree kosong dan sebaliknya */
boolean IsEmptyTree(BinTree P){
  return (P == Nil);
}

/*Hasil Alokasi Ekspresi Tree menghasilkan address */
addressTree AlokasiTree(infotypeTree X){
  addressTree P;

  P = (addressTree)malloc(sizeof(treeNode));
  if (P != Nil){
    strcpy(Info(P),X);
    Left(P) = Nil;
    Right(P) = Nil;
  }
  return P;
}

/* Membuat agar sebuah tree punya anak */
void CreateTree(infotypeTree X, BinTree L, BinTree R, BinTree *P){
  *P=AlokasiTree(X);
	if(*P!=Nil) {
		strcpy(Info(*P),X);
	   	Left(*P)=L;
		Right(*P)=R;	
  }
}

/* Membuat sebuah ekspresi Node Tree baru tetapi belum ada anak */
void CreateNodeTree(BinTree *P, infotypeTree X){
 *P=AlokasiTree(X);
	if(*P!=Nil) {
		strcpy(Info(*P),X);
	    Left(*P)=Right(*P)=Nil;
	} 
} 

/* Mengembalikan anak kiri dari sebuah ekspresi tree */
BinTree LeftChild(BinTree P){
  return Left(P);
}

/* Mengembalikan anak kanan dari sebuah ekspresi tree */
BinTree RightChild(BinTree P){
  return Right(P);
}

/* Memperlihatkan informasi dari setiap node dari sebuah ekspresi tree */
void ShowInfoTree(BinTree P){
  BinTree L, R, x;
  
  if(P != Nil){
    ShowInfoTree(Left(P));
    printf("Info Node\t: %s\n", Info(P));
    if(LeftChild(P) != Nil){
      L = LeftChild(P);
      printf("Left Child\t: %s\n", Info(L));
    } else{
      printf("Left Child\t: NULL\n");
    }
    if(RightChild(P) != Nil){
      R = RightChild(P);
      printf("Right Child\t: %s\n", Info(R));
    } else{
      printf("Right Child\t: NULL\n");
    }
    printf("\n");
    ShowInfoTree(Right(P));
  }
}

/* Mengkonversi string menjadi float */
float StringToFloat(String X){
  return atof(X);
}

/* Mengembalikan nilai prioritas dari sebuah operator (semakin besar nilai, prioritas semakin diutamakan) */
int Priority(char x){
  switch(x){
    case ')' : return 0;
    case '(': return 0;
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case 'x': return 2;
    case '/': return 2;
    case ':': return 2;
	case '^': return 3;   
    case 'v': return 3;
  }
}


/* Mengembalikan true jika operator1 memiliki prioritas yang lebih tinggi daripada operator2 */
boolean isPriority(char info1, char info2){
  return (Priority(info1) >= Priority(info2));
} 

/* Return true jika karakter yang dicek atau diperiksa merupakan sebuah operator */
boolean isOperator(char c){
  return(c=='+' || c=='-' || c=='*' || c=='x' || c=='/' || c ==':' || c =='^' || c=='v');
}

