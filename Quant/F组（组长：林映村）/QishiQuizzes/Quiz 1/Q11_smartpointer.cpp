#include <iostream>

using namespace std;

class referencecount
{
    public:
    int count; 				//reference count

    referencecount() : count(0) {}
    ~referencecount() {}
    void increase() { count++;}
    int decrease() { return --count;} 
};

template < class T > 
class smartpointer 
{
    private:
    T* p;   			//pointer
    referencecount* reference; 	//reference count

    public:
    //overloading constructors
    smartpointer() 
    { 	
	reference = new referencecount();
	reference->increase(); 			//reference count = 1 when construct
	cout << "Pointer is being created: " << "reference count = " << reference->count<< endl;
    }

    smartpointer(T* p): p(p)
    { 	 
	reference = new referencecount();
	reference->increase(); 
	cout << "Pointer is being created: " << "reference count = " << reference->count<< endl;
    } 

    smartpointer(const smartpointer<T>& copyfrom): p(copyfrom.p), reference(copyfrom.reference)
    { 	 
	reference->increase(); 
	cout << "Pointer is being created: " << "reference count = " << reference->count<< endl;
    } 

    //destructor
    ~smartpointer()				//decrease the reference count, if reference become zero delete the pointer
    {
        if(reference->decrease() == 0)
        {
	    cout << "Pointer is being deleted " << "reference count = " << reference->count<<  endl;
            delete p;
            delete reference;
        }
	else cout << "Pointer is being deleted " << "reference count = " << reference->count<<  endl;
    }

    //overloading operator =
    smartpointer<T>& operator = (const smartpointer<T>& copyfrom)
    {
        if (this != &copyfrom) 			//avoid copy from itself 
        {
            //copy the T pointer  and reference pointer and increase the reference count
            p = copyfrom.p;
            reference = copyfrom.reference;
            reference->increase();
	    cout << "copy pointers: reference count = " << reference->count<< endl;
        }
	
	return *this;
    }
};

class test{

	public:
	int a;
	test(int a) : a(a) {}
	~test() {}
};

int main()
{
  cout<< "Testing the smart pointer" << endl;
  for(int i=0; i < 1; i++){
  	smartpointer<test> first(new test(0));

  	for(int j=0; j < 1; j++){
		smartpointer<test> second;
		second =  first;
  	}
  }
  return 0;

}
