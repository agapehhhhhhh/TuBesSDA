/** Nama File : StackForTree.h
 *  Deskripsi : File header ADT StackTree
 *  Oleh      : Muhamad Aryadipura
 *  Tanggal   : 24 Juli 2021
 * 
 *  Modifikasi: Lamda Richo Vanjaya Sumaryadi
 *  Tanggal   : 25 Juli 2021
 */


#ifndef STACK_TREE_H
#define STACK_TREE_H

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Top(S)  ((S).top)

#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree.h"
#include"boolean.h"

typedef BinTree infotypeStackTree;
typedef struct tElmStackTree *addressStackTree;
typedef struct tElmStackTree{
  infotypeStackTree info;
  addressStackTree next;
}ElmStackTree;
 
typedef struct{
  addressStackTree top;
}StackTree;


boolean isEmptyStackTree(StackTree S);
/* Mengembalikan true jika Stack Char kosong */
/* I.S   : S terdefinisi					  */
/* F.S   : S diketahui apakah kosong atau tidak  */


void NewStackTree(StackTree *S);
/* Membuat sebuah Stack Tree kosong		 */
/* I.S   : S belum terdefinisi			 */
/* F.S   : Menghasilkan Stack Char kosong */


addressStackTree alokasiStackTree(infotypeStackTree X);
/* Menghasilkan address hasil alokasi Stack Tree		*/
/* I.S   : X belum dialokasi							*/
/* F.S   : Menghasilkan address X yang sudah dialokasi	*/

void dealokasiStackTree(addressStackTree P);
/* Melepaskan address P			*/
/* I.S   : P sudah dialokasi		*/
/* F.S   : P berhasil didealokasi	*/

void AddStackTree(StackTree *S, infotypeStackTree X);
/* Menambahkan X ke bagian Top	*/
/* I.S   : S terdefinisi tapi kosong							*/
/* F.S   : X ditambahkan ke Top	*/ 
 

void DellStackTree(StackTree *S, infotypeStackTree *X);
/* Menghapus X dari bagian Top*/
/* I.S   : Top berisikan X	 */
/* F.S   : X dihapuskan dari Top */ 

#endif
