from sys import stdin


def main():
    q = int(stdin.readline())
    for qq in range(q):
        n , x = [int(x) for x in stdin.readline().split()]
        print(2*x)
        #l =  [i  for i in range(1,n+1)]
        #print(l)
        """
        i = 0
    
        while 1:
            if n>i:
             l.pop(i)
             n-=1
             i+=1            
            else:
                break
        print(l[x-1])
        """
main()