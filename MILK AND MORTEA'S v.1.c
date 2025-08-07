#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct orders{
	char name[50];
	char email[50];
	char time[50];
	char date[50];
	long long int phoneN;
};
	struct orders ord;

void mainmenu(void);
void customer(void);
void menu(void);
void order(void);
void admin(void);
void adminacc(void);

char items[][50] = {"HAZLENUT", "RED VELVET", "DARK CHOCO", "MATCHA", "CLASSIC", "WINTERMELON", "TARO", "CHOCOLATE", "STRAWBERRY", "BELGIAN CHOCO", "FRESH MILK", "COFFEE CARAMEL"};
char toppN[][50] = {"PEARL", "CREAMPUFF", "NATA", "BIGPEARL", "CHEESECAKE"};

	int itemPL[] = {65, 65, 65, 65, 65, 65, 65, 65, 65, 100, 100, 100};
	int itemPLG[] = {85, 85, 85, 85, 85, 85, 85, 85, 85, 120, 120, 120};
	int toppP[] = {10, 10, 10, 15, 20};

	double totald;
	
int main()
{
	system("cls");
	mainmenu();
	return 0;
}
	
void mainmenu(void)
{
	
	int choice;
	
	system("cls");
	printf("\t\t________________________________________________________________\n");
	printf("\t\t||=============MILK N' MORTEA'S ORDER TAKER SYSTEM============||\n");
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
	
			system("cls");
			customer();
			break;
		
		case 2:
			
			system("cls");
			adminacc();
			break;
		
		case 3:
			system("cls");
			printf("\t\t________________________________________________________________\n");
			printf("\t\t||                                                            ||\n");
			printf("\t\t||                   THANK YOU FOR USING                      ||\n");
			printf("\t\t||          MILK AND MORTEA'S ORDER TAKER SYSTEM!!            ||\n");
			printf("\t\t||                Shum Shum Slippedy Dop! <3                  ||\n");
			printf("\t\t||                                                            ||\n");
			printf("\t\t________________________________________________________________\n");
			
			
			strcpy(ord.date,__DATE__);
			
			FILE*sav;
			
			sav=fopen("CustomerInfo.txt","a");
			fprintf(sav,"\nGathered Info on ==> %s", ord.date);
			fprintf(sav,"\n===============================\n\n");
			fclose(sav);
			
			sav=fopen("CustomerOrder.txt","a");
			fprintf(sav,"\n\n\t\t\tGathered Info on ==> %s", ord.date);
			fprintf(sav,"\n=======================================================================================\n\n");
			fclose(sav);
		
			sav=fopen("DailyIncome.txt","a");
			fprintf(sav,"\n\t\t\tDATE: %s", ord.date);
			fprintf(sav,"\n\t\t\tTotal Income: %.2lf\n", totald);
			fclose(sav);	
			
			exit(0);
			
			break;
			
		default: 
			printf("\t\tWrong input option... \n\n \t\tClick any button to input proper option...");
			getch();
			mainmenu();
	}
}
	
void customer(void)
{
	int c;
	
	system("cls");
	printf("\t\t________________________________________________________________\n");
	printf("\t\t||=============MILK N'MORTEA'S ORDER TAKER SYSTEM=============||\n");
	printf("\t\t||                                                            ||\n");
	printf("\t\t|| 1. Take Orders                                             ||\n");
	printf("\t\t|| 2. View Orders                                             ||\n");
	printf("\t\t|| 3. Main menu                                               ||\n");
	printf("\t\t||                                                            ||\n");
	printf("\t\t|| Enter your choice                                          ||\n");
	printf("\t\t________________________________________________________________\n");
	
	scanf("%d", &c);
				
	fgetc(stdin);
	
	if (c==1)
	{
		system("cls");
			printf("\n\n\t\tPlease enter the name of the customer:\t");
			fgets(ord.name, sizeof(ord.name), stdin);
			printf("\n\n\t\tPlease enter your Email:\t");
			fgets(ord.email, sizeof(ord.email), stdin);
			printf("\n\n\t\tPlease enter your Phone Number:\t");
			scanf("%lld", &ord.phoneN);
			strcpy(ord.date,__DATE__);
			strcpy(ord.time,__TIME__);
			printf("\n\t\tPress any butoon to proceed...");
			
			FILE*orde;
			orde=fopen("CustomerInfo.txt","a");
			fprintf(orde,"Customer name: %s\n", ord.name);
			fprintf(orde,"Time ordered: %s\n", ord.time);
			fprintf(orde,"Email: %s", ord.email);
			fprintf(orde,"Phone Nmber: %lld\n", ord.phoneN);
			fclose(orde);
			
			FILE*cust;
			cust=fopen("CustomerOrder.txt","a");
			fprintf(cust,"Customer name: %s", ord.name);
			fprintf(cust,"Time ordered: %s\n\n", ord.time);
			fprintf(cust,"Beverage\t\tQty \tToppings\tTop/sink \t Beverage\n");
			fprintf(cust,"Name    \t\t    \tsinkers\t\tPrice            Price\n\n");
			fclose(cust);
				getch();
				menu();
	}
	
	else if (c==2)
	{
		system("cls");
		FILE*Oinfo;
		char v;
		Oinfo=fopen("CustomerOrder.txt","r");
		while((v=fgetc(Oinfo))!=EOF)
		{
			printf("%c",v);
		}
		if(getch())
		customer();
	}
	else if (c==3)
	{
		system("cls");
		mainmenu();
	}
	
	else 
	{
		printf("\tWrong input value! Try again...\n\n");
		if(getch())
		customer();
		}

	}
	
void menu(void)
{
	
	int itemofp = sizeof(items)/50;
	int itemoftop = sizeof(toppN)/50;
	
	system("cls");
	printf("\t\t  =================NONSTOP=================\n");
	
	int longest = 0;
	int i;
	for (i = 0; i < itemofp; i++){
		if (longest < strlen(items[i])){
			longest = strlen(items[i]);	
		}
	}
	
	printf("\t\tCode\tBeverage Name       Large      Grande");
	for (i = 0; i <  itemofp-3; i++){
		printf("\n\t\t%d\t%s", i+1, items[i]);
		int numberofS = longest - strlen(items[i]) + 7;
		int j;
		for (j = 0; j < numberofS; j++)
			printf(" ");
		printf("%d  \t %d", itemPL[i], itemPLG[i]);
	
	}
	printf("\n\n");
	
	printf("\t\t  ==============EXTRAORDINARY==============\n");
	
	printf("\t\tCode\tBeverage Name       Large       Grande");
	for (i = 9; i <  itemofp; i++){
		printf("\n\t\t%d\t%s", i+1, items[i]);
		int numberofS = longest - strlen(items[i]) + 7;
		int j;
		for (j = 0; j < numberofS; j++)
			printf(" ");
		printf("%d  \t %d", itemPL[i], itemPLG[i]);
		}
	printf("\n\n");
	
	printf("\t\t  ==============TOPPINGS/SINKERS============\n");

	for (i = 0; i < itemoftop; i++){
		if (longest < strlen(toppN[i])){
			longest = strlen(toppN[i]);	
		}
	}
	
	printf("\t\tCode\tToppings Name   \tPrice");
	for (i = 0; i <  itemoftop; i++){
		printf("\n\t\t%d\t%s", i+1, toppN[i]);
		int numberofS = longest - strlen(toppN[i]) + 5;
		int j;
		for (j = 0; j < numberofS; j++)
			printf(" ");
		printf("\t %d", toppP[i]);
	}
	printf("\n\n");
	order();
}
	
void order(void)
{
	
	double total, change;
	int qt, oks=0, C, enter, SL, cash, ST;
	char size; 
	
	while (oks == 0)
	{	
	printf("\t\tEnter 1==> NONSTOP\n\t\tEnter 2==> Extraondinary\n\t\tEnter 3==> Exit\n\t\tEnter 0==> Payment\n\t\t\tYour Choice ==> ");
	scanf("%d", &enter);
	
	switch(enter){
	FILE*cust;	
	FILE *orde;
	
	case 0:
	while (oks == 0){
	
	system ("cls");
	printf("\n\n\t\t\t\t\tPAYMENT");
	printf("\n\n\n\t\t\t\tTotal: %.2lf", total);
	printf("\tCash: ");
	scanf("%d", &cash);
	
		if (cash < total)
			{printf("\n");}	

		else if (cash >= total){
			change = cash - total;
			printf("\t\t\t\t\t\tChange: %.2lf", change);
			totald += total;
			
		if (getch())
		
			orde=fopen("CustomerInfo.txt","a");
				fprintf(orde,"Total Amount: %.2lf ", total);
				fprintf(orde,"\tCash: %d\n", cash);
				fprintf(orde,"\t\t\tChange: %2.lf\n\n", change);
				fclose(orde);
			
			cust=fopen("CustomerOrder.txt","a");
				fprintf(cust,"\n\t\t\t\t\t\t     Grand Total: %.2lf \n\n", total);
				fclose(cust);
		customer();
		}
	}		
		break;
			
	case 1:
	printf("\n\t\t\tNONSTOP\n");	
	printf("\t\t\tCustomer Order: ");
	scanf("%d", &C);	
	printf("\n\t\t\t%s\n", items[C-1]);
	printf("\t\t\tQuantity: \t");
		scanf("%d", &qt);
		printf("\t\t\tLarge ==> L \tGrande ==> G");
		printf("\n\t\t\tSize: ");
		scanf("%s", &size);
			if (size == 'L' || size == 'l'){
				printf("\t\t\tPrice: %d", itemPL[0]);
				total = total + itemPL[0]*qt;
				printf("\t\t\tSugar Level: ");
					scanf("%d", &SL);
				printf("\n\t\t\tSinkers/Toppings: ");
					scanf("%d", &ST);
					if (ST > 0){
					printf("\t\t\t %s \tPrice: %d", toppN[ST-1], toppP[ST-1]);
						total = total + toppP[ST-1]*qt;
						
							cust=fopen("CustomerOrder.txt","a");
							fprintf(cust,"%s \t\t%d \t%s \t\t%d \t\t  %d\n",items[C-1], qt, toppN[ST-1], toppP[ST-1], itemPL[0]);
							fclose(cust);}
						
						else if (ST == 0){	
						printf("\t\t\tNONE");
						
							cust=fopen("CustomerOrder.txt","a");
							fprintf(cust,"%s \t\t%d  \tNONE \t\t0 \t\t  %d\n", items[C-1], qt, itemPL[0]);
								fclose(cust);}
						else
						{printf(" ");}
							
					printf("\n\t\t\t\t\tTotal cash to pay: %.2lf\n\n", total);}
					
		
			else if (size == 'G' || size == 'g'){
				printf("\t\t\tPrice: %d", itemPLG[0]);
				total = total + itemPLG[0]*qt;
				printf("\t\t\tSugar Level: ");
					scanf("%d", &SL);
				printf("\n\t\t\tSinkers/Toppings: ");
					scanf("%d", &ST);
					if (ST > 0){
					printf("\t\t\t %s \tPrice: %d", toppN[ST-1], toppP[ST-1]);
						total = total + toppP[ST-1]*qt;
						
						cust=fopen("CustomerOrder.txt","a");
						fprintf(cust,"%s \t\t%d  \t%s \t\t%d \t\t  %d\n", items[C-1], qt, toppN[ST-1], toppP[ST-1], itemPLG[0]);
							fclose(cust);}
							
						else if (ST == 0){
					printf("\t\t\tNONE");
					
							cust=fopen("CustomerOrder.txt","a");
							fprintf(cust,"%s \t\t%d  \tNONE \t\t0 \t\t  %d\n",items[C-1], qt, itemPLG[0]);
								fclose(cust);}
						else
					{printf(" ");}
							
					printf("\n\t\t\t\tTotal cash to pay: %.2lf\n\n", total );}
		getch();	
		break;
		
	case 2:
		
	printf("\n\t\t\tEXTRAORDINARY\n");	
	printf("\t\t\tCustomer Order: ");
	scanf("%d", &C);
	printf("\n\t\t\t%s\n", items[C-1]);
		printf("\t\t\tQuantity: ");
		scanf("%d", &qt);
		printf("\t\t\tLarge ==> L \tGrande ==> G");
		fgetc(stdin);
		printf("\n\t\t\tSize: ");
		scanf("%s", &size);
			if (size == 'L' || size == 'l'){
				printf("\t\t\tPrice: %d", itemPL[10]);
				total = total + itemPL[10]*qt;
				printf("\t\t\tSugar Level: ");
					scanf("%d", &SL);
				printf("\n\t\t\tSinkers/Toppings: ");
					scanf("%d", &ST);
					if (ST > 0){
					printf("\t\t\t %s \tPrice: %d", toppN[ST-1], toppP[ST-1]);
						total = total + toppP[ST-1]*qt;
						
						cust=fopen("CustomerOrder.txt","a");
						fprintf(cust,"%s \t\t%d  \t%s \t\t%d \t\t  %d\n",items[C-1], qt, toppN[ST-1], toppP[ST-1], itemPL[10]);
							fclose(cust);}
							
						else if (ST == 0){
					printf("\t\t\tNONE");
						cust=fopen("CustomerOrder.txt","a");
						fprintf(cust,"%s \t\t%d  \tNONE \t\t0 \t\t  %d\n",items[C-1], qt, itemPL[10]);
							fclose(cust);}
						else
						{printf(" ");}
							
					printf("\n\t\t\t\tTotal cash to pay: %.2lf\n\n", total);}
				
			else if (size == 'G' || size == 'g'){
				printf("\t\t\tPrice: %d", itemPLG[10]);
				total = total + itemPLG[10]*qt;
				printf("\t\t\tSugar Level: ");
					scanf("%d", &SL);
				printf("\n\t\t\tSinkers/Toppings: ");
					scanf("%d", &ST);
					if (ST > 0){
				printf("\t\t\t %s \tPrice: %d", toppN[ST-1], toppP[ST-1]);
					total = total + toppP[ST-1]*qt;
					
					cust=fopen("CustomerOrder.txt","a");
					fprintf(cust,"%s \t\t%d  \t%s \t\t%d \t\t  %d\n",items[C-1], qt, toppN[ST-1], toppP[ST-1], itemPLG[10]);
						fclose(cust);}
					
					else if (ST == 0){
					printf("\t\t\tNONE");	
					
						cust=fopen("CustomerOrder.txt","a");
						fprintf(cust,"%s \t\t%d  \tNONE \t\t0 \t\t  %d\n",items[C-1], qt, itemPLG[10]);
							fclose(cust);}
					else
					{printf(" ");}
					
					printf("\n\t\t\t\tTotal cash to pay: %.2lf\n\n", total);}
		getch();	
		break;
	
	case 3:
		
		cust=fopen("CustomerInfo.txt","a");
		fprintf(cust,"\n=====Order Cancelled=====\n\n");
		fclose(cust);
		
		cust=fopen("CustomerOrder.txt","a");
		fprintf(cust,"\n\t\t\t===========Order Cancelled===========\n\n");
		fclose(cust);
		
		system("cls");	
		customer();	
		break;
	
	default:
		printf("\tWrong input value! Try again...\n\n");
		if(getch())
		system("cls");
		menu();
	
		}
	}
}
	
void adminacc(void)
{
	system("cls");
	int ID;
	int password;
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
	
void admin(void)
{
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
		printf("\n\t\t=============MILK N' MORTEA'S DAILY INCOME=============\n");
		
		FILE*Onfo;
		Onfo=fopen("DailyIncome.txt","r");
		while((v=fgetc(Onfo))!=EOF)
		{
			printf("%c", v);
		}
		strcpy(ord.date,__DATE__);
		printf("\n\n\t\t\tDATE: %s", ord.date);
		printf("\n\t\t\tTotal Income: %.2lf", totald);
		
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
		if(getch())
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
	
