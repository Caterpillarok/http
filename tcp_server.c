#include<stdio.h>
#include<time.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

#define PORT 12345

int main{
	int sockfd;
	int new_socket;
	int N;
	struct sockaddr_in server_addr;
	socklen_t len;

	int mat[10][10];

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_address.s_addr = INADDR_ANY;
	server_addr.sin_port = htons[PORT];

	bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));

	listen(sockfd,3);

	printf("TCP server running\n");
	
	len = sizeof(server_addr);

	new_socket = accept(sockfd,(struct sockaddr*)&server_addr,&len);

	recv(new_socket,&N,sizeof(N),0);

	recv(new_socket,&mat,sizeof(mat),0);

	int uppper = 0;
	int lower = 0;
	int diagonal = 0;


	for(int i =0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i>j && mat[i][j]!=0){
				upper = 1;
			}
			if(i<j && mat[i][j]!=0){
				lower = 1;
			}
			if (i==j && mat[i][j]!=0){
				diagonal = 1;
			}
		}
	}
	char result[1024];

	if (upper){
		strcpy(result,"The matrix is upper diagonal\n");
	}
	if (lower){
		strcpy(result,"The matrix is lower diagonal\n");
	}
	if(diagonal){
		strcpy(result,"The matrix is diagonal\n");
	}
	else{
		strcpy(result,"special");
	}

	send(new_socket,result,strlen(result)+1,0);
	
	close(new_socket);
	close(sockfd);

	return 0;

}










	



































}
