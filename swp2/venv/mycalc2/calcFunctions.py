from math import factorial as fact

romans = [
        (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
        (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
        (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'),
        (1, 'I')
    ]


romans_list = [x[1] for x in romans]


def factorial(numStr):
    try:
        n = int(numStr)
        r = str(fact(n))
    except:
        r = 'Error!'
    return r


def decToBin(numStr):
    try:
        n = int(numStr)
        r = bin(n)[2:]
    except:
        r = 'Error!'
    return r


def binToDec(numStr):
    try:
        n = int(numStr, 2)
        r = str(n)
    except:
        r = 'Error!'
    return r


def decToRoman(numStr):
    try:
        n = int(numStr)
    except:
        return 'Error!'

    if n >= 4000:
        return 'Error!'



    result = ''
    for value, letters in romans:
        while n >= value:
            result += letters
            n -= value

    return result


def romanToDec(numStr):

    splitList = list(numStr)
    for i in splitList:
        if not i in romans_list:
            return "Put in the right Roman alphabet"
            break

    # if numStr.isdit:
    #     print(int(numStr))
    #     print("a")
    #     return "Put in the Roman alphabet

    else:

        Copy_n = numStr[:] #객체를 복사해옴.

        n = numStr



        result = 0
        for value, letters in romans:
            #while letters in n:
            #자꾸 이상하케 나왔움.

            while n.find(letters) == 0:
                result += value


                # 멍청했다.

                # if len(letters) == 2:
                #     n = n[2:]
                # else:
                #     n = n[1:]

                n = n[len(letters):]



        if decToRoman(result) != Copy_n:
            return "Put the right content in"

        result = str(result)
        return result

