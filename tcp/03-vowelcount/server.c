#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

	int s,c;
	char str[100] = {0};
	struct sockaddr_in server;

	s = socket(AF_INET,SOCK_STREAM,0);

	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	server.sin_addr.s_addr = INADDR_ANY;

	bind(s,(struct sockaddr*)&server,sizeof(server));
	listen(s,5);

	printf("Waiting for client\n");
	c = accept(s,NULL,NULL);

	recv(c,str,sizeof(str),0);
	int count = 0;

	for (int i =0;str[i]!='\0';i++){
		char ch = str[i];
		if(ch == 'a' || ch =='e' || ch =='i' || ch =='o' || ch =='u'
				|| ch == 'A' || ch =='E' || ch == 'I' || ch == 'O'|| ch =='U'){
			count++;
		}
	}

	send(c,&count,sizeof(count),0);

	close(c);
	close(s);

	return 0;

}
















