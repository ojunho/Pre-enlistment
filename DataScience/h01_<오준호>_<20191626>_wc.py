# 첫번째 시도.
# stdin 으로 한줄씩 받으면서 strip(), regex 를 사용하여 문자열을 특수문자 없게, 깔끔한 문자열로 바꿈.
# 그 문자열을 split()한 결과(단어들)를 소문자 취해서 매번 새로운 Counter 를 만들고 += 연산을 통해서 계속 더해줌. (10분 이상)

# 두번째 시도.
# 첫번째 시도에서 += 연산 대신에 update 연산을 통해서 시간 단축을 했음. (약 2분 이상)

# 세번째 시도.
# 매번 새로운 Counter 객체를 만들지 않고, Generator 에서 작업을 전부 수행 하도록 짜고, Counter 객체에 한번에 넘길 수 있도록 작성함.
# Generator 는 매번 한줄(line)씩 받아오는데, 그 줄에서 단어(word)는 line 에서 특수문자를 없애고, split()한 배열을 돌며, 소문자로 바꿔서 넘긴다.

import sys
import re
from collections import Counter

# regex expression about SpecialCharacters, Korean
# korean = re.compile('[\u3131-\u3163\uac00-\ud7a3]+')
special = '[^\w\s]'

num_words = 1000

# Using Generator immediately
counter = Counter(word.lower()
                  for line in sys.stdin
                  for word in re.sub(special, ' ', line).split())

# Using update operation

# for line in sys.stdin:
#     # Cleaning spaces front and back of strings and spots at the end
#     # line = line.strip(".")
#
#     # cleaning SpecialCharacters, Korean
#     line = re.sub(special, ' ', line)
#     # line = re.sub(korean, ' ', line)
#
#
#     # too,, slow,,,
#     # Change all words into lowercase, put them on the 'words' list
#     # and 'words' list to Counter object.
#     # add existing Counter to the Counter receives one line each
#
#     # After switching from plus operation to update operation, the speed increased.
#     # counter += Counter([x.lower() for x in line.split()])
#
#     counter.update(Counter([x.lower() for x in line.split()]))

for word, count in counter.most_common(num_words):
    print("%s\t%d" %(word, count))