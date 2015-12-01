#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area () const
      { return 0; }
    int print() const
      { return this->area();} 
};

class Rectangle: public Polygon {
  public:
    int area () const
      { return width * height; }
};

class Triangle: public Polygon {
  public:
    int area () const
      { return (width * height / 2); }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  Polygon * ppoly3 = &poly;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly3->set_values (4,5);
  cout << ppoly1->print() << '\n';
  cout << ppoly2->print() << '\n';
  cout << ppoly3->print() << '\n';
  return 0;
}
