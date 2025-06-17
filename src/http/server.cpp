#include <sys/socket.h>
#include "http/server.h"

HttpServer::HttpServer(int port) {
	this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	this->serverAddress.sin_family = AF_INET;
	this->serverAddress.sin_port = htons(port);
	this->serverAddress.sin_addr.s_addr = INADDR_ANY;

	bind(this->serverSocket, (sockaddr *) &this->serverAddress, sizeof(this->serverAddress));
	listen(this->serverSocket, 5);
}

HttpServer::HttpServer() {
	this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	this->serverAddress.sin_family = AF_INET;
	this->serverAddress.sin_port = htons(80);
	this->serverAddress.sin_addr.s_addr = INADDR_ANY;

	bind(this->serverSocket, (sockaddr *) &this->serverAddress, sizeof(this->serverAddress));
	listen(this->serverSocket, 5);
}

