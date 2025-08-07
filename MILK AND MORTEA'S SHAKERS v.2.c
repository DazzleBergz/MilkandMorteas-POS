#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct orders{
	char customer[50];
	char date[50];
};

struct orders ord;

void mainmenu(void);
void customer(void);
void vieword(void);

void menu(void);
void menutea(void);
void menushakes(void);
void menuMmeal(void);

void orderMmeal(void);
void ordertea(void);
void ordershakes(void);

void vieworders(void);
void payment(void);

void receipt(void);
void nextcustomer(void);
void save(void);

void adminacc(void);
void admin(void);
	
	char tea[][50] = { "HAZLENUT", "RED VELVET", "DARK CHOCO", "MATCHA", "CLASSIC", "WINTERMELON", "TARO", "CHOCOLATE", "STRAWBERRY", "BELGIAN CHOCO", "NUTELLA OVERLOAD", "COFFEE CARAMEL"};
	char shake[][50] = { "STRAWBERY", "BLACK FOREST", "BUCO PANDAN", "CAPPUCCINO", "CHOCO MOUSE", "LECHE FLAN", "AVOCADO"};
	char Mmeal[][50] = { "BURGER", "FRIES", "SPAGHETTI", "FOOTLONG", "NACHOS", "MOJOS"};
	
	int teaPL[] = {65, 65, 65, 65, 65, 65, 65, 65, 65, 100, 100, 100};
	int teaPLG[] = {85, 85, 85, 85, 85, 85, 85, 85, 85, 120, 120, 120};
	int shakePL[] = {25, 25, 25, 25, 25, 30, 30};
	int shakePLG[] = {35, 35, 35, 35, 35, 40, 40};
	int MmealP[] = {20, 20, 30, 25, 25, 50};

	int teaLQty[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int teaGQty[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int shakeLQty[] = {0, 0, 0, 0, 0, 0, 0};
	int shakeGQty[] = {0, 0, 0, 0, 0, 0, 0};
	int MmealQty[] = {0, 0, 0, 0, 0, 0};
		
	int itemofTea = sizeof(tea)/50;
	int itemofShake = sizeof(shake)/50;
	int itemofMmeal = sizeof(Mmeal)/50;
	
	int choice;
	float total;
	double totalA = 0;
	int i;

int main(){
	
	system("cls");
	mainmenu();
}

void mainmenu(void){
	
	int choice;
	system("cls");
	printf("\t\t________________________________________________________________\n");
	printf("\t\t||============MILK AND MORTEA'S ORDER TAKER SYSTEM============||\n");
	printf("\t\t||                                                            ||\n");
	printf("\t\t|| 1. Customers Section                                       ||\n");
	printf("\t\t|| 2. Admin Section                                           ||\n");
	printf("\t\t|| 3. Exit                                                    ||\n");
	printf("\t\t||                                                            ||\n");
	printf("\t\t|| Enter your choice                                          ||\n");
	printf("\t\t________________________________________________________________\n");
	
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			customer();
			break;
		
		case 2:
			adminacc();
			break;
		
		case 3:
			system("cls");
			printf("\t\t________________________________________________________________\n");
			printf("\t\t||                                                            ||\n");
			printf("\t\t||                  THANK YOU FOR USING                       ||\n");
			printf("\t\t||               MLIK AND MORTEA'S SYSTEM!!                   ||\n");
			printf("\t\t||                Shum Shum Slippedy Dop! <3                  ||\n");
			printf("\t\t||                                                            ||\n");
			printf("\t\t________________________________________________________________\n");
			
			strcpy(ord.date,__DATE__);
			
			FILE*sav;
			
			sav=fopen("DailyInc.txt","a");
			fprintf(sav,"\n\t\t\tDATE: %s", ord.date);
			fprintf(sav,"\n\t\t\tTotal Income: %.2lf\n", totalA);
			fclose(sav);
			
			exit(0);
		
		default: 
			printf("\t\tWrong input option... \n\n \t\tClick any button to input proper option...");
			getch();
			mainmenu();
	}
}

void customer(void){
	
	int c;
	
	system("cls");
	printf("\t___________________________________________________________________________\n");
	printf("\n\t1. Customer Order\n\t2. View Orders\n\t3. Main menu\n\n\nEnter your option--> ");
	printf("\n\n\t___________________________________________________________________________\n");
	scanf("%d", &c);
	
	fgetc(stdin);
	switch(c){
		case 1:
			system("cls");
			printf("\n\n\t\tPlease enter the name of the customer:\t");
			fgets(ord.customer,50,stdin);
			ord.customer[strlen(ord.customer)-1]=0;
			strcpy(ord.date,__DATE__);
			printf("\n\t\tPress any butoon to proceed...");
				getch();
				menu();
			break;
			
		case 2:
			system("cls");
			FILE*Oinfo;
			char v;
			Oinfo=fopen("Receipt.txt","r");
			while((v=fgetc(Oinfo))!=EOF)
			{
				printf("%c",v);
			}
			if(getch())
			customer();
			break;
			
		case 3:
			mainmenu();
			break;
			
		default: 
			printf("\t\tWrong input option... \n\n \t\tClick any button to input proper option...");
			getch();
			menu();
	}
}
		
void menu(void){
	
	system("cls");
	vieworders();
	printf("\t___________________________________________________________________________\n");
	printf("\n\t[1] Milk Tea \t\t\t[4] Paymet\n");
	printf("\n\t[2] Shakers \t\t\t[5] Exit\n");
	printf("\n\t[3] Meryenda Meal\n\n\nEnter your option--> ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			
			menutea();
			break;
		
		case 2:
			
			menushakes();
			break;
		
		case 3:
			
			menuMmeal();
			break;
		
		case 4:
			payment();
			break;
			
		case 5:
			
		for (i=0; i<itemofTea; i++)
			{
			teaLQty[i] = 0;
			teaGQty[i] = 0;
			}
		
			for (i=0; i<itemofShake; i++)
			{
			shakeLQty[i] = 0;
			shakeGQty[i] = 0;
			}
			
				for (i=0; i<itemofMmeal; i++)
				{
				MmealQty[i] = 0;
				}
		
		total = 0;
		mainmenu();
		break;
			
		default:
			printf("Wrong input... Try an appropriate number!");
			getch();
			menu();
			break;
	}
}	

void menutea(void){

	system("cls");
	printf("\t\t  =================NONSTOP=================\n");
	
	int longest = 0;
	int i;
	for (i = 0; i < itemofTea; i++){
		if (longest < strlen(tea[i])){
			longest = strlen(tea[i]);	
		}
	}
	
	printf("\t\tCode\tBeverage Name       Large      Grande");
	for (i = 0; i <  itemofTea-3; i++){
		printf("\n\t\t%d\t%s", i+1, tea[i]);
		int numberofS = longest - strlen(tea[i]) + 5;
		int j;
		for (j = 0; j < numberofS; j++)
			printf(" ");
		printf("%d  \t %d", teaPL[i], teaPLG[i]);
	
	}
	printf("\n\n");
	
	printf("\t\t  ==============EXTRAORDINARY==============\n");
	
	for (i = 0; i < itemofTea; i++){
		if (longest < strlen(tea[i])){
			longest = strlen(tea[i]);	
		}
	}
	
	printf("\t\tCode\tBeverage Name       Large       Grande");
	for (i = 9; i <  itemofTea; i++){
		printf("\n\t\t%d\t%s", i+1, tea[i]);
		int numberofS = longest - strlen(tea[i]) + 5;
		int j;
		for (j = 0; j < numberofS; j++)
			printf(" ");
		printf("%d  \t %d", teaPL[i], teaPLG[i]);
		}
	printf("\n\n");
	
	ordertea();
	}

void menushakes(void){
	
	system("cls");
	printf("\t\t  =================SHAKERS=================\n");
	
	int longest = 0;
	int i;
	for (i = 0; i < itemofShake; i++){
		if (longest < strlen(shake[i])){
			longest = strlen(shake[i]);	
		}
	}
	
	printf("\t\tCode\tBeverage Name       Large      Grande");
	for (i = 0; i < itemofShake; i++){
		printf("\n\t\t%d\t%s", i+1, shake[i]);
		int numberofS = longest - strlen(shake[i]) + 9;
		int j;
		for (j = 0; j < numberofS; j++)
			printf(" ");
		printf("%d  \t %d", shakePL[i], shakePLG[i]);
	}
	printf("\n\n");
	
	ordershakes();
	
}	

void menuMmeal(void){
	
	system("cls");
	printf("\t\t  ==============MERYENDA MEAL==============\n");
	
	int longest = 0;
	int i;
	for (i = 0; i < itemofMmeal; i++){
		if (longest < strlen(Mmeal[i])){
			longest = strlen(Mmeal[i]);	
		}
	}
	
	printf("\t\tCode\tBeverage Name\t    Price");
	for (i = 0; i <  itemofMmeal; i++){
		printf("\n\t\t%d\t%s", i+1, Mmeal[i]);
		int numberofS = longest - strlen(Mmeal[i]) + 12;
		int j;
		for (j = 0; j < numberofS; j++)
			printf(" ");
		printf("%d ", MmealP[i]);
	}
	printf("\n\n");
	
	orderMmeal();
}

	int code, qty, cash;
	float change;

void ordertea(void){
	
	int enter, top, SL;
	char size;
	
	printf("\t\tEnter 1==> Take Order\n\t\tEnter 0==> Exit\n\t\t\tYour Choice ==> ");
	scanf("%d", &enter);
	
	switch(enter){
	
	case 1:
		printf("\t\tCode: ");
		scanf("%d", &code);
		if (code >= 1)
		{
		 	fgetc(stdin);
			printf("\t\tL ==> Large\n\t\tG ==> 1Liter");
			printf("\t\t\tSize: ");
			scanf("%s", &size);
			
			if(size == 'L' || size == 'l'){
			printf("\n\t\tQuantity: ");
			scanf("%d", &qty);
			teaLQty[code-1] += qty;
			total += teaPL[code - 1] * qty;
			}
			
			else if (size == 'G' || size == 'g'){
			printf("\n\t\tQuantity: ");
			scanf("%d", &qty);
			teaGQty[code-1] += qty;
			total += teaPLG[code - 1] * qty;
			}
		}
		
		else{
			printf("Wrong input... Try an appropriate code!");
		}
		printf("\n\t\tSugar Level: ");
		scanf("%d", &SL);
		menu();
		
	break;
	
	case 0:
		menu();
		
		break;
		
	default: 
			printf("\t\tWrong input option... \n\n \t\tClick any button to input proper option...");
			getch();
			system("cls");
			menu();	
		}
	}

void ordershakes(void){
	
	int enter, SL;
	char size;
	
	printf("\t\tEnter 1==> Take Order\n\t\tEnter 0==> Exit\n\t\t\tYour Choice ==> ");
	scanf("%d", &enter);
	
	switch(enter){
	
	case 1:
		printf("\t\tCode: ");
		scanf("%d", &code);
		if (code >= 1)
		{
		 	fgetc(stdin);
			printf("\t\tL ==> Large\n\t\tG ==> 1Liter");
			printf("\t\t\tSize: ");
			scanf("%s", &size);
			
			if(size == 'L' || size == 'l'){
			printf("\n\t\tQuantity: ");
			scanf("%d", &qty);
			shakeLQty[code-1] += qty;
			total += shakePL[code - 1] * qty;
			}
			
			else if (size == 'G' || size == 'g'){
			printf("\n\t\tQuantity: ");
			scanf("%d", &qty);
			shakeGQty[code-1] += qty;
			total += shakePLG[code - 1] * qty;
			}
		}
		
		else{
			printf("Wrong input... Try an appropriate code!");
			ordershakes();
		}
		menu();
		
	break;
	
	case 0:
		menu();
		break;
		
	default: 
			printf("\t\tWrong input option... \n\n \t\tClick any button to input proper option...");
			getch();
			system("cls");
			menu();
		}
	}
	
void orderMmeal(void){
	
	int enter;
	
	printf("\t\tEnter 1==> Take Order\n\t\tEnter 0==> Exit\n\t\t\tYour Choice ==> ");
	scanf("%d", &enter);
	
	switch(enter){
	
	case 1:
		printf("\t\tCode: ");
		scanf("%d", &code);
		if (code >= 1)
		{
		 	fgetc(stdin);
			printf("\n\t\tQuantity: ");
			scanf("%d", &qty);
			MmealQty[code-1] += qty;
			total += MmealP[code - 1] * qty;
			}

		else{
			printf("Wrong input... Try an appropriate code!");
			orderMmeal();
		}
		menu();
		
	break;
	
	case 0:
		menu();
		break;
		
	default: 
			printf("\t\tWrong input option... \n\n \t\tClick any button to input proper option...");
			getch();
			system("cls");
			menu();	
		}
	}
		
void vieworders(void){
	
	int i;
	system("cls");
	printf("\n\n\t\t\t\t====Review Orders====\n\n");
	
		int longest = 0;
		for (i = 0; i < itemofTea; i++){
		if (longest < strlen(tea[i])){
			longest = strlen(tea[i]);	
		}
	}
		for (i = 0; i < itemofShake; i++){
		if (longest < strlen(shake[i])){
			longest = strlen(shake[i]);	
		}
	}
		for (i = 0; i < itemofMmeal; i++){
		if (longest < strlen(Mmeal[i])){
			longest = strlen(Mmeal[i]);	
		}
	}

		for (i=0; i<itemofTea; i++){
		if (teaLQty[i] > 0){
		
		printf("\n\t\t%s", tea[i]);
			int numberofS = longest - strlen(tea[i]);
			int j;
			for (j = 0; j < numberofS; j++)
				printf(" ");
		printf("Price: %d  Qty: %d   Subtotal: %d", teaPL[i], teaLQty[i], teaPL[i] * teaLQty[i]);
	}
		}
	
			for (i=0; i<itemofTea; i++){
			if (teaGQty[i] > 0){
				printf("\n\t\t%s", tea[i]);
				int numberofS = longest - strlen(tea[i]);
				int j;
				for (j = 0; j < numberofS; j++)
					printf(" ");
			printf("Price: %d  Qty: %d   Subtotal: %d", teaPLG[i], teaGQty[i], teaPLG[i] * teaGQty[i]);
		}
			}
				
				for (i=0; i<itemofShake; i++){
				if (shakeLQty[i] > 0){
					printf("\n\t\t%s", shake[i]);
					int numberofS = longest - strlen(shake[i]);
					int j;
					for (j = 0; j < numberofS; j++)
					printf(" ");
				printf("Price: %d  Qty: %d   Subtotal: %d", shakePL[i], shakeLQty[i], shakePL[i] * shakeLQty[i]);
			}
				}
				
					for (i=0; i<itemofShake; i++){
					if (shakeGQty[i] > 0){
						printf("\n\t\t%s", shake[i]);
						int numberofS = longest - strlen(shake[i]);
						int j;
						for (j = 0; j < numberofS; j++)
						printf(" ");
					printf("Code: %d  Price: %d  Qty: %d   Subtotal: %d",  shakePLG[i], shakeGQty[i], shakePLG[i] * shakeGQty[i]);
				}
					}

						for (i=0; i<itemofMmeal; i++){
						if (MmealQty[i] > 0){
							printf("\n\t\t%s", Mmeal[i]);
							int numberofS = longest - strlen(Mmeal[i]) ;
							int j;
							for (j = 0; j < numberofS; j++)
							printf(" ");
						printf("Price: %d  Qty: %d   Subtotal: %d", MmealP[i], MmealQty[i], MmealP[i] * MmealQty[i]);
					}
						}
							
	printf("\n\n\t\t\t\t\t\t     Total: %.2f\n", total);
	}

void payment(void){	
	int oks = 0;
	
	while (oks == 0){
	system ("cls");
	printf("\n\n\n\nTotal: %.2f", total);
	printf("\tCash: ");
	scanf("%d", &cash);
	
	if (cash == 0)
	{menu();}
	
	else if (cash < total)
		{printf("\n");}
	
	else if (cash >= total){
		change = cash - total;
		printf("\t\tChange: %.2f", change);
		totalA += total;
		getch();
		receipt();
			}	
		}
	}

void receipt(void){
	
	system("cls");
	printf("\n\n\t\tMILK AND MORTEAS SHAKERS");
		printf("\n\t   -----------------------------------");
		printf("\n\tDate: %s", ord.date);
		printf("\n\tOrdered by: %s", ord.customer);
		printf("\n");
		printf("\t----------------------------------------\n");
		printf("\tName\t\t");
		printf("    Qty\t");
		printf("    Sub total\t\t");
		printf("\n\t----------------------------------------");
		
		int longest = 0;
		int i;
		for (i = 0; i < itemofTea; i++){
		if (longest < strlen(tea[i])){
			longest = strlen(tea[i]);	
		}
	}
		for (i = 0; i < itemofShake; i++){
		if (longest < strlen(shake[i])){
			longest = strlen(shake[i]);	
		}
	}
		for (i = 0; i < itemofMmeal; i++){
		if (longest < strlen(Mmeal[i])){
			longest = strlen(Mmeal[i]);	
		}
	}
	
		for (i=0; i<itemofTea; i++){
		if (teaLQty[i] > 0){
			printf("\n\t%s", tea[i]);
			int numberofS = longest - strlen(tea[i])+5;
			int j;
			for (j = 0; j < numberofS; j++)
				printf(" ");
			printf("%d\t       %d", teaLQty[i], teaPL[i] * teaLQty[i]);
			}
		}
	
			for (i=0; i<itemofTea; i++){
			if (teaGQty[i] > 0){
			printf("\n\t%s", tea[i]);
			int numberofS = longest - strlen(tea[i])+5;
			int j;
			for (j = 0; j < numberofS; j++)
				printf(" ");
			printf("%d\t       %d", teaGQty[i], teaPLG[i] * teaGQty[i]);
				}
			}
				
				for (i=0; i<itemofShake; i++){
				if (shakeLQty[i] > 0){
				printf("\n\t%s", shake[i]);
				int numberofS = longest - strlen(shake[i]) + 5;
				int j;
				for (j = 0; j < numberofS; j++)
					printf(" ");
				printf("%d \t       %d", shakeLQty[i], shakePL[i] * shakeLQty[i]);
					}
				}
				
					for (i=0; i<itemofShake; i++){
					if (shakeGQty[i] > 0){
					printf("\n\t%s", shake[i]);
					int numberofS = longest - strlen(shake[i]) + 5;
					int j;
					for (j = 0; j < numberofS; j++)
						printf(" ");
					printf("%d \t       %d", shakeGQty[i], shakePLG[i] * shakeGQty[i]);
						}
					}

						for (i=0; i<itemofMmeal; i++){
						if (MmealQty[i] > 0){
						printf("\n\t%s", Mmeal[i]);
						int numberofS = longest - strlen(Mmeal[i]) + 5;
						int j;
						for (j = 0; j < numberofS; j++)
							printf(" ");
						printf("%d\t       %d", qty,  MmealP[i]);
						}
						}
	printf("\n\t----------------------------------------\n");
	printf("\tCash\t\t\t       %d", cash);
	printf("\n\tChange\t\t\t       %.2f", change);
	printf("\n\t----------------------------------------\n");
	printf("\tGrand Total\t\t       %.2f", total);
	printf("\n\t----------------------------------------");
			getch();
		save();
}

void nextcustomer(void){
	
	char choice;
	
	system("cls");
	printf("\n\n\n\t\t\tNext Customer: [Y/N]");
	scanf("%s", &choice);
	
	if (choice == 'Y' || choice == 'y')
	{
		for (i=0; i<itemofTea; i++)
		{
			teaLQty[i] = 0;
			teaGQty[i] = 0;
		}
		
			for (i=0; i<itemofShake; i++)
			{
				shakeLQty[i] = 0;
				shakeGQty[i] = 0;
			}
			
				for (i=0; i<itemofMmeal; i++)
				{
				MmealQty[i] = 0;
				}
		
		total = 0;
		change = 0;
		menu();
	}
	
	else if (choice == 'N' || choice == 'n')
	{
		for (i=0; i<itemofTea; i++)
		{
			teaLQty[i] = 0;
			teaGQty[i] = 0;
		}
		
			for (i=0; i<itemofShake; i++)
			{
				shakeLQty[i] = 0;
				shakeGQty[i] = 0;
			}
			
				for (i=0; i<itemofMmeal; i++)
				{
				MmealQty[i] = 0;
				}
		
		total = 0;
		change = 0;
		mainmenu();
	}
}

void save(void){
	
	char choice;
	
	printf("\n\n\tDo you want to save? [Y/N]");
	scanf("%s", &choice);
	
	if(choice == 'Y' || choice == 'y'){
		
		FILE*orde;
		orde=fopen("Receipt.txt","a");
		fprintf(orde, "\n\n\tDate: %s", ord.date);
		fprintf(orde, "\n\tOrdered by: %s", ord.customer);
		fprintf(orde, "\n");
		fprintf(orde, "\t----------------------------------------\n");
		fprintf(orde, "\tName\t\t");
		fprintf(orde, "    Qty\t");
		fprintf(orde, "    Sub total\t\t");
		fprintf(orde, "\n\t----------------------------------------");
		
		int longest = 0;
		int i;
		for (i = 0; i < itemofTea; i++){
		if (longest < strlen(tea[i])){
			longest = strlen(tea[i]);	
		}
	}
		for (i = 0; i < itemofShake; i++){
		if (longest < strlen(shake[i])){
			longest = strlen(shake[i]);	
		}
	}
		for (i = 0; i < itemofMmeal; i++){
		if (longest < strlen(Mmeal[i])){
			longest = strlen(Mmeal[i]);	
		}
	}
	
		for (i=0; i<itemofTea; i++){
		if (teaLQty[i] > 0){
			fprintf(orde, "\n\t%s", tea[i]);
			int numberofS = longest - strlen(tea[i])+5;
			int j;
			for (j = 0; j < numberofS; j++)
				fprintf(orde, " ");
			fprintf(orde, "%d\t       %d", teaLQty[i], teaPL[i] * teaLQty[i]);
			}
		}
	
			for (i=0; i<itemofTea; i++){
			if (teaGQty[i] > 0){
			fprintf(orde, "\n\t%s", tea[i]);
			int numberofS = longest - strlen(tea[i])+5;
			int j;
			for (j = 0; j < numberofS; j++)
				fprintf(orde, " ");
			fprintf(orde, "%d\t       %d", teaGQty[i], teaPLG[i] * teaGQty[i]);
				}
			}
				
				for (i=0; i<itemofShake; i++){
				if (shakeLQty[i] > 0){
				fprintf(orde, "\n\t%s", shake[i]);
				int numberofS = longest - strlen(shake[i]) + 5;
				int j;
				for (j = 0; j < numberofS; j++)
					fprintf(orde, " ");
				fprintf(orde, "%d \t       %d", shakeLQty[i], shakePL[i] * shakeLQty[i]);
					}
				}
				
					for (i=0; i<itemofShake; i++){
					if (shakeGQty[i] > 0){
					fprintf(orde, "\n\t%s", shake[i]);
					int numberofS = longest - strlen(shake[i]) + 5;
					int j;
					for (j = 0; j < numberofS; j++)
						fprintf(orde, " ");
					fprintf(orde, "%d \t       %d", shakeGQty[i], shakePLG[i] * shakeGQty[i]);
						}
					}

						for (i=0; i<itemofMmeal; i++){
						if (MmealQty[i] > 0){
						fprintf(orde, "\n\t%s", Mmeal[i]);
						int numberofS = longest - strlen(Mmeal[i]) + 5;
						int j;
						for (j = 0; j < numberofS; j++)
							fprintf(orde, " ");
						fprintf(orde, "%d\t       %d", qty,  MmealP[i]);
						}
						}
	fprintf(orde, "\n\t----------------------------------------\n");
	fprintf(orde, "\tCash\t\t\t       %d", cash);
	fprintf(orde, "\n\tChange\t\t\t       %.2f", change);
	fprintf(orde, "\n\t----------------------------------------\n");
	fprintf(orde, "\tGrand Total\t\t       %.2f", total);
	fprintf(orde, "\n\t----------------------------------------");
		fclose(orde);
		printf("\n\tSuccessfully Saved!");
		getch();
		nextcustomer();
	}
	
	else if (choice == 'N' || choice == 'n'){
		nextcustomer();
	}
}

void adminacc(void){
	
	system("cls");
	int ID = 0;
	int password = 0;
	printf("\n\n\t\t\tPlese Enter Your ID:");
		scanf("%d", &ID);
	switch (ID) 
		{
		case 20211107:
			printf("\n\n\t\t\tEnter your password:");
			scanf("%d", &password);
			
				switch (password) 
				{
					case 143:
						admin();
				break;
			
				default:
				printf("\n\n\t\t\tincorrect password");
				mainmenu();
				break;
				}
		break;
		default:
			printf("\n\n\t\t\tIncorrect ID");
			mainmenu();
		break;
		}
	}
	
void admin(void){
	
	int d, load;
	char v;
	
	system("cls");
	printf("\t\t________________________________________________________________\n");
	printf("\t\t||=============MILK N' MORTEA'S ORDER TAKER SYSTEM=============||\n");
	printf("\t\t||                                                             ||\n");
	printf("\t\t|| 1. Daily Income                                             ||\n");
	printf("\t\t|| 2. Review Payments                                          ||\n");
	printf("\t\t|| 3. Main Menu                                                ||\n");
	printf("\t\t||                                                             ||\n");
	printf("\t\t|| Enter your choice                                           ||\n");
	printf("\t\t________________________________________________________________\n");
	
	scanf("\n\t\t%d", &d);
	
	for(load=0;load<=50000;load++)
	{
		printf("\rLoading: %d",load/500);
	}
	
	if (d==1)
	{
		system("cls");
		printf("\n\t\t===========MILK N' MORTEA'S SHAKERS DAILY INCOME===========\n");
		
		FILE*Onfo;
		Onfo=fopen("DailyInc.txt","r");
		while((v=fgetc(Onfo))!=EOF)
		{
			printf("%c", v);
		}
		strcpy(ord.date,__DATE__);
		printf("\n\n\t\t\tDATE: %s", ord.date);
		printf("\n\t\t\tTotal Income: %.2lf", totalA);
		
		getch();
		admin();
	}
	
	else if (d==2)
	{
		system("cls");
		FILE*info;
		info=fopen("CustomerInfo.txt","r");
		while((v=fgetc(info))!=EOF)
		{
			printf("%c",v);
		}
		getch();
		admin();
	}
	
	else if (d==3)
	{
		system("cls");
		mainmenu();
	}
	else 
	{
		printf("\tWrong input value! Try again...\n\n");
		if(getch())
		admin();
		}
	}

		
