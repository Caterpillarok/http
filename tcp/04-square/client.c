#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

	int s,num,square;

	struct sockaddr_in server;

	s = socket(AF_INET,SOCK_STREAM,0);

	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(s,(struct sockaddr*)&server,sizeof(server));

	printf("Enter the nummber\n");
	scanf("%d",&num);

	send(s,&num,sizeof(num),0);

	recv(s,&square,sizeof(square),0);

	printf("Square = %d\n",square);
	close(s);

	return 0;
}
