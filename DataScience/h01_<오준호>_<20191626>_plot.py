#**************************************************************************************************************
# list_k: 원래의 k 값들을 담는 배열(즉 원래의 x값). 1~1000까지의 값을 갖는다. [1, 2, 3, 4, ... 1000]
# list_n: 원래의 n 값들을 담는 배열(즉 원래의 y값). 단어의 출현 횟수를 담는다. [10846785, 5348160,  ... 17814]

# res_c: 구해야 하는 c값을 담는 변수. c의 결과는 첫번째로 많이 등장한 단어(the)의 출현횟수이다.
#       지프의 법칙 원래 식(n = c*k**(-s))에서 k == 1 일 때의 n 값이 c 값이기 때문이다.
# res_s: 구해야 하는 s값을 담는 변수. 지프의 법칙 원래 식의 양변에 로그를 취하면 log(n) = -s* log(k) + log(c) 이기 때문에,
#       원래의 그래프의 x, y에 대해서 로그스케일 취한 그래프의 그래프의 기울기이다. (-s)가 기울기.

# 기울기를 구한 방법 : 결과가 나온 x(k), y(n) 값들에 전부 상용로그를 취해서 값들을 얻어서 배열을 만들었다. 그 배열에서 한 인덱스씩 차이나는
#      값들의 차이 (바로 다음 값과의 차이)를 담는 배열을 만들었다. x, y 값들의 차이 배열 두개를 zip 해서 (y의 증가량)/ (x의 증가량)을 활용해
#       한칸마다 기울기 조각을 구해서 그 조각들의 평균으로 전체 그래프의 기울기를 측정했다.

# 코드를 작성할 때, 처음에는 plot 에서는 그냥 scale만 log로 해주었는데, 위의 과정으로 기울기를 구하면서 원래의 값들에 상용로그 취한 값들을 알아내기
# 때문에, 그래프도 구한 로그 값 배열을 활용하여 그려주었다.

# log_k: list_k 배열의 값들에 상용로그를 취한 값들을 담는 배열.
# log_n: list_n 배열의 값들에 상용로그를 취한 값들을 담는 배열.

# gap_k: log_k 배열의 바로 다음 원소와의 차잇값을 담는 배열.
# gap_n: log_n 배열의 바로 다음 원소와의 차잇값을 담는 배열.

# slope_fragment: gap_k, gap_n 배열을 활용하여 구한 (y의 증가량)/ (x의 증가량) 조각들을 담는 배열.
#**************************************************************************************************************

from matplotlib import pyplot as plt
import sys
import math

num_data = 1000
list_k = [k for k in range(1, num_data + 1)]
list_n = [int(line.split()[1]) for line in sys.stdin]

# def cal_cs(k, n):
#     c = n[0]
#     print(c)
#
#     log_k = [round(math.log(x_k), 2) for x_k in k]
#     log_n = [round(math.log(y_n), 2) for y_n in n]
#
#     gap_k = [log_k[i+1] - log_k[i] for i in range(len(log_k)-1)]
#     gap_n = [log_n[i+1] - log_n[i] for i in range(len(log_n)-1)]
#
#
#     slope_fragment = [round(y/x, 2) for x, y in zip(gap_k, gap_n)]
#     # for x, y in zip(gap_k, gap_n):
#     #     slope_fragment.append(y/x)
#
#     print("slope_fragment: ", slope_fragment)
#     s = sum(slope_fragment)/len(slope_fragment)
#     s = -1*s
#     print(s)
#
#     # return str(c), str(s)
#     return

res_c = list_n[0]
log_k = [round(math.log10(x_k), 3) for x_k in list_k]
log_n = [round(math.log10(y_n), 3) for y_n in list_n]

gap_k = [log_k[i+1] - log_k[i] for i in range(len(log_k)-1)]
gap_n = [log_n[i+1] - log_n[i] for i in range(len(log_n)-1)]

slope_fragment = [round(y/x, 3) for x, y in zip(gap_k, gap_n) if x!=0]

s = sum(slope_fragment)/len(slope_fragment)
res_s = -1 * s
print("C: %d\nS: %f" %(res_c, res_s))

plt.plot(log_k, log_n, 'co--')
plt.title("log(n) = (-s)*log(k) + log(c)")
plt.ylabel("log(n)")
plt.xlabel("log(k)")
plt.savefig("h01_<오준호>_<20191626>_plot.png")
plt.show()