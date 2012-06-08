//#include"mouse.cpp"
#define GC getch();
#define NAME 1
#include<ctype.h>
#include<graphics.h>
#include<fstream.h>
#include<iostream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#define NL cout<<"\n";

// Use getmousepos(int*, int*, int*) to get mouse's position

void dir();
int mon_hack();
int pname();
int ppass();
int hack();
void load();
void ipcall();

int h,j,dis,cfn=1,caught=0;
int avg;
char com[20],s_pwd[9],s_na[10],c[10];
char ch=' ';

struct player
{
  char name[20];
  unsigned long int cash;int days;
  int iparr[10],ipc[10];
  player();
}p;

void initserver()
{
  randomize();
  ifstream fin;
  int f;
  do{
  f=random(51);
  }while(f<2);
  fin.open("nam_list.txt");
  for(int i=0;i<f;i++)
    fin.getline(s_na,10);
  fin.close();
  fin.clear();
  do{
  f=random(51);}while(f<2);
  fin.open("pwd_list.txt",ios::in);
  for(i=0;i<f;i++)
    fin.getline(s_pwd,9);
  fin.close();
}

player::player()
{
  strcpy(name,"");
  cash=days=0;
  for(int i=0;i<10;i++)
    iparr[i]=1;
  for(i=0;i<10;i++)
    ipc[i]=0;
}

void save_set()
{
  if(strcmpi(p.name,"exit"))
  if(p.cash!=0)
  {
  ofstream fout("Save.hack",ios::app||ios::binary);
  fout.seekp(0,ios::end);
  fout.clear();
  fout.write((char*)&p,sizeof(p));
  }
  NL
  cout<<"Settings Saved";
  GC
}
void myexit()
{
  system("del *.dbf");
  clrscr();
  textcolor(BLUE);
  cputs("Abhay Rana");NL cputs("XII-Sc");NL cputs("Templeton College");
  textcolor(WHITE);
  NL NL cputs("Thanks to all those who helped me complete the project in time. Your names do appear in the program"); NL cputs("S‚ Onr Sv‚rdar Sitja Hvass");
  GC
}

void ipcall()
{
  char msg[]="connect ";
  for(int i=0;i<strlen(msg);i++)
  {
    cout<<msg[i];
    delay(25);
  }
  randomize();
  //Initialize IP Addresses;
  unsigned int ip1=300,ip2=300,ip3=300,ip4=300;
  do{
   ip1=random(224);
  }while(ip1<200);
  randomize();
  do{
   ip2=random(254);
  }while(ip2<2);
  randomize();
  do{
  ip3=random(224);}while(ip3<12);
  randomize();
  do{
  ip4=random(224);}while(ip4<50);
  cout<<ip1<<"."<<ip2<<"."<<ip3<<"."<<ip4<<"\n";
}

unsigned long int _Cdecl randoml(unsigned long int __num)
{
  return(unsigned long int)(((unsigned long int)rand()*__num)/(RAND_MAX+1));
}

int sql()
{
  char f_l[4][15]={"employee","payroll","spending","expendit"};
  char fn[15];
  clrscr();
  char comm[30]="w";
  char name[20];int am;unsigned long int ac;
  cout<<"This Server supports miniSQL. Use q to exit";
  NL
  cputs("#");int r=1;
  cin.getline(comm,30);
do{
  strcpy(fn,f_l[cfn]);
  cin.getline(comm,30);
  if(strstr(comm,"insert")==comm)
  {

    if(strstr(comm,"into")!=NULL)
    {
      if(strstr(comm,fn)!=NULL)
      {
	NL
	cout<<"Enter Name: ";
	gets(name);
	cout<<"Enter Amount: ";
	cin>>am;
	do{
	cout<<"Enter Account No: ";
	cin>>ac;}while(ac<111111||ac>999999);
	ofstream fout(strcat(fn,".dbf"),ios::app);
	strcpy(fn,f_l[cfn]);
	fout<<name<<"\t\t$"<<am<<"\t\t"<<ac<<endl;
	p.cash+=am;
	NL
	if(abs(am-avg)<500)
	  r=1;
	else
	  r=0;
      }                         }
  }
  else if(strstr(comm,"select")==comm)
  {
    if(strstr(comm,"from")!=NULL)
    {
       if(strstr(comm,fn)!=NULL)
       {
	 NL
	 if(strstr(comm,"*")!=NULL)
	 {
	 ifstream f(strcat(fn,".dbf"));
	 char *p;
	 while(f)
	 {
	   f.getline(p,50);
	   cout<<p<<endl;
	 }
	 f.close();
	 strcpy(fn,"");
	 }
	 else if(strstr(comm,"avg")!=NULL)
	 {
	    NL
	    cout<<"Average="<<avg;
	 }
       }
    }
  }
  else if(!strcmpi(comm,"cls"))
    clrscr();
  else
     ;
  NL
  cputs("#");
  }while(strcmpi(comm,"q"));
  clrscr();
  return(r);
}

void load()
{
  static int num=0;
  ofstream db;ifstream nl;
  double sum=0;
  int randno,namarr[8];
  for(int loop=0;loop<8;loop++)
    namarr[loop]=55;
  char file_list[4][15]={"Employee","Payroll","spending","expendit"};
  randomize();
  randno=random(4);
  cfn=randno;
  char file_name[15];
  strcpy(file_name,file_list[randno]);
  nl.open("Name.txt",ios::trunc);
  char name[20];
  db.open(strcat(file_name,".dbf"),ios::trunc);
  db<<"Name\t\tAmount\t\tA/c Number\n";
  int max=8;
  if(num==0)
  {
  gotoxy(30,11);
  textcolor(RED);
  cputs("HACKER ");
  textcolor(YELLOW);
  cputs("2.9.04 -The Game");
  gotoxy(35,12);
  textcolor(3);
  cputs("Loading ");
  _setcursortype(_NOCURSOR);
  }
  for(int i=0;i<max;i++)
  {
     randomize();
     do{randno=random(1000)%100;
     }while(randno<1||randno>33);
     int amount;
     for(int jk=0;jk<=randno;jk++)
	nl.getline(name,20);
     if(nl.eof())
       nl.clear();
     nl.seekg(0);
     amount=random(5000);
     avg+=amount;
     unsigned long int acno;
     randomize();
     do{acno=randoml(999999);
     }while(acno<111111);
     int flag=0;
     for(loop=0;loop<8;loop++)
     if(jk==namarr[loop])
     {
       flag=1;
       break;
     }
     if(flag!=1)
     {
	db<<name<<"\t\t$"<<amount<<"\t\t"<<acno<<endl;
	namarr[i]=jk;
	sum+=amount;
	if(num==0)
	{
	  textcolor(WHITE);
	  cputs(".");
	}
     }
     else
     {
	i--;
	flag=0;
     }
  }
  initserver();
  db.close();
  nl.close();
  if(num==0)
  {
  clrscr();
  _setcursortype(_NORMALCURSOR);
  textcolor(2);
  }
  avg=sum/8;
  num=1;
}
void dir()
{
  static int no=0;
  char dir[5][200]={"Welcome to our server.Don't try to be oversmart and hack us. We are highly protected.\n","I had Send you an email when you were at home. You should have recieved it by now. But we are having problems. Or maybe Tommy is playing on your PC again.\n William.","This server has been having problems recently. So don't touch anything if you are not sure. Maybe your desktop is creeped up by worms and viruses\n ","Remain calm and quiet and you will be unharmed. Don't delete any files.\n","WELCOME\n"};
  if(no==0)
  {
    randomize();
    randomize();
    h=random(6);
    cout<<dir[h];
    no=1;
  }
  else
   no++;
}
int mon_hack()
{
 static int no=0;
 int sq;
 date d;
 if(no==1)
 {
 cout<<"\n>Please Wait Transferring Data.";
 load();
 }

 struct time t;int sqq=1;
 while(1)
 {
  if(no==0)
    NL
  cputs("$>");
  cin>>com;
  if(!strcmpi(com,"exit"))
  { no=1;
    return(sqq);
  }
  else if(!strcmpi(com,"quit"))
    return(sqq);
  else if(!strcmpi(com,"date"))
  {
    getdate(&d);
    cputs("Current Date Is ");
    cout<<int(d.da_day)<<"/"<<int(d.da_mon)<<"/"<<d.da_year;
  }
  else if(!strcmpi(com,"bye"))
    _exit(0);
  else if(!strcmpi(com,"time"))
  {
    gettime(&t);
    cputs("Time Is ");
    cout<<int(t.ti_hour)<<":"<<int(t.ti_min)<<":"<<int(t.ti_sec)<<"."<<int(t.ti_hund);
  }
  else if(!strcmpi(com,"now"))
  {
    getdate(&d);
    cputs("Current Date Is ");
    cout<<int(d.da_day)<<"/"<<int(d.da_mon)<<"/"<<d.da_year;
    gettime(&t);
    NL
    cputs("Time Is ");
    cout<<int(t.ti_hour)<<":"<<int(t.ti_min)<<":"<<int(t.ti_sec)<<"."<<int(t.ti_hund);
  }
  else if((!strcmpi(com,"dir"))||(!strcmpi(com,"ls")))
  {
    randomize();
    char f_l[4][15]={"employee","payroll","spending","expendit"};
    dir();
    cout<<"\n Directory Of $root\n";
    cout<<"1.Test.txt\n2.";
    cputs(f_l[cfn]);
    cout<<".dbf\n\n2 File(s)\n0 Dir(s)";
  }
  else if((!strcmpi(com,"cls"))||(!strcmpi(com,"clear")))
    clrscr();
  else if((!strcmpi(com,"sql")))
    sqq=sql();
  else
  {
    cputs("'");
    cout<<com;
    cputs("' is not recognized as an internal or external command, operable program or batch file.");
  }
 }
}
int pname()
{
  int cur[51],pos;
  for(int x=0;x<51;x++)
    cur[x]=0;
  char name[10];
  ifstream fin("nam_list.txt");
  int flag=0;
  for(j=0;j<dis;j++)
  {
    do{
      pos=random(1000)%100;
    }while(pos>51||cur[pos]==1||pos==0);
    if(cur[pos]==0)
    {
      for(int i=0;i<pos;i++)
	fin.getline(name,20);
      fin.seekg(0);
      cur[pos]=1;
    }
    else
    {
      j--;
      flag=1;
    }
    if(!strcmp(name,s_na))
    {
      cputs(">The user name was cracked. It is ");
      cout<<s_na;
      NL
      GC
      return(1);
    }
    else
     {
      if(flag==0)
      {
      cputs(">Invalid user name.");
      NL
      cputs(">You have ");
      cout<<50-j;
      cputs(" attempts left.");
      NL
      delay(100);
      }
     }
  flag=0;
  if(fin.eof())
  {
    fin.clear();
    fin.seekg(0);
  }
  }
  cputs("Wrong Name Entered. Your IP address has been stored and you have been banned from further visits to this server");
  GC
  fin.close();
  return(0);
}
int ppass()
{
  int cur[51],pos;
  for(int x=0;x<51;x++)
    cur[x]=0;
  char pwd[10];
  ifstream fin("pwd_list.txt");
  int flag=0;
  for(j=0;j<dis;j++)
  {
    do{
      pos=random(1000)%100;
    }while(pos>51||cur[pos]==1||pos==0);
    if(cur[pos]==0)
    {
      for(int i=0;i<pos;i++)
	fin.getline(pwd,20);
      fin.seekg(0);
      cur[pos]=1;
    }
    else
    {
      j--;
      flag=1;
    }
    if(!strcmp(pwd,s_pwd))
    {
      cputs(">The Password was cracked. It is ");
      cout<<pwd;
      NL
      GC
      dis=0;
      return(1);
    }
    else
     {
      if(flag==0)
      {
      cputs(">Invalid user name.");
      NL
      cputs(">You have ");
      cout<<50-j;
      cputs(" attempts left.");
      NL
      delay(100);
      }
     }
  flag=0;
  if(fin.eof())
  {
    fin.clear();
    fin.seekg(0);
  }
  }
  cputs("Wrong Name Entered. Your IP address has been stored and you have been banned from further visits to this server");
  GC
  fin.close();
  return(0);
}

int hack(int s)
{
  int i,check,f,att=0,m_att=3;
  char ser[9][30]={"Microsoft corp","Amazon.com","eBay","Adobe Inc","IBM","Sony","Compaq","NSA","NASA"};
  static int no=0;
  initserver();
  char name_ent[10],pwd_ent[9],wel_1[400]="This Is a high protection server , which recognizes you by a unique user name  and password. You will Only be given 3 chances for each. If they are still wrong your IP address will be stored and you will banned from entering this server again.Please enter your name ";
  char wel_2[200]="You are welcome. But beware hackers and thieves, our server is highly protected.Please enter u'r Name ";
  ipcall();
  delay(500);
  cputs(".");
  delay(400);
  cputs(".");
  delay(300);
  cout<<"\n\n";
  cputs(ser[s-1]);
  cputs(" Welcomes You.");
  cout<<"\n\n";
  cputs(">");
  randomize();
  dis=0;
  while(dis<12)
  {
    dis=random(50);
  }
  //Decide which msg
  if((s-1)%2==0)
    cputs(wel_1);
  else
   cputs(wel_2);
//-=======================USER--------NAME========================-:|
  NL
  cputs(">");
/////////////////////Name Entry-------------------------
  int n_ent=0;
  int cor_nam=0;
  do
  {
    NL
    cputs(">");cputs("Enter Name");
    NL
    cputs(">");
    gets(name_ent);
    cout<<name_ent;
    att++;
    if(!strcmpi(name_ent,"exit"))
      return(2);
    if(!strcmpi(s_na,name_ent))
       cor_nam=1;
    if(!strcmpi(name_ent,"pname"))
    {
      if(pname()==0)
       return(0);
      cor_nam=1;
    }
///////////////////////////---------/NAME Check/---------////////////////////////
    if(!cor_nam)
    {
      NL
      cputs(">");cputs("Wrong Name Entered. Please Try Again. You have ");
      cout<<3-att;
      cputs("attempt(s) left");
      NL
      if(att==m_att)
      {
	cputs("Your IP address has been stored and you have been banned from further visits to this server");
	n_ent=1;
	return(0);
      }
    }
    else
    {
      NL
      cputs("Correct Name. Enter Password");
      n_ent=1;
    }
  }while(n_ent==0);
//---------------------------PASSSSSSSSSWORD------------------------

  att=0;
  m_att=3;
  int pwd_entt=0;
do
{
  NL
  cputs(">");
////////////////////Password entry////////////////////////
  gets(pwd_ent);
  if(!strcmpi(pwd_ent,"exit"))
    return(2);
  int cor_pwd=0;
  if(!strcmpi(pwd_ent,"ppass"))
  {
    cout<<"in ppass";
    if(ppass()==0)
      return(0);
    cor_pwd=1;
  }
  if(!strcmpi(s_pwd,pwd_ent))
    cor_pwd=1;
  att++;
///////////////////////PASSSSSSWORD CHECK///////////////////////
 if(!cor_pwd)
 {
  NL
  cputs(">");
  cputs("Wrong Password Entered. Please Try Again. You have ");
  cout<<m_att-att;
  cputs(" attempt(s) left");
  NL
  if(att==m_att)
  {
    cputs("Your IP address has been stored and you have been banned from further visits to this server");
    return(0);
  }
 }
 else
  {
    NL
    cputs("Correct Password. Welcome Back Employees ");
    pwd_entt=1;
  }
}while(!pwd_entt);
no=1;
return(mon_hack());
}

void main()
{
  clrscr();
  ifstream sf("Save.hack");
  textcolor(3);
  int test=0;
  clrscr();
  char ser[9][30]={"Microsoft corp","Amazon.com","eBay","Adobe Inc","IBM","Sony","Compaq","NSA","NASA"};
  atexit(myexit);
/*  if(initmouse()==0)
  {
     printf("\nMouse Driver Not Loaded");
     exit(1);
  }
  showmouseptr();*/
  int sfl=1;player r;int savr=0;
  clrscr();
  if(sf){
   cout<<"Loading Game File:(0 for New Game)\n";
   cout<<"Name\t\tCash\t\tDays\n";

  do
  {
    sf.read((char*)&r,sizeof(player));
    cout<<sfl<<"."<<r.name<<"\t\t"<<r.cash<<"\t\t"<<r.days<<endl;
    sfl++;
  }while(sf&&sfl<10);
  sf.seekg(0);
  int choice=getch()-48;
  if(choice<10&&choice>0)
  {
    for(sfl=0;sfl<choice;sfl++)
      sf.read((char*)&r,sizeof(r));
    p=r;
    savr=1;
  }}
  clrscr();
  load();
  textcolor(2);
  if(savr==0)
  {
  cout<<"Enter Your Name :";
  cin.getline(p.name,18);
  if(!strcmpi(p.name,"exit"))
    exit(0);
  }
  char comm[20];
  do{
  clrscr();
  cout<<"List Of Sites :\n\n";
  for(int k=1;k<10;k++)
  {
    cout<<k;
    cputs(".");
    cputs(ser[k-1]);
    NL
  }
  NL
  textcolor(3);
  NL
  gotoxy(55,1);
  cputs("ÕName: ");
  cputs(p.name);
  gotoxy(55,2);
  cprintf("³Cash: ");
  cprintf("%d",p.cash);
  gotoxy(55,3);
  cputs("ÔDays Spent: ");
  cprintf("%d",p.days);
  gotoxy(1,14);
  textcolor(2);
  cputs(">");
  gets(comm);
  int flag=0;
  for(int co=0;co<=strlen(comm);co++)
  {
    if(isdigit(comm[co]))
    {
      ch=comm[co];
      flag=1;
      break;
    }
  }
  int sno=11;
 if(flag==1)
  sno=int(ch)-48;
 char m[]="connect";
 for(int low=0;low<strlen(comm);low++)
   comm[low]=tolower(comm[low]);
 if(!strcmpi(comm,"save"))
    save_set();
 if(strstr(comm,m)==comm&&sno<10)
 {
  if(p.iparr[sno]!=0)
  {
    if(ch>48&&ch<=57)
    {
      p.iparr[sno]=hack(sno);
      if(p.iparr[sno]==0)
	p.ipc[sno]=3;
      ch=60;
      //Increase days passed
      if(p.iparr[sno]!=2)
      {
      p.days++;
      for(int ml=0;ml<10;ml++)
	if(p.ipc[ml]>0)
	  if(--p.ipc[ml]==0)
	    p.iparr[ml]=1;
      }
    }
  }
  else
  {
    ipcall();
    cout<<"Your IP address is in our banned list. Please contact the administrator\n";
    int ph1,ph2;
    do{
      randomize();
      ph1=random(999);
    }while(ph1<200);
    randomize();
    do{
      randomize();
     ph2=random(999);
    }while(ph2<100);
    cout<<"Phone: "<<ph1<<ph2<<endl;
    GC
  }
 }
 else if(strstr(comm,m)==comm)
  {
    cout<<"The syntax of command is incorrect\n";
    GC
  }

 if(!strcmpi(comm,"exit"))
   test=1;
 if(p.days>31)
   test=1;
 }while(!test);
 if(p.days==31)
 {  cout<<"Time Up";GC}

}
