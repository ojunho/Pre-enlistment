
##
def solution(s, n):
    answer = ''
    for i in s:

        if 97 <= (ord(i) + n) <= 122:
            a = str(chr(ord(i) + n))
            answer += a

        elif ord(i) + n > 122:
            a = str(chr(97 + (n - 1)))
            answer += a

        elif 65 <= (ord(i) + n) <= 90:
            a = str(chr(ord(i) + n))
            answer += a

        elif ord(i) == 32:
            answer += i

        else:
            a = str(chr(65 + (n - 1)))
            answer += a

    return answer


##
def solution(s, n):
    s = list(s)  # s 문자열을 리스트로 만들어준다.

    for i in range(len(s)):

        if s[i].isupper():  # 대문자라면

            s[i] = chr((ord(s[i]) - ord('A') + n) % 26 + ord('A'))

            # 위와 같은 방식을 사용하는데 ord를 통해 아스키코드로 변환한다.

        elif s[i].islower():

            s[i] = chr((ord(s[i]) - ord('a') + n) % 26 + ord('a'))

    answer = "".join(s)

    return answer


##
def solution(s, n):
    answer = ''

    for i in s:
        if i.isupper():
            if ord(i) + n > ord('Z'):
                answer += chr(ord('A') + (n - 1))
            else:
                answer += chr(ord(i) + n)
        elif i.islower():
            if ord(i) + n > ord('z'):
                answer += chr(ord('a') + (n - 1))
            else:
                answer += chr(ord(i) + n)
        else:
            answer += ' '

    return answer