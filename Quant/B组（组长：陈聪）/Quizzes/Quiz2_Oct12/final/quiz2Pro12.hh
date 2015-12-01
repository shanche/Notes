
class Matrix {

private:
    int numRows;
    int numCols;
    // matriarray to store the data in Matrix
    int *matrixarray;              
  
public:
    // Constructors
    Matrix();  // default constructor
    Matrix(int sizeRow, int sizeCol);          
    Matrix(Matrix &a); // copy constructor

    // Destructor
    ~Matrix();

    // Mutator methods
    void setelem(int row, int col, int elem);
    void add (Matrix &a);
    void subtract (Matrix &a);
    bool equals (Matrix &a);

    // Accessor methods
    int getrows();
    int getcols();
    int getelem(int row, int col);
};
