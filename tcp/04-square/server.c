#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>

int main(){
	int s,square,num,c;
	struct sockaddr_in server;

	s = socket(AF_INET,SOCK_STREAM,0);

	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	server.sin_addr.s_addr = INADDR_ANY;

	bind(s,(struct sockaddr*)&server,sizeof(server));
	listen(s,5);

	printf("waiting for server\n");
	c = accept(s,NULL,NULL);

	recv(c,&num,sizeof(num),0);

	square = num*num;

	send(c,&square,sizeof(square),0);

	close(c);
	close(s);

	return 0;
}














