#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345

void translate(char *word){
	struct {
		char *abbr;
		char *full;
	} dict[] = {
		{"idc", "i dont care"},
		{"ig", "I guess"},
		{"tbf", "to be fair"},
		{"atm", "at the moment"},
		{"irl", "in real life"},
		{"lol", "laughing out loud"},
		{"asap", "as soon as possible"},
		{"omg", "oh my God"},
		{"ttyl", "talk to you later"},
		{"idk", "I don't know"},
		{"nvm", "never mind"},
	};
	int ndict = sizeof(dict) / sizeof(dict[0]);

	char result[1024] = "";
	char temp[100];
	int i = 0;

	while(sscanf(word + i, "%99s", temp) == 1){
		int found = 0;
		for(int j = 0; j < ndict; j++){
			if(strcmp(temp, dict[j].abbr) == 0){
				strcat(result, dict[j].full);
				found = 1;
				break;
			}
		}
		if(!found){
			strcat(result, temp);
		}

		strcat(result, " ");
		i = i + strlen(temp);

		while(word[i] == ' ')
			i++;
	}
	strcpy(word, result);
}

int main(){
	int sockfd;
	char buffer[1024];
	struct sockaddr_in server_addr, client_addr;
	socklen_t len;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);

	bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

	printf("UDP server running\n");

	len = sizeof(client_addr);

	recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &len);

	printf("Message received\n");

	translate(buffer);

	sendto(sockfd, buffer, strlen(buffer) + 1, 0, (struct sockaddr*)&client_addr, len);
	close(sockfd);
	return 0;
}
