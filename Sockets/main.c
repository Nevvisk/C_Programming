#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#define PORT 8080

int main () {
	int server_fd, new_socket;
	struct sockaddr_in address;
	socklen_t addrlen = sizeof(address);
	char buffer[1024] = {0};

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	inet_pton(AF_INET, "0.0.0.0", &address.sin_addr);

	if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
		perror("bind faild");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 10) < 0) {
		perror("listen failed");
		exit(EXIT_FAILURE);
	}

	int cfd = accept(server_fd, &address, &addrlen); 
	
	if (cfd < 0) {
		perror("accept failed");
		exit(EXIT_FAILURE);
	}	

	//send a message to the socket
	write(cfd, "Hello\n", 6);

	int close_result = close(server_fd);
	if (close_result < 0) {
		perror("close failed.");
		exit(EXIT_FAILURE);
	}
	return 0;
}

