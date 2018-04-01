import sys

global fib
fib = list()


def FIB():
    fib.append(1)
    fib.append(2)
    for i in range(2,105):
        fib.append(fib[i-1]+fib[i-2])

def decimal(a):
    n = 0
    lon = len(a)
    for i in  range(lon):
        if(a[i]=='0'):
            m = 0
        else:
            m = 1
        n+=(m* fib[lon-i-1])
    return n

def lb(target):
    l, r = 0, len(fib) - 1
    while l <= r:
        mid = l + (r - l) //2
        if fib[mid] >= target:
            r = mid - 1
        else:
            l = mid + 1
    return l

def main():
    FIB()
    flang_print = 0
    c = 1
    while(1):   
       n = sys.stdin.readline().strip()
       if not(n):break
       if(flang_print):print()
       flang_print = 1
       n_ = sys.stdin.readline().strip()
       sys.stdin.readline().strip()
       suma = decimal(n) + decimal(n_)
       flang = 0
       maxi  = 0
       res = ["0" for i in range(0,101)]
       if(suma==0):print(0)
       else:
            
            while(True):
                ind = lb(suma)
                if(fib[ind]>suma):ind-=1
                if not(flang): maxi = ind
                flang = 1
                res[ind] = "1"
                if(fib[ind] == suma or ind<=0 ):break;
                suma = suma-fib[ind]
            l = res[0:maxi+1]
            l.reverse()
            print("".join(l))
            flang_print = 1
           
main()
