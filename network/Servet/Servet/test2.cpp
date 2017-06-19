#include<iostream>
#include<fstream>
#include<string>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")


char* substring(char* ch, int pos, int length);
int pos(char *ch, char c);
const int MAX_RESP = 3;
using namespace std;
string find_matchtest(string input);

//去掉字符串的收尾空格
void trim(string &s)
{
	 if (!s.empty())
	 {
		 s.erase(0, s.find_first_not_of(" "));
		 s.erase(s.find_last_not_of(" ") + 1);
	} 
}

int main()
{
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
		cout << "WSA初始化失败\n" << endl;
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
		cout << "请绑定端口号" << endl;
		return 0;
	}

	//循环接收数据
	cout << "准备就绪！等待连接……" << endl;

	while (1)
	{
		memset(senddata, 0, sizeof(senddata));
		ret = recvfrom(serSocket, revdata, 255, 0, (SOCKADDR*)&remoteAddr, &nAddrlen);
		//printf("%d", ret);
		if (ret > 0)
		{
			revdata[ret] = 0x00;
			cout << "\n接收到一个连接：" << inet_ntoa(remoteAddr.sin_addr) << endl;
			cout << endl;
			cout << "客户：";
			cout << revdata << endl;
		}
		//发送数据
		cout << "我：";

		string strtemp = revdata;
		trim(strtemp);
		string responses = find_matchtest(strtemp);

		if (revdata == "BYE"||revdata=="bye") {
			strcpy(senddata, "Good bye,welcome to go back!");
		}
		else if (responses.size() == 0)  {
			strcpy(senddata, "Sorry ,I don not understand what you say.");
		}
		else
		{
			for (int i = 0; i < responses.size(); i++)
			{
				senddata[i] = responses[i];
			}

		}
		//scanf("%s", senddata);
		printf("%s", senddata);
		sendto(serSocket, senddata, strlen(senddata), 0, (SOCKADDR*)&remoteAddr, nAddrlen);
	}

	closesocket(serSocket);
	WSACleanup();
	return 0;
}

string find_matchtest(string input)
{
	string strt="";  //输出
	strt.clear();
	ifstream file;
	file.open("F:\\work\\network\\robot.txt");
	char szbuff[1024] = { 0 };  //缓冲
	while (!file.eof())
	{
		file.getline(szbuff, 1024);
		int i = 0, j = 0;
		string strff = szbuff;  //转化为字符串
		trim(strff);    //去掉收尾空格
		int index = 0;
		for (int i = 0; i < strff.size(); i++)
		{
			if (strff[i] == '\\')
				break;
			index++;
		}
	//cout << strff << "  " << index << endl;
		string str = strff.substr(0,index);  //截取前半部分
	//	cout << index << endl;
		if (str == input&&index<strff.size())   //和输入做对比
		{
			strt = strff.substr(index + 1, strff.size() - 1);
			break;
		}
	}
	return strt;
}