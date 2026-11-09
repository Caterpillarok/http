#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){

	int num,s,count;

	struct sockaddr_in server ;
	socklen_t len = sizeof(server);

	s = socket(AF_INET,SOCK_DGRAM,0);

	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	printf("Enter the number\n");
	scanf("%d",&num);

	sendto(s,&num,sizeof(num),0,(struct sockaddr*)&server,len);
	recvfrom(s,&count,sizeof(count),0,(struct sockaddr*)&server,&len);

	printf("The count is: %d\n",count);

	close(s);

	return 0;

}
