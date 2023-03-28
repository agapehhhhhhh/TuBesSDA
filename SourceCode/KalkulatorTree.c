/** Nama File : KalkulatorTree.c
 *  Deskripsi : File Body ADT Kalkulator
 *  Oleh      : Fiora Berliana Putri
 *  Tanggal   : 24 Juli 2021
 * 
 *  Modifikasi: Lamda Richo Vanjaya Sumaryadi
 *  Tanggal   : 25 Juli 2021 dan 31 Juli 2021
 */

#include "KalkulatorTree.h"

/* Membuat sebuah ekspresi tree dari ekspresi postfix yang sudah didapatkan. 
 * I.S. : Postfix terdefinisi.
 * F.S. : Mengembalikan ekspresi tree.
 */
BinTree BuildExpressionTree(infotypeTree postfix){
	printf("\n\n\n BUILDEXPRESSIONTREE\n");
	int i = 0, j, k;
	StackTree StackTree;
	BinTree ExpressionTree, Right, Left;
	infotypeStackTree Delete;
	infotypeTree tempOperator, tempStr;
	
	NewStackTree(&StackTree);
	printf("panjang postfix : %d\n", strlen(postfix));
	while(i < strlen(postfix)){
		//untuk operand
		if (!isOperator(postfix[i]) && postfix[i] != ' '){
			j = 0;
			tempStr[j] = postfix[i];
			printf("\npostfix bukan operator, postfix tdk kosong. POSTFIX (tempSTR[%d] : %c)\n", j, tempStr[j]);
			while(!isOperator(postfix[i+1]) && postfix[i+1] != ' '){
				tempStr[j+1] = postfix[i+1];
				printf("postfix+1 bukan operator, postfix+1 tdk kosong. POSTFIX (tempSTR[%d] : %c)\n", j+1, tempStr[j+1]);
				j++;
				i++;	
			}
			CreateNodeTree(&ExpressionTree, tempStr);
			for(k = 0; k < strlen(tempStr); k++) {
				tempStr[k] = ' ';
				printf("memasukkan postfix ke array baru, tempStr[%d]: %c\n",k,tempStr[k]);
			}
			AddStackTree(&StackTree, ExpressionTree);
			printf("Add tree\n");
		}
		//untuk kasus operasi -
		else if(postfix[i] == '-' && isOperator(postfix[i-4])) { 
		tempOperator[0] = postfix[i];
		printf("\npostfix[%d]=%c, postfix[%d]:%c = operator\n",i,postfix[i],i-4,postfix[i-4]);
		CreateNodeTree(&ExpressionTree, tempOperator);
		printf("create node tree\n");
		
		Right = Info(Top(StackTree));
		DellStackTree(&StackTree, &Delete);
							 
		Left = Info(Top(StackTree));
		DellStackTree(&StackTree, &Delete);
			
		CreateTree(tempOperator, Left, Right, &ExpressionTree);
		printf("create tree \n");
			
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
			printf("\noperasi '-', create node tree, tempOperator[0] : %c\n",tempOperator[0]);
		
			Right = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
			
			Left = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
			
			CreateTree(tempOperator, Left, Right, &ExpressionTree);
			printf("create tree \n");
			
			AddStackTree(&StackTree, ExpressionTree); 
		}
		//untuk operator
		else if(postfix[i] != ' ') { 
			tempOperator[0] = postfix[i];
			CreateNodeTree(&ExpressionTree, tempOperator);
			printf("\noperasi ' ', create node tree, tempOperator[0] : %c\n",tempOperator[0]);
		
			Right = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
			
			Left = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
			
			CreateTree(tempOperator, Left, Right, &ExpressionTree);
			printf("create tree \n");
			
			AddStackTree(&StackTree, ExpressionTree); 
		}
		i++;					
	}
	ExpressionTree = Info(Top(StackTree));
	DellStackTree(&StackTree, &ExpressionTree);
	return ExpressionTree;
}

/* Mengkonversi ekspresi infix menjadi ekspresi postfix.
 * I.S. : Infix terdefinisi.
 * F.S. : Infix berhasil dikonversi menjadi ekspresi postfix.
 */
void InfixToPostfix(String infix, String postfix){
	int i, ukuran, index = 0;
	char tempChar;
    StackChar temp;
    
    NewStackChar(&temp);
    
    ukuran = strlen(infix);
    for(i = 0; i < ukuran; i++) {
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
                printf("\nCASE 1\n");
                printf("postfix1[%d] = '%c'\n", index, postfix[index]);
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
                postfix[index] = ' ';
                printf("\nCASE 2\n");
                printf("postfix2[%d] = '%c'\n", index, postfix[index]);
                index++;            
                if(isEmptyStackChar(temp)){
                    AddStackChar(&temp,infix[i]);
                    printf("EMPTY->temp infix[%d] = '%c'\n", i, infix[i]);
                }
				else if(!isPriority(Info(Top(temp)),infix[i])){
                    AddStackChar(&temp,infix[i]);
                    printf("NON-PRIOR->Top infix[%d] = '%c'\n", i, infix[i]);
                }
				else{
                    while(!isEmptyStackChar(temp)&&isPriority(Info(Top(temp)),infix[i])){
                    	printf("temp = '%c' tempChar = '%c'\n", temp, tempChar);
                        DellStackChar(&temp,&tempChar);
                        postfix[index] = tempChar;
                        printf("postfix[%d] = '%c'\n", index, postfix[index]);
                        index++;
                    }                
                    AddStackChar(&temp,infix[i]);
                    printf("infix[%d] = '%c'\n", i, infix[i]);
                }
                break;
            case ')':
                while(!isEmptyStackChar(temp)&&Info(Top(temp))!='('){
                    DellStackChar(&temp,&tempChar);
                    postfix[index] = tempChar;
                    printf("\nCASE 3\n");
                    printf("NOT EMPTY, infotop!=')', DEL, postfix[%d] = '%c'\n", index, postfix[index]);
                    index++;                    
                }
                DellStackChar(&temp,&tempChar);
                printf("delete\n");
                break;
            case '(':
                AddStackChar(&temp,infix[i]);
                printf("\nCASE 4\n");
                printf("ADD, '(', infix[%d] = '%c'\n", i, infix[i]);
                break;
        }
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
}

