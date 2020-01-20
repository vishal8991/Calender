/*Calender to check a day ,check leapyear & to print month & add a task
on Turboc++ software*/
#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int check_day();
void display();
int get_month(int,int);
int leap_year(int);
void get_value();
void display();
void print_month();
void check_event();
void add_event();
FILE  *fp, *ft ;
char *months[]={"Jan","Feb","Mar",
		"Apr","May","Jun","Jul",
		"Aug","Sept","Oct",
		"Nov","Dec"};
struct calender
{
int dd;
int mm;
int yyyy;
char e_name[40];
};
struct calender c;
void main()
{
fp = fopen ( "List.DAT", "rb+" ) ;
 if ( fp == NULL )
 {
 fp = fopen ( "List.DAT", "wb+" ) ;
 if ( fp == NULL )
 {
 puts ( "Cannot open file" ) ;
 exit(0) ;
 }
 }
int gd=DETECT,gm,x,y,i;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
x=getmaxx()/2;
y=getmaxy()/2;
//setcolor(15);
rectangle(x-50,y-50,x+50,y+50);
rectangle(x-51,y-51,x+51,y+51);
rectangle(x-52,y-52,x+52,y+52);
setfillstyle(9,2);
bar(x-50,y-50,x+50,y+50);
settextstyle(3, HORIZ_DIR, 2);
for(i=x-50;i<x+50;i=i+2)
putpixel(i,y-46,0);
outtextxy(x-45,y-25,"CALENDER");
outtextxy(x-30,y+5,"2K18");
outtextxy(x-100,y+70,"TO Continue Press any key:");
getch();
setbkcolor(1);
char ch;
do
{
cleardevice();
setcolor(4);
outtextxy(5,2,"*********************< Calender_2K18>********************");
time_t tt;
	struct tm *ti;
	time(&tt);
	ti=localtime(&tt);
	gotoxy(10,5);
	cout<<asctime(ti);
gotoxy(30,8);
printf("1.Check_Day");
gotoxy(30,10);
printf("2.Check_Leap_Year");
gotoxy(30,12);
printf("3.Calender");
gotoxy(30,14);
printf("4.Add Task");
gotoxy(30,16);
printf("5.Event List");
gotoxy(30,18);
printf("6.Exit");
printf("\n\tEnter Your Choice: ");
char choice;
gotoxy(30,20);
choice=getche();
cleardevice();
outtextxy(5,2,"********************* < Calender_2K18 > ********************");
switch(choice)
{
case '1':
int val;
get_value();
val=check_day();
clrscr();
display();
gotoxy(10,12);
if(val==0)
cout<<"Sunday";
else if(val==1)
cout<<"Monday";
else if(val==2)
cout<<"Tuesday";
else if(val==3)
cout<<"Wednesday";
else if(val==4)
cout<<"Thursday";
else if(val==5)
cout<<"Friday";
else if(val==6)
cout<<"Saturday";
break;
case '2':
cleardevice();
outtextxy(5,2,"********************* < Calender_2K18 > ********************");
gotoxy(1,3);
cout<<"Leap Year is repeat by every 4 years but century years which are";
cout<<"\nnot divisible by 400 are not a leap year like 1700,1900....";
cout<<"\n\nEnter Year:";
int year,l;
cin>>year;
l=leap_year(year);
if(l==1)
cout<<"\n"<<year<<" is a Leap Year!";
else if(l==0)
cout<<"\n"<<year<<" is not a Leap Year!";
break;
case '3':
gotoxy(10,12);
c.dd=1;
cout<<"Enter Month & Year: ";
cin>>c.mm>>c.yyyy;
clrscr();
print_month();
break;
case '4':
cleardevice();
outtextxy(5,2,"********************* < Calender_2K18 > ********************");
gotoxy(10,3);
cout<<"Add New Event:";
add_event();
break;
case '5':
cleardevice();
outtextxy(5,2,"********************* < Calender_2K18 > ********************");
//scout<<"\nCheck Events:";
check_event();
break;
case '6':
exit(0);
default:
cout<<"\nWrong Choice!";
}
gotoxy(10,15);
cout<<"To Contniue Press 'P': ";
ch=getche();
}while(ch=='P');
getch();
closegraph();
}
int check_day()
{
while(1)
{
gotoxy(10,13);
/*To Check date is valid 0r not */
if(c.dd<1||c.dd>31)
{
cout<<"invalid Date!";
break;
}
/*To Check month is valid 0r not */
if(c.mm<1||c.mm>12)
{
cout<<"invalid month!";
break;
}
/*To Check year is valid 0r not */
if(c.yyyy<=1600||c.yyyy>2050)
{
cout<<"invalid Year!";
break;
}
int val,cen,div,rem,yr,odd,date,noncen,mon;
if(c.yyyy%400==0)
{
div=(c.yyyy-1)%400;
cen=div%100;
odd=div-cen;
if(odd==300)
noncen=1;
else if(odd==200)
noncen=3;
else if(odd==100)
noncen=5;
else
noncen=0;
int x;
x=cen/4;
rem=(x*2+((cen)-x))%7;
}
else
{
div=(c.yyyy)%400;
cen=div%100;
odd=div-cen;
if(odd==300)
noncen=1;
else if(odd==200)
noncen=3;
else if(odd==100)
noncen=5;
else
noncen=0;
if(cen%4==0)
{
int x;
x=(cen-1)/4;
rem=(x*2+((cen-1)-x))%7;
///cout<<",x="<<x<<",rem="<<rem;
}
else
{
int x;
x=cen/4;
rem=(x*2+((cen-1)-x))%7;
//cout<<",rem="<<rem;
}
}
date=c.dd%7;
int num=0;
for(int i=1;i<c.mm;i++)
{
mon=get_month(i,c.yyyy);
num=num+mon;
//cout<<"\nnum="<<num;
}
mon=num%7;
val=(0+noncen+rem+date+mon)%7;
gotoxy(10,9);
//cout<<"noncen="<<noncen<<",rem="<<rem<<",date="<<date<<",mon="<<mon;
return(val);
}
}
void get_value()
{
gotoxy(10,10);
cout<<"Enter Date, Month & Year(like 10 07 1998):\n";
gotoxy(10,11);
cout<<"DD/MM/YYYY:";
cin>>c.dd>>c.mm>>c.yyyy;
}
void display()
{
cleardevice();
outtextxy(5,2,"********************* < Calender_2K18 > ********************");
gotoxy(10,10);
//cout<<"\t\t\t"<<c.yyyy;
cout<<c.dd<<" "<<months[(c.mm)-1]<<" "<<c.yyyy;
}
int leap_year(int y)
{
if(y%400!=0)
{
if(y%100!=0 && y%4==0)
{
return(1);
}
else
{
return(0);
}
}
else
return(1);
}
int get_month(int mon,int year)
{
int r;
if(mon==1)
return(31);
else if(mon==2)
{
r=leap_year(year);
if(r==0)
return(28);
else if(r==1)
return(29);
}
else if(mon==3)
return(31);
else if(mon==4)
return(30);
else if(mon==5)
return(31);
else if(mon==6)
return(30);
else if(mon==7)
return(31);
else if(mon==8)
return(31);
else if(mon==9)
return(30);
else if(mon==10)
return(31);
else if(mon==11)
return(30);
else if(mon==12)
return(31);
}
void print_month()
{
int mnth,value;
//for(int m=0;m<=11;m++)
//{
value=check_day();
mnth=get_month(c.mm,c.yyyy);
cleardevice();
outtextxy(5,2,"********************* < Calender_2K18 > ********************");
gotoxy(1,3);
cout<<"\n	------------------- "<<months[c.mm-1]<<" "<<c.yyyy<<" ---------------------\n";
cout<<"\n	Sun	Mon	Tue	Wed	Thu	Fri	Sat";
int i=0,j=1;
cout<<"\n";
for(i=0;i<=value;i++)
{
printf("	");
}
for(j=1;j<=mnth;j++)
{
cout<<j;
if((j+value)%7>0)
cout<<"\t";
else
cout<<"\n\t";
}
//check_event();
//getch();
//}
}
void check_event()
{
int i=5,month,year;
gotoxy(1,3);
cout<<"Enter month & year: ";
cin>>month>>year;
//c.mm=1;
//c.yyyy=2018;
cleardevice();
outtextxy(5,2,"********************* < Calender_2K18 > ********************");
rewind(fp);
while(fread(&c,sizeof(c),1,fp)==1)
{
gotoxy(1,3);
cout<<"\n		------------------- "<<c.yyyy<<" ---------------------\n";
gotoxy(1,i);
if(c.mm==month && c.yyyy==year)
{
cout<<c.dd<<" "<<months[c.mm-1]<<": "<<c.e_name;
i++;
}
}
}
void add_event()
{
	char ch='Y';
	while(ch=='Y')
	{
	gotoxy(10,5);
	cout<<"DD MM YYYY: ";
	cin>>c.dd>>c.mm>>c.yyyy;
	gotoxy(10,7);
	cout<<"EVENT: ";
	gets(c.e_name);
	gotoxy(10,9);
	cout<<"To Continue Press 'S':\n";
	char sub;
	sub=getche();
	cleardevice();
	outtextxy(5,2,"********************* < Calender_2K18 > ********************");
	if(sub=='S')
	{
	fwrite ( &c, sizeof(c), 1, fp ) ;
	gotoxy(10,10);
	cout<<c.dd<<" "<<months[c.mm-1]<<": "<<c.e_name;
	}
	fflush(stdin);
	gotoxy(10,11);
	cout<<"To add Another Task Enter 'Y': ";
	ch=getche();
	cleardevice();
	outtextxy(5,2,"********************* < Calender_2K18 > ********************");
	}
}

