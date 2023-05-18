// 재귀적 알고리즘.
// 인자로 탐색할 리스트, 찾을 숫자, 왼쪽 인덱스, 오른쪽 인덱스를 넣어준다.

int reSearch(int list[], int obj, int left, int right){
  if(right >= left){
    // 중간점을 설정해준다.
    int mid = (left + right)/2;

    if(list[mid] == obj){
      return mid;
    }
    // 영역에 따라서 다시 검사할 부분을 인자로 넣어 재귀함수를 호출한다.
    if(list[mid] > obj){
      return reSearch(list, obj, left, mid - 1);
    }
    return reSearch(list, obj, mid + 1, right);
  }
  return -1;
}
