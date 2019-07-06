from sys import stdin
import math


def main():    
    lon = int(stdin.readline().strip())
    string = stdin.readline().strip()
    if string.count('1')!=string.count('0'):
        print(1)
        print(string)
    else:
        print(2)
        print(string[0:lon-1],string[lon-1])
main()

