#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main(void){
    string line;
    ifstream myfile("aaa.txt");
    getline(myfile,line);
    stringstream call_line;
    call_line << "curl.exe -b cookie.txt -d test=" << line << "  http://example.com";
    system(call_line.str().c_str());
}