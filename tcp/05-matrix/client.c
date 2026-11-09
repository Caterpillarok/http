#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

#define PORT 12345
#define SIZE 10

int main(){
	int sockfd, N;
	int mat[SIZE][SIZE];
	struct sockaddr_in server;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(PORT);

	connect(sockfd, (struct sockaddr*)&server, sizeof(server));

	printf("Enter the size of the matrix (max %d)\n", SIZE);
	scanf("%d", &N);

	srand(time(0));

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			mat[i][j] = rand() % 51;
			printf("%3d ", mat[i][j]);
		}
		printf("\n");
	}

	send(sockfd, &N, sizeof(N), 0);
	send(sockfd, mat, sizeof(mat), 0);

	char result[100];
	recv(sockfd, result, sizeof(result), 0);

	printf("%s\n", result);

	close(sockfd);

	return 0;
}
