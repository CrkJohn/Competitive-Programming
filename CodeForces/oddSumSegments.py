from sys import stdin



def main():
    q = int(stdin.readline())
    for qq in range(q):
        n  , k = [int(x) for x in stdin.readline().strip().split()]
        arr = [int(x) for x in stdin.readline().strip().split()]
        particionesMax = n/m;
        ans = []
        tmp = 0
        for t in range(1,particiones):
            k = t
            while k!=n:
                prevSum = sum(arr[k:k+t])
                if prevSum%2 != 0:
                    
                



        print(*ans)
main()
