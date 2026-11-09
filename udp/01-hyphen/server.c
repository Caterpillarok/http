#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(){

	int s;
	char str[100];
	struct sockaddr_in server,client;

	socklen_t len = sizeof(client);

	s = socket(AF_INET,SOCK_DGRAM,0);

	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	server.sin_addr.s_addr = INADDR_ANY;

	bind(s,(struct sockaddr*)&server,sizeof(server));

	printf("Waiting for server\n");
	recvfrom(s,str,sizeof(str),0,(struct sockaddr*)&client,&len);

	for(int i =0; str[i]!=0;i++){
		if(str[i] ==' '){
			str[i] = '-';
		}
	}

	sendto(s,str,strlen(str)+1,0,(struct sockaddr*)&client,len);
	close(s);

	return 0;


}
