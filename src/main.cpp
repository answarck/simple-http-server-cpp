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
		// cout << client.getRequest().getRawRequest() << endl;
		// cout << client.getRequest().getRequestBody() << endl;

	}
	return 0;
}
