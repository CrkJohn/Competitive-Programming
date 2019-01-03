from sys import stdin


def main():
    while True:
        dim = int(stdin.readline().strip())
        arr = list()
        flag = False
        for i in range(dim):
            arr.append(list(stdin.readline().strip()))
        while True:
            sSearch = stdin.readline().strip()
            if(sSearch[0]=="0"):break
            print(buscar(sSearch,dim,arr))
            
        break

def buscar(sSearch,dim,arr):
    ax = [0,1,-1,0, 1,1,-1,-1]
    ay = [1,0,0,-1, 1,-1,1,-1]
    for i in range(dim):
        for j in range(dim):
            for u in range(8):
                h = i
                k = j
                lon = 0
                while(sSearch[lon]==arr[h][k]):
                    #print(sSearch[lon],arr[h][k],u)
                    h = h + ax[u]
                    k = k + ay[u]
                    lon+=1
                    if(lon==len(sSearch)-1 and sSearch[lon]==arr[h][k]):
                        #print(arr)
                        a = ("{},{} {},{}".format(i+1,j+1,h+1,k+1))
                        return a
                    if not(lon<dim and k>=0 and k<dim and h>=0 and h<dim):
                           break
                    
                   

    return "Not found"     
                    
                    
main()
