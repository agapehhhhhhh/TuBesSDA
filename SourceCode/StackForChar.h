/** Nama File : StackForChar.h
 *  Deskripsi : File header ADT StackChar
 *  Oleh      : Muhamad Aryadipura
 *  Tanggal   : 24 Juli 2021
 * 
 *  Modifikasi: Lamda Richo Vanjaya Sumaryadi
 *  Tanggal   : 25 Juli 2021
 */

#ifndef STACK_CHAR_H
#define STACK_CHAR_H

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Top(S)  ((S).top)

#include<stdio.h>
#include<stdlib.h>
#include "boolean.h"

typedef char infotypeStackChar;
typedef struct tElmStackChar *addressStackChar;
typedef struct tElmStackChar {
	infotypeStackChar info;
	addressStackChar next;
}ElmStackChar;
 
typedef struct{
	addressStackChar top;
}StackChar;


boolean isEmptyStackChar(StackChar S);
/* Mengembalikan true jika Stack Char kosong */
/* I.S   : S terdefinisi					  */
/* F.S   : S diketahui apakah kosong atau tidak  */

void NewStackChar(StackChar *S);
/* Membuat sebuah Stack Char kosong		 */
/* I.S   : S belum terdefinisi			 */
/* F.S   : Menghasilkan Stack Char kosong */

addressStackChar alokasiStackChar(infotypeStackChar X);
/* Menghasilkan address hasil alokasi Stack Char		*/
/* I.S   : X belum dialokasi							*/
/* F.S   : Menghasilkan address X yang sudah dialokasi	*/

void dealokasiStackChar(addressStackChar P);
/* Melepaskan address P			*/
/* I.S   : P sudah dialokasi		*/
/* F.S   : P berhasil didealokasi	*/

void AddStackChar(StackChar *S, infotypeStackChar X);
/* Menambahkan X ke bagian Top	*/
/* I.S   : S terdefinisi tapi kosong							*/
/* F.S   : X ditambahkan ke Top	*/ 

void DellStackChar(StackChar *S, infotypeStackChar *X);
/* Menghapus X dari bagian Top*/
/* I.S   : Top berisikan X	 */
/* F.S   : X dihapuskan dari Top */ 

#endif
