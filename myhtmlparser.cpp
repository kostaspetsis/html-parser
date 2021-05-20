#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <cctype>
#include <algorithm>
using std::cout; using std::vector;
using std::endl; using std::string;
using std::copy;
using namespace std;

#define DEFAULT_WIDTH 100
#define DEFAULT_HEIGHT 40

class Style{
public:
	int width=DEFAULT_WIDTH,height=DEFAULT_HEIGHT;
};
class Element{
public:
	enum Tag {HTML=0,HEAD,BODY,DIV,H1,H2,H3,H4,P,SPAN,META,TITLE,LINK,SCRIPT};
	Style style;
};
class Parser{
public:
	Parser(){

	}
	void Parse(string code){
		std::stringstream ss(code);
		std::string to;

		// if (code != NULL)
		// {
			while(std::getline(ss,to,'\n')){
				cout << to <<endl;
				std::string s = to;
				std::string delimiter = ">";
				std::string token = s.substr(0, s.find(delimiter)); // token is "scott"

				token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
				// #include <algorithm>
				if(token.find("/")){
					cout << "Found closing tag(/).Removing it..."<<endl;
				}
				token.erase(std::remove(token.begin(), token.end(), '/'), token.end());
				cout << "TOKEN="<<'"'<<&token[1]<<'"'<<endl;
			}
		// }
		
	}
};
int main(int argc, const char** argv) {
	// string code="<!DOCTYPE html>\n\
	// dsd";
	// "<html>"
	// "<head>"
	// "	<meta charset=\"utf-8\" />"
	// "	<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">"
	// "	<title>Page Title</title>"
	// "	<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
	// "	<link rel=\"stylesheet\" type=\"text/css\" media=\"screen\" href=\"main.css\" />"
	// "	<script src=\"main.js\"></script>"
	// "</head>"
	// "<body>"
	// "	"
	// "</body>"
	// "</html>";
	string code="<!DOCTYPE html>\n\
	<html>\n\
	<head>\n\
		<meta charset=\"utf-8\" />\n\
		<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n\
		<title>Page Title</title>\n\
		<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n\
		<link rel=\"stylesheet\" type=\"text/css\" media=\"screen\" href=\"main.css\" />\n\
		<script src=\"main.js\"></script>\n\
	</head>\n\
	<body>\n\
	</body>\n\
	</html>";

	Parser parser;
	parser.Parse(code);
	return 0;
}

