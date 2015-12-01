// The header file which defines base class
// Shape and derived class Circle

class Shape {  
public:  
  virtual ~Shape() { }              // A virtual destructor  
  virtual void draw() = 0;          // A pure virtual function  
  virtual void move() = 0;  
  // ...  
  virtual Shape* clone()  const = 0;// Uses the copy constructor  
  virtual Shape* create() const = 0;// Uses the default constructor  
};  

class Circle : public Shape {  
public:  
  Circle* clone()  const;// Covariant Return Types; see below  
  Circle* create() const;// Covariant Return Types; see below  
  // ...  
};  


Circle* Circle::clone()  const { return new Circle(*this); }  
Circle* Circle::create() const { return new Circle();      }  
