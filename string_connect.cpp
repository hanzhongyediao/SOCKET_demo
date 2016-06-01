/*test string d = "find "+ b*/
#include <iostream>
#include <string>
using namespace std;
int main(void){
	string a = "aaaaaaaaaaaaaaaaaaaaa";
	string b = "bbbb";
	string c = "cccc";
	string d;
	d = " "+b+" "+c;
	cout<<d<<endl;
	return 0;
}
/*代码能够编译通过是因为对" "中的字符串进行了隐士转换。*/
