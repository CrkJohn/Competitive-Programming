from sys import stdin


def main():
    while 1:
        n = int(stdin.readline())
        if(n==-1):
            break
        str1 = stdin.readline().strip()
        str2 = stdin.readline().strip()
        print("Round {}".format(n))
        d = 0
        for st2 in str2:
            lonBefore = len(str1)
            str1 = str1.replace(st2,"")
            lonAfter = len(str1)
            if lonBefore == lonAfter:
                d+=1
            if(d==7 or lonAfter == 0):
                break    
        if(lonAfter == 0):
            print("You win.")
        elif(d==7):
            print("You lose.")
        else:
            print("You chickened out.")

main()
