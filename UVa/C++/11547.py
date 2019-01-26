from sys import stdin



def main():
    ntc = int(stdin.readline())
    for i in range(ntc):
        n = int(stdin.readline())
        res = (((((n*567)//9)+7492)*235)//47)-498
        s = ""
        if(res<0):res= abs(res)
        s =   str(res)
        print(s[-2])
main()
