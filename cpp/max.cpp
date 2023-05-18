/* Problems: 주어진 정수중에서 최댓값과 최솟값을 구하기.
소프트웨어학부 20191626 오준호 */

#include <iostream>
using namespace std;

int main(){
  int numCase;
  cin >> numCase;

  for(int i=0; i<numCase; i++){
    int numData;
    cin >> numData;
    int arr[numData];
    for(int j=0; j<numData; j++){
      int Data;
      cin >> Data;
      arr[j] = Data;
    }
    int min = arr[0];
    int max = arr[0];
    for(int k=0; k<numData-1; k++){
      if(arr[k+1]<min){
        min = arr[k+1];
      }
      if(arr[k+1]>max){
        max = arr[k+1];
      }
    }
    cout << max << " " << min << endl;
  }
  return 0;
}
