#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Staff{
	int id;
	char name[100];
	char gender[30];
	int phone;
	char email[100];
};

void append();
void export();
void del();
int main()
{
int ch;
while(1)
{

	printf("***********************************\n 1.Add New Staff Profile\n 2.Delete Staff Profile\n" );
	printf(" 3.Export All profiles to 'output.txt' \n 4.Exit\n***********************************\n" );//Think how to put output.txt in 3
	printf("Please enter your option < 1 / 2 / 3 / 4 >:\n");
scanf("%d",&ch);
switch(ch)
{
case 1: append();
break;

case 2: del();
break;

case 3: export();
break;

case 4:
printf("Thank you");
exit(0);
break;
default:
	printf("Invalid option");
	break;

}}
return 0;
}
void append()
{
FILE *fp;
struct Staff staff;
fp=fopen("database.dat","ab");

printf("\nID:");
scanf("%d",&staff.id);
printf("Name: ");
			scanf("%s",staff.name);
			printf("Gender: ");
			scanf("%s",staff.gender);
			printf("Phone: ");
			scanf("%d",&staff.phone);
			printf("Email: ");
			scanf("%s",staff.email);
			printf("SYSTEM: New staff profile is added successfully.\n" );

fwrite(&staff,sizeof(struct Staff),1,fp);

fclose(fp);
}


void del()
{
FILE *fp,*fp1;
struct Staff staff,staff1;
int id,found=0,count=0;
fp=fopen("database.dat","rb");
fp1=fopen("temp.dat","wb");
printf("\nEnter the Emp ID you want to Delete:");
scanf("%d",&id);
while(1)
{
fread(&staff,sizeof(struct Staff),1,fp);
if(feof(fp))
{
break;
}
if(staff.id==id)
{
found=1;
}
else
{
fwrite(&staff,sizeof(struct Staff),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen("database.dat","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&staff,sizeof(struct Staff),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&staff,sizeof(struct Staff),1,fp);
}
}
fclose(fp);
fclose(fp1);
}


void export()
{
FILE *fp;
struct Staff staff;
FILE *fptr;
fptr=fopen("output.txt","w");
fp=fopen("database.dat","rb");
fprintf(fptr,"ID\tName\tGender\tPhone\tEmail\n\n");

while(1)
{
fread(&staff,sizeof(struct Staff),1,fp);

if(feof(fp))
{
break;
}
fprintf(fptr,"%d\t",staff.id);
fprintf(fptr,"%s\t",staff.name);
fprintf(fptr,"%s\t",staff.gender);
fprintf(fptr,"%d\t",staff.phone);
fprintf(fptr,"%s\t\n\n",staff.email);
}
fclose(fp);
fclose(fptr);
}
