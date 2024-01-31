#include <iostream>
#include <iomanip>
using namespace std;

// overloading unary operator
class Negation {
    private:
        int value;
    
    public:
        Negation(int value)
        {
            this->value = value;
        }
        
        Negation operator- ()
        {
            value = -value;
            return Negation(value);
        }
        
        void showResult() 
        {
            cout << "Negated Value: " << value << endl;
        }
        
        ~Negation()
        {
            
        }
};

// binary operator overloading
class Duo {
    public:
        int len;
        int bre;
        
    public:
        Duo()
        {
        }
    
        Duo(int l, int b):len(l), bre(b)
        {
            
        }
        
        Duo operator+ (const Duo& obj)
        {
            Duo d;
            d.len = this->len + obj.len; 
            d.bre = this->bre + obj.bre;
            return d;
        }
        
        void setLength(int l)
        {
            len = l;
        }
        
        void setBreadth(int b)
        {
            bre = b;
        }
        
        int showResult() 
        {
            return len*bre;
        }
};

// Input/Output overloading
class Distance 
{
    private:
        int feet;
        int inches;
        
    public:
        Distance()
        {
            feet = 0;
            inches = 0;
        }
        
        Distance(int ft, int in)
        {
            feet = ft;
            inches = in;
        }
        
        friend istream& operator>> ( istream& input, Distance& D)
        {
            input >> D.feet >> D.inches;  
            return input;
        }
        
        friend ostream& operator<< (ostream& output, const Distance& D)
        {
            output << D.feet <<" ft," << setw(3) << D.inches << " in" << endl;
            return output;
        }
        
        void operator= (const Distance& obj)
        {
            feet = obj.feet;
            inches = obj.inches;
        }
};

// Pre-increment & post-increment overloading
class Time {
    private:
        int hours;
        int minutes;
    
    public:
        Time()
        {
            hours = 0;
            minutes = 0;
        }
        
        Time(int h, int m)
        {
            hours = h;
            minutes = m;
        }
        
        void showTime() 
        {
            cout << hours << ":" << minutes << endl;
        }
        
        // prefix
        Time operator++ ()
        {
            ++minutes;
            if (minutes >= 60)
            {
                ++hours;
                minutes -= 60;
            }
            return Time(hours, minutes);
        }
        
        // postfix
        Time operator++(int)
        {
            Time T(hours, minutes);
            ++minutes;
            if (minutes >= 60)
            {
                ++hours;
                minutes -= 60;
            }
            return T;
        }
};

// [] operator overloading
const int SIZE = 5;
class safearray {
    private:
        int array[SIZE];
        
    public:
    safearray() 
    {
        register int i;
        for(i = 0; i < SIZE; i++)
        {
            array[i] = i;
        }
    }
    
    int& operator[](int i)
    {
        if (i >= SIZE)
        {
            return array[0];
        }
        
        return array[i];
    }
    
};

int main()
{
    // Unary operator overloading 
    Negation minus(56);
    -minus;
    minus.showResult();
    
    // Binary operator overloading 
    Duo d1, d2, d3;
    d1.setLength(3);
    d1.setBreadth(4);
    cout << "area1: " << d1.showResult() << endl;
    
    d2.setLength(2);
    d2.setBreadth(4);
    cout << "area2: " << d2.showResult() << endl;
    
    d3 = d1 + d2;
    cout << "Total length: " << d3.len << endl;
    cout << "Total breadth: " << d3.bre << endl;
    cout << "Total area: " << d3.showResult() << endl;
    
    
    // input + output overloading
    Distance D1(12, 34), D2(43, 21), D3;
    cout << "Enter the distance: ";
    cin >> D3;
    D1 = D2;
    cout << "First Distance  :" << D1;
    cout << "Second Distance :" << D2;
    cout << "Third Distance  :" << D3;
    
    // Preincrement and post-increment overloading
    Time t1(10, 20), t2(11, 10);
    ++t1;
    t1.showTime();
    
    t2++;
    t2.showTime();
    
    // [] operator overloading
    safearray sa;
    cout << "sa[1]: " << sa[1] << endl;
    cout << "sa[4]: " << sa[4] << endl;
    cout << "sa[6]: " << sa[6] << endl;
    
    return 0;
}