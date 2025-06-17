#include <sys/socket.h>
#include "http/client.h"

HttpClient::HttpClient(int serverSocket) {
	this->clientSocket = accept(serverSocket, nullptr, nullptr);
}

void HttpClient::recvRequest() {
	char buffer[1024];
	size_t bytesRecieved = recv(this->clientSocket, buffer, sizeof(buffer), 0);
	if (bytesRecieved > 0) {
		this->request = string(buffer, bytesRecieved);
	}
}
