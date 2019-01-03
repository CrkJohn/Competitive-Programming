from sys import stdin

def change_A(A,i_,j_):
    x = [0,0,-1,1]
    y = [-1,1,0,0]
    for i in  range(4):
        h=i_ + x[i];  k = j_ + y[i]
        if(h>=0 and h<10 and k>=0 and k<10):
            A[h][k] = '#' if(A[h][k] == 'O') else "O"
    A[i_][j_] = '#' if(A[i_][j_] == 'O') else "O"
    return A
        
def f(A,i,j,c):
    global l
    if(l<c): return
    if(j==10):
        i+=1;
        j = 0
    if(i==0):
        f(A,i,j+1,c);
        A = change_A(A,i,j)
        f(A,i,j+1,c+1)
        A = change_A(A,i,j)            
    elif(i==10):
        for i_ in range(10):
            if(A[9][i_]!="#"):
                return
        l = min(c,l)
    else:
        if(A[i-1][j]=='O'):        
            A = change_A(A,i,j)
            f(A,i,j+1,c+1)
            A = change_A(A,i,j)
        else:
            f(A,i,j+1,c)
def main():
    global l
    flang = 0
    while True:
        Lights = list()
        if(not(flang)):name = stdin.readline().strip()
        else: name = light
        while True:
            light = stdin.readline().strip()
            if(light[0]!='O' and light[0]!='#'):break;
            Lights.append(list(light))
        flang = 1
        l = float("inf");
        f(Lights,0,0,0)
        print(name,-1 if(l==float("inf")) else l)
        if(light=='end'):break;
        
main()
