from sys import stdin


n, m =  [int(x) for x in stdin.readline().strip().split()]
m-=1;
for i in range(1,n+1):
    if i%4==0:
        print('#'+str("."*m))
    elif i%2==0:
        print(str("."*m)+'#')
    else:
        print("#"*(m+1))
    
    
