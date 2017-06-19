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
printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));
printf(recvData);
}

char * sendData = "一个来自服务端的UDP数据包\n";
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
{ "嗯，我的名字叫瞎聊。",
"你可以叫我公主...，是啊，我是大小姐啊。",
"为什么你想知道我的名字？下一步是要交换QQ号吗？" }
},

{ "HI",
{ "哈哈，好啊！",
"你是谁？",
"噢，你好！" }
},

{ "HOW ARE YOU",
{ "我干得不坏！",
"你干得怎么样？",
"为什么你会想知道我是怎么做到的？" }
},

{ "WHO ARE YOU",
{ "我尼玛就是个程序啊。",
"表说，我知道你知道我是谁。",
"为什么还问？" }
},

{ "ARE YOU INTELLIGENT",
{ "是的，当然是的。",
"你是怎么想的？",
"哈哈，事实上我确实很聪明。" }
},

{ "ARE YOU REAL",
{ "这对你真的是个问题吗？",
"啥意思啊？你？",
"我尽量让我看起来像个真正的人类。" }
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
cout << "和你聊天太愉快了，下次再来！" << std::endl;
break;
}
else if (responses.size() == 0)  {
cout << "我，我，我不确定我是否能理解你说的是什么 ..." << endl;
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
