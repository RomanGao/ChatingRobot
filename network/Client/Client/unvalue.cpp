/*
int main()
{
//��ʼ��Windows Socket API
WORD sockVision = MAKEWORD(2, 2);
WSADATA wsadata;

//��������
SOCKET sclient;
struct sockaddr_in clientAddr;
char senddata[255];
char revdata[255];
int ret = -1;
int len = -1;
if (WSAStartup(sockVision, &wsadata) != 0)
{
printf("WSA��ʼ��ʧ��\n");
return 0;
}

//�����׽���
sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (sclient == INVALID_SOCKET)
{
printf("socket�ͻ��˴���ʧ��\n");
return 0;
}
//printf("��32��ִ�У�");
clientAddr.sin_family = AF_INET;
clientAddr.sin_port = htons(8888);
clientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
len = sizeof(clientAddr);

//	printf("��38��ִ�У�");
while (1)
{
printf("�ң�");
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
printf("��������");
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
