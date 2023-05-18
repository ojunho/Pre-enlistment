import time

def fibo(n):
	a = 0
	b = 1
	for i in range(n-1):
		c = a + b
		a = b
		b = c
	return c

while True:
	n = int(input("몇 번째 수를 구하고 싶으신가요?> "))
	ts = time.time()
	
	if n == 0:
		c = 0
	
	elif n == 1:
		c = 1
	
	elif n == -1:
		break
	else:
		c = fibo(n)
		

	print("%d 번째 피보나치 수는 %d 입니다." %(n,c))
	print("걸린 시간은 : ", time.time() - ts)


