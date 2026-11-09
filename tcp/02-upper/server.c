#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(){
	int s,c;
	char string[100] = {0};
	struct sockaddr_in server;

	s = socket(AF_INET,SOCK_STREAM,0);
	
	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	server.sin_addr.s_addr = INADDR_ANY;

	bind(s,(struct sockaddr*)&server,sizeof(server));
	listen(s,5);

	printf("Waiting for client\n");
	c = accept(s,NULL,NULL);

	recv(c,&string,sizeof(string),0);

	for(int i =0;string[i]!='\0';i++){
		string[i] = toupper(string[i]);
	}
	send(c,string,strlen(string)+1,0);

	close(c);
	close(s);

	return 0;



}
