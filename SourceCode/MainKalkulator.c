#include "KalkulatorTree.h"

int main(){
	int input;
	
	while(true) {
		MainMenu(&input);
		switch(input) {	
		    case 1 :
		    	MenuKalkulator();
				break;
			case 2 : 
				showAbout();
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
