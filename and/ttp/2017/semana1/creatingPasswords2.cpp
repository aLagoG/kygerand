//1905
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string basura;
	getline(cin,basura);
	while(n--){
		string line;
		getline(cin, line);
		vector<string> v = split(line, ' ');
		cout << v[0][0] << v[0][1];
		for(int i=v.size()-1;i>0;i--){
			cout << v[i] << (i!=1?"*":"");
		}
		cout << v[0][2] << v[0][3] << "\n";
	}
}