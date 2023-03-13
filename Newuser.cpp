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


//#include"sign.h"
//#include"Newuser.h"
//#include"connetsql.cpp"


#ifdef _WIN64 
typedef INT64 SQLLEN; 
typedef UINT64 SQLULEN; 
#else 
#define SQLLEN SQLINTEGER 
#define SQLULEN SQLUINTEGER 
#endif

using namespace std;


int CheckPassword(char * password);
int CreatNewUser();




int CheckPassword(char * password)
{
    int k=0;
    int slen=strlen(password);
    //cout<<slen<<endl;
    if(slen>=18||slen<=8)
    {
        return 2;//too long or too short
    }
    else
    {
        for(int i=0;password[i]!='\0';i++)
        {
            if(password[i]>='0'&&password[i]<='9')//||(s[i]<='a'&&s[i]>='z')||(s[i]<='A'&&s[i]>='Z'))
            {
                k++;
            }
            else if(password[i]>='a'&&password[i]<='z')
            {
                k++;
            }
            else if(password[i]>='A'&&password[i]<='Z')
            {
                k++;
            }
        }
        
        if(slen!=k)
        {
           // cout<<k<<" "<<slen<<endl;
            
            return 3;
        }
        else
        {
            cout<<1<<endl;
            return 1;
        }
       //legal
    }
}






int CreatNewUser()//-1 username too long // 1 success create user // 2 password too long // 3 password not legal // 4 undefine error
{
    cout<<"create new user"<<endl;
    char NewuserName[200];
    char NewuserPassword[200];
    int namelen;
    cout<<"please input new user name"<<endl;
    cin>>NewuserName;
    namelen=strlen(NewuserName);
    //cout<<namelen<<endl;
    if(namelen>18)//too long
    {
        return -1;
    }
    else
    {
        cout<<"please input new user password"<<endl;
        cin>>NewuserPassword;
        int stt=CheckPassword(NewuserPassword);
        //cout<<"stt "<<stt<<endl;
        if(stt==1)//CheckPassword(NewuserPassword)==1
        {
            int temp=SqlNewUser(NewuserName, NewuserPassword);
            //cout<<"temp "<<temp<<endl;
            if(temp==1)
            {
                int temp2=Insertsql(NewuserName,NewuserPassword,1);//user and password!
                //cout<<"temp2 "<<temp<<endl;
                if(temp2==1)
                {
                    return 1;
                }
                else
                {
                    return 4;
                }
                
            }
            else if(temp==5)
            {
                return 5;
            }
            else
            {
                return 4;
            }
        }
        else if(stt==2)//CheckPassword(NewuserPassword)==2
        {
            return 2;
        }
        else if(stt==3)//CheckPassword(NewuserPassword)==3
        {
            
            return 3;
        }
        else
        {
            return 4;
        }
    }
    

}


