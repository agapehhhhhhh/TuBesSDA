/** Nama File : BangunDatar.h
 *  Deskripsi : File Header ADT Bangun Datar
 *  Oleh      : Fiora Berliana Putri
 *  Tanggal   : 23 Juli 2021
 */
 
#ifndef BANGUNDATAR_H
#define BANGUNDATAR_H

#define Sisi(P) P.sisi
#define Panjang(P) P.panjang
#define Lebar(P) P.lebar
#define Alas(P) P.alas
#define Tinggi(P) P.tinggi
#define RusukSejajar1(P) P.rusukSejajar1
#define RusukSejajar2(P) P.rusukSejajar2
#define Sisi1(P) P.sisi1
#define Sisi2(P) P.sisi2
#define Diagonal1(P) P.diagonal1
#define Diagonal2(P) P.diagonal2
#define JariJari(P) P.jariJari

#include<stdio.h>
#include<math.h>

typedef struct {
	int sisi;
}Persegi;

typedef struct {
	int panjang;
	int lebar;
}PersegiPanjang;

typedef struct {
	int alas;
	int tinggi;
}Segitiga;

typedef struct {
	int rusukSejajar1;
	int rusukSejajar2;
	int sisi1;
	int sisi2;
	int tinggi;
}Trapesium;

typedef struct {
	int alas;
	int tinggi;
	int sisi;
}JajarGenjang;

typedef struct{
	int diagonal1;
	int diagonal2;
	int sisi;
}BelahKetupat;

typedef struct {
	int diagonal1;
	int diagonal2;
	int sisi1;
	int sisi2;
}LayangLayang;

typedef struct {
	int jariJari;
}Lingkaran;

/* Mengembalikan hasil perhitungan luas persegi.	*/
/* I.S. : P terdefinisi.							*/
/* F.S. : Hasil perhitungan luas P dikembalikan.	*/
float LuasPersegi(Persegi P);

/* Mengembalikan hasil perhitungan keliling persegi. 	*/
/* I.S. : P terdefinisi.								*/
/* F.S. : Hasil perhitungan keliling P dikembalikan.	*/
float KelilingPersegi(Persegi P);

/* Procedure untuk menginput, dan menghitung luas dan keliling persegi. 	*/
/* I.S. : Sembarang															*/
/* F.S. : Hasil perhitungan luas dan keliling persegi ditamplkan ke layar.	*/
void HitungPersegi();

/* Mengembalikan hasil perhitungan luas persegi panjang.*/
/* I.S. : P terdefinisi.								*/
/* F.S. : Hasil perhitungan luas P dikembalikan.		*/
float LuasPersegiPanjang(PersegiPanjang P);

/* Mengembalikan hasil perhitungan keliling persegi panjang.*/
/* I.S. : P terdefinisi.									*/
/* F.S. : Hasil perhitungan keliling P dikembalikan.		*/
float KelilingPersegiPanjang(PersegiPanjang P);

/* Procedure untuk menginput, dan menghitung luas dan keliling persegi panjang.		*/
/* I.S. : Sembarang																	*/
/* F.S. : Hasil perhitungan luas dan keliling persegi panjang ditamplkan ke layar.	*/
void HitungPersegiPanjang();

/* Mengembalikan hasil perhitungan luas segitiga.	*/
/* I.S. : P terdefinisi.							*/
/* F.S. : Hasil perhitungan luas P dikembalikan.	*/
float LuasSegitiga(Segitiga P);

/* Mengembalikan hasil perhitungan keliling segitiga. 	*/
/* I.S. : P terdefinisi.								*/
/* F.S. : Hasil perhitungan keliling P dikembalikan.	*/
float KelilingSegitiga(Segitiga P);

/* Procedure untuk menginput, dan menghitung luas dan keliling segitiga. 	*/
/* I.S. : Sembarang															*/
/* F.S. : Hasil perhitungan luas dan keliling segitiga ditamplkan ke layar.	*/
void HitungSegitiga();

/* Mengembalikan hasil perhitungan luas trapseium.	*/ 
/* I.S. : P terdefinisi.							*/								
/* F.S. : Hasil perhitungan luas P dikembalikan.	*/
float LuasTrapesium(Trapesium P);

/* Mengembalikan hasil perhitungan keliling trapesium.	*/
/* I.S.   : P terdefinisi.								*/
/* F.S.   : Hasil perhitungan keliling P dikembalikan.	*/
float KelilingTrapesium(Trapesium P);

/* Procedure untuk menginput, dan menghitung luas dan keliling trapesium.		*/
/* I.S.   : Sembarang.															*/
/* F.S.   : Hasil perhitungan luas dan keliling trapesium ditamplkan ke layar.	*/
void HitungTrapesium();

/* Mengembalikan hasil perhitungan luas jajar genjang.	*/
/* I.S.   : P terdefinisi.								*/
/* F.S.  : Hasil perhitungan luas P dikembalikan.		*/
float LuasJajarGenjang(JajarGenjang P);

/* Mengembalikan hasil perhitungan keliling jajar genjang.	*/
/* I.S.   : P terdefinisi.									*/
/* F.S.  : Hasil perhitungan keliling P dikembalikan.		*/
float KelilingJajarGenjang(JajarGenjang P);

/* Procedure untuk menginput, dan menghitung luas dan keliling jajar genjang.		*/
/* I.S.   : Sembarang.																*/
/* F.S.   : Hasil perhitungan luas dan keliling jajar genjang ditamplkan ke layar.	*/
void HitungJajarGenjang();

/* Mengembalikan hasil perhitungan luas belah ketupat.	*/
/* I.S.   : P terdefinisi.								*/
/* F.S.   : Hasil perhitungan luas P dikembalikan.		*/
float LuasBelahKetupat(BelahKetupat P);

/* Mengembalikan hasil perhitungan keliling belah ketupat.	*/
/* I.S.   : P terdefinisi.									*/
/* F.S.   : Hasil perhitungan keliling P dikembalikan.		*/
float KelilingBelahKetupat(BelahKetupat P);

/* Procedure untuk menginput, dan menghitung luas dan keliling belah ketupat.		*/
/* I.S.   : Sembarang.																*/
/* F.S.   : Hasil perhitungan luas dan keliling belah ketupat ditamplkan ke layar.	*/
void HitungBelahKetupat();

/* Mengembalikan hasil perhitungan luas layang-layang.	*/
/* I.S.   : P terdefinisi.								*/
/* F.S.   : Hasil perhitungan luas P dikembalikan.		*/
float LuasLayangLayang(LayangLayang P);

/* Mengembalikan hasil perhitungan keliling layang-layang.	*/
/* I.S.   : P terdefinisi.									*/
/* F.S.   : Hasil perhitungan keliling P dikembalikan.		*/
float KelilingLayangLayang(LayangLayang P);

/* Procedure untuk menginput, dan menghitung luas dan keliling layang-layang.		*/
/* I.S.   : Sembarang.																*/
/* F.S.   : Hasil perhitungan luas dan keliling layang-layang ditamplkan ke layar.	*/
void HitungLayangLayang();

/* Mengembalikan hasil perhitungan luas lingkaran.	*/
/* I.S.   : P terdefinisi.							*/
/* F.S.   : Hasil perhitungan luas P dikembalikan.	*/
float LuasLingkaran(Lingkaran P);

/* Mengembalikan hasil perhitungan keliling lingkaran.	*/
/* I.S.   : P terdefinisi.								*/
/* F.S.   : Hasil perhitungan keliling P dikembalikan.	*/
float KelilingLingkaran(Lingkaran P);

/* Procedure untuk menginput, dan menghitung luas dan keliling lingkaran.		*/
/* I.S   : Sembarang.															*/
/* F.S   : Hasil perhitungan luas dan keliling lingkaran ditamplkan ke layar.	*/
void HitungLingkaran();

#endif
