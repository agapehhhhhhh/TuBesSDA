#include "KalkulatorTree.h"


int main() {
	mainMenu();
}
void MenuKalkulator(){
	BinTree expTree;
	String postfix, input;
	
	system("cls");
	puts("\n\t\t\t Aplikasi Kalkulator \n");
	printf("Petunjuk : ");
	printf("\n1. Gunakan '^' untuk melakukan operasi perpangkatan.");
	printf("\n2. Gunakan '*' atau 'x' untuk melakukan operasi perkalian.");
	printf("\n3. Gunakan ':' atau '/' untuk melakukan operasi pembagian.");
	printf("\n4. Gunakan '+' untuk melakukan operasi penjumlahan.");
	printf("\n5. Gunakan '-' untuk melakukan operasi pengurangan.");
	printf("\n6. Gunakan '2v' untuk melakukan operasi akar pangkat 2.");
	printf("\n7. Dapat menambahkan '(' dan ')' ke dalam operasi perhitungan.");
	printf("\n8. Bilangan yang berlaku adalah bilangan bulat dan bilangan desimal.");
	printf("\n9. Dilarang untuk menggunakan spasi. \n");
	printf("\n\n");
	system("PAUSE");
	system("cls");
	puts("\n\t\t\t Aplikasi Kalkulator \n");
	printf("Lakukan perhitungan :\n\n"); 
	scanf("%s", input);
	InfixToPostfix(input, postfix);
	printf("\n");
	expTree = BuildExpressionTree(postfix);
	printf("\n\n");
	ShowInfoTree(expTree);
	printf("\n\n");
	printf("= %.2f\n", CalculationOfTree(expTree)); 
	
}

void About(){
	system("cls");
	printf("\n\t\t\t About \n");
	printf("\nAplikasi Kalkulator ini dibuat oleh kelompok ARFILA");
	printf("\nKelas 1B-D4 Teknik Informatika, yang beranggotakan : ");
	printf("\n  1. Fiora Berliana Putri - 201524045");
	printf("\n  2. Lamda Richo Vanjaya Sumaryadi - 201524049");
	printf("\n  3. Muhamad Aryadipura Sasmita Atmadja - 201524054");
	printf("\nUntuk memenuhi Tugas Besar mata kuliah Struktur Data dan Algoritma.\n");
}

int mainMenu(){
	int i;
	int nomor;
	
	while(i <= 100) {
		puts("\n\t\t Aplikasi Kalkulator \t\t");
		puts("\nMain Menu\n ");
		puts("1. Kalkulator");
		puts("2. About");
		puts("3. Exit");
		printf("Masukkan pilihan sesuai nomor : ");
		scanf("%d", &nomor);
		switch(nomor) {	
		    case 1 :
		    	MenuKalkulator();
				break;
			case 2 : 
				About();
				break;
			case 3 :
				system("cls");
				puts("\nTerima Kasih sudah menggunakan aplikasi kami..");
				return 0;
				break;
			default :
				puts("\nNomor yang Anda masukkan tidak valid!");
		}
		printf("\n");
		system("PAUSE");
		system("cls");
	}
}
