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

#include"filepart.h"



#ifdef _WIN64 
typedef INT64 SQLLEN; 
typedef UINT64 SQLULEN; 
#else 
#define SQLLEN SQLINTEGER 
#define SQLULEN SQLUINTEGER 
#endif

using namespace std;
//

int connetsql()
{

    SQLRETURN ret;  
	SQLHENV henv;//SQLHANDLE henv  
	SQLHDBC hdbc;//SQLHANDLE hdbc  
	SQLHSTMT hstmt;//SQLHANDLE hstmt  
    SQLCHAR connout[256];
    SQLSMALLINT connout_len;


	ret=SQLAllocHandle(SQL_HANDLE_ENV,NULL, &henv); 
	ret=SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	ret=SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);


	ret=SQLConnect(hdbc, (SQLCHAR*)"userlib", SQL_NTS,(SQLCHAR*)"sa", SQL_NTS,(SQLCHAR*)"123", SQL_NTS);
    if(ret==SQL_SUCCESS||ret==SQL_SUCCESS_WITH_INFO)
    {
        SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	    SQLFreeHandle(SQL_HANDLE_ENV, henv);
        return 1;
    }
    else
    {
        /*cout<<"CONNECT FAIL!"<<endl;
        cout<<"wrong code : "<<ret<<endl;
        cout<<"Press any button"<<endl;*/
        SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
        SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	    SQLFreeHandle(SQL_HANDLE_ENV, henv);
        //getch();
        return ret;
    }
}




int CheckPassword(char * TempPassword,char * LoginPassword )//check password
{
    string cPassWord;
	string UserPassword;
	string s2=" ";
	int Checkpoint;
	int State;
    cPassWord=cPassWord+TempPassword;
	UserPassword=UserPassword+LoginPassword;
    Checkpoint=cPassWord.find_first_of(s2);
	State=cPassWord.compare(0,Checkpoint,UserPassword);
    //cout<<State<<endl;
	return State;
}




int sreachpart(char * LoginUsername, char  *LoginPassword)//const const [20][20]
{
    SQLRETURN ret;//
	SQLHENV henv;//SQLHANDLE henv  
	SQLHDBC hdbc;//SQLHANDLE hdbc  
	SQLHSTMT hstmt;//SQLHANDLE hstmt  
	SQLRETURN ret2;


	SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
	SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);


	ret = SQLConnect(hdbc, (SQLCHAR*)"userlib", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"123", SQL_NTS);
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
	{
		SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
		SQLCHAR ConnectDatabaseSql[] = "use userlib;";
		ret2=SQLExecDirect(hstmt, (SQLCHAR*)ConnectDatabaseSql, SQL_NTS);
		SQLCHAR SearchResult[1024];
        int Namelen=strlen(LoginUsername);
        int PasswordState;//=strlen(LoginPassword)
		char SQLSearchName[1024];
        char SQLSearchPassword[1145];
		//SQLExecDirect(hstmt, (SQLCHAR*)SQLSearchPassword, strlen(SQLSearchPassword)+1);//check password
		//ret2=SQLExecute(SQLSearchPassword);
		//cout<<ret2<<endl;


		snprintf(SQLSearchName,114514, "select * from userlib where uname = '%s';", LoginUsername);
        snprintf(SQLSearchPassword,114514, "select * from userlib where upassword = '%s';", LoginPassword);
		strcpy((char*)SearchResult, SQLSearchName);
		SQLPrepare(hstmt, (SQLCHAR*)SearchResult, SQL_NTS);
		ret = SQLExecute(hstmt);



		if (ret == SQL_SUCCESS_WITH_INFO || ret == SQL_SUCCESS)
		{
			SQLCHAR USERNAME[20], PASSWORD[20], TempPassword[20];
			SQLLEN USERNAME_Len, PASSWORD_Len,TempPassword_Len;
			while (SQLFetch(hstmt) != SQL_NO_DATA)
			{

				SQLRETURN TempRet;//tempret
				SQLGetData(hstmt, 1, SQL_C_CHAR, USERNAME, Namelen+1, &USERNAME_Len);
				SQLGetData(hstmt, 2, SQL_C_CHAR, PASSWORD, 13, &PASSWORD_Len);//8-12 password Passwordlen+1
				PasswordState=CheckPassword( (char*)PASSWORD, (char*)LoginPassword);//password check
                //cout<<USERNAME<<" "<<PASSWORD<<'|'<<endl;	
				if(PasswordState!=0)
				{

					return -1;
							//password wrong
				}
				if (PasswordState==0)//strcmp(LoginUsername, (char*)USERNAME) == 0 && strcmp(LoginPassword, (char*)PASSWORD) == 0
				{
					SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
					SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
					SQLFreeHandle(SQL_HANDLE_ENV, henv);

					return 1;
							//success 
				}

				SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
				SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
				SQLFreeHandle(SQL_HANDLE_ENV, henv);
				return 0;
			}
		}
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
		SQLFreeHandle(SQL_HANDLE_ENV, henv);
		return 2;
				//not find user

	}
	SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	SQLFreeHandle(SQL_HANDLE_ENV, henv);
}

















void ShowRank()
{
	SQLRETURN ret;  
	SQLHENV henv;//SQLHANDLE henv  
	SQLHDBC hdbc;//SQLHANDLE hdbc  
	SQLHSTMT hstmt;//SQLHANDLE hstmt  
   	SQLCHAR connout[256];
   	SQLSMALLINT connout_len;
    
	char SQLInsert[1145];
	ret=SQLAllocHandle(SQL_HANDLE_ENV,NULL,&henv); 
	ret=SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	ret=SQLAllocHandle(SQL_HANDLE_DBC,henv,&hdbc);

	
	ret=SQLConnect(hdbc,(SQLCHAR*)"userlib", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"123", SQL_NTS);
   	if(ret==SQL_SUCCESS||ret==SQL_SUCCESS_WITH_INFO)
   	{
      	cout<<"CONNECT SECCESS!"<<endl;
      	ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

      	SQLCHAR udb[]="use userlib;";
    	char sql2[]="select * from userlib order by usorce desc;";
		
      	SQLExecDirect(hstmt, (SQLCHAR*)udb, SQL_NTS);
      	ret=SQLExecDirect(hstmt, (SQLCHAR*)sql2, SQL_NTS);//
      	if(ret==SQL_SUCCESS||ret==SQL_SUCCESS_WITH_INFO)
      	{
        	//cout<<1<<endl;
        	//ret = SQLPrepare(hstmt, (SQLCHAR *)"select * from userlib", SQL_NTS);
    		//ret = SQLExecute(hstmt);
        	SQLLEN len_str1, len_str2, len_str3,len_str4,len_str5,len_str6;
        	SQLCHAR str1[20],str2[20],str3[20],str4[20],str5[20],str6[20];
       		printf("ranking\tuserid\tname\tmod1sorce\tmod2sorce\tmod3sorce\n");
			int i=0;
        	while(SQLFetch(hstmt)!=SQL_NO_DATA)
			{
				i++;
				
            	SQLGetData(hstmt, 1, SQL_C_CHAR , str1, 5, &len_str1);  
				SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2); 
				SQLGetData(hstmt, 3, SQL_C_CHAR, str3, 50, &len_str3);
				SQLGetData(hstmt, 4, SQL_C_CHAR, str4, 50, &len_str4); 
				SQLGetData(hstmt, 5, SQL_C_CHAR, str5, 50, &len_str5); 
				SQLGetData(hstmt, 6, SQL_C_CHAR, str6, 50, &len_str6); 
				SQLGetData(hstmt, 8, SQL_C_CHAR , str2, 8, &len_str2);
				printf("%d\t%s\t%s\t%s\t\t%s\t\t%s\t\n",i,str2,str1,str4,str5,str6);//
				//printf("name is : %s, password is: %s, sorce is: %lf\n", uname,upassword,usorce);
			
        	}
			
        		SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
	        	SQLFreeHandle(SQL_HANDLE_ENV,henv);
            	cout<<"Press any button"<<endl;
      	}
        else
        {
        	cout<<ret<<endl;
        }

   	}
	else
   	{
   		cout<<"CONNECT FAIL!"<<endl;
      	cout<<ret<<endl;
   	}
}




int userid()
{
	SQLRETURN ret;//
	SQLHENV henv;//SQLHANDLE henv  
	SQLHDBC hdbc;//SQLHANDLE hdbc  
	SQLHSTMT hstmt;//SQLHANDLE hstmt  
	SQLRETURN ret2;


	SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
	SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);


	ret = SQLConnect(hdbc, (SQLCHAR*)"userlib", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"123", SQL_NTS);
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
	{

      	cout<<"CONNECT SECCESS!"<<endl;
      	ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

      	SQLCHAR udb[]="use userlib;";
    	char sql2[]="SELECT max(userid) FROM userlib ";
		
      	SQLExecDirect(hstmt, (SQLCHAR*)udb, SQL_NTS);
      	ret=SQLExecDirect(hstmt, (SQLCHAR*)sql2, SQL_NTS);//
		if (ret == SQL_SUCCESS_WITH_INFO || ret == SQL_SUCCESS)
		{
			cout<<1<<endl;
			//SQLCHAR USERNAME[20], PASSWORD[20], TempPassword[20];
			int USERID[20];
			SQLLEN USERNAME_Len, PASSWORD_Len,TempPassword_Len;
			while (SQLFetch(hstmt) != SQL_NO_DATA)
			{

				SQLRETURN TempRet;//tempret
				SQLGetData(hstmt, 1, SQL_C_SLONG, USERID, 20, &USERNAME_Len);
				cout<<USERID[0]<<endl;;
				return USERID[0];
			}
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
		SQLFreeHandle(SQL_HANDLE_ENV, henv);
		}
		else
		{
			cout<<"wrong !"<<endl;
			exit(0);
		}

	}
	else
	{
		cout<<"wrong !"<<endl;
		exit(0);
	}
}














int Insertsql(char * name,char * password, int flag)//updata new user data
{
    SQLRETURN ret;
	SQLHENV henv;
	SQLHDBC hdbc;
	SQLHSTMT hstmt;
	//SQLCHAR Lib[]='use userlib';
    SQLCHAR SearchResult[1024];
    /*char [20];
    char [20];*/
    char SqlInsert[20];
	float sorce=0.0;
	int MaxUserid=userid()+1;
    //cout<<name>>password;
	SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
	SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);

	ret=SQLConnect(hdbc, (SQLCHAR*)"userlib",SQL_NTS,(SQLCHAR*)"sa",SQL_NTS,(SQLCHAR*)"123",SQL_NTS);
	if(ret==SQL_SUCCESS||ret==SQL_SUCCESS_WITH_INFO)
	{
		cout<<"CONNECT SECCESS!"<<endl;
		SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
		SQLCHAR ConnectDatabaseSql[] = "use userlib;";
		char Usertype[]="cu";
		ret=SQLExecDirect(hstmt, (SQLCHAR*)ConnectDatabaseSql, SQL_NTS);
			char sql[]= "insert into userlib (uname, upassword, usorce, mod1, mod2, mod3, Usertype, userid) values (?, ?, ?, ?, ?, ?, ?, ?)";
        	SQLPrepare(hstmt, (SQLCHAR*)sql, SQL_NTS);
        	ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, strlen(name), 0, (SQLPOINTER)name, 0, NULL);//name
        	ret = SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, strlen(password), 0, (SQLPOINTER)password, 0, NULL);//password
			ret = SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_REAL, 0, 4, (SQLPOINTER)&sorce, 0, NULL);//sorce
			ret = SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_REAL, 0, 4, (SQLPOINTER)&sorce, 0, NULL);//sorce
			ret = SQLBindParameter(hstmt, 5, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_REAL, 0, 4, (SQLPOINTER)&sorce, 0, NULL);//sorce
			ret = SQLBindParameter(hstmt, 6, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_REAL, 0, 4, (SQLPOINTER)&sorce, 0, NULL);//sorce
			ret = SQLBindParameter(hstmt, 7, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, strlen(Usertype), 0, (SQLPOINTER)Usertype, 0, NULL);//type
			ret = SQLBindParameter(hstmt, 8, SQL_PARAM_INPUT, SQL_C_SLONG, SQL_REAL, 0, 4, (SQLPOINTER)&MaxUserid, 0, NULL);//id
			ret = SQLExecute(hstmt);
      		if(ret==SQL_SUCCESS||ret==SQL_SUCCESS_WITH_INFO)
      		{
            	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
            	SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
	        	SQLFreeHandle(SQL_HANDLE_ENV,henv);	
				return 1;		
      		}
        	else
        	{
        		//cout<<ret<<endl;
            	SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
	        	SQLFreeHandle(SQL_HANDLE_ENV,henv);
				return -1;
        	}
        //ret=SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_DOUBLE, 0, 4, (SQLPOINTER)&password, 0, NULL);
        //cout<<ret<<endl;
        //ret = 

        //strcpy((char*)SearchResult, SqlInsert);
        //cout<<SearchResult<<endl;
		


	}
            SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
	        SQLFreeHandle(SQL_HANDLE_ENV,henv);

}





int SqlNewUser(char *NewUser, char * NewPassWord)//check new user exist or not
{
    SQLRETURN ret;//
	SQLHENV henv;//SQLHANDLE henv  
	SQLHDBC hdbc;//SQLHANDLE hdbc  
	SQLHSTMT hstmt;//SQLHANDLE hstmt  
	SQLRETURN ret2;


	SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
	SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);


	ret = SQLConnect(hdbc, (SQLCHAR*)"userlib", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"123", SQL_NTS);
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
	{


		SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
		SQLCHAR ConnectDatabaseSql[] = "use userlib;";
		ret2=SQLExecDirect(hstmt, (SQLCHAR*)ConnectDatabaseSql, SQL_NTS);
		SQLCHAR SearchResult[1024];
        int Namelen=strlen(NewUser);
        int PasswordState;//=strlen(LoginPassword)
		char SQLSearchName[1024];
        char SQLSearchPassword[1145];
		snprintf(SQLSearchName,114514, "select * from userlib where uname = '%s';", NewUser);
        //snprintf(SQLSearchPassword,114514, "select * from userlib where upassword = '%s';", NewPassWord);
		strcpy((char*)SearchResult, SQLSearchName);
		SQLPrepare(hstmt, (SQLCHAR*)SearchResult, SQL_NTS);
        //cout<<SQLSearchName<<endl;
        //cout<<SQLSearchPassword<<endl;
		//cout<<NewUser<<" "<<NewPassWord<<endl;
		ret = SQLExecute(hstmt);
		if (ret == SQL_SUCCESS_WITH_INFO || ret == SQL_SUCCESS)
		{
			SQLCHAR USERNAME[20], PASSWORD[20], TempPassword[20];
			SQLLEN USERNAME_Len, PASSWORD_Len,TempPassword_Len;
			while (SQLFetch(hstmt) != SQL_NO_DATA)
			{

				SQLRETURN TempRet;//tempret
				SQLGetData(hstmt, 1, SQL_C_CHAR, USERNAME, Namelen+1, &USERNAME_Len);
				SQLGetData(hstmt, 2, SQL_C_CHAR, PASSWORD, 13, &PASSWORD_Len);//8-12 password Passwordlen+1
				return 5;
			}
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
		SQLFreeHandle(SQL_HANDLE_ENV, henv);
		return 1;
				//not find user

	}
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
		SQLFreeHandle(SQL_HANDLE_ENV, henv);
	}
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
		SQLFreeHandle(SQL_HANDLE_ENV, henv);

}





int Updata(char * name,float sorce, char modin)//updata sorce
{
    SQLRETURN ret;
	SQLHENV henv;
	SQLHDBC hdbc;
	SQLHSTMT hstmt;
	//SQLCHAR Lib[]='use userlib';
    //char name[20] ;
    //double sorce;
    //cin>>name>>sorce;
    SQLCHAR SearchResult[1024];
    /*char [20];
    char [20];*/
    char SqlInsert[20];
	//float sorce=0.0;
    cout<<strlen(name)<<endl;
	SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
	SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);

	ret=SQLConnect(hdbc, (SQLCHAR*)"userlib",SQL_NTS,(SQLCHAR*)"sa",SQL_NTS,(SQLCHAR*)"123",SQL_NTS);
	if(ret==SQL_SUCCESS||ret==SQL_SUCCESS_WITH_INFO)
	{
		cout<<"CONNECT SECCESS!"<<endl;
		SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
		SQLCHAR ConnectDatabaseSql[] = "use userlib;";
		
		ret=SQLExecDirect(hstmt, (SQLCHAR*)ConnectDatabaseSql, SQL_NTS);
		char sql[114514];//= "UPDATE userlib SET mod=? WHERE uname=?;";
		snprintf(sql, 114514, "UPDATE userlib SET mod%c=? WHERE uname=?;", modin);
			cout<<sql<<endl;
			//strcpy((char*)SearchResult, SQLSearchName);
        	SQLPrepare(hstmt, (SQLCHAR*)sql, SQL_NTS);
        	SQLLEN len = SQL_NTS; 
        	ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_REAL, 0, 4, &sorce, 0, NULL);
            ret = SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, strlen(name), 0, (SQLPOINTER)name, 0, NULL);
			ret = SQLExecute(hstmt);
            cout<<ret<<endl;
      		if(ret==SQL_SUCCESS||ret==SQL_SUCCESS_WITH_INFO)
      		{
      			//cout<<1<<endl;
            	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
            	SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
	        	SQLFreeHandle(SQL_HANDLE_ENV,henv);	
				return 1;		
      		}
        	else
        	{
        		//cout<<ret<<endl;
        		//cout<<ret<<endl;
            	SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
	        	SQLFreeHandle(SQL_HANDLE_ENV,henv);
				return ret;
        	}

	}
            SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
	        SQLFreeHandle(SQL_HANDLE_ENV,henv);
}






int CheckUsertype(char* LoginUsername)
{
	SQLRETURN ret;  
	SQLHENV henv;//SQLHANDLE henv  
	SQLHDBC hdbc;//SQLHANDLE hdbc  
	SQLHSTMT hstmt;//SQLHANDLE hstmt  
   	SQLCHAR connout[256];
   	SQLSMALLINT connout_len;
	ret=SQLAllocHandle(SQL_HANDLE_ENV,NULL,&henv); 
	ret=SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	ret=SQLAllocHandle(SQL_HANDLE_DBC,henv,&hdbc);
	ret=SQLConnect(hdbc, (SQLCHAR*)"userlib", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"123", SQL_NTS);
	//cout<<1<<endl;
	cout<<"username : "<<LoginUsername<<endl;
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
	{
		SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
		SQLCHAR ConnectDatabaseSql[] = "use userlib;";
		ret=SQLExecDirect(hstmt, (SQLCHAR*)ConnectDatabaseSql, SQL_NTS);
		char sql2[]= "select Usertype from userlib where uname=?;";
		SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, strlen(LoginUsername), 0, (SQLPOINTER)LoginUsername, 0, NULL);
		SQLPrepare(hstmt, (SQLCHAR*)sql2, SQL_NTS);
      	ret=SQLExecDirect(hstmt, (SQLCHAR*)sql2, SQL_NTS);//
		if (ret == SQL_SUCCESS_WITH_INFO || ret == SQL_SUCCESS)
		{
			SQLLEN len_str;
        	char str[200];
        	while(SQLFetch(hstmt)!=SQL_NO_DATA)
			{
				SQLGetData(hstmt, 1, SQL_C_CHAR, str, 50, &len_str); 
				cout<<"usertype : "<<str<<endl;
				string tempstr="Admin";
				string tempstr2;
				tempstr2=tempstr2+str;
				int k=tempstr.compare(tempstr2);
				if(k==0)
				{
					SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
					SQLFreeHandle(SQL_HANDLE_ENV, henv);	
					return 0;//adm
				}
				else
				{
					SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
					SQLFreeHandle(SQL_HANDLE_ENV, henv);	
					return 1;//user
				}
        	}
				//delet succese
		}
	}
}






int deletesql(char* LoginUsername, char* LoginPassword) // int usertype
{

		SQLRETURN ret;  
		SQLHENV henv;//SQLHANDLE henv  
		SQLHDBC hdbc;//SQLHANDLE hdbc  
		SQLHSTMT hstmt;//SQLHANDLE hstmt  
   		SQLCHAR connout[256];
   		SQLSMALLINT connout_len;
		ret=SQLAllocHandle(SQL_HANDLE_ENV,NULL,&henv); 
		ret=SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
		ret=SQLAllocHandle(SQL_HANDLE_DBC,henv,&hdbc);
		ret = SQLConnect(hdbc, (SQLCHAR*)"userlib", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"123", SQL_NTS);
		cout<<1<<endl;
		cout<<LoginUsername<<endl;
		if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
		{
			SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
			SQLCHAR ConnectDatabaseSql[] = "use userlib;";
			ret=SQLExecDirect(hstmt, (SQLCHAR*)ConnectDatabaseSql, SQL_NTS);
			char sql[]= "delete userlib where uname=?";
			SQLPrepare(hstmt, (SQLCHAR*)sql, SQL_NTS);
			ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, strlen(LoginUsername), 0, (SQLPOINTER)LoginUsername, 0, NULL);
			cout<<LoginUsername<<endl;
			ret = SQLExecute(hstmt);
			if (ret == SQL_SUCCESS_WITH_INFO || ret == SQL_SUCCESS)
			{
				SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
				SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
				SQLFreeHandle(SQL_HANDLE_ENV, henv);
				return 1;
				//delet succese

			}
			else
			{
				SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
				SQLFreeHandle(SQL_HANDLE_ENV, henv);			
				return ret;
			}
		}	
		else
		{
			SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
			SQLFreeHandle(SQL_HANDLE_ENV, henv);			
			return ret;
			//undefine error
		}
}



int CheckSingleUser(char* Username)
{
		SQLRETURN ret;  
		SQLHENV henv;//SQLHANDLE henv  
		SQLHDBC hdbc;//SQLHANDLE hdbc  
		SQLHSTMT hstmt;//SQLHANDLE hstmt  
   		SQLCHAR connout[256];
   		SQLSMALLINT connout_len;
		ret=SQLAllocHandle(SQL_HANDLE_ENV,NULL,&henv); 
		ret=SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
		ret=SQLAllocHandle(SQL_HANDLE_DBC,henv,&hdbc);
		ret = SQLConnect(hdbc, (SQLCHAR*)"userlib", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"123", SQL_NTS);
		if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
		{
			SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
			SQLCHAR ConnectDatabaseSql[] = "use userlib;";
			ret=SQLExecDirect(hstmt, (SQLCHAR*)ConnectDatabaseSql, SQL_NTS);
			char sql2[]= "select * from userlib where uname=?;";
			SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, strlen(Username), 0, (SQLPOINTER)Username, 0, NULL);
			SQLPrepare(hstmt, (SQLCHAR*)sql2, SQL_NTS);
      		ret=SQLExecDirect(hstmt, (SQLCHAR*)sql2, SQL_NTS);//
			if (ret == SQL_SUCCESS_WITH_INFO || ret == SQL_SUCCESS)
			{
				SQLLEN len_str;
        		char str[200];
        		SQLLEN len_str1, len_str2, len_str3,len_str4,len_str5,len_str6;
        		SQLCHAR str1[20],str2[20],str3[20],str4[20],str5[20],str6[20];
       			printf("ranking\tuserid\tname\tmod1sorce\tmod2sorce\tmod3sorce\n");
				int i=0;
        		while(SQLFetch(hstmt)!=SQL_NO_DATA)
				{
					i++;
            		SQLGetData(hstmt, 1, SQL_C_CHAR , str1, 5, &len_str1);  
					SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2); 
					SQLGetData(hstmt, 3, SQL_C_CHAR, str3, 50, &len_str3);
					SQLGetData(hstmt, 4, SQL_C_CHAR, str4, 50, &len_str4); 
					SQLGetData(hstmt, 5, SQL_C_CHAR, str5, 50, &len_str5); 
					SQLGetData(hstmt, 6, SQL_C_CHAR, str6, 50, &len_str6); 
					SQLGetData(hstmt, 8, SQL_C_CHAR , str2, 8, &len_str2);
					printf("%d\t%s\t%s\t%s\t\t%s\t\t%s\t\n",i,str2,str1,str4,str5,str6);//
				//printf("name is : %s, password is: %s, sorce is: %lf\n", uname,upassword,usorce);
        		}
				getch();
				SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
				SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
				SQLFreeHandle(SQL_HANDLE_ENV, henv);
				return 1;
				// succese
			}
			else
			{
				return -1;//fall
			}
		}
		else
		{
			return -1;//fall
		}
}


int BackUp()
{
	char *s;
	char path[1000];
	string name;
	string tpaht;
	cin>>name;
	s=fidd(2);
	tpaht+=s;
	cout<<s<<endl;
	tpaht+="\\"+name+".bak";
	cout<<tpaht<<endl;
	strcpy(path,tpaht.c_str()); 
	SQLRETURN ret;  
	SQLHENV henv;//SQLHANDLE henv  
	SQLHDBC hdbc;//SQLHANDLE hdbc  
	SQLHSTMT hstmt;//SQLHANDLE hstmt  
   	SQLCHAR connout[256];
   	SQLSMALLINT connout_len;
	ret=SQLAllocHandle(SQL_HANDLE_ENV,NULL,&henv); 
	ret=SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	ret=SQLAllocHandle(SQL_HANDLE_DBC,henv,&hdbc);
	ret = SQLConnect(hdbc, (SQLCHAR*)"userlib", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"123", SQL_NTS);
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
	{
		SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
		SQLCHAR ConnectDatabaseSql[] = "use userlib;";
		ret=SQLExecDirect(hstmt, (SQLCHAR*)ConnectDatabaseSql, SQL_NTS);
		char sql2[]= "backup database[userlib] to disk = ?";//select * from userlib where uname=?;
		SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, strlen(path), 0, (SQLPOINTER)path, 0, NULL);//
		SQLPrepare(hstmt, (SQLCHAR*)sql2, SQL_NTS);
      	ret=SQLExecDirect(hstmt, (SQLCHAR*)sql2, SQL_NTS);
		if(ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
		{
			Sleep(1000); 
			SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
    		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
			SQLFreeHandle(SQL_HANDLE_ENV, henv);
			return 1;//success
		}
		else
		{
			return -1;//fail
		}
	}
	else
	{
		return -1;//fail
	}
}
