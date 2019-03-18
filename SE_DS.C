#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<string.h>
struct acc
{
	double bal,ltran;
	long id;
	char uid[13],pan[10],tpwd[20],pwd[20],fname[30],lname[30],paisa[30],key[30],trolls[20];
	struct acc* next;
}*head,*trav,*temp;
int i=0;
void login()
{
	char a[100],pwd2[20],pwd3[20],tran[20],troll[20];
	long id;
	int ch,id2,x,f1,chn,in,cht;
	double amt;
	vapaslogin:
	system("cls");
	printf("\t\t+-----------------------------------------------+\n");
	printf("\t\t|\t                                   \t|\n");
	printf("\t\t|\tWelcome to LOOT Bank Account portal\t|\n");
	printf("\t\t|\t                                   \t|\n");
	printf("\t\t+-----------------------------------------------+\n");
	printf("\nEnter your one digit user id: ");
	scanf("%ld",&id);
	if(id>i){
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\t  +-----------------------------------------------------+\n");
		printf("\t  |                                                     |\n");
		printf("\t  |                         Sorry                       |\n");
		printf("\t  |             No account with such id found           |\n");
		printf("\t  |                                                     |\n");
		printf("\t  +-----------------------------------------------------+\n");
		sleep(2);
		system("cls");
	}
	else
	{
		trav=head;
		while(trav->id!=id)
			trav=trav->next;
		printf("Hello, %s",trav->fname);
		printf("\nEnter your password:");
		scanf(" %s",&pwd2);
		trav=head;
		if(strcmp(trav->pwd,pwd2))
		{
			printf("\nIncorrect Password!!\n1.Try logging in again?\n2.Forgot Password?\n");
			scanf("%d",&chn);
			switch(chn)
			{
				case 1: goto vapaslogin;
			    case 2: trendytrollers:
					printf("Enter your troll key: ");
					scanf(" %s",&troll);
					if(strcmp(trav->trolls,troll))
					{
						printf("Wrong troll password\n1.Enter troll key again\n2.Go back");
						scanf("%d",&cht);
						switch(cht)
						{
							case 1: goto trendytrollers;
							case 2: system("cls");
									break;
						}
					}
					else
					{
						system("cls");
							printf("\t\t+-----------------------------------------------+\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t|\tWelcome to LOOT Bank Account portal\t|\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t+-----------------------------------------------+\n");
						goto apnakhaata;
					}
			}
		}
		else
		{
			system("cls");
							printf("\t\t+-----------------------------------------------+\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t|\tWelcome to LOOT Bank Account portal\t|\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t+-----------------------------------------------+\n");
			apnakhaata:
			printf("+------------------------+\n");
			printf("|1.Transfer money.       |\n|2.Display A/C details.  |\n|3.Link PAN with account.|\n|4.Register a complaint. |\n|5.LogOut.               |\n+------------------------+\nEnter your choice:\n");
			scanf("%d",&ch);
			while(id!=trav->id)
				trav=trav->next;
			switch(ch)
			{
				benkhaata:
				case 1: printf("Enter Beneficiary's ID: \n");
						scanf("%d",&id2);
						if(id2>i){
								printf("No account found with such id.\nPlease Try Again!.\n\n");
								system("cls");
							printf("\t\t+-----------------------------------------------+\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t|\tWelcome to LOOT Bank Account portal\t|\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t+-----------------------------------------------+\n");
						}
						else if(id2==id)
						{
							printf("Cannot Place A Transfer To The Same Account!\nPlease Enter A Valid Beneficiary ID!\n\n");
							sleep(2);
							system("cls");
							goto benkhaata;
						}
						else
							{
								printf("Available balance: %lf\n",trav->bal);
								vapas:
								printf("Enter the amount to be transferred: ");
								scanf("%lf",&amt);
								if(amt>trav->bal)
								{
									printf("Insufficient Balance\nAvailable balance:%lf\n",trav->bal);
									goto vapas;
								}
								else
								{
									tranvapas:
									printf("Enter your transaction password:\n");
									scanf(" %s",&tran);
									if(!strcmp(trav->tpwd,tran))
									{
										temp=head;
										while(temp->id!=id2)
											temp=temp->next;
										trav->ltran=(-1)*amt;
										temp->ltran=amt;
										temp->bal+=amt;
										trav->bal-=amt;
										for(in=0;temp->fname[in]!='\0';in++)
											trav->paisa[in]=temp->fname[in];
										for(in=0;temp->lname[in]!='\0';in++)
											trav->paisa[in]=temp->lname[in];
										for(in=0;trav->fname[in]!='\0';in++)
											temp->paisa[in]=trav->fname[in];
										for(in=0;trav->lname[in]!='\0';in++)
											temp->paisa[in]=trav->lname[in];
										printf("Amount transferred successfully!!\n");
										getch();
										system("cls");
										printf("\t\t+-----------------------------------------------+\n");
										printf("\t\t|\t                                   \t|\n");
										printf("\t\t|\tWelcome to LOOT Bank Account portal\t|\n");
										printf("\t\t|\t                                   \t|\n");
										printf("\t\t+-----------------------------------------------+\n");
									}
									else
									{
										printf("Incorrect password\n");
										goto tranvapas;
									}
								}
							}

						goto apnakhaata;
				case 2: if(trav->ltran==0)
							printf("Account Holder's Name: %s %s\nAccount Holder's ID: %ld\nBalance : %lf\nNo Last Transaction\n",trav->fname,trav->lname,trav->id,trav->bal);
						else if(trav->ltran<0)
							printf("Account Holder's Name: %s %s\nAccount Holder's ID: %ld\nBalance : %lf\nLast Transaction: Your account was debited by Rs.%lf to %s's account. \n",trav->fname,trav->lname,trav->id,trav->bal,(-1)*trav->ltran,trav->paisa);
						else
							printf("Account Holder's Name: %s %s\nAccount Holder's ID: %ld\nBalance : %lf\nLast Transaction: Your account was credited by Rs.%lf by %s .\n",trav->fname,trav->lname,trav->id,trav->bal,trav->ltran,trav->paisa);
						if(trav->pan==NULL)
							printf("Link your PAN as early as possible\n");
						getch();
							system("cls");
								printf("\t\t+-----------------------------------------------+\n");
								printf("\t\t|\t                                   \t|\n");
								printf("\t\t|\tWelcome to LOOT Bank Account portal\t|\n");
								printf("\t\t|\t                                   \t|\n");
								printf("\t\t+-----------------------------------------------+\n");
						goto apnakhaata;
				case 3: if(trav->pan[0]==NULL)
						{
							printf("Enter you PAN number\n");
							scanf("%s",&trav->pan);
							system("cls");
							printf("\n\n\n\n\n\n\n\n\n\t  +-----------------------------------------------------+\n");
							printf("\t  |                                                     |\n");
							printf("\t  |           PAN has been successfully linked          |\n");
							printf("\t  |                 Have A Nice Day!!..                 |\n");
							printf("\t  |                                                     |\n");
							printf("\t  +-----------------------------------------------------+\n");
							sleep(2);
							system("cls");
						}
						else
						printf("PAN is already linked!.");
						system("cls");
							printf("\t\t+-----------------------------------------------+\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t|\tWelcome to LOOT Bank Account portal\t|\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t+-----------------------------------------------+\n");
						goto apnakhaata;
				case 4: system("cls");
							printf("\t\t+-----------------------------------------------+\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t|\tWelcome to LOOT Bank Account portal\t|\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t+-----------------------------------------------+\n");
						printf("\t\t***Welcome to LOOT Online Complaint Forum***\n\nEnter your complaint below :-\n");
						gets(a);
						system("cls");
							printf("\n\n\n\n\n\n\n\n\n\t  +-----------------------------------------------------+\n");
							printf("\t  |                                                     |\n");
							printf("\t  |           We will work On your issue soon,          |\n");
							printf("\t  |      Please note your Complaint id :CC%d            |\n",(x<0)?(-x):(x));
							printf("\t  |                 Have A Nice Day!!..                 |\n");
							printf("\t  |                                                     |\n");
							printf("\t  +-----------------------------------------------------+\n");
							sleep(2);
							system("cls");
					//	printf("We will work On your issue soon,please note your complaint id :CC%d",(x<0)?(-x):(x));
							printf("\t\t+-----------------------------------------------+\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t|\tWelcome to LOOT Bank Account portal\t|\n");
							printf("\t\t|\t                                   \t|\n");
							printf("\t\t+-----------------------------------------------+\n");
						goto apnakhaata;
				case 5: system("cls");
							printf("\n\n\n\n\n\n\n\n\n\t  +-----------------------------------------------------+\n");
							printf("\t  |                                                     |\n");
							printf("\t  |        You Have Been Successfully Logged Out!!      |\n");
							printf("\t  |                 Have A Nice Day!!..                 |\n");
							printf("\t  |                                                     |\n");
							printf("\t  +-----------------------------------------------------+\n");
							sleep(2);
							system("cls");
							break;
			}
		}
	}
}
void create()
{
    int store/*,count=0*/,len;
    char pwd1[20],adar[30];
	struct acc* a=(struct acc*)malloc(sizeof(struct acc));
	a->next=NULL;
	system("cls");
	printf("\t\t+-----------------------------------------------+\n");
	printf("\t\t|\t                                   \t|\n");
	printf("\t\t|\tWelcome to LOOT Bank Account portal\t|\n");
	printf("\t\t|\t                                   \t|\n");
	printf("\t\t+-----------------------------------------------+\n\n");
	printf("Enter your first name:");
	scanf(" %s",&a->fname);
	printf("Enter your last name:");
	scanf(" %s",&a->lname);
	Aadhaar:
	printf("Enter your 12 digit Aadhaar number:");
	scanf(" %s",&a->uid);
	if (strlen(a->uid)!=12)
	{
		printf("Please Enter A Valid Aadhar Number!\n");
		goto Aadhaar;
	}
	vapasconfirm:
	printf("\nEnter Your Password:");
	scanf(" %s",&a->pwd);
	printf("Confirm Your Password:");
	scanf(" %s",&pwd1);
	if(strcmp(a->pwd,pwd1))
    {
	printf("Password Doesn't Match!!\n Please Retry.\n");
	goto vapasconfirm;
    }
    else
    {
	strcat(pwd1,"het3030");
		printf("Your id is %d.\nYour password is %s.\nYour online transaction password is:%s.\nPlease Remember These Details Correctly!",++i,a->pwd,pwd1);
		printf("\n\nCongratulations!!!, your account has been succesfully created with us.\n\nEnter Opening Balance: ");
		scanf("%lf",&a->bal);
		a->id=i;
		a->pan[0]=NULL;
		a->ltran=0;
		(a->id%2==0)?(strcpy(a->trolls,"chaipilo")):(strcpy(a->trolls,"halofrands"));
		strcpy(a->tpwd,pwd1);
		if(head==NULL)
			head=a;
		else
		{
			trav=head;
			while(trav->next!=NULL)
				trav=trav->next;
			trav->next=a;
		}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t  +-----------------------------------------------------+\n");
	printf("\t  |                                                     |\n");
	printf("\t  |            Account opened successfully!!            |\n");
	printf("\t  |                 Have A Nice Day!!..                 |\n");
	printf("\t  |                                                     |\n");
	printf("\t  +-----------------------------------------------------+\n");
	sleep(2);
	system("cls");
    }
}
int main()
  {
	int ch;
	system("cls");
	do{
		printf("\t\t+-----------------------------------------------+\n");
		printf("\t\t|\t                                   \t|\n");
		printf("\t\t|\tWelcome to LOOT Bank Account portal\t|\n");
		printf("\t\t|\t                                   \t|\n");
		printf("\t\t+-----------------------------------------------+\n");
		printf("+---------------------+");
		printf("\n|1.Existing customer? |\n|2.Create an account. |\n|3.Exit.              |\n");
		printf("+---------------------+\n");
		printf("Enter Your Choice: ");
		scanf(" %d",&ch);
		switch(ch)
		{
			case 1: login();
					break;
			case 2: create();
					break;
			case 3: system("cls");
				printf("\n\n\n\n\n\n\n\n\n\t  +-----------------------------------------------------+\n");
				printf("\t  |                                                     |\n");
				printf("\t  |            Thank You For Banking With Us!!          |\n");
				printf("\t  |                 Have A Nice Day!!..                 |\n");
				printf("\t  |                                                     |\n");
				printf("\t  +-----------------------------------------------------+\n");
				sleep(2);
				break;
			default: printf("Enter valid choice!\n");
		}
	}while(ch!=3);
	return 0;
}