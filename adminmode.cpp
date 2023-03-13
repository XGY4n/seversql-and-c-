#include<stdio.h>  
#include<windows.h>  
#include<sql.h>  
#include<sqlext.h>  
#include<sqltypes.h>  
#include<string.h>
#include<conio.h>
#include<shlobj.h>
#include <windows.h>
#include <Commdlg.h>
#include<bits/stdc++.h>


//#include"filepart.h"
#include"Newuser.h"
//#include"connetsql.cpp"



#ifdef _WIN64 
typedef INT64 SQLLEN; 
typedef UINT64 SQLULEN; 
#else 
#define SQLLEN SQLINTEGER 
#define SQLULEN SQLUINTEGER 
#endif

using namespace std;



void adminmode(char* LoginUsername, char* LoginPassword);
int x();




void adminmode(char* LoginUsername, char* LoginPassword)//
{
    int n;
    printf("        -----------------------\n");
    printf("        |welcome admin %s       \n", LoginUsername);
    printf("        -----------------------\n");
    printf("        |choose your mode      |\n");
    printf("        -----------------------\n");
    printf("	|    1 delete other user|\n");
    printf("        -----------------------\n");
	printf("	|    2 creat new user   |\n");
    printf("        -----------------------\n");
    printf("	|    3 Backup database  |\n");
    printf("        -----------------------\n");
	printf("	|    4 check user data  |\n");
    printf("        -----------------------\n");
    printf("	|    5 check user data  |\n");
    printf("        -----------------------\n");
    printf("	|    6 sign out        |\n");  
    printf("        -----------------------\n"); 
    printf("	|    7 delete user     |\n");  
    printf("        -----------------------\n"); 
    printf("	|    0 quit            |\n");
    printf("        -----------------------\n");
    printf("        select:");
    cin>>n;
    switch (n)
    {
        case 1:
        if(n==1)
        {
            cout<<"You are admin you can delete other user except admin user"<<endl;
            cout<<"choose user"<<endl;
            char tempstrr[11234];
            cin>>tempstrr;
            string strrr2;
            string strrrr2;
            strrrr2+=LoginUsername;
            strrr2+=tempstrr;
            if(strrr2.compare(strrrr2)==0)
            {
                cout<<"can not delete admian Press any button"<<endl;
                getch();
                system("cls");
                adminmode(LoginUsername,LoginPassword);
            }
            else
            {
                int temp2=deletesql(tempstrr,LoginPassword);
                //cout<<temp2<<endl;
                if(temp2==1)
                {
                    cout<<"delete user sucess! Press any button to mainmeau"<<endl;
                    getch();
                    system("cls");
                    adminmode(LoginUsername,LoginPassword);
                }
                else
                {
                    cout<<"something wrong ! wrong code:"<<temp2<<"  Press any buttonendl"<<endl;
                    getch();
                    system("cls");
                    adminmode(LoginUsername,LoginPassword);
                }
            }
        }
    case 2:
        system("cls");
        int sttt;
        sttt=CreatNewUser();
        //cout<<"sttt"<<sttt<<endl;
        if(sttt==1)
        {
            cout<<"success create user Press any button back signmeau"<<endl;
            getch();
            system("cls");
            adminmode(LoginUsername,LoginPassword);
        }
        else if(sttt==-1)//CreatNewUser()==-1
        {
            cout<<"username too long Press any button "<<endl;
            getch();
            system("cls");
            CreatNewUser();
        }
        else if(sttt==2)//CreatNewUser()==2
        {
            cout<<"password too long or too short Press any button "<<endl;
            getch();
            system("cls");
            CreatNewUser();
        }
        else if(sttt==3)//CreatNewUser()==3
        {
            cout<<"password not legal Press any button "<<endl;
            getch();
            system("cls");
            CreatNewUser();
        }
        else if(sttt==4)//CreatNewUser()==4
        {
            cout<<"undefine error Press any button"<<endl;
            getch();
            system("cls");
            adminmode(LoginUsername,LoginPassword);
        }
        else if(sttt==5)
        {
            cout<<"The user already exists  Press any button"<<endl;
            getch();
            system("cls");
            CreatNewUser();
        }
        getch();
        system("cls");
        break;
    case 3:
        if(n==3)
        {
            system("cls");
            cout<<"please input backup file name"<<endl;
            int temp=BackUp();
            if(temp==1)
            {
                cout<<"back database success press any button"<<endl;
                getch();
                system("cls");
                adminmode(LoginUsername,LoginPassword);
            }
            else if(temp==-1)
            {
                cout<<"back database fail press any button"<<endl;
                getch();
                system("cls");
                adminmode(LoginUsername,LoginPassword);
            }            
        } 
    case 4:
        if(n==4)
        {
            system("cls");
            int temp;
            char name[100];
            cout<<"please input name"<<endl;
            cin>>name;
            temp=CheckSingleUser(name);
            if(temp!=1)
            {
                cout<<"user not find"<<endl;
            }
            cout<<"Press any button"<<endl;
            getch();
            system("cls");
            adminmode(LoginUsername,LoginPassword);
        }           
    case 0:
        exit(0);
        break;
    default:
        printf("        Error!\n");printf("        Press any button\n");getch();system("cls");
        break;
    }
}
int x()
{
    cout<<1<<endl;
    return 1;
}
