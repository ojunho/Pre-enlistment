def solution(answers):
    answer = []
    Arr1 = [1, 2, 3, 4, 5] * 2000
    Arr2 = [2, 1, 2, 3, 2, 4, 2, 5] * 1250
    Arr3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5] * 1000

    tmp1 = 0
    for i in range(len(answers)):
        if answers[i] == Arr1[i]:
            tmp1 += 1
    answer.append(tmp1)

    tmp2 = 0
    for i in range(len(answers)):
        if answers[i] == Arr2[i]:
            tmp2 += 1
    answer.append(tmp2)

    tmp3 = 0
    for i in range(len(answers)):
        if answers[i] == Arr3[i]:
            tmp3 += 1
    answer.append(tmp3)

    first_max = 0
    idx_list = []
    max_list = []
    for i in range(3):
        if answers[i] > first_max:
            first_max = answers[i]
            idx_list.append(i + 1)
            del idx_list[i]

        elif answers[i] == first_max:
            idx_list.append(i + 1)

    idx_list.sort()
    answer = idx_list

    return answer

if __name__ == "__main__":
    solution([3, 2, 1, 4, 2, 5, 4, 3, 2, 1])