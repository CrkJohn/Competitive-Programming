from sys import stdin
from math import *


def main():

    strN = (stdin.readline().strip())
    sumaN = sum([int(x) for x in list(strN)])
    if(sumaN%4 == 0):
        print(strN)
    else:
        i = int(strN)
        while 1:
            string = str(i+1)
            r = sum([int(x) for x in list(string)])
            if(r%4 == 0):
                print(string)
                break
            i+=1

main()
