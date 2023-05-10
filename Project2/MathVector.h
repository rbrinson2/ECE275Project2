//
//  MathVector.h
//

#ifndef MathVector_h
#define MathVector_h


#include <stdio.h>
#include <string>
#include <vector>

class MathVector {
public:
    MathVector();
    MathVector(int numElements) {
        this->numElements = numElements;
    }
    ~MathVector( ) { }

    bool readElements( std::string str );

    // creates a csv of this vector
    std::string toString( );

protected:
    int numElements;
    std::vector<double> elements;
};

#endif // !MathVector_h