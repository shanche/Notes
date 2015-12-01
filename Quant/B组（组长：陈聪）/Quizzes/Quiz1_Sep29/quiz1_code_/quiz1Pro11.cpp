// template class for smart pointer objects
template<typename T> class smartPtr {
public:
    smartPtr(T* realPtr) : pointee(realPtr) {}
  
    // destructor
    ~smartPtr() {
        delete pointee;
    }
     
    // dereference a smart pointer to get 
    // a member of what it points to
    T* operator->() const {
        return pointee;
    }
    
    // deference a smart pointer
    T& operator*() const {
        return *pointee;
    }
    
private:
     // what the smart pointer points to
     T *pointee;

};