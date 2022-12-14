//
//  Wrapper.h
//  OOP
//
//  Created by Luca Begatti on 06/12/2022.
//

#ifndef Wrapper_h
#define Wrapper_h


#endif /* Wrapper_h */

// template of PayoffBridge class
template <typename T>
class Wrapper{
private:
    T* ptrData; // pointer to the type T.
public:
    Wrapper(){ptrData = nullptr;} // constructor with no input
    
    // constructor
    Wrapper(const T& ptrIn){
        ptrData = ptrIn.clone(); // assuming the clone() function exists for any object of type T.
        
    }
    
    // destructor
    ~Wrapper(){
        delete ptrData; // it works also with null pointers.
    }
    
    // Copy Constructor
    Wrapper(const Wrapper<T>& ptrToCopy){
        if (ptrToCopy.ptrData == nullptr) {
            ptrData = nullptr; // null pointer does not have a clone() function
        }else{
            ptrData = ptrToCopy.ptrData->clone();
        }

    }
    
    // Assignment operator
    Wrapper& operator=(const Wrapper<T>& ptrToAssign){
        
        if (this != ptrToAssign) { // check for self assign
            delete ptrData;
            ptrData = (ptrToAssign.ptrData == nullptr) ? nullptr : ptrToAssign.ptrData-> clone();
        }
        return *this;
    }
    
    T* operator->() const{
        return ptrData;
    }
    
    T& operator*() const{
        return *ptrData;
    }
    
};
