#include"connetsql.cpp"
//#include"Memorizenumbersquickly.cpp"
//#include"adminmode.cpp"

int connetsql();
int sreachpart(char * LoginUsername, char  *LoginPassword);
int Updata(char * name, float sorce, char modin);
void ShowRank();
int SqlNewUser(char *NewUser, char * NewPassWord);
int Insertsql(char * name,char * password, int flag);
int deletesql(char* LoginUsername, char* LoginPassword);//int usertype
int PasswordComper(char* temppassword, char* LoginPassword);
int CheckUsertype(char* LoginUsername);
int CheckSingleUser(char* LoginUsername);
int BackUp();
//connetsql.cpp


/*void mainmeau();
void gamemainmuen(char* LoginUsername, char* LoginPassword);//
//Memorizenumbersquickly.cpp*/


/*void adminmode(char* LoginUsername, char* LoginPassword);//
int x();*/
//admin.cpp

