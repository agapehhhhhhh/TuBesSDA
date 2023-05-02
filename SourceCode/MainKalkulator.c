#include "KalkulatorTree.h"

int main(){
	int i;
	int nomor;
	
	while(i<=100) {
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
				system("cls");
				showAbout();
				break;
			case 3 :
				system("cls");
				puts("\n\t\t\tTerima kasih telah menggunakan program kalkulator ini :)\n\n\t\t\t\t\t\t@2023");
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


