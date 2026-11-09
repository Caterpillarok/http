#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define SIZE 10

int main(){
	int sockfd, new_socket;
	int N, upper = 0, lower = 0, diagonal = 0;
	struct sockaddr_in server_addr;
	socklen_t len = sizeof(server_addr);

	int mat[SIZE][SIZE];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);

	bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	listen(sockfd, 3);

	printf("TCP server running\n");

	new_socket = accept(sockfd, (struct sockaddr*)&server_addr, &len);

	recv(new_socket, &N, sizeof(N), 0);
	recv(new_socket, mat, sizeof(mat), 0);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i > j && mat[i][j] != 0)     // nonzero below the diagonal
				lower = 1;                   // -> not lower triangular
			if(i < j && mat[i][j] != 0)     // nonzero above the diagonal
				upper = 1;                   // -> not upper triangular
			if(i == j && mat[i][j] != 0)
				diagonal = 1;
		}
	}

	char result[100];
	strcpy(result, "special");

	// a matrix is lower/upper triangular if everything *below/above*
	// the diagonal is zero
	if(upper == 0 && lower == 0 && diagonal != 0)
		strcpy(result, "The matrix is diagonal");
	if(upper == 0 && lower != 0)
		strcpy(result, "The matrix is lower triangular");
	if(lower == 0 && upper != 0)
		strcpy(result, "The matrix is upper triangular");

	send(new_socket, result, strlen(result) + 1, 0);

	close(new_socket);
	close(sockfd);

	return 0;
}
