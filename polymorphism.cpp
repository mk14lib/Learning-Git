#include <iostream>
#include <iomanip>
using namespace std;

// Polymorphism
class Shape {
    protected:
        int width;
        int height;
    
    public:
    Shape(int a, int b)
    {
        width = a;
        height = b;
    }
    
    virtual int area()
    {
        cout << "Parent class area: " << width * height << endl;
        return width*height;
    }
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
    // Polymorphism
    Shape *shape;
    Rectangle rec(10, 20);
    shape = &rec;
    shape->area();
    
    Triangle tri(10, 20);
    shape = &tri;
    shape->area();
    
    
    return 0;
}