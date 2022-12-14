#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct manager
{
	char username[10];
	char password[10];
	char camp_manager_name[30];
	char phno[15];
	char id_type[15];
	char idno[20];
};
struct camp
{
	struct manager m;
	char district[20];
	char place[30];
	int max_capacity;
	int no_of_residents;
	struct camp *next;
};
struct camp *head=NULL;

//functions used
void admin();
void disp(struct camp *);
void search(struct camp *);
void create_user();
void insert(struct camp *);
void existing_user();
void update(struct camp *);
void display(struct camp *);
char delete(struct camp *);

void admin()
{
	system("cls");
	int ch,i=0;
	struct camp *temp=head;
	char uname[10],pwd[10];
	fflush(stdin);
	printf("\nEnter admin username: ");
	gets(uname);
	fflush(stdin);
	printf("\nEnter admin password: ");
	while(1)
	{
        ch = getch();
        if(ch == ENTER || ch == TAB){
            pwd[i] = '\0';
            break;
        }
		else if(ch == BCKSPC){
            if(i>0){
                i--;
                printf("\b \b");
            }
        }
		else
		{
            pwd[i++] = ch;
            printf("*");
        }
    }
    if(strcmp(uname,"admin")!=0||strcmp(pwd,"admin12")!=0)
    {
    	printf("\nInvalid Username or Password!!!!");
		getch();
	}
	else
	{
		printf("\nLogged in successfully\n");
		getch();
		do
		{
			system("cls");
			printf("\n-----------------------------\n Admin Panel \n-----------------------------\n");
			printf("\n 1.Display details of all camps\n 2.Search based on district\n 0.Logout\n");
			printf("\n----------------------------------------------------------------------------");
	    	printf("\n----------------------------------------------------------------------------\n");
	    	printf("\nEnter your choice: ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
						disp(head);
						break;
				case 2:
						search(head);
						break;
				case 0:
						system("cls");
						printf("\nLogged Out successfully!!!!!");
						getch();
						break;
				default:
						printf("\nInvalid choice!!!!");
						getch();
						break;
			}
		}while(ch!=0);
	}
}
void disp(struct camp *temp)
{
	system("cls");
	int i=1;
	if(temp==NULL)
	{
		printf("\n  No camps registered yet............\n");
		printf("\n\nPress any key to continue..........");
		getch();
		return;
	}
	while(temp!=NULL)
	{
		
		printf("\n|================================|");
		printf("\n User%d Details",i);
		printf("\n|================================|");
		printf("\n|Camp Manager Name: %s",temp->m.camp_manager_name);
		printf("\n|User Name: %s",temp->m.username);
		printf("\n|Password: %s",temp->m.password);
		printf("\n|Mobile Number: %s",temp->m.phno);
		printf("\n|ID Type: %s",temp->m.id_type);
		printf("\n|ID Number: %s",temp->m.idno);
		printf("\n|================================|");
		printf("\n Camp Details");
		printf("\n|================================|");
		printf("\n|District: %s",temp->district);
		printf("\n|Place: %s",temp->place);
		printf("\n|Max. Capacity: %d",temp->max_capacity);
		printf("\n|Current Residents: %d",temp->no_of_residents);
		i++;
		temp=temp->next;
	}
	printf("\n\nPress any key to continue..........");
	getch();
}

void search(struct camp *temp)
{
	system("cls");
	int i=1;
	char dis[20];
	if(temp==NULL)
	{
		printf("\n  No camps registered yet............\n");
		printf("\n\nPress any key to continue..........");
		getch();
		return;
	}
	printf("\n\n\tEnter the district name: ");
	scanf("%s",dis);
	while(temp!=NULL)
	{
		if(strcmpi(temp->district,dis)==0)
		{
			printf("\n|================================|");
			printf("\n User%d Details",i);
			printf("\n|================================|");
			printf("\n|Camp Manager Name: %s",temp->m.camp_manager_name);
			printf("\n|User Name: %s",temp->m.username);
			printf("\n|Password: %s",temp->m.password);
			printf("\n|Mobile Number: %s",temp->m.phno);
			printf("\n|ID Type: %s",temp->m.id_type);
			printf("\n|ID Number: %s",temp->m.idno);
			printf("\n|================================|");
			printf("\n Camp Details");
			printf("\n|================================|");
			printf("\n|District: %s",temp->district);
			printf("\n|Place: %s",temp->place);
			printf("\n|Max. Capacity: %d",temp->max_capacity);
			printf("\n|Current Residents: %d",temp->no_of_residents);
			i++;
		}
		temp=temp->next;
	}
	if(i==1)
	{
		printf("\n\n\t No camps have been registered in %s district",dis);
	}
	printf("\n\nPress any key to continue..........");
	getch();
}
void create_user()
{
	system("cls");
	struct camp *t;
	char pwd[10],ch;
	int i;
	t=(struct camp*)malloc(sizeof(struct camp));
	if(t==NULL)
	{
		printf("\nMemory allocation failed.....");
	}
	else
	{
		printf("\n--------------------------------\n New User Registration \n--------------------------------\n");
		printf("\nUser Details\n=======================\n");
		fflush(stdin);
		printf("\n\tEnter the camp manager name:");
		gets(t->m.camp_manager_name);
		fflush(stdin);
		printf("\n\tEnter username: ");
		gets(t->m.username);
		fflush(stdin);
		printf("\n\tEnter password: ");
		while(1)
		{
	        ch = getch();
	        if(ch == ENTER || ch == TAB){
	            pwd[i] = '\0';
	            break;
	        }
			else if(ch == BCKSPC){
	            if(i>0){
	                i--;
	                printf("\b \b");
	            }
	        }
			else
			{
	            pwd[i++] = ch;
	            printf("*");
	        }
	    }
		strcpy(t->m.password,pwd);
		fflush(stdin);
		printf("\n\n\tEnter mobile number:");
		gets(t->m.phno);
		fflush(stdin);
		printf("\n\tEnter the ID proof(PAN card / Aadhaar card /Voter's ID card):");
		gets(t->m.id_type);
		fflush(stdin);
		printf("\n\tEnter the ID Number:");
		gets(t->m.idno);
		printf("\nCamp Details\n=======================\n");
		fflush(stdin);
		printf("\n\tEnter the district:");
		gets(t->district);
		fflush(stdin);
		printf("\n\tEnter the place:");
		gets(t->place);
		printf("\n\tEnter max. capacity of the camp:");
		scanf("%d",&t->max_capacity);
		do
		{
			printf("\n\tEnter current number of residents in the camp:");
			scanf("%d",&t->no_of_residents);
			if(t->no_of_residents>t->max_capacity)
			{
				printf("\n\tIncorrect value of current residents...Please re-enter....");
			}
		}while(t->no_of_residents>t->max_capacity);
		t->next=NULL;
		insert(t);
		printf("\n******Account created successfully******\n");
		printf("\n Press any key to continue..........");
		getch();
	}
}
void insert(struct camp *newnode)
{
	struct camp *temp;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void existing_user()
{
	system("cls");
	int ch,found=0,i=0;
	char uname[10],pwd[10],res;
	struct camp *temp=head;
	fflush(stdin);
	printf("\nEnter username: ");
	gets(uname);
	fflush(stdin);
	printf("\nEnter password: ");
	while(1)
	{
        ch = getch();
        if(ch == ENTER || ch == TAB){
            pwd[i] = '\0';
            break;
        }
		else if(ch == BCKSPC){
            if(i>0){
                i--;
                printf("\b \b");
            }
        }
		else
		{
            pwd[i++] = ch;
            printf("* \b");
        }
    }
	while(temp!=NULL)
	{
		if(strcmp(uname,temp->m.username)==0&&strcmp(pwd,temp->m.password)==0)
		{
			found=1;
			break;
		}
		temp=temp->next;	
	}
	if(!found)
	{
			printf("\nInvalid Username or Password!!!!");
			getch();
	}
	else
	{
		printf("\nLogged in successfully\n");
		getch();
		do
		{
			system("cls");
			printf("\n-----------------------------\n Logged in as %s\n-----------------------------\n",temp->m.camp_manager_name);
			printf("\nOperations Available\n--------------------\n1.Update Account Details\n2.View Account Details\n3.Delete Account\n0.Logout");
			printf("\n----------------------------------------------------------------------------");
	    	printf("\n----------------------------------------------------------------------------\n");
			printf("\nEnter your choice: ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
						update(temp);
						break;
				case 2:
						display(temp);
						break;
				case 3:
						res=delete(temp);
						break;
				case 0:
						system("cls");
						printf("\nLogged Out successfully!!!!!");
						getch();
						break;
				default:
						printf("\nEnter a valid choice....\n");
						getch();
						break;		
			}
			if(ch==3&&res=='y')
			{
				printf("\n******Account deleted successfully******");
				printf("\n\nPress any key to continue..........");
				ch=0;
				getch();
			}
		}while(ch!=0);
	}
}
void update(struct camp *temp)
{
	display(temp);
	int ch;
	do
	{
		system("cls");
		printf("\n ----------------\n Update \n ----------------");
		printf("\n 1.Password\n 2.Mobile Number\n 3.Number of residents \n 0.Cancel \n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					fflush(stdin);
					printf("\n Enter password: ");
					gets(temp->m.password);
					break;
			case 2:
					fflush(stdin);
					printf("\n Enter mobile number: ");
					gets(temp->m.phno);
					break;
			case 3:
					printf("\n Enter current no of residents: ");
					scanf("%d",&temp->no_of_residents);
					break;
			case 0:
					printf("\nPress any key to continue.....");
					getch();
					break;
			default:
					printf("\nEnter a valid choice....\n");
					getch();
					break;	
		}
		if(ch==1||ch==2||ch==3)
		{
			printf("\n******Account updated successfully******");
			getch();
		}
	}while(ch!=0);
}
void display(struct camp *temp)
{
	system("cls");
	printf("\n|================================|");
	printf("\n User Details");
	printf("\n|================================|");
	printf("\n|Camp Manager Name: %s",temp->m.camp_manager_name);
	printf("\n|User Name: %s",temp->m.username);
	printf("\n|Password: %s",temp->m.password);
	printf("\n|Mobile Number: %s",temp->m.phno);
	printf("\n|ID Type: %s",temp->m.id_type);
	printf("\n|ID Number: %s",temp->m.idno);
	printf("\n|================================|");
	printf("\n Camp Details");
	printf("\n|================================|");
	printf("\n|District: %s",temp->district);
	printf("\n|Place: %s",temp->place);
	printf("\n|Max. Capacity: %d",temp->max_capacity);
	printf("\n|Current Residents: %d",temp->no_of_residents);
	printf("\n\nPress any key to continue..........");
	getch();
}
char delete(struct camp *temp)
{
	char ch;
	struct camp *t=head;
	display(temp);
	system("cls");
	printf("\n Are you sure you want to delete the account (y/n) ?  ");
	scanf(" %c",&ch);
	if(ch=='y'||ch=='Y')
	{
		if(strcmp(head->m.username,temp->m.username)==0)
		{
			head=head->next;
		}
		else
		{
			while(t->next!=NULL)
			{
				if(strcmp(t->next->m.username,temp->m.username)==0)
				{
					t->next=t->next->next;
					break;
				}
				t=t->next;
			}
		}
	} 
	return ch;
}
int main()
{
	system("color f5");
	int ch,choice;
	do
	{
		system("cls");
		printf("\n----------------------------------------------------------------------------\n");
    	printf("                    Welcome to Relief Camp Management System"                    );
    	printf("\n----------------------------------------------------------------------------\n");
		printf("\nLogin\n-----------------------\n 1.Admin\n 2.New User\n 3.Existing User\n 0.Exit\n-----------------------\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					admin();
					break;
			case 2:
					create_user();
					break;
			case 3:
					existing_user();
					break;
			case 0:
					printf("\nThank you for visiting!!!!!");
					getch();
					break; 
			default:
					printf("\nEnter a valid choice....\n");
					getch();
					break;	
		}
	}while(choice!=0);
	return 0;
}