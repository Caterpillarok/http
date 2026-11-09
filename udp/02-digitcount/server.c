#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int s,num,temp,count = 0;
	struct sockaddr_in server,client;
	socklen_t len = sizeof(client);

	s = socket(AF_INET,SOCK_DGRAM,0);

	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	server.sin_addr.s_addr = INADDR_ANY;

	bind(s,(struct sockaddr*)&server,sizeof(server));

	printf("Waiting for server\n");
	
	recvfrom(s,&num,sizeof(num),0,(struct sockaddr*)&client,&len);

	temp = abs(num);
	
	do{
		count++;
		temp = temp/10;
	}while (temp>0);

	sendto(s,&count,sizeof(count),0,(struct sockaddr*)&client,len);
	close(s);

	return 0;

}
