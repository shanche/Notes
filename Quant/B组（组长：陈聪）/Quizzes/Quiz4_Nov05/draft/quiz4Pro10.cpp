double area(double x1, double y1, double x2, double y2, 
               double x3, double y3) {
    return abs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
}

bool isInside(double x1, double y1, double x2, double y2, 
            double x3, double y3, double x, double y) {
  double total = area(x1,y1,x2,y2,x3,y3);
  
  double A1= area(x,y,x2,y2,x3,y3);
  
  double A2= area(x1,y1,x,y,x3,y3);
  
  double A3= area(x1,y1,x2,y2,x,y);
  
  return (total == A1+A2+A3);

}