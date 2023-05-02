/** Nama File : BangunDatar.c
 *  Deskripsi : File Body ADT Bangun Datar
 *  Oleh      : Fiora Berliana Putri
 *  Tanggal   : 23 Juli 2021
 */
 
#include"BangunDatar.h"

/* Mengembalikan hasil perhitungan luas persegi.	*/
/* I.S. : P terdefinisi.							*/
/* F.S. : Hasil perhitungan luas P dikembalikan.	*/
float LuasPersegi(Persegi P){
	return Sisi(P)*Sisi(P);
}

/* Mengembalikan hasil perhitungan keliling persegi. 	*/
/* I.S. : P terdefinisi.								*/
/* F.S. : Hasil perhitungan keliling P dikembalikan.	*/
float KelilingPersegi(Persegi P){
	return 4*Sisi(P);
}

/* Procedure untuk menginput, dan menghitung luas dan keliling persegi. 	*/
/* I.S. : Sembarang															*/
/* F.S. : Hasil perhitungan luas dan keliling persegi ditamplkan ke layar.	*/
void HitungPersegi(){
	Persegi P;
	printf("\n\t\t Hitung Persegi \n");
	printf("\nMasukkan Sisi\t : "); scanf("%d", &Sisi(P));
	printf("\nLuas Persegi\t = %.2f", LuasPersegi(P));
	printf("\nKeliling Persegi = %.2f\n", KelilingPersegi(P));	
}

/* Mengembalikan hasil perhitungan luas persegi panjang.*/
/* I.S. : P terdefinisi.								*/
/* F.S. : Hasil perhitungan luas P dikembalikan.		*/
float LuasPersegiPanjang(PersegiPanjang P){
	return Panjang(P)*Lebar(P);
}

/* Mengembalikan hasil perhitungan keliling persegi panjang.*/
/* I.S. : P terdefinisi.									*/
/* F.S. : Hasil perhitungan keliling P dikembalikan.		*/
float KelilingPersegiPanjang(PersegiPanjang P){
	return 2*(Panjang(P)+Lebar(P));
}

/* Procedure untuk menginput, dan menghitung luas dan keliling persegi panjang.		*/
/* I.S. : Sembarang																	*/
/* F.S. : Hasil perhitungan luas dan keliling persegi panjang ditamplkan ke layar.	*/
void HitungPersegiPanjang(){
	PersegiPanjang P;
	printf("\n\t\t Hitung Persegi Panjang \n");
	printf("\nMasukkan Panjang\t : "); scanf("%d", &Panjang(P));
	printf("Masukkan Lebar\t\t : "); scanf("%d", &Lebar(P));
	printf("\nLuas Persegi Panjang\t = %.2f", LuasPersegiPanjang(P));
	printf("\nKeliling Persegi Panjang = %.2f\n", KelilingPersegiPanjang(P));
}

/* Mengembalikan hasil perhitungan luas segitiga.	*/
/* I.S. : P terdefinisi.							*/
/* F.S. : Hasil perhitungan luas P dikembalikan.	*/
float LuasSegitiga(Segitiga P){ //asumsi nya segitiga sama sisi
	return 0.5*Alas(P)*Tinggi(P);
}

/* Mengembalikan hasil perhitungan keliling segitiga. 	*/
/* I.S. : P terdefinisi.								*/
/* F.S. : Hasil perhitungan keliling P dikembalikan.	*/
float KelilingSegitiga(Segitiga P){
	return 3*Alas(P);
}

/* Procedure untuk menginput, dan menghitung luas dan keliling segitiga. 	*/
/* I.S. : Sembarang															*/
/* F.S. : Hasil perhitungan luas dan keliling segitiga ditamplkan ke layar.	*/
void HitungSegitiga(){
	Segitiga P;
	printf("\n\t\t Hitung Segitiga \n");
	printf("\nMasukkan Alas\t\t : "); scanf("%d", &Alas(P));
	printf("Masukkan Tinggi\t\t : "); scanf("%d", &Tinggi(P));
	printf("\nLuas Segitiga\t\t = %.2f", LuasSegitiga(P));
	printf("\nKeliling Segitiga\t = %.2f\n", KelilingSegitiga(P));
}

/* Mengembalikan hasil perhitungan luas trapseium.	*/ 
/* I.S. : P terdefinisi.							*/								
/* F.S. : Hasil perhitungan luas P dikembalikan.	*/
float LuasTrapesium(Trapesium P){
	return 0.5*(RusukSejajar1(P)+RusukSejajar2(P))*Tinggi(P);
}

/* Mengembalikan hasil perhitungan keliling trapesium.	*/
/* I.S.   : P terdefinisi.								*/
/* F.S.   : Hasil perhitungan keliling P dikembalikan.	*/
float KelilingTrapesium(Trapesium P){
	return Sisi1(P)+Sisi2(P)+RusukSejajar1(P)+RusukSejajar2(P);
}

/* Procedure untuk menginput, dan menghitung luas dan keliling trapesium.		*/
/* I.S.   : Sembarang.															*/
/* F.S.   : Hasil perhitungan luas dan keliling trapesium ditamplkan ke layar.	*/
void HitungTrapesium(){
	Trapesium P;
	printf("\n\t\t Hitung Trapesium \n");
	printf("\nMasukkan Rusuk Sejajar 1\t : "); scanf("%d", &RusukSejajar1(P));
	printf("Masukkan Rusuk Sejajar 2\t : "); scanf("%d", &RusukSejajar2(P));
	printf("Masukkan Tinggi\t\t\t : "); scanf("%d", &Tinggi(P));
	printf("Masukkan Sisi Kiri\t\t : "); scanf("%d", &Sisi1(P));
	printf("Masukkan Sisi Kanan\t\t : "); scanf("%d", &Sisi2(P));
	printf("\nLuas Trapesium\t\t = %.2f", LuasTrapesium(P));
	printf("\nKeliling Trapesium\t = %.2f\n", KelilingTrapesium(P));
}

/* Mengembalikan hasil perhitungan luas jajar genjang.	*/
/* I.S.   : P terdefinisi.								*/
/* F.S.  : Hasil perhitungan luas P dikembalikan.		*/
float LuasJajarGenjang(JajarGenjang P){
	return Alas(P)*Tinggi(P);
}

/* Mengembalikan hasil perhitungan keliling jajar genjang.	*/
/* I.S.   : P terdefinisi.									*/
/* F.S.  : Hasil perhitungan keliling P dikembalikan.		*/
float KelilingJajarGenjang(JajarGenjang P){
	return 2*(Sisi(P)+Alas(P));
}

/* Procedure untuk menginput, dan menghitung luas dan keliling jajar genjang.		*/
/* I.S.   : Sembarang.																*/
/* F.S.   : Hasil perhitungan luas dan keliling jajar genjang ditamplkan ke layar.	*/
void HitungJajarGenjang(){
	JajarGenjang P;
	printf("\n\t\t Hitung Jajar Genjang \n");
	printf("\nMasukkan Alas\t\t  : "); scanf("%d", &Alas(P));
	printf("Masukkan Tinggi\t\t  : "); scanf("%d", &Tinggi(P));
	printf("Masukkan Sisi Miring\t : "); scanf("%d", &Sisi(P));
	printf("\nLuas Jajar Genjang\t  = %.2f", LuasJajarGenjang(P));
	printf("\nKeliling\t\t  = %.2f\n", KelilingJajarGenjang(P));	
}

/* Mengembalikan hasil perhitungan luas belah ketupat.	*/
/* I.S.   : P terdefinisi.								*/
/* F.S.   : Hasil perhitungan luas P dikembalikan.		*/
float LuasBelahKetupat(BelahKetupat P){
	return 0.5*(Diagonal1(P)*Diagonal2(P)); 
}

/* Mengembalikan hasil perhitungan keliling belah ketupat.	*/
/* I.S.   : P terdefinisi.									*/
/* F.S.   : Hasil perhitungan keliling P dikembalikan.		*/
float KelilingBelahKetupat(BelahKetupat P){
	return 4*Sisi(P);
}

/* Procedure untuk menginput, dan menghitung luas dan keliling belah ketupat.		*/
/* I.S.   : Sembarang.																*/
/* F.S.   : Hasil perhitungan luas dan keliling belah ketupat ditamplkan ke layar.	*/
void HitungBelahKetupat(){
	BelahKetupat P;
	printf("\n\t\t Hitung Belah Ketupat \n");
	printf("\nMasukkan Diagonal 1\t : "); scanf("%d", &Diagonal1(P));
	printf("Masukkan Diagonal 2\t : "); scanf("%d", &Diagonal2(P));
	printf("Masukkan Sisi\t\t : "); scanf("%d", &Sisi(P));
	printf("\nLuas Belah Ketupat \t = %.2f", LuasBelahKetupat(P));
	printf("\nKeliling Belah ketupat   = %.2f\n", KelilingBelahKetupat(P));
}

/* Mengembalikan hasil perhitungan luas layang-layang.	*/
/* I.S.   : P terdefinisi.								*/
/* F.S.   : Hasil perhitungan luas P dikembalikan.		*/
float LuasLayangLayang(LayangLayang P){
	return 0.5*(Diagonal1(P)*Diagonal2(P));
}

/* Mengembalikan hasil perhitungan keliling layang-layang.	*/
/* I.S.   : P terdefinisi.									*/
/* F.S.   : Hasil perhitungan keliling P dikembalikan.		*/
float KelilingLayangLayang(LayangLayang P){
	return 2*(Sisi1(P)+Sisi2(P));	
}

/* Procedure untuk menginput, dan menghitung luas dan keliling layang-layang.		*/
/* I.S.   : Sembarang.																*/
/* F.S.   : Hasil perhitungan luas dan keliling layang-layang ditamplkan ke layar.	*/
void HitungLayangLayang(){
	LayangLayang P;
	printf("\n\t\t Hitung Layang-Layang \n");
	printf("\nMasukkan Diagonal 1\t   : "); scanf("%d", &Diagonal1(P));
	printf("Masukkan Diagonal 2\t   : "); scanf("%d", &Diagonal2(P));
	printf("Masukkan Sisi Miring Kiri  : "); scanf("%d", &Sisi1(P));
	printf("Masukkan Sisi Miring Kanan : "); scanf("%d", &Sisi2(P));
	printf("\nLuas Layang-layang\t= %.2f", LuasLayangLayang(P));
	printf("\nKeliling Layang-layang\t= %.2f\n", KelilingLayangLayang(P));	
}

/* Mengembalikan hasil perhitungan luas lingkaran.	*/
/* I.S.   : P terdefinisi.							*/
/* F.S.   : Hasil perhitungan luas P dikembalikan.	*/
float LuasLingkaran(Lingkaran P){
	return 3.14*JariJari(P)*JariJari(P);
}

/* Mengembalikan hasil perhitungan keliling lingkaran.	*/
/* I.S.   : P terdefinisi.								*/
/* F.S.   : Hasil perhitungan keliling P dikembalikan.	*/
float KelilingLingkaran(Lingkaran P){
	return 2*3.14*JariJari(P);
}

/* Procedure untuk menginput, dan menghitung luas dan keliling lingkaran.		*/
/* I.S   : Sembarang.															*/
/* F.S   : Hasil perhitungan luas dan keliling lingkaran ditamplkan ke layar.	*/
void HitungLingkaran(){
	Lingkaran P;
	printf("\n\t\t Hitung Lingkaran #\n");
	printf("\nMasukkan Jari-Jari\t: "); scanf("%d", &JariJari(P));
	printf("\nLuas Lingkaran\t\t= %.2f", LuasLingkaran(P));
	printf("\nKeliling Lingkaran\t= %.2f\n", KelilingLingkaran(P));
}
