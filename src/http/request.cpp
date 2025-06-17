#include <http/request.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Request::Request(string rawRequest) {
	this->rawRequest = rawRequest;

	string line, word, key, value;
	bool isBody = false;
	istringstream stream(rawRequest);

	for (int i = 0; getline(stream, line); i++) {
		istringstream lineStream(line);
		if (i == 0) {
			for ( int k = 0; lineStream >> word; k++) {
				this->requestLine[k] = word;				
			}
		}		
		else {
			if (isBody) { 
				this->requestBody += line + "\n"; 
				cout << line << endl;
			}
			if (line.empty() || line == "\r"){ 
				isBody = true;
				continue;
			}
			if (getline(lineStream, key, ':') && getline(lineStream, value)) {
				value.erase(0, value.find_first_not_of(" \t"));
				this->header[key] = value;
			}
		}
	}
}
