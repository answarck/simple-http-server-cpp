#include <string>
#include <unordered_map>

using namespace std;

class Request {
	private:
		string requestLine[3], requestBody, rawRequest;
		unordered_map<string, string> header;
	public:
		Request() = default;
		Request(string rawRequest);
		string getRequestMethod() { return this->requestLine[0]; }
		string getRequestLocation() { return this->requestLine[1]; }
		string getHttpVersion() { return this->requestLine[2]; }
		string getRequestBody() { return this->requestBody; }
		string getRawRequest() { return this->rawRequest; }
};
