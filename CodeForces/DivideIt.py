from sys import stdin


def main():
    q = int(stdin.readline())
    for query in range(q):
        n = int(stdin.readline())
        c = 0
        while 1:
            if n % 5 != 0:
                break
            n  = 4*n// 5
            c+=1
        while 1:
            if n % 3 != 0:
                break
            n  = 2*n// 3
            c+=1
        while 1:
            if n % 2 != 0:
                break
            n  = n //2
            c+=1
        if n == 1:
            print(c)
        else:
            print(-1)
        


main()
