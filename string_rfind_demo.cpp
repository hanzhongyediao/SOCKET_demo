/*test for rfind function*/
#include <iostream>
#include <string>
using namespace std;
int main(void){
	string a = "www.baidu.com/index.html";
	int n = a.rfind("com");
	string b(a.begin()+n, a.end());
	cout<<b<<endl;
	return 0;
}
