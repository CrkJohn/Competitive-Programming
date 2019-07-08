import random
import string

for k in range(100):
    n = random.randint(1,500)
    q = random.randint(1,51) 
    print(n,q)
    letters = string.ascii_letters.lower()
    stringLength = 100
    for i in range(n):
        print(random.choice(letters),random.choice(letters))

    for j in range(q):
        print(''.join(random.choice(letters) for i in range(stringLength)),''.join(random.choice(letters) for i in range(stringLength)))