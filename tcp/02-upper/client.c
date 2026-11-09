#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){

	int s;
	char sentence[100];
	
	struct sockaddr_in server;

	s = socket(AF_INET,SOCK_STREAM,0);

	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(s,(struct sockaddr*)&server,sizeof(server));

	printf("Enter the string\n");
	scanf(" %[^\n]",sentence);

	send(s,sentence,strlen(sentence)+1,0);

	recv(s,sentence,sizeof(sentence),0);

	printf("The translated sentence is %s\n",sentence);

	close(s);

	return 0;
}
