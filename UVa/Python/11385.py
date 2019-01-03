from sys import stdin
import re

global fib
fib = list()

def FIB():
   fib.append(1)
   fib.append(2)
   i = 2
   while(1):
        fib.append(fib[i-1]+fib[i-2])
        if(fib[i]>2**31):break;
        i+=1
        
def main():
    FIB()
    ntc = int(stdin.readline().strip())
    while(ntc):
        lon = int(stdin.readline().strip())
        fib_arr = [int(x) for x in stdin.readline().strip().split()]
        string_ = list(re.sub("[^A-Z]","",stdin.readline().strip()))
        dic = {}
        for i in range(lon):
            dic[fib_arr[i]]= string_[i]
        fib_arr.sort()
        maxi = fib_arr[lon-1];
        i = 0;
        buffer = ""
        #print(maxi)
        while(fib[i]<=maxi):
            buffer+=dic.get(fib[i]," ")
            i+=1
        print(buffer)
        ntc-=1
main()
