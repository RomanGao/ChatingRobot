#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib")


int main(int argc, char* argv[])
{
	// ��ʼ��Windows Socket API
	WORD socketVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(socketVersion, &wsaData) != 0)
	{
		printf("WSA��ʼ��ʧ��\n");
		return 0;
	}

	//�����׽���
	SOCKET sclient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sclient == INVALID_SOCKET)
	{
		printf("socket�ͻ��˴���ʧ��\n");
		return 0;
	}

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	int len = sizeof(sin);



	char senddata[255];
	char revdata[255];
	printf("�ͻ�����������");

	while (1)
	{
		printf("\n�ң�");

		gets(senddata);

		sendto(sclient, senddata, strlen(senddata), 0, (sockaddr *)&sin, len);
		if (strcmp(senddata, "bye") == 0)
		{
			printf("��������̫����ˣ��´�������");
			break;
		}
			
		int ret = recvfrom(sclient, revdata, 255, 0, (sockaddr *)&sin, &len);
		//	printf("%d", ret);
		if (ret > 0)
		{
			revdata[ret] = 0x00;
			printf("Sir��");
			printf(revdata);
			printf("\n");
		}
	}

	closesocket(sclient);
	WSACleanup();
	system("pause");
	return 0;
}



