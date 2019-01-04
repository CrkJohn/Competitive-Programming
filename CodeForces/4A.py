from sys import stdin


def  main():
         n = int(stdin.readline().strip())
         if(n%2 == 0 and n >2) :
                print("YES")
         else:
                print("NO")
main()
