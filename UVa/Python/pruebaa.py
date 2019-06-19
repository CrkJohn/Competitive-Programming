from sys import stdin
from math import sqrt

global sqrt32
sqrt32 = sqrt(3)/2

"""
3040 682
2528 184
2119 352
1704 8027
"""

def solve(n):
    if (n == 0):
        return (0,0)
    i = 0 ; nvl = 0
    while 1:
        i = i + (nvl+1)
        maxValueFigure = (i)*6
        if(n<=maxValueFigure):
            break
        nvl+=1
    nvl+=1
    #print("nivel ", nvl)
    cx = 0.5*nvl;cy = -sqrt32*nvl
    #print(cx,cy,nvl)
    identifyVertex = 1
    for i in range(1,7):
        if maxValueFigure-nvl<n  and n <=maxValueFigure:
            identifyVertex = i
            break
        maxValueFigure-=nvl
    #print("identify , maxFigure",identifyVertex,maxValueFigure,nvl)
    #vertex1
    if  identifyVertex == 1:
        if n == maxValueFigure:
            return (cx,cy)
        cx = -cx
        cx += ((n-(maxValueFigure-nvl))) 
        return (cx,cy)
    #vertex2
    if  identifyVertex == 2:
        if n == maxValueFigure:
            return (-cx,cy)
        cx = -cx+(-0.5*(maxValueFigure-n))
        cy += ((maxValueFigure-n)*sqrt32)
        return (cx,cy)
    #vertex3
    if  identifyVertex == 3:
        if n == maxValueFigure:
            return (-nvl,0)
        cx = -cx + (-0.5*(n-(maxValueFigure-nvl)))
        cy = -cy - ( (n-(maxValueFigure-nvl)) * sqrt32)
        return (cx,cy)
    #vertex4
    if  identifyVertex == 4:
        if n == maxValueFigure:
            return (-cx,-cy)
        cx = cx - (n-(maxValueFigure-nvl))
        return (cx,-cy)
    #vertex5
    if  identifyVertex == 5:
        if n == maxValueFigure:
            return (cx,-cy)
        cx = nvl - (0.5* (n-(maxValueFigure-nvl)))
        cy = sqrt32 * (n-(maxValueFigure-nvl))
        return (cx,cy)
    #vertex6
    if  identifyVertex == 6:
        if n == maxValueFigure:
            return (nvl,0)
        cx = nvl - (0.5* (maxValueFigure-n))
        cy = sqrt32 * (maxValueFigure-n)
        return (cx,-cy)
    


def main():
    i = 1
    while 1:
        lec = stdin.readline().strip()
        if not lec:
            break
        a , b = [int(x) for x in lec.split()]
        ax = solve(a)
        bx = solve(b)
        sol  = (ax[1]-bx[1])**2 + (ax[0]-bx[0])**2
        #print(ax)
        #print(bx)
        print("%.3f %.3f"%(abs(b-a),sqrt(sol)))
        
main()    
