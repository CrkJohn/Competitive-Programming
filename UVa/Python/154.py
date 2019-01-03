from sys import stdin
import collections
global dic,dic2
import operator




dic =  {"r":0 ,"o":1 ,"y":2 ,"g":3 ,"b":4}
dic2 = {"P":0 ,"G":1 ,"S":2 ,"A":3 ,"N":4}
def main():
    while(True):
        matriz = list()
        string = stdin.readline().strip()
        if(string[0]=="#"):break
        matriz.append(string.split(","))
        while(True):
            string = stdin.readline().strip()
            if(string[0] == "e"):break
            matriz.append(string.split(","))
        lon = len(matriz)
        comp = [[0 for i in range(5)] for j in range(lon)]
        for i in range(lon):
            for j in range(5):
                comp[i][ dic2[matriz[i][j][2]] ] =  dic[matriz[i][j][0]]
        i = 0
        res = dict()
        for i in range(lon):
            diferencia = 0
            for j in range(lon):
                if(i!=j):
                    for k in range(5):
                         if(comp[i][k]!=comp[j][k]):
                             diferencia+=1

            res[i] = diferencia
        resultado = sorted(res.items(), key=operator.itemgetter(1))
        print(resultado[0][0]+1)
    

main()         

