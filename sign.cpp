#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include<conio.h>
#include<shlobj.h>
#include <windows.h>
#include <Commdlg.h>

#include"connetsql.h"
//#include"Newuser.h"
#include"Memorizenumbersquickly.cpp"


using namespace std;
void sign();
int connectsqlmainmeau();
void mainmeau();





/*int CheckPassword(char * password)
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


*/




void sign()
{

    char LoginUsername[20];//const 
    char LoginPassword[20];//const 
    cout<<"username: ";
    cin>>LoginUsername;
    cout<<endl;
    cout<<"password: ";
    cin>>LoginPassword;
    cout<<endl;
    int temp=sreachpart(LoginUsername, LoginPassword);
    if(temp==1)
    {
        cout<<"Login successful"<<endl;
        cout<<"Press any button to game"<<endl;
        getch();
        system("cls");
        // cout<<"game mainmeau";
        gamemainmuen(LoginUsername,LoginPassword);
    
    }
    else if(temp==2)
    {
	
        cout<<"user not find"<<endl;
        cout<<"You can press 1 to resign or press 2 back mainma"<<endl;
        int c;
        cin>>c;
        if(c==1)
        {

            system("cls");
            sign();
        }
        else
        {

            system("cls");
            mainmeau();
        }

    }
    else if(temp=-1)
    {
        cout<<"password worng"<<endl;
        cout<<"Press any button resign"<<endl;
        getch();
        system("cls");
        sign();
    }
    else 
    {
    	cout<<"user or password worng"<<endl;
        cout<<"Press any button resign"<<endl;
        getch();
        system("cls");
        sign();
	}


}






int connectsqlmainmeau()
{
    cout<<"Press any button connect"<<endl;
    getch();
    system("cls");
    int sts=connetsql();
    if(sts==1)
    {
        cout<<"CONNECT SECCESS! Press any button"<<endl;
        getch();
        system("cls");
        return 1;
    }
    else
    {
        cout<<"CONNECT FAIL!"<<endl;
        cout<<"wrong code : "<<sts<<endl;
        cout<<"if you want reconnect press 'y', if you want quit press 'n'"<<endl;
        char choose;
        cin>>choose;
        if(choose=='y')
        {
            cout<<"Press any button reconnect"<<endl;
            getch();
            system("cls");
            return -1;
        }
        else if(choose=='n')
        {
            exit(0);
        }
        else
        {
            printf("        Error!\n");
            printf("        Press any button quit\n");
            getch();
            system("cls");
            exit(0);
        }
        
    }
}






void mainmeau()
{
    
    printf("        ----------------------\n");
    printf("        |  sign   meau        |\n");
    printf("        ----------------------\n");
    printf("	|    1 creat new user |\n");
    printf("        ----------------------\n");
	printf("	|    2 sign           |\n");
    printf("        ----------------------\n");
    printf("	|    3 showrank!      |\n");
    printf("        ----------------------\n");
    printf("	|    0 quit           |\n");
    printf("        ----------------------\n");
    printf("        select:");
    int n;
    cin>>n;
    switch (n)
    {
    case 1://in this case cant create new user
        system("cls");
        int sttt;
        sttt=CreatNewUser();
        //cout<<"sttt"<<sttt<<endl;
        if(sttt==1)
        {
            cout<<"success create user Press any button back signmeau"<<endl;
            getch();
            system("cls");
            mainmeau();
        }
        else if(sttt==-1)//CreatNewUser()==-1
        {
            cout<<"username too long Press any button "<<endl;
            getch();
            system("cls");
            mainmeau();
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
            mainmeau();
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
    case 2:
        system("cls");
        sign();
        getch();
        system("cls");
        break;
    case 3:
        system("cls");
        ShowRank();
        getch();
        system("cls");
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("        Error!\n");
        printf("        Press any button\n");
        getch();
        system("cls");
        mainmeau();
        break;
    }
    mainmeau();
}






int main()
{
    
    int st;
    st=connectsqlmainmeau();
    if(st==1)
    {
        void x();
        mainmeau();
        
    }
    else if(st==-1)
    {  
        connectsqlmainmeau();
    }

    return 0;
}
