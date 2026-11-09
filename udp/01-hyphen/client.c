#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int s;
	char str[100];
	struct sockaddr_in server;
	socklen_t len = sizeof(server);

	s = socket(AF_INET,SOCK_DGRAM,0);

	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	printf("Enter the sentence\n");
	scanf(" %[^\n]",str);

	sendto(s,str,strlen(str)+1,0,(struct sockaddr*)&server,len);
	recvfrom(s,str,sizeof(str),0,(struct sockaddr*)&server,&len);

	printf("The translated sentence is: %s\n",str);

	close(s);
	return 0;


}
	




