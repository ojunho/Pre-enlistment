/* 소프트웨어학부 20191626 오준호
Problems 정수의 합 구하기 */

#include <iostream>
using namespace std;

int main(){
    int numCase;
    cin >> numCase;

    int numData, data;

    for(int i=0; i<numCase; i++){
      int sum = 0;
      cin >> numData;

      for(int j=0; j<numData; j++){
        cin >> data;
        sum += data;
      }
      cout << sum << endl;
    }
    return 1;

}
