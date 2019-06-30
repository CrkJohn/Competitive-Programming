from sys import stdin


def main():
    t = int(stdin.readline())
    for query in range(t):
        n = int(stdin.readline())
        ln = [int(x) for x in stdin.readline().strip().split()]
        divise = [0]*3
        for numbers in ln:
            divise[numbers%3]+=1
        resultado = divise[0] # Todo modulo 3
        minimo = min(divise[1],divise[2])
        resultado+=minimo
        divise[1]-=minimo
        divise[2]-=minimo
        print(divise)
        resultado+=(divise[1]+divise[2])//3
        print(resultado)
        
   
        


main()
