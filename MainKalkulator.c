#include "KalkulatorTree.h"

int main(){
	int nomor;	
	do {
		system("cls");
		tampilan();
		puts("\n\t\t\tMain Menu\n ");
		puts("\t\t\t1. Kalkulator");
		puts("\t\t\t2. About");
		puts("\t\t\t3. History");
		puts("\t\t\t4. Exit");
		printf("Masukkan pilihan sesuai nomor : ");
		scanf("%d", &nomor);
		switch(nomor) {	
		    case 1 :
		    	MenuKalkulator();		    	
				break;
			case 2 : 
				system("cls");
				tampilan();
				showAbout();
				break;
			case 3 :
				system("cls");
				showHistory();
				break;
			case 4 :
				system("cls");
				tampilan();
				puts("\n\t\t\tTerima kasih telah menggunakan program kalkulator ini :)\n\n\t\t\t\t\t\t@2023");
				return 0;
				break;
			default :
				puts("\nNomor yang Anda masukkan tidak valid!");
				getchar();
				getchar();
				break;
		}
	} while (nomor != 4);
	
}


