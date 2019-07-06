from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(9000)



def back(ind,vis,final):
    global lon,arr,find
    #print(final)
    if find:
        return 
    if ind == lon-1:
        if final[0]+final[lon-2] > final[lon-1] and final[lon-1]+final[1]>final[0]:       
            find = True
            print("YES")
            print(*final)
        return 
    else:        
        for i in range(ind,lon):
            num = final[ind]
            prev = final[ind-1]
            for k in range(lon):
                if not vis[k] and prev+arr[k]>num:
                    #print("prev",prev," k ",arr[k])
                    final[ind+1] = arr[k]
                    vis[k] = 1
                    back(ind+1,vis,final)
                    vis[k] = 0
        

def main():
    global lon,arr,find
    lon = int(stdin.readline().strip())
    arr = [int(x) for x in stdin.readline().strip().split()]
    vis = [0]*lon
    find = False
    for i in range(lon):
        for j in range(i+1,lon):
            final = [0]*lon
            final[0] = arr[i]
            vis[i]  = 1
            vis[j]  = 1
            final[1] = arr[j]
            back(1,vis,final)
            vis[i]  = 0
            vis[j]  = 0
            if find:
                break
        if find:
            break
    if not find:
        print("NO")

main()
