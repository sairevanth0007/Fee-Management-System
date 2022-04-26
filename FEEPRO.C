#include<stdio.h>
#include<string.h>
#include<conio.h>
int j=0;
int rr=1;
unsigned long int ecmmax=100000;
unsigned long int eccmax=62000;
unsigned long int mmax=90000;
unsigned long int cmax=55000;
unsigned long int cemmax=70000;
unsigned long int cecmax=45000;
struct student
{
char sname[15];
char cour[10];
int sem;
char susn[11];
char seet[4];
unsigned long int spay;
unsigned long int sbal;
};
struct student stu[20];
void nfee(char nusn[10]);
void adm();
void nbal(char nusn[10]);
int eusn(char ausn[10]);
void dis();
void main()
{
int ch,p,a=0;
char gusn[10];
clrscr();
printf("\t\t\twelcome\n\n");
la:printf("Enter the 4 digit pass\n");
scanf("%d",&p);
a++;
if(p==1234)
{
}
else
{
if(a<3)
{
printf("retry with correct pass\n\n");
goto la;
}
else
{
printf("entred wrong pass max times");
getch();
exit(0);
}
}
do
{
clrscr();
printf("\t\tFEE PAYMENT SYSTEM\n  MENU \n" );
printf(" enter the Operation \n");
printf(" 1. Fee Payment \n 2. Balence Enquiry \n 3. New Admission \n 4. Display all student details\n 5. EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:clrscr();
if(j>0)
{
printf("Enter the USN number\n");
scanf("%s",gusn);
nfee(gusn);
}
else
{
printf("No student data found\n");
getch();
}
break;
case 2:clrscr();
if(j>0)
{
printf("Enter the USN number\n");
scanf("%s",gusn);
nbal(gusn);
}
else
{
printf("No student data found\n");
getch();
}
break;
case 3:clrscr();
adm();
break;
case 4:clrscr();
if(j>0)
{
dis();
}
else
{
printf("No student data found\n");
getch();
}
break;
case 5:exit(0);
default:printf("Invalid option\n");
}
}while(ch!=6);
}
void adm()
{
int q=0,f,u;
char len[11],qbz[11];
printf("enter the name\n ");
scanf("%s",stu[j].sname);
pco:printf("enter the course\n");
scanf("%s",stu[j].cour);
if(strcmp(stu[j].cour,"cse")==0)
{
strcpy(len,"3br18cs");
}
else if((strcmp(stu[j].cour,"ece")==0))
{
strcpy(len,"3br18ec");
}
else if((strcmp(stu[j].cour,"ele")==0))
{
strcpy(len,"3br18el");
}
else if((strcmp(stu[j].cour,"mec")==0))
{
strcpy(len,"3br18me");
}
else if((strcmp(stu[j].cour,"civ")==0))
{
strcpy(len,"3br18ci");
}
else
{
printf("enter a valid branch name\n\n") ;
goto pco;
}
pusn:printf("enter the 10 digit valid usn no\n");
scanf("%s",stu[j].susn);
strcpy(qbz,stu[j].susn);
u=strlen(qbz);
f=strncmp(qbz,len,7);
if(f==0 && u==10)
{
q=eusn(stu[j].susn);
if(q==1)
{
psem:printf("enter the enerting sem\n");
scanf("%d",&stu[j].sem);
if(stu[j].sem<8)
{
}
else
{
printf("please enter a proper sem no\n\n");
goto psem;
}
pq:printf("enter the quota\n");
scanf("%s",stu[j].seet);
if(strcmp(stu[j].cour,"cse")==0||(strcmp(stu[j].cour,"ece")==0))
{
if(strcmp(stu[j].seet,"mgt")==0)
{
stu[j].spay=0;
stu[j].sbal=100000;
}
else if(strcmp(stu[j].seet,"cet")==0)
{
stu[j].spay=0;
stu[j].sbal=62000;
}
else
{
printf("please enter quota as mgt/cet\n\n");
goto pq;
}
}
else if(strcmp(stu[j].cour,"ele")==0||(strcmp(stu[j].cour,"civ")==0))
{
if(strcmp(stu[j].seet,"mgt")==0)
{
stu[j].spay=0;
stu[j].sbal=70000;
}
else if(strcmp(stu[j].seet,"cet")==0)
{
stu[j].spay=0;
stu[j].sbal=45000;
}
else
{
printf("please enter quota as mgt/cet\n\n");
goto pq;
}
}
else if(strcmp(stu[j].cour,"mec")==0)
{
if(strcmp(stu[j].seet,"mgt")==0)
{
stu[j].spay=0;
stu[j].sbal=90000;
}
else if(strcmp(stu[j].seet,"cet")==0)
{
stu[j].spay=0;
stu[j].sbal=55000;
}
else
{
printf("please enter quota as mgt/cet\n\n");
goto pq;
}
}
j++;
}
else
{
printf("usn already taken \n");
}
}
else
{
if(strcmp(stu[j].cour,"cse")==0)
{
printf("usn should be in the format of 3br18cs***\n\n");
goto pusn;
}
else if(strcmp(stu[j].cour,"ele")==0)
{
printf("usn should be in the format of 3br18el***\n\n");
goto pusn;
}
else if(strcmp(stu[j].cour,"ece")==0)
{
printf("usn should be in the format of 3br18ec***\n\n");
goto pusn;
}
else if(strcmp(stu[j].cour,"mec")==0)
{
printf("usn should be in the format of 3br18me***\n\n");
goto pusn;
}
else if(strcmp(stu[j].cour,"civ")==0)
{
printf("usn should be in the format of 3br18ci***\n\n");
goto pusn;
}
}
getch();
}
void nfee(char nusn[10])
{
unsigned long int pay,max;
int yes,i;
for(i=0;i<j;i++)
{
if(strcmp(stu[i].susn,nusn)==0)
{
 if(strcmp(stu[i].cour,"cse")==0||(strcmp(stu[i].cour,"ece")==0))
 {
 if(strcmp(stu[i].seet,"mgt")==0)
 {
 max=ecmmax;
 }
 else
 {
 max=eccmax;
 }
 }
else if(strcmp(stu[i].cour,"ele")==0||(strcmp(stu[i].cour,"civ")==0))
{
if(strcmp(stu[i].seet,"mgt")==0)
{
max=cemmax;
}
else
{
max=cecmax;
}
}
else if(strcmp(stu[i].cour,"mec")==0)
{
if(strcmp(stu[i].seet,"mgt")==0)
{
max=mmax;
}
else
{
max=cmax;
}
}
printf("enter the paying amount\n");
scanf("%lu",&pay);
clrscr();
if(pay+stu[i].spay<=max)
{
printf("\t\t\tFee Receipt\n");
printf("  Student Name: %s\t\t",stu[i].sname);
printf("  Course & sem: %s - %d sem\n",stu[i].cour,stu[i].sem);
printf("  USN / Board NO: %s\tRef no: Rn%d\n",stu[i].susn,rr);
printf("  Quota: %s\t\t\t",stu[i].seet);
printf("  Date:%s\tTime:%s\n",__DATE__,__TIME__);
printf("  \n\tParticulars\t\tAmount\n");
printf("  tution fee:\t\t\t%lu\n",pay);
printf("  total:\t\t\t%lu\n",pay);
stu[i].spay=stu[i].spay+pay;
stu[i].sbal=max-stu[i].spay;
rr++;
printf("\n\n Remaining balance from total fee is:%lu\n",stu[i].sbal);
yes=1;
}
else
{
printf("You just need to pay %lu\n",stu[i].sbal);
yes=1;
getch();
}
}
}
if(yes!=1)
{
printf("No student found with %s usn\n",nusn);
getch();
}
getch();
}
void nbal(char nusn[10])
{
int i,k;
for(k=0;k<j;k++)
{
if(strcmp(stu[k].susn,nusn)==0)
{
printf("  Student Name:%s\t\t",stu[k].sname);
printf("  Course & sem:%s & %d sem\n",stu[k].cour,stu[k].sem);
printf("  USN / Board NO:%s\n",nusn);
printf("  student has payed %lu\n",stu[k].spay);
printf("  student has to pay %lu\n",stu[k].sbal);
i=1;
getch();
}
}
if(i!=1)
{
printf("No student found with %s usn\n",nusn);
getch();
}
}
int eusn(char ausn[10])
{
int i,z=10,f;
for(i=0;i<j;i++)
{
if(strcmp(stu[i].susn,ausn)==0)
{
z=0;
}
}
if(z==0)
{
return 0;
}
else
{
return 1;
}
}
void dis()
{
int k;
clrscr();
for(k=0;k<j;k++)
{
printf("  Student Name:%s\t\t",stu[k].sname);
printf("  course & sem:%s & %d sem\n",stu[k].cour,stu[k].sem);
printf("  USN / Board NO:%s\t",stu[k].susn);
printf("  Quota:%s\n",stu[k].seet);
printf("  student has payed %lu\n",stu[k].spay);
printf("  student has to pay %lu\n\n",stu[k].sbal);
}
getch();
}

