import time
while True:
	nbr = int(input("Enter a number : "))
	if nbr == -1 :
		break
	ts = time.time()
	fibonumber = iterfibo(nbr)
	ts = time.time() - ts
	print("IterFibo(%d) = %d, time %.6f" %(nbr, fibonumber, ts))
	ts = time.time()
	fibonumber = fibo(nbr)
	ts = time.time() - ts
	print("Fibo(%d) = %d, time %.6f" %(nbr, fibonumber, ts))


