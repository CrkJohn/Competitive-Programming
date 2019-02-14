from sys import stdin
import random

def main():
         nx = 10
         for i in range(nx):
                 n  = random.randint(1,10)
                 m  = random.randint(1,10) 
                 print(n,m)
                 for ii in range(n):
                    for j in range(m):
                         print(random.randint(1,20), end =" ")
                    print()
main()
