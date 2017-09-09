#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

typedef unordered_map<string,int> strIntMap;
typedef unordered_map<int,string> intStrMap;

strIntMap months ({
		{"January", 0},
		{"February", 1},
		{"March", 2},
		{"April", 3},
		{"May", 4},
		{"June", 5},
		{"July", 6},
		{"August", 7},
		{"Semptember", 8},
		{"October", 9},
		{"November", 10},
		{"December", 11},
});

string days[] = {
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday",
	"hello"
};

string monthStr;
int year, day, month, Y, y, c, d, m, w=0;

int main(){
	cin >> day >> monthStr >> year;

	month = months[monthStr];
	Y = year;
    if (month < 3) Y--;
    y = Y % 100;
    c = ((int)(Y / 100)) % 100;
    d = day;
    m = ( (month - 2) < 1 ? month + 10 : month - 2 );
	w = (int)(d + ((2.6f*m) - 0.2f) + y + (y / 4) + (c / 4) - (2*c)) % 7;


    string t = days[(int)w];
    cout << "---" << w << "---\n";
    cout << "The day is: \n";
    cout << t;

}