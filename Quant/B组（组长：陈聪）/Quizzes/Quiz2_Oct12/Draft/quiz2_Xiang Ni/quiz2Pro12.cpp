#include "Matrix.hh"
#include <cassert>
using namespace std;


// The default constructor creates a 0 by 0 matrix.   
Matrix::Matrix() {  
    numRows = 0;
    numCols = 0;
    matrixarray = new int[0];  
}


// Copy constructor
Matrix::Matrix(Matrix &a) {  
    numRows = a.getrows();
    numCols = a.getcols();
    matrixarray = new int[numRows * numCols];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrixarray[i * numCols + j] = 
            a.matrixarray[i * numCols + j];
        }
    }       
}


// Initialize matrix of size sizeRow by sizeCol
Matrix::Matrix (int sizeRow, int sizeCol) {
    matrixarray = new int[sizeRow * sizeCol]; 
    numRows = sizeRow;
    numCols = sizeCol;
    for (int i = 0; i < sizeRow; i++) {
        for (int j = 0; j < sizeCol; j++) {
            matrixarray[i * sizeCol + j] = 0;
        }
    }   
}


// Get the rows tall of the matrix
int Matrix::getrows () {
    return numRows;
}


// Get the columns wide of the matrix
int Matrix::getcols () {
    return numCols;
}


// Set the element at row-th row, col-th column as elem
void Matrix::setelem (int row, int col, int elem) {
    assert ((row >= 0) && (row < numRows));
    assert ((col >= 0) && (col < numCols));
    matrixarray[row * numCols + col] = elem; 
}


// Get the element at row-th row, col-th column
int Matrix::getelem (int row, int col) {
    assert ((row >= 0) && (row < numRows));
    assert ((col >= 0) && (col < numCols));
    return matrixarray[row * numCols + col];
}


// Add two matrices
void Matrix::add (Matrix &a) {
    assert(numRows == a.getrows());
    assert(numCols == a.getcols()); 
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrixarray[i * numCols + j] = 
                matrixarray[i * numCols + j]
                + a.matrixarray[i * numCols + j];
        }
    }
}


// Subtract a from another matrix 
void Matrix::subtract (Matrix &a) {
    assert(numRows == a.getrows());
    assert(numCols == a.getcols()); 
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            matrixarray[i * numCols + j] = 
               matrixarray[i * numCols + j]
                - a.matrixarray[i * numCols + j];
        }
    }  
}


// Test for equality
bool Matrix::equals (Matrix &a) {
    if (numRows != a.getrows() || numCols != a.getcols()){
        return false;
    }  
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if ((matrixarray[i * numCols + j]) 
                != (a.matrixarray[i * numCols + j])) {
                    return false;
            }
        }
    }
    return true;                   
}


// Release the memory
Matrix::~Matrix() {
    delete[] matrixarray;
}


