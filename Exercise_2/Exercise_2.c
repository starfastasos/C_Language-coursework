/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>


/* Struct creation */
struct client{
	char name[100];
	char surname[100];
	/* Struct creation */
	struct address{
		char street[100];
		int	number;
		int meters;	
	}Address;
	char username[150];
	char password[5];
	float cost[12][3];
}Client;

// Use of typedef
typedef struct client CLIENT;
typedef struct address ADDRESS;


/* Statement of functions */
int signup_user(int sum);
int login_user();
	void view_user();
	void modify_user();
	int calculate_cost();
	void payment();
	void most_expensive();



int main(){
	char choice1;
	int sum=0, S=0, check=0, L=1;
	do{
		/* Validation check */
		do{
			printf("--HOME SCREEN--\n\n");
			printf("a.Register\nb.Login\nc.Exit\n");
			printf("Enter your choice: ");
			scanf(" %c", &choice1);
			if(choice1!='a' && choice1!='b' && choice1!='c'){
				system("cls");
				printf("Wrong data!!! Try again.\n");		
			}
		}while(choice1!='a' && choice1!='b' && choice1!='c');
		system("cls");
		if(choice1!='c'){
			/* Sign up */
			if(choice1=='a'){
				sum++;
				/* Up to 20 registrations */
				if(sum<=20){
					S=signup_user(sum);
					check=1;
				}
				else{
					printf("The registration can not be done, because the specific customer management system has completed the required number of registrations.\n");
				}	
			}
			/* Login */		
			else{
				do{
					/* Client check that it is registered */
					if(S || check){
						system("cls");
						S=login_user();
					}
					else{
						system("cls");
						printf("No account found. Please create a new account.\n");
					}	
				}while(S);
			}	
		}	
	}while(choice1!='c'); // Exit of the program
	printf("Successful completion of the program.\n");	
	return 0;
}



/* Functions creation */
int signup_user(int sum){
	int i;
	char check[150];
	printf("-Create a new account-\n\n");
	/* Enter the necessary data of the client for his registration */
	printf("Name: ");
	scanf(" %s", Client.name);
	printf("Surname: ");
	scanf(" %s", Client.surname);
	printf("*Address*\n");
	printf(" Enter your street: ");
	scanf(" %s", Client.Address.street);
	printf(" Enter your street number: ");
	scanf(" %d", &Client.Address.number); 
	printf(" Enter the square meters of your home: ");
	scanf(" %d", &Client.Address.meters);
	/* Password validation check */
	do{
		printf("Enter password: ");
		scanf(" %s", Client.password);
		if(strlen(Client.password)!=4){
			system("cls");
			printf("Wrong data!!! Try again.\n");
		}
	}while(strlen(Client.password)!=4);
	for(i=0; i<strlen(Client.surname); i++){
		check[i]=tolower(Client.surname[i]); // tolower()
	}
	strcat(check, "123");
	strcpy(Client.username, check);
	printf("\nUsername: %s\n", Client.username);
	printf("Successful sign up.\n");
	printf("Please wait...");
	sleep(5); // sleep()
	system("cls");
	return 1;
}


int login_user(){
	char usernameL[100], passwordL[4];
	int choice, CC=0;
	printf("Enter your username:\n");
	/* Username validation check */
	do{
	   	scanf(" %s", usernameL);
	   	if(strcmp(Client.username, usernameL)!=0){
			system("cls");
			printf("Wrong data!!! Try again.\nUsername:\n");
		}
	}while(strcmp(Client.username, usernameL)!=0);
	system("cls");
	printf("Enter your password:\n");
	/* Password validation check */
    do{
	    scanf(" %s", passwordL);
		if(strcmp(Client.password, passwordL)!=0){
			system("cls");
    		printf("Wrong data!!! Try again.\nPassword:\n");
		}
	}while(strcmp(Client.password, passwordL)!=0);
	system("cls");
	printf("Successful login.\n");
	do{
		if(CC==1){
			/* Validation check */
			do{
				printf("--CLIENT SCREEN--\n\n");
				printf("1.View\n2.Modify\n3.Calculate\n4.Payment\n5.Most Expensive\n6.Logout\n");
				scanf(" %d", &choice);
				if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6){
					system("cls");
					printf("-Login-\n\n");
					printf("Wrong data!!! Try again.\n");	
				}
			}while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6);
		}
		else{
			/* Validation check */
			do{
				printf("--CLIENT SCREEN--\n\n");
				printf("1.View\n2.Modify\n3.Calculate\n4.-------\n5.Most Expensive\n6.Logout\n");
				scanf(" %d", &choice);
				if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6){
					system("cls");
					printf("-Login-\n\n");
					printf("Wrong data!!! Try again.\n");	
				}
			}while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6);
		}
		if(choice==1){
			system("cls");
			view_user();
		}
		else if(choice==2){
			system("cls");
			modify_user();
		}
		else if(choice==3){
			system("cls");
			CC=calculate_cost();
		}
		else if(choice==4){
			system("cls");
			if(CC==1){
				payment();
			}
		}
		else if(choice==5){
			if(CC==1){
				system("cls");
				most_expensive();
			}
			else{
				system("cls");
				printf("Select the third option to calculate the final payment amount for each month.\n");
			}
		}	
	}while(choice!=6);	
	system("cls");
	printf("Successful logout.\n");
	return 0;	
}


void view_user(){
	/* Display the details of the client that is connected to the system */
	printf("Name: %s\n", Client.name);
	printf("Surname: %s\n", Client.surname);
	printf("*Address*\n");
	printf(" Street: %s\n", Client.Address.street);
	printf(" Street number: %d\n", Client.Address.number);
	printf(" Square meters: %d\n", Client.Address.meters);
	printf("Username: %s\n", Client.username);
	printf("Password: %s\n", Client.password);
}


void modify_user(){
	/* Change client details(Address) */
	printf("*Address*\n");
	printf(" Street: %s\n", Client.Address.street);
	printf(" Street number: %d\n", Client.Address.number);
	printf(" Square meters: %d\n\n", Client.Address.meters);
	printf("-Modify Address-\n");
	printf("*Address*\n");
	printf("Enter your street: ");
	scanf(" %s", Client.Address.street);
	printf("Enter your street number: ");
	scanf(" %d", &Client.Address.number); 
	printf("Enter the square meters of your home: ");
	scanf(" %d", &Client.Address.meters);	
}


int calculate_cost(){
	int i, month[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	float XrewshE;
	/* Enter the necessary data for to calculate the final payment amount */
	for(i=0; i<12; i++){
		/* Validation check */
		do{
			printf("Enter the total number of kWh for no.%d month: ", i+1);
			scanf(" %f", &Client.cost[i][1]);
			if(Client.cost[i][1]<0){
				system("cls");
				printf("Wrong data!!! Try again.\n");
			}
		}while(Client.cost[i][1]<0);
		/* Calculation of the XrewshE */
		if(Client.cost[i][1]<=1600){
			XrewshE=0.005;
		}
		else if(Client.cost[i][1]<=2000){
			XrewshE=0.008;
		}
		else{
			XrewshE=0.009;
		}
		/* Calculation of the final payment amount */
		Client.cost[i][2]=Client.Address.meters*Client.cost[i][1]*XrewshE*month[i]/365;
	}
	return 1;
}


void payment(){
	int i, Pmonth;
	float poso;
	/* Show the cost for each month */
	for(i=0; i<12; i++){
		printf("The cost of no.%d month is: %.2f\n", i+1, Client.cost[i][2]);
	}
	printf("Enter the month you want to pay:\n");
	scanf(" %d", &Pmonth);
	Pmonth=Pmonth-1;
	/* Validation check */
	do{
		printf("The cost for this month is %.2f\n", Client.cost[Pmonth][2]);
		printf("Enter the amount to pay: \n");
		scanf(" %f", &poso);
		if(fabs(Client.cost[Pmonth][2]-poso)>=0.01){
			system("cls");
			printf("Wrong data!!! Try again.\n");
		}
	}while(fabs(Client.cost[Pmonth][2]-poso)>=0.01);
	Client.cost[Pmonth][3]=1; // The month was paid by the client
	printf("Successful payment.\n");
}


void most_expensive(){
	int i, t_max, sum=0;
	float max=-1;
	/* Search to find the most expensive month paid */
	for(i=0; i<12; i++){
		if(Client.cost[i][3]==1){
			if(Client.cost[i][2]>max){
				max=Client.cost[i][2];
				t_max=i;
			}
		}
		else{
			sum++;
		}		
	}
	/* Show of the month with the highest payment amount it has
	is paid by the client, as well as all his details */
	if(sum!=12){
		printf("The month with the highest payment amount by the client is no.%d\n", t_max+1);
		printf("For this month:\n");
		printf("The total number of kWh is %d\n", (int)Client.cost[t_max][1]);
		printf("The final amount is %.2f\n", Client.cost[t_max][2]);
	}
	else{
		printf("No month has been paid by the client.\n");
	}
}


