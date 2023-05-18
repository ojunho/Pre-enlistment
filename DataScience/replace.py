import re

text = """안녕하세요.0.00012????3, whicㅎh corresponds to a distance of 705 Mly, or 216 Mpc.
000webhost is a free web hosting service, operated by Hostinger.
0010x0010 is a Dutch-born audiovisual artist, currently living in Los Angeles.
0-0-1-3 is an alcohol abuse prevention program developed in 2004 at Francis E. W
arren Air Force Base based on research by the National Institute on Alcohol Abus
e and Alcoholism regardi??????ng binge drinking in college students.
0.01 is the debut studio album of H3llb3nt, released on February 20, 1996 by Fif
th Colvmn Records.
001 of 3 February 1997, which was signed between the Government of the Republic
of Rwanda, and FAPADER.
003230 is a South Korean food manufacturer.
0.04%Gas molecules in soil are in continuous thermal motion according to the kin
etic theory of gasses, there is also collision between molecules - a random walk
.
0.04% of the votes were invalid.
005.1999.06 is the fifth studio album by the South Korean singer and actress Uhm
 Jung-hwa.
005 is a 1981 arcade game by Sega.
007 Legends is a first-person shooter video game featuring the character of Brit
ish secret agent J?????ames Bond.
007 Legends is the fourth and final James Bond game title released by Activision
, the last game Eurocom developed before the company ceased operations and also
the last James Bond video game to be available on home video game systems, to da
te.????
"""

pattern = '[^\w\s]'
korean = re.compile('[\u3131-\u3163\uac00-\ud7a3]+')

# cleaning SpecialCharacters, Korean
result = re.sub(pattern, ' ', text)
result = re.sub(korean, ' ', result)
print("result: ", result)

words = [x.lower() for x in result.split()]
print(words)