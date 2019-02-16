from sys import stdin
import random

def main():
         nx = 10
         print(nx)
         for i in range(nx):
                 n  = random.randint(1,6)
                 m  = random.randint(1,6) 
                 print(n,m)
                 for ii in range(n):
                    for j in range(m):
                         print(random.randint(1,20), end =" ")
                    print()
main()
