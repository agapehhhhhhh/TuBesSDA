/** Nama File : StackForTree.c
 *  Deskripsi : File header ADT StackTree
 *  Oleh      : Muhamad Aryadipura
 *  Tanggal   : 24 Juli 2021
 * 
 *  Modifikasi: Lamda Richo Vanjaya Sumaryadi
 *  Tanggal   : 25 Juli 2021
 */

#include "StackForTree.h"

boolean isEmptyStackTree(StackTree S) {
/* Mengembalikan true jika Stack Char kosong */
/* I.S   : S terdefinisi					  */
/* F.S   : S diketahui apakah kosong atau tidak  */
	
    return (Top(S)==Nil);
}

void NewStackTree(StackTree *S) {
/* Membuat sebuah Stack Tree kosong		 */
/* I.S   : S belum terdefinisi			 */
/* F.S   : Menghasilkan Stack Char kosong */

    Top(*S)=Nil;
}

addressStackTree alokasiStackTree(infotypeStackTree X) {
/* Menghasilkan address hasil alokasi Stack Tree		*/
/* I.S   : X belum dialokasi							*/
/* F.S   : Menghasilkan address X yang sudah dialokasi	*/
	
    addressStackTree P;
    
    P=(addressStackTree)malloc(sizeof(ElmStackTree));
    if(P!=Nil) {
        Info(P)=X;
        Next(P)=Nil;
    }
    return P;
}

void dealokasiStackTree(addressStackTree P) {
/* Melepaskan address P			*/
/* I.S   : P sudah dialokasi		*/
/* F.S   : P berhasil didealokasi	*/
	
    free(P);
}

void AddStackTree(StackTree *S, infotypeStackTree X) {
/* Menambahkan X ke bagian Top	*/
/* I.S   : S terdefinisi tapi kosong							*/
/* F.S   : X ditambahkan ke Top	*/
	
    addressStackTree P;
    
    P=alokasiStackTree(X);
    Next(P)=Top(*S);
    Top(*S)=P;
}

void DellStackTree(StackTree *S, infotypeStackTree *X) {
/* Menghapus X dari bagian Top*/
/* I.S   : Top berisikan X	 */
/* F.S   : X dihapuskan dari Top */ 
    addressStackTree P;
    
    if(!isEmptyStackTree(*S)) {
        P=Top(*S);
        Top(*S)=Next(P);
        *X=Info(P);
        dealokasiStackTree(P);
    }
	else {
        printf("\nStack sudah kosong..\n");
    }
}
