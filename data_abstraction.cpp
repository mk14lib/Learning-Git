#include <iostream>
#include <iomanip>
using namespace std;

// Data encapsulation
class Shape {
    // data abstraction
    protected:
        int width;
        int height;
    
    public:
    Shape(int a, int b)
    {
        width = a;
        height = b;
    }
    
    // data abstraction - pure virtual function
    virtual int area() = 0;
    
    // virtual function 
    // virtual int area()
    // {
    //     return width*height;    
    // }
};

class Rectangle: public Shape {
    public:
    Rectangle(int a, int b):Shape(a, b) {
        
    }
    
    int area()
    {
        cout << "Rectangle area: " << width*height << endl;
        return width * height;
    }
    
};

class Triangle: public Shape {
  public:
  Triangle(int a, int b): Shape(a, b)
  {
      
  }
  
  int area()
  {
      cout << "Triangle area: " << (width*height)/2 << endl;
      return (width*height)/2;
  }
};


int main()
{
    // data abstraction and data encapsulation
    Rectangle rec(10, 20);
    rec.area();
    
    Triangle tri(10, 20);
    tri.area();
    
    return 0;
}