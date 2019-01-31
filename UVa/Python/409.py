from sys import stdin
import re


def main():
        ntc = 1
        while 1:
             a = stdin.readline().strip()
             if(not a):
                  break
             n , m  = [int(x) for x in a.split()]
             keywords = []
             for i  in range(n):
                  keywords.append(stdin.readline().strip())
             excuses  = []
             for i in range(m):
                  excuses.append(stdin.readline().strip())
             maximoConcidencias  = []
             print("Excuse Set #{}".format(ntc))
             ntc+=1
             for  ex in  excuses:
                    count = 0
                    ex2 = re.sub(r'[^A-Za-z]',' ',ex)
                    for e in ex2.split():
                          for keys in keywords:
                            
                                if(e.lower() == keys.lower()):
                                        count+=1
                    maximoConcidencias.append(count)
             maximoCon = max(maximoConcidencias)
             for t in range(m):
                     if maximoConcidencias[t] == maximoCon:
                             print(excuses[t])
             print()
                    
main()
