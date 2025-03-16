/* -Libraries- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* -Statement of functions- */
// USER functions //
int signup_user();
void login_user();
	int calculate_cost();
	int payment();
	void get_receipt();
	int exit_user();
	
// ADMIN functions //		
int login_admin();
	void change_cost();
	int exit_admin();
	
// USER and ADMIN function //	
int logout();

// HOME function //
int terminate();


/* Statement of global variables */
char name[100], surname[100], address[100], usernameU[100], passwordU[5];
int sunK, tetraM, plithosH=166, plhrwmh, t1, t2, t3, t4;
float XrewseisD, XrewseisE, SunolikesX, KostosD, TelikoPosoXrewshs, poso, TelikoPosoXrewshsFC;



int main(){
	char choice1[5], strA[]="admin", strU[]="user", str0[]="0";
	int choice2, U=1, A=1, HOME=1, UL=0;
	while(HOME!=0){
		/* -HOME  menu- */
		do{
			printf("--HOME SCREEN--\n\n");
			printf("Enter your user group. The word 'admin' if you are the administrator of the program,\nthe word 'user' if you are a simple user or '0' for a complete program termination.\n");
			scanf(" %s", choice1);
			if(strcmp(choice1, strA) && strcmp(choice1, strU) && strcmp(choice1, str0)){
				system("cls");
				printf("Wrong data!!! Try again.\n");
			}
		}while(strcmp(choice1, strA) && strcmp(choice1, strU) && strcmp(choice1, str0));
		system("cls");
		if(strcmp(choice1, str0)){
			if(!strcmp(choice1, strU)){
				/* -USER menu- */
				do{
					// Validation check // 
					do{
						printf("--USER SCREEN--\n\n");
						printf("1.SignUp\n2.Login\n3.Logout\n");
						scanf(" %d", &choice2);
						if(choice2!=1 && choice2!=2 && choice2!=3){
							system("cls");
							printf("Wrong data!!! Try again.\n");
						}
				   }while(choice2!=1 && choice2!=2 && choice2!=3);
					if(choice2==1){
						system("cls");
						UL=signup_user();
					}
					else if(choice2==2){
						if(UL){
							system("cls");
							login_user();
						}
						else{
							system("cls");
							printf("No account found. Please create a new account.\n");
						}
					}
					else{
						system("cls");
						U=logout();
					}
				}while(U);	
			}
			else{
				/* -ADMIN menu- */
				do{
					// Validation check // 
					do{
						printf("--ADMIN SCREEN--\n\n");
						printf("1.Login\n2.Logout\n");
						scanf(" %d", &choice2);
						if(choice2!=1 && choice2!=2){
							system("cls");
							printf("Wrong data!!! Try again.\n");
						}
					}while(choice2!=1 && choice2!=2);
					if(choice2==1){
						system("cls");
						A=login_admin();
					}
					else{
						system("cls");
						A=logout();
					}
				}while(A);
			}
		}
		else{
			system("cls");
			HOME=terminate();
		}
	}
return 0;
}



/* -Create functions- */
// USER functions //
int signup_user(){
	printf("-Create a new account-\n\n");
	/* Enter the necessary data of the user for his registration */
	printf("Name: ");
	scanf(" %s", name);
	printf("Surname: ");
	scanf(" %s", surname);
	printf("Address: ");
    fgets(address, sizeof(address), stdin);
    address[strcspn(address, "\n")] = 0; // Remove the newline character
	printf("Username: ");
	scanf(" %s", usernameU);
	system("cls");
	printf("-Create a new account-\n\n");
	/* Password validation check */ 
	do{
		printf("Enter password:\n");
	 	scanf(" %s", passwordU);
		if(strlen(passwordU)!=4){
			system("cls");
			printf("Wrong data!!! Try again.\n");
		}
	}while(strlen(passwordU)!=4);
	system("cls");
	printf("Successful sign up.\n");
return 1;		
}


void login_user(){
	char username[100], password[4], choice;
	int L=1, CC=0, P=0;
do{
	/* Username validation check */ 
	printf("-Login-\n\n");
	printf("Enter your username:\n");
	do{
    	scanf(" %s", username);
    	if(strcmp(username, usernameU)!=0){
    		system("cls");
    		printf("-Login-\n\n");
    		printf("Wrong data!!! Try again.\nUsername:\n");
		}
	}while(strcmp(username, usernameU)!=0);
	system("cls");
	printf("-Login-\n\n");
	printf("Enter your password:\n");
	/* Password validation check */
	do{
	 	scanf(" %s", password);
		if(strcmp(password, passwordU)!=0){
			system("cls");
    		printf("-Login-\n\n");
    		printf("Wrong data!!! Try again.\nPassword:\n");
		}
	}while(strcmp(password, passwordU)!=0);
	system("cls");
	printf("Successful login.\n");
	printf("-Login-\n\n");
	do{
		/* Validation check */
		do{
			printf("a.Calculate cost\nb.Payment\nc.Receipt\nd.Exit\n");
			scanf(" %c", &choice);
			if(choice!='a' && choice!='b' && choice!='c' && choice!='d'){
				system("cls");
				printf("-Login-\n\n");
				printf("Wrong data!!! Try again.\n");	
			}
		}while(choice!='a' && choice!='b' && choice!='c' && choice!='d');
		if(choice=='a'){
			system("cls");
			CC=calculate_cost();
		}
		else if(choice=='b'){
			if(CC){
				system("cls");
				P=payment();
			}
			else{
				system("cls");
				printf("-Login-\n\n");
				printf("Please select the first option to calculation the final payment amount.\n");
			}
		}
		else if(choice=='c'){
			if(P){
				system("cls");
				get_receipt();
			}
			else{
				system("cls");
				printf("-Login-\n\n");
				printf("Please select the first option to calculation the final payment amount.\nIf you have selected the first option, then select the second option to pay the final amount calculated.\n");
			}
		}
		else{
			L=exit_user();
		}	
	}while(L);	
	system("cls");
}while(L);	
}


int calculate_cost(){
	/* Enter the necessary data for to calculate the final payment amount */
 	printf("Enter the total number of kWh you have consumed:\n");
 	scanf(" %d", &sunK);
 	sunK=abs(sunK);	// abs() //
 	printf("Enter the square meters of your home:\n");
 	scanf(" %d", &tetraM);
 	tetraM=abs(tetraM);	// abs() //
 	/* Calculation of the final payment amount */
 	if(tetraM<=75){
		XrewseisD=0.13;	
	}
	else if(tetraM<=115){
		XrewseisD=0.26;
	} 
	else{
		XrewseisD=0.42;
	}
	KostosD=tetraM*XrewseisD*plithosH/365;
	if(sunK<=1600){
		XrewseisE=0.00542;
	}
	else if(sunK<=2000){
		XrewseisE=0.00682;
	}
	else{
		XrewseisE=0.00822;
	}
	SunolikesX=sunK*XrewseisE;
	TelikoPosoXrewshs=KostosD+SunolikesX;
	system("cls");
	printf("Initial cost: %f\n", TelikoPosoXrewshs);
return 1;
}


int payment(){
	int n, i;
	/* Validation check */
	do{
		printf("The payment of the initial cost can be made with:\n1.Credit card\n2.Cash\n");
		scanf(" %d", &plhrwmh);
		if(plhrwmh!=1 && plhrwmh!=2){
			system("cls");
			printf("Wrong data!!! Try again.\n");	
		}
	}while(plhrwmh!=1 && plhrwmh!=2);
	system("cls");
	if(plhrwmh==1){
		/* Credit card number validation check */
		printf("*Credit card number*\n");
		do{
			printf("1. Enter the first 4 numbers of your credit card:\n");
			scanf("%d", &n);
			t1=n;
			i=0;
			do{
				n=n/10;
				i=i+1;
			}while(n!=0);
			if(i!=4){
				system("cls");
				printf("*Credit card number*\n");
				printf("Wrong data!!! Try again.\n");
			}	
		}while(i!=4);
		printf("*Credit card number*\n");
		do{
			printf("2. Enter the next 4 numbers of your credit card:\n");
			scanf("%d", &n);
			t2=n;
			i=0;
			do{
				n=n/10;
				i=i+1;
			}while(n!=0);
			if(i!=4){
				system("cls");
				printf("*Credit card number*\n");
				printf("Wrong data!!! Try again.\n");
			}	
		}while(i!=4);
		printf("*Credit card number*\n");
		do{
			printf("3. Enter the next 4 numbers of your credit card:\n");
			scanf("%d", &n);
			t3=n;
			i=0;
			do{
				n=n/10;
				i=i+1;
			}while(n!=0);
			if(i!=4){
				system("cls");
				printf("*Credit card number*\n");
				printf("Wrong data!!! Try again.\n");
			}	
		}while(i!=4);
		printf("*Credit card number*\n");
		do{
			printf("4. Enter the next 4 numbers of your credit card:\n");
			scanf("%d", &n);
			t4=n;
			i=0;
			do{
				n=n/10;
				i=i+1;
			}while(n!=0);
			if(i!=4){
				system("cls");
				printf("*Credit card number*\n");
				printf("Wrong data!!! Try again.\n");
			}	
		}while(i!=4);
		/* 10% discount on the final payment amount, because the payment was made by  credit card */
		TelikoPosoXrewshsFC=TelikoPosoXrewshs-0.1*TelikoPosoXrewshs;
		/* Validation check */
		do{
			printf("Enter the amount to pay %f euros:\n", TelikoPosoXrewshsFC);
			scanf(" %f", &poso);
			if(poso!=TelikoPosoXrewshsFC){
				system("cls");
				printf("Wrong data!!! Try again.\n");	
			}
		}while(poso!=TelikoPosoXrewshsFC);
	}
	else{
		/* Validation check */
		do{
			printf("Enter the amount to pay %f euros:\n", TelikoPosoXrewshs);
			scanf(" %f", &poso);
			if(poso!=TelikoPosoXrewshs){
				system("cls");
				printf("Wrong data!!! Try again.\n");
			}
		}while(poso!=TelikoPosoXrewshs);
	}
	system("cls");
return 1;
}


void get_receipt(){
	int i;
	/* Display of the details concerning the payment of the amount */
	printf("*********************************************************************************************\n");
	printf("*			               	PERSONAL DETAILS			            *\n");
	printf("*                                                                                 \n");																												
	printf("*	Name:							%s\n", name);
	printf("*       Surname:						%s\n", surname);
	printf("*       Address:						%s\n", address);
	printf("*       Total days of consumption:     				%d\n", plithosH);
	printf("*       Sq. Meters:						%d\n", sunK);
	printf("*                                                                                           *\n");
	printf("*********************************************************************************************\n");
	printf("*                                          PRICING                                          *\n");
	printf("*       Initial cost:				 		EUR %2.2f\n", TelikoPosoXrewshs);
	printf("*   	Details:                                                                            *\n");
	printf("*       	Municipal Taxes:     				EUR %2.2f\n", KostosD);
	printf("*               Total Chargers:      				EUR %2.2f\n", SunolikesX);
	if(plhrwmh==1){
		printf("*       Final cost (after credit card payment deduction):	EUR %2.2f\n", TelikoPosoXrewshsFC);
	}
	else{
		printf("*       Final cost (after credit card payment deduction):       ---------	            *\n");
	}
	printf("*                                                                                           *\n");
	printf("*********************************************************************************************\n");
	printf("*                                      PAYMENT DETAILS                                      *\n");
	if(plhrwmh==1){
		printf("*	Credit Card Number                    			%d %d %d %d         *\n", t1, t2, t3, t4);
	}
	else{
		printf("*	Cash                				        EUR %2.2f          	    *\n", TelikoPosoXrewshs);
	}
	printf("*                                                                                           *\n");
	printf("*********************************************************************************************\n");	
}


int exit_user(){
	system("cls");
return 0; /* The return of this value terminates the user options menu */
}



// ADMIN functions //
int login_admin(){
	char usernameA[]="root", passwordA[]="admin123", username1[100], password1[100], choice;
	int T=1;
	do{
		printf("-Login-\n\n");
		/* Username validation check */ 
		printf("Enter your username:\n");
		do{
	    	scanf(" %s", username1);
	    	if(strcmp(username1, usernameA)){
	    		system("cls");
	    		printf("-Login-\n\n");
    			printf("Wrong data!!! Try again.\nUsername:\n");
			}
		}while(strcmp(username1, usernameA));
		system("cls");
		printf("-Login-\n\n");
		printf("Successful login.\n");
		/* Password validation check */
		printf("Enter your password:\n");
		do{
			scanf(" %s", password1);
			if(strcmp(password1, passwordA)){
				system("cls");
				printf("-Login-\n\n");
    			printf("Wrong data!!! Try again.\nPassword:\n");
			}
		}while(strcmp(password1, passwordA));
		system("cls");
		do{
			printf("-Login-\n\n");
			/* Validation check */
			do{
				printf("a.Change Cost\nb.Exit\n");
				scanf(" %c", &choice);
				if(choice!='a' && choice!='b'){
					system("cls");
					printf("-Login-\n\n");
					printf("Wrong data!!! Try again.\n");		
				}
			}while(choice!='a' && choice!='b');
			if(choice=='a'){
				system("cls");
				change_cost();
			}
			else{
				system("cls");
				T=exit_admin();
			}
		}while(T);
	}while(T);
return 1;
}


void change_cost(){
	int b;
	float Ntimh, Ptimh;
	/* Validation check */
	do{
		printf("Enter step(1-3):\n");
		scanf(" %d", &b);
		if(b!=1 && b!=2 && b!=3){
			system("cls");
			printf("Wrong data!!! Try again.\n");
		}
	}while(b!=1 && b!=2 && b!=3);
		if(b==1){
		Ptimh=0.00542;
	}
	else if(b==2){
		Ptimh=0.00682;
	}
	else{
		Ptimh=0.00822;
	}
	system("cls");
	/* ?ntroduction and validation of the new price */
	printf("Enter the new value:\n");
	scanf(" %f", &Ntimh);
	if(Ntimh>Ptimh+0.2*Ptimh || Ntimh<Ptimh-0.2*Ptimh){
		printf("Wrong data!!! Try again.\n");
		do{
			printf("Enter the new value:\n");
			scanf(" %f", &Ntimh);
		}while(Ntimh>Ptimh+0.2*Ptimh || Ntimh<Ptimh-0.2*Ptimh);		
	}
	system("cls");
	printf("Successful value.\n");
}


int exit_admin(){
	system("cls");
return 0; /* The return of this value terminates the admin options menu */
}


// USER and ADMIN function //
int logout(){
	printf("Successful logout.\n");
return 0; /* The return of this value terminates the connection to the admin or user account */
}


// HOME function //
int terminate(){
	printf("Successful completion of the program.\n.");
return 0; /* The return of this value terminates the program */
}


