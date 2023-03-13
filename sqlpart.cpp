#include<bits/stdc++.h>
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


#ifdef _WIN64 
typedef INT64 SQLLEN; 
typedef UINT64 SQLULEN; 
#else 
#define SQLLEN SQLINTEGER 
#define SQLULEN SQLUINTEGER 
#endif

using namespace std;



int Select2(char *path)//choose compress feil save place 
{
	BROWSEINFO bi;   
	ZeroMemory(&bi,sizeof(BROWSEINFO));   
	bi.hwndOwner = NULL;   
	bi.pszDisplayName = path;   
	bi.lpszTitle = ("compress file will save at:");   
	bi.ulFlags = BIF_RETURNFSANCESTORS;   
	LPITEMIDLIST idl = SHBrowseForFolder(&bi);   
	SHGetPathFromIDList(idl,path); 
	//cout<<path<<endl;
    if(NULL==idl)
    {
        return 0;
    }  
    else
    {
        return 1;
    }  
}
char *fidd(int n)
{
	if(n==2)
	{
		char *path=NULL;
		char szFile[1000];
		int temp=Select2(szFile);
		cout<<temp<<endl;
		cout<<szFile<<endl;
    	if(temp==1)
    	{
			path=szFile;
        	cout<<szFile<<endl;
        	return path;
    	}
    	else if(temp==0)
    	{
        	cout<<"wrong"<<endl;
			getch();
			fidd(2);
			system("cls");
    	}
	}

}  

int main()
{
	char *s;
	char path[100];
	string name;
	string tpaht;
	cin>>name;
	s=fidd(2);
	cout<<s<<endl;
	tpaht+=s;
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
	}
	Sleep(1000); 
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	SQLFreeHandle(SQL_HANDLE_ENV, henv);

}
