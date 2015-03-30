/*==============================================================================
Webedit 3.1
||Computer Science Project||
Programmed by T.Thiyagaraj, 12-F (2013-2014)
Mount Carmel School Anand Niketan
================================================================================
Objective of the Program - Edit a html and css based website
================================================================================
Ensure that the program is in the folder with the following files-
*These are necessary files for the program to execute*
home.html
about.html
info.html
blog.html
contact.html
style.css
*Thes files are designed specifically in accordance to the program, it is not
compactible with any website
-Once the User starts executes the program, the user is allowed to make back-up
 files of the above html file in the form of .dat files.

-There addition .png files also which must be present in the path \images
 Without the images certain features do not work.
-Internet Browser is a must in order to preview the website.
-Recommended browser is Google Chrome
==============================================================================*/


#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

//Time Delay Function ----------------------------------------------------------
//Scope<GLOBAL>
void delay(float seconds)
{
time_t start, current;
time(&start)  ;
do
{
time(&current);
}
while
((current - start) < seconds);
}

//Option-Limiter function ----------------------------------------------------
//Scope<GLOBAL>
int inpop(int m , int M)
{
int o ;
cout<<"\n=>" ;
cin>>o ;
if((m<=o)&&(o<=M))
return(o) ;
else
{
cout<<"\nYou entered an invalid option Invalid Option" ;
delay(2) ;
cout<<"\nYou are being redirected back to the menu ..." ;
delay(2);
clrscr();
return(0) ;
}
}

//LOGO generator ---------------------------------------------------------------
//Scope<GLOBAL>
void logo ()
{
clrscr();
char a ;
a=177;
char b ;
b=178 ;
//Makes a visual appear on the screen ...
cout<<endl;
cputs("           ");cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<endl;
cputs("                  ");cout<<a<<b<<a<<a<<a<<endl;
cputs("           ");cout<<b<<b<<b<<b<<b<<b;cputs(" ");cout<<a<<b<<a<<a<<a<<endl;
cputs("           ");cout<<b<<b<<b<<b<<b<<b;cputs(" ");cout<<a<<b<<a<<a<<a;
cputs("    WebediT ");cout<<endl;
cputs("           ");cout<<b<<b<<b<<b<<b<<b;cputs(" ");cout<<a<<b<<a<<a<<a;
cputs("        Version 3.0 ");cout<<endl;;
cputs("           ");cout<<b<<b<<b<<b<<b<<b;cputs(" ");cout<<a<<b<<a<<a<<a<<endl;
cputs("           ");cout<<b<<b<<b<<b<<b<<b;cputs(" ");cout<<a<<b<<a<<a<<a<<endl;
cputs("           ");cout<<b<<b<<b<<b<<b<<b;cputs(" ");cout<<a<<b<<a<<a<<a<<endl;
for(int i=0 ; i<80 ; i++)
cputs("_") ;
}


//Class defination of user -----------------------------------------------------
class user {
char name [25] ;
char pass[25] ;
void styrep( char spl[], char rep[] )  ;
void linrep( char file[] , char u[] , int n ) ;
void readlin( char file[] , int n )  ;
void fontname(int o)   ;
void fontcolor(int o)  ;
void fontsize()       ;
void update( int o )   ;
void theme(int o)    ;
public:
void menu() ;
void showdets();
void showdetails()  ;
//Constructors of user ---------------------------------------------------------
//Scope<USER:PUBLIC>
user :: user(int i)
{
cout<<"\nEnter the user name : " ;
gets(name) ;
cout<<"\Enter the password : " ;
gets(pass) ;
}

user( )
{
//No Initialization (for file handling purposes)
}

//Returns-Name-password functions ----------------------------------------------
//Scope<USER:PUBLIC>
char *retname()
{
return (name) ;
}

char*retpass()
{
return (pass) ;
}

};


//Replacing word and line functions---------------------------------------------
//Scope<USER:PRIVATE>
void user :: styrep( char spl[], char rep[] )
 {
 ifstream f1("style.css") ;
 ofstream f2("temp.css") ;
 char w[20] ;

  while(!f1.eof())
  {
  f1>>w;
  if(strcmp(spl,w)==0)
	{
	f2<<w ;
	f2<<"  " ;
	f2<<rep ;
	f2<<"  " ;
	f1>>w ;
	}
  else
	{
	f2<<w ;
	f2<<"  ";
	}

 }
  f1.close() ;
  f2.close()  ;
  remove("style.css") ;
  rename("temp.css", "style.css") ;
 }

void user :: linrep( char file[] , char u[] , int n )
 {
 int c = 1 ;
 ifstream f1(file) ;
 ofstream f2("temp.html") ;
 char r[200] ;
 f1.getline(r,200)  ;
 while(!f1.eof())
  {
  if(c==n)
  f2<<u<<endl ;
  else
  f2<<r<<endl ;
  f1.getline(r,200) ;
  c++ ;
  }
  f1.close() ;
  f2.close() ;
  remove(file);
  rename("temp.html",file);

 }


//Reading Line function -----------------------------------------------------------------
//Scope<USER:PRIVATE>
void user :: readlin( char file[] , int n )
 {
 ifstream f1(file) ;
 int c= 1 ;
 char r[200] ;
 f1.getline(r,200) ;
 while(!f1.eof())
  {
  if(c==n)
  puts(r) ;
  c++ ;
  f1.getline(r,200);
  }
 }


//functions of Style Sub-Menu -------------------------------------------------
//Scope<USER:PRIVATE>
void user :: fontname(int o)
 {
 cout<<"\nChoose the desired font : " ;
 cout<<"\nVivaldi            (1)" ;
 cout<<"\nArial              (2)" ;
 cout<<"\nChiller            (3)" ;
 cout<<"\nLucida Console     (4)" ;
 cout<<"\nCentury Gothic     (5)" ;
 cout<<"\nEnter you own font (6)" ;
 o=inpop(1,6) ;
 switch(o){
 case 1: styrep("/*fontname*/", "Vivaldi");
 break ;
 case 2: styrep("/*fontname*/", "Arial") ;
 break ;
 case 3: styrep("/*fontname*/", "Chiller") ;
 break ;
 case 4: styrep("/*fontname*/", "Lucida/**/Console") ;
 break ;
 case 5: styrep("/*fontname*/", "Century/**/Gothic") ;
 break ;
 case 6:
 char f[15] ;
 cout<<"\nEnter the font\nIf font name is 'Sample Font', then enter 'Sample/**/Font')\n-> "  ;
 cin>>f ;
 styrep("/*fontname*/", f) ;
 if(o==0)
 {
 cout<<"\nInvalid Option" ;
 delay(1);
 menu();
 }
 break ;
 }
 }

void user :: fontcolor(int o)
 {
 cout<<"\nChoose the color of the font : " ;
 cout<<"\nBlack   (1)" ;
 cout<<"\nRed     (2)" ;
 cout<<"\nBlue    (3)" ;
 cout<<"\nYellow  (4)" ;
 cout<<"\nPink    (5)" ;
 cout<<"\nGreen   (6)" ;
 o=inpop(1,6) ;
 if(o==0)
 {
 menu() ;
 }
 switch(o){
 case 1: styrep("/*textcolor*/", "black");
 break ;
 case 2: styrep("/*textcolor*/", "red") ;
 break ;
 case 3: styrep("/*textcolor*/", "blue") ;
 break ;
 case 4: styrep("/*textcolor*/", "yellow") ;
 break ;
 case 5: styrep("/*textcolor*/", "pink") ;
 break ;
 case 6: styrep("/*textcolor*/", "green") ;
 break ;
 }
 }

void user::  fontsize()
 {
 cout<<"\n Enter the desired size of the Font of the content (in px): ";
 char s[3] ;
 gets(s) ;
 styrep("/*fontsize*/", strcat(s,"px") ) ;
 }

void user ::  update( int o )
 {
 switch(o){
 char i[100];
 case 1 :  //For Header
 cout<<"Enter the Title (First Part) : " ;
 gets(i) ;
 linrep("home.html" ,i,5) ;
 linrep("home.html" ,i,11) ;
 linrep("about.html" ,i,5) ;
 linrep("about.html" ,i,11) ;
 linrep("contact.html" ,i,5) ;
 linrep("contact.html" ,i,11) ;
 linrep("info.html" ,i,5) ;
 linrep("info.html" ,i,11) ;
 linrep("blog.html" ,i,5) ;
 linrep("blog.html" ,i,11) ;
 cout<<"Enter the Title (Second Part) : " ;
 gets(i) ;
 linrep("home.html" ,i,13) ;
 linrep("about.html" ,i,13) ;
 linrep("contact.html" ,i,13) ;
 linrep("info.html" ,i,13) ;
 linrep("blog.html" ,i,13) ;
 cout<<"Enter the Tag Line : " ;
 gets(i) ;
 linrep("home.html" ,i,17) ;
 linrep("about.html" ,i,17) ;
 linrep("contact.html" ,i,17) ;
 linrep("info.html" ,i,17) ;
 linrep("blog.html" ,i,17) ;
 break ;

 case 2 : //for home page
 cputs("\nExisting Heading -\n") ;
 readlin("home.html",34) ;
 cputs("\nExisting Content -\n") ;
 readlin("home.html",37) ;
 cout<<"Enter the Heading  :"    ;
 gets(i) ;
 linrep("home.html",i,34) ;
 cout<<"Enter the Paragraph :" ;
 gets(i) ;
 linrep("home.html",i,37) ;
 break ;

 case 3 :
 cputs("\nExisting Heading -\n") ;
 readlin("about.html",34) ;
 cputs("\nExisting Content -\n") ;
 readlin("about.html",37) ;
 cout<<"Enter the Heading  :"    ;
 gets(i) ;
 linrep("about.html",i,34) ;
 cout<<"Enter the Paragraph :" ;
 gets(i) ;
 linrep("about.html",i,37) ;
 break ;

 case 4 :
 cputs("\nExisting Heading -\n") ;
 readlin("info.html",34) ;
 cputs("\nExisting Content -\n") ;
 readlin("info.html",37) ;
 cout<<"Enter the Heading  :"    ;
 gets(i) ;
 linrep("info.html",i,34) ;
 cout<<"Enter the Paragraph :" ;
 gets(i) ;
 linrep("info.html",i,37) ;
 break ;

 case 5 :
 cputs("\nExisting Heading -\n") ;
 readlin("info.html",34) ;
 cputs("\nExisting Content -\n") ;
 readlin("info.html",37) ;
 cout<<"Enter the Heading  :"    ;
 gets(i) ;
 linrep("blog.html",i,34) ;
 cout<<"Enter the Paragraph :" ;
 gets(i) ;
 linrep("blog.html",i,37) ;
 break;

 case 6 :
 cputs("\nExisting Heading -\n") ;
 readlin("contact.html",34) ;
 cputs("\nExisting Content -\n") ;
 readlin("contact.html",37) ;
 cout<<"Enter the Heading  :"    ;
 gets(i) ;
 linrep("contact.html",i,34) ;
 cout<<"Enter the Paragraph :" ;
 gets(i) ;
 linrep("contact.html",i,37) ;
 break ;
 }
 }


void user:: theme(int o)
 {
 switch(o){
 case 1 :
 styrep( "/*bg*/" , "url(images/redbg.png)"  );
 styrep( "/*bglink*/" , "url(images/redlink.png)" ) ;
 break;
 case 2 :
 styrep(   "/*bg*/" , "url(images/bluebg.png)"  );
 styrep(  "/*bglink*/" , "url(images/bluelink.png)" ) ;
 break;
 case 3 :
 styrep(   "/*bg*/" , "url(images/greenbg.png)"  );
 styrep(  "/*bglink*/" , "url(images/greenlink.png)" ) ;
 break;
 case 4 :
 styrep(   "/*bg*/" , "url(images/blackbg.png)"  );
 styrep(  "/*bglink*/" , "url(images/blacklink.png)" ) ;
 break;

 }
 }


//Main-Menu function defination ------------------------------------------------
//Scope<USER:PUBLIC>
void user :: menu()
{
clrscr();
logo();
int o ;
cout<<"\nAccess tools -" ;
cout<<"\nChange website's theme    (1)" ;
cout<<"\nEdit Style                (2)" ;
cout<<"\nUpdate Content            (3)" ;
cout<<"\nHelp                      (4)" ;
cout<<"\nAbout Webedit             (5)" ;
cout<<"\nExit                      (6)" ;
o=inpop(1,6) ;
if(o==0)
{
menu();
}
if(o==1)
 {
 cout<<"\nSelect the desired theme" ;
 cout<<"\nBurnout Red   (1) " ;
 cout<<"\nAqua Blue     (2) " ;
 cout<<"\nGreen Swamp   (3) " ;
 cout<<"\nSteel Black   (4) " ;
 o=inpop(1,4) ;
 if(o==0)
 {
 menu();
 }
 theme(o) ;
 menu() ;
 }
else if ( o==2)
 {
 cout<<"\n Change Font       (1)" ;
 cout<<"\n Change Font Color (2)" ;
 cout<<"\n Change Font Size  (3)" ;
 o=inpop(1,3);
 if(o==0)
 {
 menu();
 }
 switch(o){
  case 1 :
  fontname(o) ;
  menu() ;
  case 2 :
  fontcolor(o) ;
  menu() ;
  case 3 :
  fontsize() ;
  menu() ;
  }
 }
else if (o==3)
 {
 cout<<"\nChoose the webpage :" ;
 cout<<"\nWebsite's Header (1)" ;
 cout<<"\nHome             (2)" ;
 cout<<"\nAbout            (3)" ;
 cout<<"\nInfo             (4)" ;
 cout<<"\nBlog             (5)" ;
 cout<<"\nContact Us       (6)" ;
 o=inpop(1,6) ;
 if(o==0)
 {
 menu();
 }
 update(o) ;
 menu();
 }
else if(o==4)
{
cputs("Webedit offers a no. of tools to edit your website's design") ;
cout<<endl;
cout<<endl;
cputs("This version of Webedit also offers you tools which allows you to-");
cout<<endl;
cputs("-Update the content") ;
cout<<endl;
cputs("-Make Back-Up of Content*") ;
cout<<endl;
cputs("-Predesigned Themes") ;
cout<<"\n*Only in Admin mode";
cout<<endl;
cout<<endl;
cputs("While updating content, if you want to go to the second line then,") ;
cout<<"\n- Type <br> " ;
cout<<endl;
cout<<endl;
cputs("In case the website is not showing the changes" ) ;
cout<<"\n-Refresh the browser";
cout<<"\n-Contact the Admin and Reload the BackUp" ;
cout<<"\n-If back-up files are missing, send a request to tstream.h@outlook.com" ;
cout<<"\n-Do not use html tags, it can have its effects on the website\n\n" ;
cputs("Press any Key to go back....") ;
getch() ;
menu();
}
else if (o==5)
{
clrscr();
logo();
cout<<"\n\t   ";
cputs("Webedit Version 3.1");
cout<<endl;
cout<<"\t   ";
cputs("Last Updated  : September 2013") ;
cout<<endl;
cout<<"\t   ";
cputs("Programmed by T.Thiyagaraj") ;
cout<<endl;
cout<<"\t   ";
cputs("tstream.h@outlook.com") ;

cout<<"\n\n\t   Press any key to go back ..."      ;
getch();
menu();
}
else
exit(0);
}

void user:: showdets()
{
cout<<"\nUser Name : " ;
puts(name) ;
cout<<"Password : ";
puts(pass);
}


//Shows Details function--------------------------------------------------------
//Scope<USER:PUBLIC>
void user :: showdetails()
{
cout<<"\nUser Name:" ;
puts(name) ;
cout<<"\nPassword:" ;
puts(pass)       ;
}



//Class Defination of admin ----------------------------------------------------
class admin : public user
{

//Backup Functions--------------------------------------------------------------
//Scope<USER:PRIVATE>
void makebackup()
{
ifstream f1 ;
ofstream f2;
f1.open("blog.html")  ;
f2.open("blogbu.dat",ios::binary) ;
char line[200];
f1.getline(line,200);
while(!f1.eof())
{
f2.write((char*)&line , sizeof(line)) ;
f1.getline(line, 200) ;
}
f1.close();
f2.close();

f1.open("info.html")  ;
f2.open("infobu.dat",ios::binary) ;
f1.getline(line, 200) ;
while(!f1.eof())
{
f2.write((char*)&line , sizeof(line)) ;
f1.getline(line, 200) ;
}
f1.close();
f2.close();

f1.open("about.html")  ;
f2.open("aboutbu.dat",ios::binary) ;
f1.getline(line, 200) ;
while(!f1.eof())
{
f2.write((char*)&line , sizeof(line)) ;
f1.getline(line, 200) ;
}
f1.close();
f2.close();

f1.open("home.html")  ;
f2.open("homebu.dat",ios::binary) ;
f1.getline(line, 200) ;
while(!f1.eof())
{
f2.write((char*)&line , sizeof(line)) ;
f1.getline(line, 200) ;
}
f1.close();
f2.close();

f1.open("contact.html")  ;
f2.open("contactbu.dat",ios::binary) ;
f1.getline(line, 200) ;
while(!f1.eof())
{
f2.write((char*)&line , sizeof(line)) ;
f1.getline(line, 200) ;
}
f1.close();
f2.close();
}

reload()
{
ifstream f2 ;
ofstream f1 ;
char line[200];
f1.open("home.html")  ;
f2.open("homebu.dat",ios::binary) ;
f2.read((char*)&line, sizeof(line)) ;
while(!f2.eof())
{
f1<<line;
f1<<endl;
f2.read((char*)&line , sizeof(line)) ;
}
f1.close();
f2.close();

f1.open("info.html")  ;
f2.open("infobu.dat",ios::binary) ;
f2.read((char*)&line, sizeof(line)) ;
while(!f2.eof())
{
f1<<line;
f1<<endl;
f2.read((char*)&line , sizeof(line)) ;
}
f1.close();
f2.close();

f1.open("about.html")  ;
f2.open("aboutbu.dat",ios::binary) ;
f2.read((char*)&line, sizeof(line)) ;
while(!f2.eof())
{
f1<<line;
f1<<endl;
f2.read((char*)&line , sizeof(line)) ;
}
f1.close();
f2.close();

f1.open("blog.html")  ;
f2.open("blogbu.dat",ios::binary) ;
f2.read((char*)&line, sizeof(line)) ;
while(!f2.eof())
{
f1<<line;
f1<<endl;
f2.read((char*)&line , sizeof(line)) ;
}
f1.close();
f2.close();

f1.open("contact.html")  ;
f2.open("contactbu.dat",ios::binary) ;
f2.read((char*)&line, sizeof(line)) ;
while(!f2.eof())
{
f1<<line;
f1<<endl;
f2.read((char*)&line , sizeof(line)) ;
}
f1.close();
f2.close();
}

//Generate a user function------------------------------------------------------
//Scope<ADMIN:PRIVATE>
void genuser()
{
user a(1) ;
fstream f1("users.dat" ,ios::binary|ios::app ) ;
f1.write((char*)&a ,sizeof(a)) ;
f1.close() ;
}

//Display users and passwords function -----------------------------------------
//Scope<ADMIN:PRIVATE>
void showusers()
{
int c =0 ;
cout<<"\n\t    <<-Users and Their Passwords->>\n ";
user a ;
fstream f1("users.dat", ios::binary|ios::in) ;
f1.read((char*)&a ,sizeof(a)) ;
while (!f1.eof())
{
cout<<"\nUser No. "<< ++c ;
a.showdets() ;
f1.read((char*)&a, sizeof(a) ) ;
cout<<"----------------------------------------------------------------------";
}
f1.close();
cputs("Press any key to go back...");
getch();
}

//Delete a user function--------------------------------------------------------
//Scope<ADMIN:PRIVATE>
void deleteuser()
{
char name[20];
cout<<"\nEnter the user-name (CAse-SenStIvE) : "   ;
gets(name) ;
ifstream f1("users.dat", ios::binary) ;
ofstream f2("temp.dat", ios::binary) ;
user a ;
f1.read((char*)&a ,sizeof(a) ) ;
while(!f1.eof())
{
char*r=a.retname();
if(strcmpi(r,name)!=0)
{
f2.write((char*)&a, sizeof(a)) ;
f1.read((char*)&a, sizeof(a));
}
else
{
f1.read((char*)&a, sizeof(a) ) ;
}
}
f1.close() ;
f2.close() ;
remove("users.dat")   ;
rename("temp.dat","users.dat")    ;
}

public:

//Master Menu function defination-----------------------------------------------
//Scope<USER:PUBLIC>
void mastermenu()
{
clrscr();
logo();
int o ;
cout<<"\nCreate a new User                      ";
cputs("(1)")  ;
cout<<"\nDisplay the User Names and Passwords   ";
cputs("(2)") ;
cout<<"\nUser Mode                              ";
cputs("(3)") ;
cout<<"\nDelete a User                          ";
cputs("(4)") ;
cout<<"\nReload the Back-up of Content          ";
cputs("(5)") ;
cout<<"\nMake Back-up of Content                ";
cputs("(6)") ;
cout<<"\nExit                                   ";
cputs("(7)") ;
o=inpop(1,7) ;
switch(o){
case 1 :
genuser() ;
mastermenu();
case 2 :
showusers() ;
mastermenu() ;
case 3 :
menu();
case 4 :
deleteuser();
mastermenu();
case 5 :
reload();
mastermenu();
case 6 :
makebackup();
mastermenu();
case 7 :
mastermenu();
case 0 :
mastermenu() ;
}
}
};

//Usermode function ------------------------------------------------------------
//Scope<GLOBAL>
void usermode()
{
textcolor(YELLOW);
clrscr();
logo()   ;
cputs("Login as -");
cout<<"\nAdmin           ";
cputs("(1)");
cout<<"\nUser            ";
cputs("(2)");
cout<<"\nAbout Webedit   ";
cputs("(3)");
cout<<"\nExit            ";
cputs("(4)");
int o ;
o=inpop(1,4) ;
if(o==1)
{
clrscr();
logo();
cout<<"\n\nEnter the Password : ";
char password[] = "thiyagaraj";
char input[20];
char c ;
int i=0 ;
while(i<20) //Loop until 'Enter' is pressed
{
c = getch();
input[i]= c;
i++   ;
if(c==13)
break;
cout << "*";
}
int size ;
int flag=1 ;
int p=0 ;
size=strlen(input);
for(int j=0 ; j<(size-1) ;j++)
{
if(input[j]==password[j])
p++;
else
flag=0 ;
}
if(flag)
{
cout<<"\nYou entered the correct password" ;
delay(2) ;
cout<<"\nWelcome to Webedit " ;
cout<<"\nInitializing" ;
delay(1) ;
cout<<". " ;
delay(1) ;
cout<<". " ;
delay(1) ;
cout<<". " ;
delay(1) ;
admin me ;
me.mastermenu() ;
}
else
{
cout<<"\nSorry, You entered the wrong password" ;
delay(2) ;
cout<<"\nYou are being redirected to the main menu" ;
delay(2) ;
usermode() ;
}
}
else if(o==2)
{
int f = 1 ;
char n[20], p[20], ni[20], pi[20] ;
cputs("\nEnter the user name : ") ;
gets(ni);
cputs("\nEnter the password : ") ;
gets(pi);
user r ;
ifstream f1("users.dat",ios::binary) ;
f1.read((char*)&r, sizeof(r)) ;
while(!f1.eof())
{
strcpy(n,r.retname())  ;
strcpy(p,r.retpass()) ;
int size=strlen(pi);
for(int j=0 ; j<(size) ;j++)
{
if(p[j]==pi[j])
f=1;
else
{
f=0 ;
break;
}
}
if((strcmpi(n,ni)==0)&&(f==1))
{
f=1 ;
break;
}
f=0 ;
f1.read((char*)&r, sizeof(r)) ;
}
f1.close();
if(f==0)
{
cout<<"\nSorry, You entered the wrong password" ;
delay(2) ;
cout<<"\nYou are being redirected to the main menu" ;
delay(2) ;
usermode();
}
else
{
cout<<"\nYou entered the correct password" ;
delay(2) ;
cout<<"\nWelcome to Webedit " ;
cout<<"\nInitializing" ;
delay(1) ;
cout<<". " ;
delay(1) ;
cout<<". " ;
delay(1) ;
cout<<". " ;
delay(1) ;
admin me ;
r.menu() ;
}
}
else if(o==3)
{
clrscr();
logo();
cout<<"\n\t   ";
cputs("Webedit Version 3.1");
cout<<endl;
cout<<"\t   ";
cputs("Last Updated  : September 2013") ;
cout<<endl;
cout<<"\t   ";
cputs("Programmed by T.Thiyagaraj") ;
cout<<endl;
cout<<"\t   ";
cputs("tstream.h@outlook.com") ;

cout<<"\n\n\t   Press any key to go back ..."      ;
getch();
usermode() ;
}
else
usermode() ;
}
void main()
{
int p = 1 ;
ifstream f1 ;
f1.open("home.html") ;
if (f1.good())
{
//the file exists
}
else
p=0 ;
f1.close() ;
f1.open("about.html") ;
if (f1.good())
{
//the file exists
}
else
p=0 ;
f1.close() ;
f1.open("info.html") ;
if (f1.good())
{
//the file exists
}
else
p=0 ;
f1.close() ;
f1.open("blog.html") ;
if (f1.good())
{
//the file exists
}
else
p=0 ;
f1.close() ;
f1.open("contact.html") ;
if (f1.good())
{
//the file exists
}
else
p=0 ;
f1.close() ;

if(p==1)
{
cputs("Resource files were successfully identified...") ;
cout<<endl ;
cout<<endl ;
cout<<"Welcome to";
delay(1);
cout<<"." ;
delay(1);
cout<<"." ;
delay(1);
cout<<"." ;
cout<<"\n\nWebedit";
delay(2);
usermode();
}
else{
cout<<"\n !ERROR! \n\nResource files not fount ... " ;
delay(2);
cout<<"\nFailed to launch Webedit " ;
delay(1) ;
cout<<"\nSorry .... " ;
delay(2)  ;
exit(0);
}
}