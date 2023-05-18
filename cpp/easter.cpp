/* Problems: 부활절 구하기
소프트웨어학부 20191626 오준호 */
#include <iostream>
using namespace std;

int main(){
  int numCase;
  cin >> numCase;

  int Y;
  for(int i=0; i<numCase; i++){
    cin >> Y;
    int C = Y/100;
    int N = Y - (Y/19*19);
    int T = (C-17)/25;
    int I = C - C/4 - (C-T)/3 + N*19 + 15;
    int J = I-I/30*30;
    int K = J - (J/28 * (1-J/28) * 29/(J+1) * (21-N)/11);
    int L = Y + Y/4 + J + 2 - C + C/4;
    int P = L - L/7*7;
    int Q = K - P;
    int M = (Q+40)/44 + 3;
    int D = Q + 28 - (M/4*31);

    cout << M << " " << D << endl;

  }
  return 1;
}
