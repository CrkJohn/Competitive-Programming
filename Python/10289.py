from sys import stdin

def main():
    #T = "ACACABACACABACACAC"
    #P = "ACA"
    #kmp(T,P)
    while True:
        T = stdin.readline().strip()
        if not(T):break
        arr = "".join(reversed((list(T))))
        j = kmp(T,arr)
        if(0 == j):
            print(T)
        else:
            print(T+("".join(((list(arr[j:]))))) )

def kmp(T , P):
    n = len(T) ; m = len(P)
    fail =  f(P)
    i ,j  , cont =  0 , 0 , 0
    while i < n:
         while(j>=0  and T[i]!=P[j]):j = fail[j]
         i+=1 ; j+=1
         if(j == m):
            j = fail[j]
            cont+=1
            # j = fail[j-1] si quiero tomar una aparicion partiendo desde mi ultimo match
    return j

def f(string):
    m =  len(string)
    arrF = [0 for x in range(m+1)]
    j = -1
    for  i in range(m):
        #Compresion en el arreglo de los fallos
        arrF[i] = arrF[j] if(string[i]==string[j] and j>=0) else j
        #if(j>=0):arrF[i] = j
        while(j>=0 and string[i]!=string[j]): j = arrF[j]
        j+=1
    return arrF
main()
        
        

