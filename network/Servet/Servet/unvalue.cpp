/*

int main(int argc, char* argv[])
{
WSADATA wsaData;
WORD sockVersion = MAKEWORD(2, 2);
if (WSAStartup(sockVersion, &wsaData) != 0)
{
return 0;
}

SOCKET serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if (serSocket == INVALID_SOCKET)
{
printf("socket error !");
return 0;
}

sockaddr_in serAddr;
serAddr.sin_family = AF_INET;
serAddr.sin_port = htons(8888);
serAddr.sin_addr.S_un.S_addr = INADDR_ANY;
if (bind(serSocket, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
{
printf("bind error !");
closesocket(serSocket);
return 0;
}

sockaddr_in remoteAddr;
int nAddrLen = sizeof(remoteAddr);
while (true)
{
char recvData[255];
int ret = recvfrom(serSocket, recvData, 255, 0, (sockaddr *)&remoteAddr, &nAddrLen);
if (ret > 0)
{
recvData[ret] = 0x00;
printf("���ܵ�һ�����ӣ�%s \r\n", inet_ntoa(remoteAddr.sin_addr));
printf(recvData);
}

char * sendData = "һ�����Է���˵�UDP���ݰ�\n";
sendto(serSocket, sendData, strlen(sendData), 0, (sockaddr *)&remoteAddr, nAddrLen);

}
closesocket(serSocket);
WSACleanup();
return 0;
}












#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

const int MAX_RESP = 3;

typedef vector<string> vstring;

vstring find_match(string input);
void copy(char *array[], vstring &v);


typedef struct {
char *input;
char *responses[MAX_RESP];
}record;

record KnowledgeBase[] = {
{ "WHAT IS YOUR NAME",
{ "�ţ��ҵ����ֽ�Ϲ�ġ�",
"����Խ��ҹ���...���ǰ������Ǵ�С�㰡��",
"Ϊʲô����֪���ҵ����֣���һ����Ҫ����QQ����" }
},

{ "HI",
{ "�������ð���",
"����˭��",
"�ޣ���ã�" }
},

{ "HOW ARE YOU",
{ "�Ҹɵò�����",
"��ɵ���ô����",
"Ϊʲô�����֪��������ô�����ģ�" }
},

{ "WHO ARE YOU",
{ "��������Ǹ����򰡡�",
"��˵����֪����֪������˭��",
"Ϊʲô���ʣ�" }
},

{ "ARE YOU INTELLIGENT",
{ "�ǵģ���Ȼ�ǵġ�",
"������ô��ģ�",
"��������ʵ����ȷʵ�ܴ�����" }
},

{ "ARE YOU REAL",
{ "���������Ǹ�������",
"ɶ��˼�����㣿",
"�Ҿ������ҿ�����������������ࡣ" }
}
};

size_t nKnowledgeBaseSize = sizeof(KnowledgeBase) / sizeof(KnowledgeBase[0]);


int main() {
srand((unsigned)time(NULL));

string sInput = "";
string sResponse = "";

while (1) {
cout << ">";
getline(cin, sInput);
vstring responses = find_match(sInput);
if (sInput == "BYE") {
cout << "��������̫����ˣ��´�������" << std::endl;
break;
}
else if (responses.size() == 0)  {
cout << "�ң��ң��Ҳ�ȷ�����Ƿ��������˵����ʲô ..." << endl;
}
else {
int nSelection = rand() % MAX_RESP;
sResponse = responses[nSelection];
cout << sResponse << endl;
}
}

return 0;
}

// make a  search for the  user's input
// inside the database of the program
vstring find_match(string  input) {
vstring result;
for (int i = 0; i < nKnowledgeBaseSize; ++i) {
if (string(KnowledgeBase[i].input) == input) {
copy(KnowledgeBase[i].responses, result);
return result;
}
}
return result;
}

void copy(char  *array[], vstring &v) {
for (int i = 0; i < MAX_RESP; ++i) {
v.push_back(array[i]);
}
}



*/
