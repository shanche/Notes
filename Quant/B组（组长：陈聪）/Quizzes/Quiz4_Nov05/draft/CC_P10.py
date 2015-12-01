# P10 of quiz10
# reference: http://www.blackpawn.com/texts/pointinpoly/
import numpy as np

# check if point (x,y) is inside triangle defined by 
# three verticies v1(x1, y1), v2(x2, y2), v3(x3, y3)
def SameSide(p1,p2, a,b):
    cp1 = np.cross(b-a, p1-a)
    cp2 = np.cross(b-a, p2-a)
    if cp1.dot(cp2) >= 0: return True
    else return False

def PointInTriangle(p, a,b,c):
    if SameSide(p,a, b,c) and SameSide(p,b, a,c)
        and SameSide(p,c, a,b): return True
    else return False
