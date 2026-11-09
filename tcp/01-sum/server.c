#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int num,s,digit,temp,c;
	struct sockaddr_in server;

	s = socket(AF_INET,SOCK_STREAM,0);

	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	server.sin_addr.s_addr = INADDR_ANY;

	bind(s,(struct sockaddr*)&server,sizeof(server));
	listen(s,5);

	printf("Waiting for client\n");

	c = accept(s,NULL,NULL);

	recv(c,&num,sizeof(num),0);
	int sum =0;
	temp = num;

	while(temp>0){
		digit = temp%10;
		sum = sum + digit;
		temp = temp/10;
	}
	send(c,&sum,sizeof(sum),0);

	close(c);
	close(s);

	return 0;
	
	}









