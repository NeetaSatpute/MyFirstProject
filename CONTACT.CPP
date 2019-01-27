#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct contact
{
	char name[40],ph[15],email[20];
}list;
FILE *fp,*ft;
char name[20],searchName[20];;
void AddContact();
void ViewContact();
void EditContact();
void SearchContact();
void DeleteContact();

void AddContact()
{
	fp=fopen("contact.dat","a");
	fflush(stdin);
	printf("Enter name:\n");
	scanf("%s",&list.name);
	fflush(stdin);
	printf("\n");
	printf("Enter phone no\n");
	scanf("%s",&list.ph);
	fflush(stdin);
	printf("\n");
	printf("enter email\n");
	gets(list.email);
	printf("\n");
	fwrite(&list,sizeof(list),1,fp);
	fclose(fp);


}

void ViewContact()
{
	for(int i=97;i<=122;i++)
	{
	fp=fopen("contact.dat","r");
	fflush(stdin);
	int count=0;

	while(fread(&list,sizeof(list),1,fp)==1)
	{
	if(list.name[0]==i||list.name[0]==i-32)
	{
	printf("%s %s %s\n",list.name,list.ph,list.email);
	count++;
	}

	}
       /*	if(count!=0)
	{
	printf("%s %d\n\n",i-32,count);
	getch();
	}*/
	fclose(fp);
	}
}

void EditContact()
{
	fp=fopen("contact.dat","r");
	ft=fopen("temp.dat","w");
	fflush(stdin);
	printf("Enter a name of contact to edit");
	scanf("%s",&name);
	while(fread(&list,sizeof(list),1,fp)==1)
	{
		if(strcmp(name,list.name)!=0)
		fwrite(&list,sizeof(list),1,ft);
	}
	fflush(stdin);
	printf("Editing %s",name);
	printf("New Name");
	scanf("%s",&list.name);
	fflush(stdin);
	printf("phone no");
	scanf("%s",&list.ph);
	fflush(stdin);
	printf("Email");
	scanf("%s",&list.email);
	printf("\n");
	fwrite(&list,sizeof(list),1,ft);
	fclose(fp);
	fclose(ft);
	remove("contact.dat");
	rename("temp.dat","contact.dat");

}

void SearchContact()
{

	int count=0,l;
	printf("Name of contact to search");
	fflush(stdin);
	scanf("%s",&searchName);
	l=strlen(searchName);
	fp=fopen("contact.dat","r");
	//clrscr();
	printf("Search result %s",searchName);
	while(fread(&list,sizeof(list),1,fp)==1)
	{
	for(int i=0;i<l;i++)
	name[i]=list.name[i];
	name[l]='\0';
	if(strcmp(name,searchName)==0)
	{
	printf("%s %s %s",list.name,list.ph,list.email);
	count++;
	if(count%4==0)
	{
	printf("press any key to continue");
	getch();
	}
	}
	}
	if(count==0)
	{
	printf("No such match found");
	}
	else
	{
	printf("%d match found",count);
	}
	fclose(fp);


}

void DeleteContact()
{
	printf("Name of contact to delete");
	scanf("%s",&name);
	int found=0;
	fp=fopen("contact.dat","rb");
	if(!fp)
	{
	printf("unable to open file %s",name);
	}

	ft=fopen("temp.dat","wb");
	while(fread(&list,sizeof(list),1,fp)!=0)
	{
		if(strcmp(name,list.name)==0)
		{
		found=1;
		}else{
		fwrite(&list,sizeof(list),1,ft);
		}
	}
	if(! found)
	{
	     printf("No such records found");
	}
	fclose(fp);
	fclose(ft);
	remove("contact.dat");
      rename("temp.dat","contact.dat");

}

void main()
{
	while(1)
	{

	int ch;

	printf("\n\t*********Welcome to contact manager***********\n\t\t");
	printf("[1] Add a new Contact\n\t\t");
	printf("[2] List all Contacts\n\t\t");
	printf("[3] Edit contact\n\t\t");
	printf("[4] Search Contact\n\t\t");
	printf("[5] Delete contact\n\t\t");
	printf("[6] EXIT\n\t\t");
	printf("Enter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: clrscr();
			AddContact();
			break;

		case 2: clrscr();
			 ViewContact();
			break;

		case 3: clrscr();
			EditContact();
			break;

		case 4: clrscr();
			SearchContact();
			printf("\n..::TRY AGAIN?\n\n\t[1] yes\t\t[0] NO\n\t");
			scanf("%d",&ch);
			break;

		case 5: clrscr();
			DeleteContact();
			break;

		case 6:clrscr();
			exit(0);
			break;
	}
	}
getch();
}