/*
int main()
{
//初始化Windows Socket API
WORD sockVision = MAKEWORD(2, 2);
WSADATA wsadata;

//其他变量
SOCKET sclient;
struct sockaddr_in clientAddr;
char senddata[255];
char revdata[255];
int ret = -1;
int len = -1;
if (WSAStartup(sockVision, &wsadata) != 0)
{
printf("WSA初始化失败\n");
return 0;
}

//创建套接字
sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (sclient == INVALID_SOCKET)
{
printf("socket客户端创建失败\n");
return 0;
}
//printf("第32行执行！");
clientAddr.sin_family = AF_INET;
clientAddr.sin_port = htons(8888);
clientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
len = sizeof(clientAddr);

//	printf("第38行执行！");
while (1)
{
printf("我：");
scanf("%s", senddata);
sendto(sclient, senddata, strlen(senddata), 0, (SOCKADDR*)&clientAddr, len);
if (strcmp(senddata, "bye") == 0)
break;
ret = recvfrom(sclient, revdata, 255, 0, (SOCKADDR*)&clientAddr, &len);
//	printf("%d", ret);
if (ret > 0)
{
revdata[ret] = 0x00;
printf("\n");
printf("服务器：");
printf(revdata);
printf("\n");
}
}

closesocket(sclient);
WSACleanup();

system("pause");
return 0;
}

*/
