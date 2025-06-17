#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "http/client.h"
#include "http/server.h"

using namespace std;

int main() {
	HttpServer server(8080);
	int serverSocket = server.getServerSocket();
	while (true) {
		HttpClient client(serverSocket);
		client.recvRequest();
		cout << client.getRequestBody() << endl;

	}
	return 0;
}
