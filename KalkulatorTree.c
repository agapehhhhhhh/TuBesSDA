/** Nama File : KalkulatorTree.c
 *  Deskripsi : File Body ADT Kalkulator
 *  Oleh      : Fiora Berliana Putri
 *  Tanggal   : 24 Juli 2021
 * 
 *  Modifikasi: Lamda Richo Vanjaya Sumaryadi
 *  Tanggal   : 25 Juli 2021 dan 31 Juli 2021
 */

#include "KalkulatorTree.h"

void MenuKalkulator(){
	BinTree expTree;
	String postfix, input;
	
	system("cls");
	showIntruction();
	system("\nPAUSE");
	system("cls");
	puts("\n\t\t\t Aplikasi Kalkulator \n");
	displayKalkulator();
	printf("Lakukan perhitungan :\n\n"); 
	scanf("%s", input);	
	InfixToPostfix(input, postfix);
//	printf("\n");
	expTree = BuildExpressionTree(postfix);
//	printf("\n\n");
//	ShowInfoTree(expTree);
	printf("\n\n");
	printf("= %.2f\n", CalculationOfTree(expTree)); 
	
}

/* Membuat sebuah ekspresi tree dari ekspresi postfix yang sudah didapatkan. 
 * I.S. : Postfix terdefinisi.
 * F.S. : Mengembalikan ekspresi tree.
 */
BinTree BuildExpressionTree(infotypeTree postfix){
//	printf("\n\n\n BUILDEXPRESSIONTREE\n");
	int i = 0, j, k;
	StackTree StackTree;
	BinTree ExpressionTree, Right, Left;
	infotypeStackTree Delete;
	infotypeTree tempOperator, tempStr;
	
	NewStackTree(&StackTree);
//	printf("panjang postfix : %d\n", strlen(postfix));
	while(i < strlen(postfix)){
		//untuk operand
		if (!isOperator(postfix[i]) && postfix[i] != ' '){
			j = 0;
			tempStr[j] = postfix[i];
//			printf("\npostfix bukan operator, postfix tdk kosong. POSTFIX (tempSTR[%d] : %c)\n", j, tempStr[j]);
			while(!isOperator(postfix[i+1]) && postfix[i+1] != ' '){
				tempStr[j+1] = postfix[i+1];
//				printf("postfix+1 bukan operator, postfix+1 tdk kosong. POSTFIX (tempSTR[%d] : %c)\n", j+1, tempStr[j+1]);
				j++;
				i++;	
			}
			CreateNodeTree(&ExpressionTree, tempStr);
			for(k = 0; k < strlen(tempStr); k++) {
				tempStr[k] = ' ';
//				printf("memasukkan postfix ke array baru, tempStr[%d]: %c\n",k,tempStr[k]);
			}
			AddStackTree(&StackTree, ExpressionTree);
//			printf("Add tree\n");
		}
		//untuk kasus operasi -
		else if(postfix[i] == '-' && isOperator(postfix[i-4])) { 
		tempOperator[0] = postfix[i];
//		printf("\npostfix[%d]=%c, postfix[%d]:%c = operator\n",i,postfix[i],i-4,postfix[i-4]);
		CreateNodeTree(&ExpressionTree, tempOperator);
//		printf("create node tree\n");
		
		Right = Info(Top(StackTree));
		DellStackTree(&StackTree, &Delete);
							 
		Left = Info(Top(StackTree));
		DellStackTree(&StackTree, &Delete);
			
		CreateTree(tempOperator, Left, Right, &ExpressionTree);
//		printf("create tree \n");
			
		AddStackTree(&StackTree, ExpressionTree); 
		} 
		//untuk kasus operasi -
		else if((postfix[i]=='-' && postfix[i-1]==' ' && postfix[i+1]!=' ' && postfix[i+2]!=' ' && !isOperator(postfix[i+2])) || 
				(postfix[i]=='-' && postfix[i-1]!=' ' && postfix[i+1]==' ') || 
				(postfix[i]=='-' && postfix[i-1]!=' ' && isOperator(postfix[i+1])) ||
				(postfix[i]=='-' && postfix[i-1]==' ' && postfix[i+1]==' ') ||
				(postfix[i]=='-' && postfix[i-1]==' ' && postfix[i+1]!=' ' && isOperator(postfix[i+2])) ||
				(postfix[i]=='-' && postfix[i-1]!=' ' && isOperator(postfix[i+1]) && isOperator(postfix[i+2]) )) { 
			tempOperator[0] = postfix[i];
			CreateNodeTree(&ExpressionTree, tempOperator);
//			printf("\noperasi '-', create node tree, tempOperator[0] : %c\n",tempOperator[0]);
		
			Right = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
			
			Left = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
			
			CreateTree(tempOperator, Left, Right, &ExpressionTree);
//			printf("create tree \n");
			
			AddStackTree(&StackTree, ExpressionTree); 
		}
		//untuk operator
		else if(postfix[i] != ' ') { 
			tempOperator[0] = postfix[i];
			CreateNodeTree(&ExpressionTree, tempOperator);
//			printf("\noperasi ' ', create node tree, tempOperator[0] : %c\n",tempOperator[0]);
		
			Right = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
			
			Left = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
			
			CreateTree(tempOperator, Left, Right, &ExpressionTree);
//			printf("create tree \n");
			
			AddStackTree(&StackTree, ExpressionTree); 
		}
		i++;					
	}
	ExpressionTree = Info(Top(StackTree));
	DellStackTree(&StackTree, &ExpressionTree);
	return ExpressionTree;
}

void editInfix(String infix){
	int ukuran = strlen(infix);
	
	//tambahan untuk membenarkan bug sebelum kurung jika tdk ada operasi maka ditambahkan operasi perkalian
    int counter1 = 0;
    int counter2;
    while(counter1<ukuran){
    	if(infix[counter1] == '(' && counter1 != 0 && infix[counter1-1] != '+' && infix[counter1-1] != '-' && infix[counter1-1] != '*' && infix[counter1-1] != '/' && infix[counter1-1] != ':' && infix[counter1-1] != '^' && infix[counter1-1] != 'v'&& infix[counter1-1] != 's'&& infix[counter1-1] != 'c'&& infix[counter1-1] != 't'&& infix[counter1-1] != 'p'&& infix[counter1-1] != 'l'&& infix[counter1-1] != 'n'&& infix[counter1-1] != 'i'&& infix[counter1-1] != 'g'){
    		for(counter2=ukuran-1; counter2 >= counter1; counter2--){
    			infix[counter2+1]=infix[counter2];
			}
			infix[counter1] = '*';
			ukuran++;
			counter1++;
		}
    	if (infix[counter1] == 's' || infix[counter1] == 'c'|| infix[counter1] == 't'|| infix[counter1] == 'p'||infix[counter1] == 'l'){		
			infix[counter1+1]=infix[counter1];
			infix[counter1]='0';
			for(counter2=counter1+3; counter2 <= ukuran; counter2++){
    			infix[counter2-1]=infix[counter2];
    			infix[counter2] = '\0';
			}
			ukuran++;
			counter1++;
		}		
		if (infix[counter1] == '%'){
			for(counter2=ukuran-1; counter2 >= counter1; counter2--){
				infix[counter2+3]=infix[counter2];
			}
			infix[counter1] = '/';
			infix[counter1+1] = '1';
			infix[counter1+2] = infix[counter1+3] = '0';
			ukuran++;
			counter1++;
		}
		if(infix[counter1] == 'v'){
			for(counter2=ukuran-1; counter2 >= counter1; counter2--){
    			infix[counter2+1]=infix[counter2];
			}
			infix[counter1] = '0';
			ukuran++;
			counter1++;
		}
		counter1++;
	}

	int	counter = 0; 
	while(counter<ukuran){
//		printf("%c", infix[counter]);
		
		counter++;
	}
}

/* Mengkonversi ekspresi infix menjadi ekspresi postfix.
 * I.S. : Infix terdefinisi.
 * F.S. : Infix berhasil dikonversi menjadi ekspresi postfix.
 */
void InfixToPostfix(String infix, String postfix){
	editInfix(infix);
	int i=0, ukuran, index = 0;
	char tempChar;
    StackChar temp;
    
    NewStackChar(&temp);
    
    ukuran = strlen(infix);
    
    while(i<ukuran) {
        switch(infix[i]) {
        	case '.':
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                postfix[index] = infix[i];
//                printf("\nCASE 1\n");
//                printf("postfix1[%d] = '%c'\n", index, postfix[index]);
                index++;
                break;
            case '+':
            case '-':
            case '*':
            case 'x':
            case '/':
            case ':':
            case '^':
			case 'v':
			case 's':
			case 'c':
			case 't':
			case 'l':
			case 'p':
                postfix[index] = ' ';
//                printf("\nCASE 2\n");
//                printf("postfix2[%d] = '%c'\n", index, postfix[index]);
                index++;            
                if(isEmptyStackChar(temp)){
                    AddStackChar(&temp,infix[i]);
//                    printf("EMPTY->temp infix[%d] = '%c'\n", i, infix[i]);
                }
				else if(!isPriority(Info(Top(temp)),infix[i])){
                    AddStackChar(&temp,infix[i]);
//                    printf("NON-PRIOR->Top infix[%d] = '%c'\n", i, infix[i]);
                }
				else{
                    while(!isEmptyStackChar(temp)&&isPriority(Info(Top(temp)),infix[i])){
//                    	printf("temp = '%c' tempChar = '%c'\n", temp, tempChar);
                        DellStackChar(&temp,&tempChar);
                        postfix[index] = tempChar;
//                        printf("postfix[%d] = '%c'\n", index, postfix[index]);
                        index++;
                    }                
                    AddStackChar(&temp,infix[i]);
//                    printf("infix[%d] = '%c'\n", i, infix[i]);
                }
                break;
            case ')':
                while(!isEmptyStackChar(temp)&&Info(Top(temp))!='('){
                    DellStackChar(&temp,&tempChar);
                    postfix[index] = tempChar;
//                    printf("\nCASE 3\n");
//                    printf("NOT EMPTY, infotop!=')', DEL, postfix[%d] = '%c'\n", index, postfix[index]);
                    index++;                    
                }
                DellStackChar(&temp,&tempChar);
//                printf("delete\n");
                break;
            case '(':
                AddStackChar(&temp,infix[i]);
//                printf("\nCASE 4\n");
//                printf("ADD, '(', infix[%d] = '%c'\n", i, infix[i]);
                break;
        }
        i++;
    }
    while(!isEmptyStackChar(temp)) {
        DellStackChar(&temp,&tempChar);
        postfix[index] = tempChar;
        index++;
    }    
    postfix[index] = '\0';
}

/* Mengembalikan hasil kalkuasi dari ekspresi tree.
 * I.S. : P terdefinisi.
 * F.S. : Hasil kalkulasi dari P dikembalikan.
 */
float CalculationOfTree(BinTree P){
    if(IsEmptyTree(P)) {
        return 0;  
	}
	//untuk leaf node
    else if(IsEmptyTree(Left(P)) && IsEmptyTree(Right(P))) {
    	//konversi dari char ke float
        return StringToFloat(Info(P));  
    }
  
	//rekursif 
    float left = CalculationOfTree(Left(P));  
    float right = CalculationOfTree(Right(P));  
    
    if(strcmp(Info(P),"+")==0) {
		return left+right;
	}
	else if(strcmp(Info(P),"-")==0) {
		return left-right;
	}
	else if(strcmp(Info(P),"*")==0) {
		return left*right;
	}
	else if(strcmp(Info(P),"x")==0) {
		return left*right;
	}
	else if(strcmp(Info(P),"/")==0) {
		if(right != 0.00){
			return left/right;
		} else{
			puts("Tidak bisa dibagi oleh nol");
			return 0;
		}
	}
	else if(strcmp(Info(P),":")==0) {
		if(right != 0.00){
			return left/right;
		} else{
			puts("Tidak bisa dibagi oleh nol");
			return 0;
		}
	}
	else if(strcmp(Info(P),"^")==0) {
		return pow(left, right);
	}
	else if(strcmp(Info(P),"v")==0){
		return sqrt(right);
	}
	else if(strcmp(Info(P),"s")==0){
		return sin(right);
	}
	else if(strcmp(Info(P),"c")==0){
		return cos(right);
	}
	else if(strcmp(Info(P),"t")==0){
		return tan(right);
	}
	else if(strcmp(Info(P),"l")==0){
		return log10(right);
	}
	else if(strcmp(Info(P),"p")==0){
		return 3.14*right;
	}
}


void showIntruction() 
{
    FILE *FF; 
    char CC;  

    if ((FF = fopen("Instruction.txt", "r")) == NULL)
    {
        printf("Pembukaan File Gagal !");
        exit(1); 
    }

    while ((CC = getc(FF)) != EOF)
    {              
        putch(CC); 
    }

    fclose(FF);
	printf("\n\n");
}

void showAbout(){
	FILE *FF; // penunjuk ke file
    char CC;  // var penunjuk karakter yang dibaca

    if ((FF = fopen("About.txt", "r")) == NULL)
    { // Buka file mode baca
        printf("Pembukaan File Gagal !");
        exit(1); // keluar program
    }

    while ((CC = getc(FF)) != EOF)
    {              // CC akan berisi karakter yg dibaca, akhir teks dengan EOF
        putch(CC); // baca dan tampilkan ke layar
    }

    fclose(FF);
    
}

void displayKalkulator(){
			char kalku[28][40]={   // Referensi program milik kating: PowerPuffCulator
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191},
	{' ',179,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',179},
	{' ',179,' ',218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191,' ',179},
	{' ',179,' ',179,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',179,' ',179},	
	{' ',179,' ',179,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',179,' ',179},
	{' ',179,' ',179,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',179,' ',179},
	{' ',179,' ',192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217,' ',179},
	{' ',179,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',179},
	{' ',179,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',179},
	{' ',179,' ',179,' ','7',' ',179,' ',179,' ','8',' ',179,' ',179,' ','9',' ',179,' ',179,' ','/',' ',179,' ',179,' ','^',' ',179,' ',179,' ','%',' ',179,' ',179},
	{' ',179,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',179},
	{' ',179,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',179},
	{' ',179,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',179},
	{' ',179,' ',179,' ','4',' ',179,' ',179,' ','5',' ',179,' ',179,' ','6',' ',179,' ',179,' ','*',' ',179,' ',179,' ','v',' ',179,' ',179,'s','i','n',179,' ',179},
	{' ',179,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',179},
	{' ',179,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',179},
	{' ',179,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',179},
	{' ',179,' ',179,' ','1',' ',179,' ',179,' ','2',' ',179,' ',179,' ','3',' ',179,' ',179,' ','-',' ',179,' ',179,'p','h','i',179,' ',179,'c','o','s',179,' ',179},
	{' ',179,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',179},
	{' ',179,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',179},
	{' ',179,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',218,196,196,196,191,' ',179},
	{' ',179,' ',179,' ','(',' ',179,' ',179,' ','0',' ',179,' ',179,' ',')',' ',179,' ',179,' ','+',' ',179,' ',179,'l','o','g',179,' ',179,'t','a','n',179,' ',179},
	{' ',179,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',192,196,196,196,217,' ',179},
	{' ',179,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',179},
	{' ',192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	};
	
	int i, j;
	String input;
	
	for(i=0;i<28;i++){
			for(j=0;j<40;j++){
				printf("%c",kalku[i][j]);	
			}	
		printf("\n");
		}
	}