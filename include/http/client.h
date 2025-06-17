#include <string>
#include <unistd.h>

using namespace std;

class HttpClient {
	private:
		int clientSocket;
		string request;
	public:
		HttpClient(int serverSocket); 
		~HttpClient() { close(this->clientSocket); }
		int getClientSocket() { return this->clientSocket; }	
		string getRequestBody() { return this->request; }
		void recvRequest();
};	
