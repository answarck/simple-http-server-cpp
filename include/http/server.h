#include <netinet/in.h>
#include <unistd.h>

using namespace std;

class HttpServer {
	private:
		int serverSocket;
		sockaddr_in serverAddress;
	public:
		HttpServer(int port); 
		HttpServer(); 
		~HttpServer() { close(this->serverSocket); }
		int getServerSocket() { return this->serverSocket; }
		sockaddr_in getSocketConfig() { return this->serverAddress; }
};
