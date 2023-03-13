#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include<conio.h>
#include<shlobj.h>
#include <windows.h>
#include <Commdlg.h>
#include<bits/stdc++.h>

#include"adim.h"

using namespace std;
FILE *outfile;




void gamemainmuen(char* LoginUsername, char* LoginPassword);
void start();
void savedate(double l,int k);
int updata(char * LoginUsername,float sorce, char modin);
void sjs();
float easy();
float hard();
float sh();
void mainmeau();
int PasswordComper(char* temppassword, char* LoginPassword);








int PasswordComper(char* temppassword, char* LoginPassword)
{
    string stemp;
    string spassword;
    stemp += temppassword;
    spassword += LoginPassword;
    int k=stemp.compare(spassword);
    return k;
}





void start()
{
    printf("ready?\n");
    Sleep(1500);
    system("cls");
    for(int i=3;i!=0;i--)
    {
        printf("%d\n",i);
        Sleep(1000);
        system("cls");
    }
    printf("start!\n");
    Sleep(800);
    system("cls");
    return ;
}
//倒计时






void savedate(double l,int k)
{
    switch (k)
    {
    case 1:
        outfile=fopen("C:\\Users\\Public\\Documents\\mnqgame\\easy.txt","a");
        fprintf(outfile,"%lf\n",l); 
        fclose(outfile);
        break;
    case 2:
        outfile=fopen("C:\\Users\\Public\\Documents\\mnqgame\\hard.txt","a");
        fprintf(outfile,"%lf\n",l); 
        fclose(outfile);
    case 3:
        outfile=fopen("C:\\Users\\Public\\Documents\\mnqgame\\superhard.txt","a");
        fprintf(outfile,"%lf\n",l); 
        fclose(outfile);
    case 4:
        outfile=fopen("C:\\Users\\Public\\Documents\\mnqgame\\diy.txt","a");
        fprintf(outfile,"%lf\n",l);
        fclose(outfile);     
    default:
        break;
    }
}
//save date







int updata(char * LoginUsername,float sorce,char modin)
{
    int n;
    cout<<"if you want updata sorce press 1 or press 2"<<endl;
    cin>>n;
    if(n==2)
    {
        cout<<"press any botton back mainmeau"<<endl;
        return 0;
    }
    else if(n==1)
    {
        int temp=Updata(LoginUsername, sorce, modin);
        if(temp==1)
        {
            cout<<"updata succese press any botton back mainmeau"<<endl;
            return 1;
        }
        else
        {
            cout<<"error wrong code "<<temp<<endl;
            return -1;
        }
    }
    else
    {
        cout<<"#😅"<<endl;
        cout<<"erro press any botton back updatameau"<<endl;
        updata(LoginUsername,sorce, modin);
    }
            
}
//save date






void sjs()
{
    int i,j,t,a1,b,c,k;
    printf("Enter the number of digits:");
    scanf("%d",&a1);
    printf("Enter the problem number:");
    scanf("%d",&b);
    printf("Enter the time between each problem(every 1000=1 second):");
    scanf("%d",&c);
    char s[100];
    char u[100];
    char l[1000]={0};
    long long int a[a1];
    t=0;
    k=4;
    double h;
    Sleep(1000);
    system("cls");
    start();
    srand((unsigned int)time(NULL)); 
    for(int k=1;k<=b;k++)
    {
    
            for(i=0;i<=a1;i++)
            {           
                a[i]=rand()%10+1;
                itoa(a[i],s,10);
                strcat(l,s); 
            } 

        printf("%s",l); 
        printf("\n");
        Sleep(c);
        system("cls");
        printf("Your answer:\n");
        scanf("%s",u);
        if(strcmp(u,l)==0)
        {
            printf("Yes!\n");
            t++;
        }
        else
        {
            printf("No~\n");
        }
        memset(l,'\0',sizeof(l));
        Sleep(500);
        system("cls");
    }
    printf("your accpet answer have %d\n",t);
    printf("your Accuracy Rate is %lf%%\n",t*1.0/b*1.0*100);
    h=t*1.0/3.0*100;
    savedate(h,k);
    printf("Press any button\n");
    return ;
}
//自定义









float easy()
{
    int a,b,t,k;
    double l;
    t=0;
    k=1;
    start();
    srand((unsigned int)time(NULL));    
    for(int j=1;j<=3;j++)
    {
        a=rand()%100001+ 10000;//5
        printf("%d\n",a);
        Sleep(1000);
        system("cls");
        printf("Your answer:\n");
        scanf("%d",&b);
        if(a==b)
        {
            printf("Yes!\n");
            t++;
        }
        else
        {
            printf("NO~\n");
        }
        Sleep(500);
        system("cls");
    }
    printf("your accpet answer have %d\n",t);
    printf("your Accuracy Rate is %lf%%\n",t*1.0/3.0*100);
    l=t*1.0/3.0*100;
    savedate(l,k);
    printf("Press any button\n");
    return t*1.0/3.0*100;
}
//easy mode









float hard()
{
    char s[100];
    char u[100];
    char l[1000]={0};
    int a[15];
    int i,j,t,k;
    k=2;
    t=0;
    double h;
    start();
    srand((unsigned int)time(NULL)); 
    for(int k=1;k<=5;k++)
    {
    
            for(i=0;i<=8;i++)
            {           
                a[i]=rand()%10+1;
                itoa(a[i],s,10);
                strcat(l,s); 
            } 

        printf("%s",l); 
        printf("\n");
        Sleep(1000);
        system("cls");
        printf("Your answer:\n");
        scanf("%s",u);
        if(strcmp(u,l)==0)
        {
            printf("Yes!\n");
            t++;
        }
        else
        {
            printf("No~\n");
        }
        memset(l,'\0',sizeof(l));
        Sleep(500);
        system("cls");
    }
    printf("your accpet answer have %d\n",t);
    printf("your Accuracy Rate is %lf%%\n",t*1.0/5.0*100);
    h=t*1.0/3.0*100;
    savedate(h,k);
    printf("Press any button\n");
    return t*1.0/5.0*100;
}
//hard mode







float sh()
{
    char s[100];
    char u[100];
    char l[1000]={0};
    int a[15];
    int i,j,t,k;
    k=3;
    t=0;
    double h;
    start();
    srand((unsigned int)time(NULL)); 
    for(int k=1;k<=8;k++)
    {
    
            for(i=0;i<=12;i++)
            {           
                a[i]=rand()%10+1;
                itoa(a[i],s,10);
                strcat(l,s); 
            } 

        printf("%s",l); 
        printf("\n");
        Sleep(1000);
        system("cls");
        printf("Your answer:\n");
        scanf("%s",u);
        if(strcmp(u,l)==0)
        {
            printf("Yes!\n");
            t++;
        }
        else
        {
            printf("No~\n");
        }
        memset(l,'\0',sizeof(l));
        Sleep(500);
        system("cls");
    }
    printf("your accpet answer have %d\n",t);
    printf("your Accuracy Rate is %lf%%\n",t*1.0/8.0*100);
    h=t*1.0/3.0*100;
    savedate(h,k);
    printf("Press any button\n");
    return t*1.0/8.0*100;
}
//super hard mode









void gamemainmuen(char* LoginUsername, char* LoginPassword)//int usertype
{
    int n;
    int m;
    string type;
    m=CheckUsertype(LoginUsername);
    
    if(m==0)
    {
        type="Admin";
        cout<<"u are admin if u want use adminmode press '1' else press any botton"<<endl;
        char temp;
        cin>>temp;
        if(temp=='1')
        {
            
            system("cls");
           	adminmode(LoginUsername, LoginPassword);//
        }
       // system("cls");
    }
    else
    {
        type="Ordinary users";
    }
    printf("        -----------------------\n");
    cout<<"         welcome user: "<<LoginUsername<<"("<<type<<")        "<<endl;
    printf("        -----------------------\n");
    printf("        |choose your mode      |\n");
    printf("        -----------------------\n");
    printf("	|    1 easy            |\n");
    printf("        -----------------------\n");
	printf("	|    2 hard            |\n");
    printf("        -----------------------\n");
    printf("	|    3 super hard      |\n");
    printf("        -----------------------\n");
	printf("	|    4 customize       |\n");
    printf("        -----------------------\n");
    printf("	|    5 showrank!       |\n");
    printf("        -----------------------\n");
    printf("	|    6 sign out        |\n");  
    printf("        -----------------------\n"); 
    printf("	|    7 delete user     |\n");  
    printf("        -----------------------\n"); 
    printf("	|    0 quit            |\n");
    printf("        -----------------------\n");
    printf("        select:");
    scanf("%d",&n); 
    float sorce;
    char temppassword[1145];
    int temp;
    switch (n)
    {
    case 1:
        system("cls");
        sorce;
        sorce=easy();
        updata(LoginUsername,sorce,'1');
        getch();
        system("cls");
        break;
    case 2:
        system("cls");
        sorce;
        sorce=hard();
        updata(LoginUsername,sorce,'2');    
        getch();
        system("cls");
        break;
    case 3:
        system("cls");
        sorce;
        sorce=sh();
        updata(LoginUsername,sorce,'3'); 
        getch();
        system("cls");
        break;
    case 4:
        system("cls");
        sjs();
        getch();
        system("cls");
        break;
    case 5:
        system("cls");
        ShowRank();
        getch();
        system("cls");
        gamemainmuen(LoginUsername,LoginPassword);
        system("cls");
    case 6:
        system("cls");
        mainmeau();
        system("cls");
    case 7:
    //delete
        system("cls");
        cout<<"need check your password angin"<<endl;
        cin>>temppassword;
        temp=PasswordComper(temppassword,LoginPassword);
        //cout<<temp<<endl;
        if(temp==0)
        {
            int tempUsertype=CheckUsertype(LoginUsername);
            if(tempUsertype==0)
            {
                //system("cls");
                cout<<"You are admin you can delete other user except admin user"<<endl;
                cout<<"choose user"<<endl;
                char strr[11234];
                cin>>strr;
                string strrr;
                string strrrr;
                strrrr+=LoginUsername;
                strrr+=strr;
                if(strrr.compare(strrrr)==0)
                {
                    cout<<"can not delete admian Press any button"<<endl;
                    getch();
                    system("cls");
                    gamemainmuen(LoginUsername,LoginPassword);
                }
                else
                {
                                    
                    int temp2=deletesql(strr,LoginPassword);
                    //cout<<temp2<<endl;
                    if(temp2==1)
                    {
                        cout<<"delete user sucess! Press any button to mainmeau"<<endl;
                        getch();
                        system("cls");
                        gamemainmuen(LoginUsername,LoginPassword);
                    }
                    else
                    {
                        cout<<"something wrong ! wrong code:"<<temp2<<"  Press any buttonendl"<<endl;
                        getch();
                        system("cls");
                        gamemainmuen(LoginUsername,LoginPassword);
                    }
                }
            }
            else
            {
                cout<<"u are not admin you only can delete yourself"<<endl;
                cout<<"are you sure? press any 'y' countnie else press any botton"<<endl;
                char userf;
                cin>>userf;
                if(userf=='y')
                {
                    int temp2=deletesql(LoginUsername,LoginPassword);
                    cout<<temp2<<endl;
                    if(temp2==1)
                    {
                        cout<<"delete user sucess! Press any button to singmainmeau"<<endl;
                        getch();
                    }
                    else
                    {
                        cout<<"something wrong ! wrong code:"<<temp2<<"  Press any buttonendl"<<endl;
                        getch();
                        system("cls");
                        gamemainmuen(LoginUsername,LoginPassword);
                    }
                }
                else
                {
                    gamemainmuen(LoginUsername,LoginPassword);
                }
            }
        }
        else
        {
            cout<<"password wrong !"<<endl;
            getch();
        }
        system("cls");
        mainmeau();
        system("cls");
    case 0:
        exit(0);
        break;
    default:
        printf("        Error!\n");printf("        Press any button\n");getch();system("cls");
        break;
    }
    gamemainmuen(LoginUsername,LoginPassword);
}
/*int main()
{
    system("mkdir C:\\Users\\Public\\Documents\\mnqgame");
    //Sign();
    gamemainmuen();
    return 0;
}*/
