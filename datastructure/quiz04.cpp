// 찾고 싶은 피보나치 수 값을 넣어준다.
int fibonacci(int n){
  if(n<=1){
    return n;
  }
  else{
    return(fibonacci(n-1)+fibonacci(n-2));
  }
}
