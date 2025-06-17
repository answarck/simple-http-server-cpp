#include <string>
#include <unistd.h>
#include "http/request.h"

using namespace std;

class HttpClient {
	private:
		int clientSocket;
		Request request;
	public:
		HttpClient(int serverSocket); 
		~HttpClient() { close(this->clientSocket); }
		int getClientSocket() { return this->clientSocket; }	
		Request getRequest() { return this->request; }
		void recvRequest();
};	
