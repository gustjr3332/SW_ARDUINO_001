/* <c++>
cin,cout 기본 사용법
#include <iostream>

using namespace std;

int main(void) {

    unsigned int A, B;

    std.cin >> A >> B; ->입력cin

   std. cout << A + B << "/n"; ->출력 c out
    //cout << A - B << endl; -> 가능

    return 0;
}*/
#include<iostream>

using namespace std;

int c_main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << "Hello Sejong!" << endl;
      }
    return 0;
}