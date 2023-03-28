/** Nama File : StackForChar.c
 *  Deskripsi : File body ADT StackChar
 *  Oleh      : Muhamad Aryadipura
 *  Tanggal   : 24 Juli 2021
 * 
 *  Modifikasi: Lamda Richo Vanjaya Sumaryadi
 *  Tanggal   : 25 Juli 2021
 */
 
#include "StackForChar.h"

boolean isEmptyStackChar(StackChar S) {
/* Mengembalikan true jika Stack Char kosong */
/* I.S   : S terdefinisi */
/* F.S   : S diketahui apakah kosong atau tidak */

    return (Top(S)==Nil);
}

void NewStackChar(StackChar *S) {
/* Membuat sebuah Stack Char kosong */
/* I.S   : S belum terdefinisi	*/
/* F.S   : Menghasilkan Stack Char kosong */
	
    Top(*S)=Nil;
}

addressStackChar alokasiStackChar(infotypeStackChar X) {
/* Menghasilkan address hasil alokasi Stack Char.		*/
/* I.S   : X belum dialokasi							*/
/* F.S   : Menghasilkan address X yang sudah dialokasi	*/
	
    addressStackChar P;
    
    P=(addressStackChar)malloc(sizeof(ElmStackChar));
    if(P!=Nil) {
        Info(P)=X;
        Next(P)=Nil;
    }
    return P;
}

void dealokasiStackChar(addressStackChar P) {
/* Melepaskan address P			*/
/* I.S   : P sudah dialokasi		*/
/* F.S   : P berhasil didealokasi	*/
	
    free(P);
}

void AddStackChar(StackChar *S, infotypeStackChar X) {
/* Menambah X ke bagian Top	*/
/* I.S   : S terdefinisi tapi kosong							*/
/* F.S   : X ditambahkan ke Top	*/
    addressStackChar P;
    
    P=alokasiStackChar(X);
    Next(P)=Top(*S);
    Top(*S)=P;
}

void DellStackChar(StackChar *S, infotypeStackChar *X) {
/* Menghapus X dari bagian Top*/
/* I.S   : Top berisikan X	 */
/* F.S   : X dihapuskan dari Top		 */ 
	
    addressStackChar P;
    
    if(!isEmptyStackChar(*S)) {
        P=Top(*S);
        Top(*S)=Next(P);
        *X=Info(P);
        dealokasiStackChar(P);
    }
	else {
        printf("\nStack sudah kosong..\n");
    }
}

