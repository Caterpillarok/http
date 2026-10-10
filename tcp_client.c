#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
#include<arpa/inet.h>

int main(){

	int sockfd;
	int N;
	int mat[10][10];
	socklen_t len;

	struct sockaddr_in client_addr;
	
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = INADDR_ANY;
	client_addr.sin_port = inet_addr("127.0.0.1");

	connect(sockfd,(struct sockadddr*)&client_addr,sizeof(client_addr));

	printf("Enter the size of the matrix\n");
	scanf("%n",&N);

	srand(time(0));

	for (int i =0;i<N;i++){
		for(int j =0;j<N;j++){
			mat[i][j] = rand()%51;
			printf("%3d ",mat[i][j]);
		}
	}
	printf("\n");


	send(sockfd,&N,sizeof(N),0);

	send(sockfd,&mat,sizeof(mat),0);

	char result[50];

	recv(sockfd,result,sizeof(result),0);

	printf("The resulting matrix is ",result);

	close(sockfd);
	close(new_socket);

	return 0;
}
