/*
#include <stdio.h>
#include<string>
#include<vector>
#include <winsock2.h>

char* substring(char* ch, int pos, int length);
int pos(char *ch, char c);
#pragma comment(lib,"ws2_32.lib")
const int MAX_RESP = 3;
using namespace std;
typedef vector<string> vstring;
vstring find_match(string input);
//string find_match(string input);

typedef struct {
	char *input;
	char *responses[MAX_RESP];
	//char *responses;
}record;

//record KnowledgeBase[10];

int main(void)
{
	//record knowrep[10];
	
	//FILE *file;
	//char str[50];
	//if ((file = fopen("e:\\test\\robot.txt","r")) != NULL)
	//{
	//	printf("\n打开失败\n");
	//	exit(1);
	//}
	//char ch[30];
	//char* ptemp;
	//int i = 0, j = 0;
	//char *temp[10];

	//while ((ptemp=fgets(ch,30,file))!=NULL)
	//{
	//	*temp[i] = *ch;
	//	i++;
	//}
	//while (j<i)
	//{
	//	char *p = temp[j];
	//	KnowledgeBase[j].input = substring(p, 0, pos(p, '\\'));
	//	KnowledgeBase[j].responses = substring(p, pos(p, '\\'), sizeof(*temp[j]));
	//}
	//初始化wsa
	WORD sockVision = MAKEWORD(2, 2);
	WSADATA wsadata;
	//其他变量
	SOCKET serSocket;
	struct sockaddr_in remoteAddr;
	struct sockaddr_in sin;
	int ret = -1;
	int nAddrlen = sizeof(remoteAddr);
	char revdata[255];
	char senddata[255];


	if (WSAStartup(sockVision, &wsadata) != 0)
	{
		printf("WSA初始化失败\n");
		return 0;
	}

	//创建套接字
	serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (serSocket == INVALID_SOCKET)
	{
		printf("socket service fail\n");
		return 0;
	}

	//绑定IP和端口
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(serSocket, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("please bind port \n");
		return 0;
	}

	//循环接收数据
	printf("准备就绪！");
	while (1)
	{
		memset(senddata, 0, sizeof(senddata));
		ret = recvfrom(serSocket, revdata, 255, 0, (SOCKADDR*)&remoteAddr, &nAddrlen);
		//printf("%d", ret);
		if (ret > 0)
		{
			revdata[ret] = 0x00;
			printf("\n接收到一个连接：%s \n", inet_ntoa(remoteAddr.sin_addr));
			printf("\n");
			printf("客户：");
			printf(revdata);
			printf("\n");
		}
		//发送数据
		printf("我：");

		vstring responses = find_match(revdata);

		if (revdata == "BYE") {
			strcpy(senddata, "Good bye,welcome to go back!");
		}
		else if (responses.size() == 0)  {
			strcpy(senddata, "Sorry ,I don not understand what you says.");
		}

		else
		{
			int nSelect = rand() % MAX_RESP;
			string temp = responses[nSelect];
			/*string temp = responses;*
			for (int i = 0; i < temp.size(); i++)
			{
				senddata[i] = temp[i];
			}
			
		}
	//	scanf("%s", senddata);
		printf("%s", senddata);
		sendto(serSocket, senddata, strlen(senddata), 0, (SOCKADDR*)&remoteAddr, nAddrlen);
	}

	closesocket(serSocket);
	WSACleanup();
	return 0;
}



record KnowledgeBase[] = {
	{ "WHAT ARE YOUR NAME",
	{ "嗯，我的名字叫瞎聊。",
	"你可以叫我公主...，是啊，我是大小姐啊。",
	"为什么你想知道我的名字？下一步是要交换QQ号吗？" }
	},
	{ "what are your name",
	{ "嗯，我的名字叫瞎聊。",
	"你可以叫我公主...，是啊，我是大小姐啊。",
	"为什么你想知道我的名字？下一步是要交换QQ号吗？" }
	},
	{ "HI",
	{ "hello",
	"have fun",
	"good time" }
	},
	{ "hi",
	{ "hello",
	"have fun",
	"good time" }
	},
	{ "hello",
	{ "hi",
	"have fun",
	"good time" }
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




void copy(char  *array[], vstring &v) {
	for (int i = 0; i < MAX_RESP; ++i) {
		v.push_back(array[i]);
	}
}

vstring find_match(string  input){
	vstring result;
	for (int i = 0; i < nKnowledgeBaseSize; ++i) {
		if (string(KnowledgeBase[i].input) == input) {
			copy(KnowledgeBase[i].responses, result);
			return result;
		}
	}
	return result;
}



//
//char* substring(char* ch, int pos, int length)
//{
//	char* pch = ch;
//	char* subch = (char*)calloc(sizeof(char), length + 1);
//	int i;
//	pch = pch + pos;
//	//是pch指针指向pos位置。  
//	for (i = 0; i < length; i++)
//	{
//		subch[i] = *(pch++);
//	}
//	subch[length] = '\0';
//	return subch;        
//}
//
//int pos(char *ch, char c)
//{
//	int num = 0;
//	char *p = ch;
//	while (1)
//	{
//		p = p + 1;
//		num++;
//		if (*p == '\\')
//			break;
//	}
//	return num;
//}

*/