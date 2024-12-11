### Unit I: Objects and Classes

#### Structure in C and C++
Structures in C and C++ are user-defined data types that allow grouping of variables of different types under a single name.

```cpp
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    Person p1;
    p1.name = "John";
    p1.age = 30;
    cout << "Name: " << p1.name << ", Age: " << p1.age << endl;
    return 0;
}
```

#### Class Specification
In C++, a class is defined using the `class` keyword. It consists of private and public sections that declare its members and methods.

```cpp
class Sample {
private:
    int data;

public:
    void setData(int value) { data = value; }
    int getData() { return data; }
};
```

#### Data Hiding, Encapsulation, and Abstraction
- **Data Hiding**: Restricts access to the internal data of a class by making members private.
- **Encapsulation**: Combines data and the functions that operate on them into a single unit (class).
- **Abstraction**: Exposes only the essential details while hiding implementation specifics.

```cpp
class Account {
private:
    double balance;

public:
    Account(double initial_balance) { balance = initial_balance; }
    void deposit(double amount) { balance += amount; }
    void displayBalance() { cout << "Balance: " << balance << endl; }
};
```

#### Namespaces
Namespaces prevent naming conflicts by grouping entities like classes, objects, and functions under a unique name.

```cpp
#include <iostream>
namespace MySpace {
    void display() {
        std::cout << "Inside MySpace" << std::endl;
    }
}

int main() {
    MySpace::display();
    return 0;
}
```

#### Arrays of Objects
You can create and use arrays of class objects to manage collections of similar objects.

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student students[2] = { {"Alice", 20}, {"Bob", 22} };
    for (int i = 0; i < 2; ++i) {
        students[i].display();
    }
    return 0;
}
```

#### Passing Objects as Arguments
Objects of a class can be passed as arguments to functions, either by value or reference.

```cpp
#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
};

void displayResult(Calculator calc, int x, int y) {
    cout << "Sum: " << calc.add(x, y) << endl;
}

int main() {
    Calculator calc;
    displayResult(calc, 5, 10);
    return 0;
}
```

#### Returning Objects from a Function
Functions in C++ can return objects, enabling object-oriented designs where objects are manipulated and passed around.

```cpp
#include <iostream>
using namespace std;

class Box {
public:
    int length;

    Box(int l) { length = l; }

    Box doubleLength() {
        return Box(length * 2);
    }

    void display() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Box b1(5);
    Box b2 = b1.doubleLength();
    b2.display();
    return 0;
}
```

#### Inline Functions
The `inline` keyword allows small functions to be expanded in-line, reducing function call overhead.

```cpp
#include <iostream>
using namespace std;

class Math {
public:
    inline int square(int x) {
        return x * x;
    }
};

int main() {
    Math m;
    cout << "Square of 5: " << m.square(5) << endl;
    return 0;
}
```

#### Static Data Members and Member Functions
Static members belong to the class rather than any specific object, sharing the same value across all instances.

```cpp
#include <iostream>
using namespace std;

class Counter {
private:
    static int count;

public:
    Counter() { ++count; }
    static int getCount() { return count; }
};

int Counter::count = 0;

int main() {
    Counter c1, c2, c3;
    cout << "Count: " << Counter::getCount() << endl;
    return 0;
}
```

---

### Unit II: Constructors and Destructors

#### Constructors
Constructors are special member functions in C++ that are automatically invoked when an object of the class is created. They initialize the object's data members.

```cpp
#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person p1("Alice", 25);
    p1.display();
    return 0;
}
```

#### Parameterized Constructors
Constructors can take arguments to initialize data members with specific values.

```cpp
class Rectangle {
private:
    int width, height;

public:
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    int area() { return width * height; }
};

int main() {
    Rectangle rect(10, 20);
    cout << "Area: " << rect.area() << endl;
    return 0;
}
```

#### Constructor Overloading
You can define multiple constructors with different parameter lists to handle various initialization scenarios.

```cpp
class Point {
private:
    int x, y;

public:
    Point() {
        x = y = 0;
    }

    Point(int a, int b) {
        x = a;
        y = b;
    }

    void display() {
        cout << "X: " << x << ", Y: " << y << endl;
    }
};

int main() {
    Point p1;
    Point p2(10, 20);
    p1.display();
    p2.display();
    return 0;
}
```

#### Copy Constructor
A copy constructor creates a new object as a copy of an existing object.

```cpp
class Sample {
private:
    int data;

public:
    Sample(int value) { data = value; }

    // Copy constructor
    Sample(const Sample &obj) {
        data = obj.data;
    }

    void display() {
        cout << "Data: " << data << endl;
    }
};

int main() {
    Sample s1(100);
    Sample s2 = s1; // Copy constructor is called
    s2.display();
    return 0;
}
```

#### Destructors
Destructors are special member functions in C++ used to release resources when an object goes out of scope or is deleted. They have the same name as the class, preceded by a tilde (`~`).

```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    Demo() { cout << "Constructor called" << endl; }
    ~Demo() { cout << "Destructor called" << endl; }
};

int main() {
    Demo d;
    return 0;
}
```

---

### Unit III: Operator Overloading and Type Conversion

#### Syntax of Operator Overloading
Operator overloading allows you to redefine the way operators work for user-defined types.

```cpp
class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // Overload + operator
    Complex operator + (const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    void display() {
        cout << "Real: " << real << ", Imaginary: " << imag << endl;
    }
};

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}
```

#### Overloading Unary Operator
Unary operators can be overloaded to perform operations on a single operand.

```cpp
class Count {
private:
    int value;

public:
    Count() : value(5) {}

    // Overload ++ when used as prefix
    Count operator ++ () {
        ++value;
        return *this;
    }

    void display() {
        cout << "Count: " << value << endl;
    }
};

int main() {
    Count c;
    ++c;
    c.display();
    return 0;
}
```

#### Overloading Binary Operator
Binary operators can be overloaded to perform operations on two operands.

```cpp
class Distance {
private:
    int feet;
    int inches;

public:
    Distance() : feet(0), inches(0) {}
    Distance(int f, int i) : feet(f), inches(i) {}

    // Overload + operator
    Distance operator + (const Distance &d) {
        Distance temp;
        temp.inches = inches + d.inches;
        temp.feet = feet + d.feet + (temp.inches / 12);
        temp.inches %= 12;
        return temp;
    }

    void display() {
        cout << "Feet: " << feet << ", Inches: " << inches << endl;
    }
};

int main() {
    Distance d1(5, 10);
    Distance d2(3, 11);
    Distance d3 = d1 + d2;
    d3.display();
    return 0;
}
```

#### Overloading Arithmetic Operator
Arithmetic operators can be overloaded to perform arithmetic operations on user-defined types.

```cpp
class Matrix {
private:
    int mat[3][3];

public:
    void input() {
        cout << "Enter elements of the matrix:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> mat[i][j];
            }
        }
    }

    // Overload + operator
    Matrix operator + (const Matrix &m) {
        Matrix temp;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                temp.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return temp;
    }

    void display() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1, m2, m3;
    m1.input();
    m2.input();
    m3 = m1 + m2;
    m3.display();
    return 0;
}
```

#### Overloading Relational Operator
Relational operators can be overloaded to compare user-defined types.

```cpp
class Box {
private:
    int length;

public:
    Box(int l) : length(l) {}

    // Overload < operator
    bool operator < (const Box &b) {
        return length < b.length;
    }

    void display() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Box b1(10);
    Box b2(20);
    if (b1 < b2) {
        cout << "Box b1 is smaller than Box b2" << endl;
    } else {
        cout << "Box b1 is not smaller than Box b2" << endl;
    }
    return 0;
}
```

#### Overloading Unary Operator and Binary Operator using Friend Function
Friend functions can be used to overload both unary and binary operators.

```cpp
class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // Friend function to overload + operator
    friend Complex operator + (const Complex &c1, const Complex &c2);

    // Friend function to overload - operator
    friend Complex operator - (const Complex &c1, const Complex &c2);

    void display() {
        cout << "Real: " << real << ", Imaginary: " << imag << endl;
    }
};

Complex operator + (const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator - (const Complex &c1, const Complex &c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    c3.display();
    c4.display();
    return 0;
}
```

#### Data Conversion
Data conversion can be done between basic types and user-defined types using conversion functions.

```cpp
class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h, int m) : hours(h), minutes(m) {}

    // Conversion operator to convert Time to int
    operator int() {
        return (hours * 60) + minutes;
    }

    void display() {
        cout << "Hours: " << hours << ", Minutes: " << minutes << endl;
    }
};

int main() {
    Time t(2, 30);
    int totalMinutes = t;
    cout << "Total Minutes: " << totalMinutes << endl;
    return 0;
}
```

---

### Unit IV: Inheritance

#### Derived Class Declaration
A derived class inherits properties and behaviors from a base class.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Base class display function" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class show function" << endl;
    }
};

int main() {
    Derived d;
    d.display();
    d.show();
    return 0;
}
```

#### Public, Private, and Protected Inheritance
Inheritance can be public, private, or protected, affecting the accessibility of base class members in the derived class.

```cpp
class Base {
protected:
    int protectedVar;

public:
    Base() : protectedVar(0) {}
};

class PublicDerived : public Base {
public:
    void setVar(int val) {
        protectedVar = val;
    }
    void display() {
        cout << "Protected Variable: " << protectedVar << endl;
    }
};

int main() {
    PublicDerived obj;
    obj.setVar(10);
    obj.display();
    return 0;
}
```

#### Friend Function and Inheritance
Friend functions can access private and protected members of a class, even in the context of inheritance.

```cpp
class Base {
private:
    int privateVar;

protected:
    int protectedVar;

public:
    Base() : privateVar(0), protectedVar(0) {}

    friend void access(Base &b);
};

void access(Base &b) {
    b.privateVar = 10;
    b.protectedVar = 20;
    cout << "Private Variable: " << b.privateVar << ", Protected Variable: " << b.protectedVar << endl;
}

int main() {
    Base b;
    access(b);
    return 0;
}
```

#### Overriding Member Function
A derived class can override a member function of the base class to provide a specific implementation.

```cpp
class Base {
public:
    virtual void display() {
        cout << "Base class display function" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived class display function" << endl;
    }
};

int main() {
    Base *b;
    Derived d;
    b = &d;
    b->display();
    return 0;
}
```

#### Forms of Inheritance
Inheritance can take various forms: single, multiple, multilevel, hierarchical, and hybrid.

```cpp
// Single Inheritance
class A {
public:
    void display() {
        cout << "Class A" << endl;
    }
};

class B : public A {
public:
    void show() {
        cout << "Class B" << endl;
    }
};

// Multiple Inheritance
class C {
public:
    void display() {
        cout << "Class C" << endl;
    }
};

class D : public A, public C {
public:
    void show() {
        cout << "Class D" << endl;
    }
};

// Multilevel Inheritance
class E : public B {
public:
    void show() {
        cout << "Class E" << endl;
    }
};

int main() {
    B objB;
    objB.display();
    objB.show();

    D objD;
    objD.A::display();
    objD.C::display();
    objD.show();

    E objE;
    objE.display();
    objE.B::show();
    objE.show();

    return 0;
}
```

#### Virtual Base Class
A virtual base class is used to avoid multiple copies of a base class when using multiple inheritance.

```cpp
class Base {
public:
    void display() {
        cout << "Base class" << endl;
    }
};

class Derived1 : virtual public Base {};
class Derived2 : virtual public Base {};

class Derived3 : public Derived1, public Derived2 {};

int main() {
    Derived3 obj;
    obj.display();
    return 0;
}
```

#### Abstract Class
An abstract class contains at least one pure virtual function and cannot be instantiated.

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Circle c;
    c.draw();
    return 0;
}
```

#### Constructor and Inheritance
Constructors of base classes are called before constructors of derived classes.

```cpp
class Base {
public:
    Base() {
        cout << "Base class constructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived class constructor" << endl;
    }
};

int main() {
    Derived d;
    return 0;
}
```

#### Destructor and Inheritance
### Unit I: Objects and Classes

#### Structure in C and C++
Structures in C and C++ are user-defined data types that allow grouping of variables of different types under a single name.

```cpp
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    Person p1;
    p1.name = "John";
    p1.age = 30;
    cout << "Name: " << p1.name << ", Age: " << p1.age << endl;
    return 0;
}
```

#### Class Specification
In C++, a class is defined using the `class` keyword. It consists of private and public sections that declare its members and methods.

```cpp
class Sample {
private:
    int data;

public:
    void setData(int value) { data = value; }
    int getData() { return data; }
};
```

#### Data Hiding, Encapsulation, and Abstraction
- **Data Hiding**: Restricts access to the internal data of a class by making members private.
- **Encapsulation**: Combines data and the functions that operate on them into a single unit (class).
- **Abstraction**: Exposes only the essential details while hiding implementation specifics.

```cpp
class Account {
private:
    double balance;

public:
    Account(double initial_balance) { balance = initial_balance; }
    void deposit(double amount) { balance += amount; }
    void displayBalance() { cout << "Balance: " << balance << endl; }
};
```

#### Namespaces
Namespaces prevent naming conflicts by grouping entities like classes, objects, and functions under a unique name.

```cpp
#include <iostream>
namespace MySpace {
    void display() {
        std::cout << "Inside MySpace" << std::endl;
    }
}

int main() {
    MySpace::display();
    return 0;
}
```

#### Arrays of Objects
You can create and use arrays of class objects to manage collections of similar objects.

```cpp
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Student students[2] = { {"Alice", 20}, {"Bob", 22} };
    for (int i = 0; i < 2; ++i) {
        students[i].display();
    }
    return 0;
}
```

#### Passing Objects as Arguments
Objects of a class can be passed as arguments to functions, either by value or reference.

```cpp
#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
};

void displayResult(Calculator calc, int x, int y) {
    cout << "Sum: " << calc.add(x, y) << endl;
}

int main() {
    Calculator calc;
    displayResult(calc, 5, 10);
    return 0;
}
```

#### Returning Objects from a Function
Functions in C++ can return objects, enabling object-oriented designs where objects are manipulated and passed around.

```cpp
#include <iostream>
using namespace std;

class Box {
public:
    int length;

    Box(int l) { length = l; }

    Box doubleLength() {
        return Box(length * 2);
    }

    void display() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Box b1(5);
    Box b2 = b1.doubleLength();
    b2.display();
    return 0;
}
```

#### Inline Functions
The `inline` keyword allows small functions to be expanded in-line, reducing function call overhead.

```cpp
#include <iostream>
using namespace std;

class Math {
public:
    inline int square(int x) {
        return x * x;
    }
};

int main() {
    Math m;
    cout << "Square of 5: " << m.square(5) << endl;
    return 0;
}
```

#### Static Data Members and Member Functions
Static members belong to the class rather than any specific object, sharing the same value across all instances.

```cpp
#include <iostream>
using namespace std;

class Counter {
private:
    static int count;

public:
    Counter() { ++count; }
    static int getCount() { return count; }
};

int Counter::count = 0;

int main() {
    Counter c1, c2, c3;
    cout << "Count: " << Counter::getCount() << endl;
    return 0;
}
```

---

### Unit II: Constructors and Destructors

#### Constructors
Constructors are special member functions in C++ that are automatically invoked when an object of the class is created. They initialize the object's data members.

```cpp
#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person p1("Alice", 25);
    p1.display();
    return 0;
}
```

#### Parameterized Constructors
Constructors can take arguments to initialize data members with specific values.

```cpp
class Rectangle {
private:
    int width, height;

public:
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    int area() { return width * height; }
};

int main() {
    Rectangle rect(10, 20);
    cout << "Area: " << rect.area() << endl;
    return 0;
}
```

#### Constructor Overloading
You can define multiple constructors with different parameter lists to handle various initialization scenarios.

```cpp
class Point {
private:
    int x, y;

public:
    Point() {
        x = y = 0;
    }

    Point(int a, int b) {
        x = a;
        y = b;
    }

    void display() {
        cout << "X: " << x << ", Y: " << y << endl;
    }
};

int main() {
    Point p1;
    Point p2(10, 20);
    p1.display();
    p2.display();
    return 0;
}
```

#### Copy Constructor
A copy constructor creates a new object as a copy of an existing object.

```cpp
class Sample {
private:
    int data;

public:
    Sample(int value) { data = value; }

    // Copy constructor
    Sample(const Sample &obj) {
        data = obj.data;
    }

    void display() {
        cout << "Data: " << data << endl;
    }
};

int main() {
    Sample s1(100);
    Sample s2 = s1; // Copy constructor is called
    s2.display();
    return 0;
}
```

#### Destructors
Destructors are special member functions in C++ used to release resources when an object goes out of scope or is deleted. They have the same name as the class, preceded by a tilde (`~`).

```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    Demo() { cout << "Constructor called" << endl; }
    ~Demo() { cout << "Destructor called" << endl; }
};

int main() {
    Demo d;
    return 0;
}
```

---

### Unit III: Operator Overloading and Type Conversion

#### Syntax of Operator Overloading
Operator overloading allows you to redefine the way operators work for user-defined types.

```cpp
class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // Overload + operator
    Complex operator + (const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    void display() {
        cout << "Real: " << real << ", Imaginary: " << imag << endl;
    }
};

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}
```

#### Overloading Unary Operator
Unary operators can be overloaded to perform operations on a single operand.

```cpp
class Count {
private:
    int value;

public:
    Count() : value(5) {}

    // Overload ++ when used as prefix
    Count operator ++ () {
        ++value;
        return *this;
    }

    void display() {
        cout << "Count: " << value << endl;
    }
};

int main() {
    Count c;
    ++c;
    c.display();
    return 0;
}
```

#### Overloading Binary Operator
Binary operators can be overloaded to perform operations on two operands.

```cpp
class Distance {
private:
    int feet;
    int inches;

public:
    Distance() : feet(0), inches(0) {}
    Distance(int f, int i) : feet(f), inches(i) {}

    // Overload + operator
    Distance operator + (const Distance &d) {
        Distance temp;
        temp.inches = inches + d.inches;
        temp.feet = feet + d.feet + (temp.inches / 12);
        temp.inches %= 12;
        return temp;
    }

    void display() {
        cout << "Feet: " << feet << ", Inches: " << inches << endl;
    }
};

int main() {
    Distance d1(5, 10);
    Distance d2(3, 11);
    Distance d3 = d1 + d2;
    d3.display();
    return 0;
}
```

#### Overloading Arithmetic Operator
Arithmetic operators can be overloaded to perform arithmetic operations on user-defined types.

```cpp
class Matrix {
private:
    int mat[3][3];

public:
    void input() {
        cout << "Enter elements of the matrix:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> mat[i][j];
            }
        }
    }

    // Overload + operator
    Matrix operator + (const Matrix &m) {
        Matrix temp;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                temp.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return temp;
    }

    void display() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1, m2, m3;
    m1.input();
    m2.input();
    m3 = m1 + m2;
    m3.display();
    return 0;
}
```

#### Overloading Relational Operator
Relational operators can be overloaded to compare user-defined types.

```cpp
class Box {
private:
    int length;

public:
    Box(int l) : length(l) {}

    // Overload < operator
    bool operator < (const Box &b) {
        return length < b.length;
    }

    void display() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Box b1(10);
    Box b2(20);
    if (b1 < b2) {
        cout << "Box b1 is smaller than Box b2" << endl;
    } else {
        cout << "Box b1 is not smaller than Box b2" << endl;
    }
    return 0;
}
```

#### Overloading Unary Operator and Binary Operator using Friend Function
Friend functions can be used to overload both unary and binary operators.

```cpp
class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // Friend function to overload + operator
    friend Complex operator + (const Complex &c1, const Complex &c2);

    // Friend function to overload - operator
    friend Complex operator - (const Complex &c1, const Complex &c2);

    void display() {
        cout << "Real: " << real << ", Imaginary: " << imag << endl;
    }
};

Complex operator + (const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator - (const Complex &c1, const Complex &c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    c3.display();
    c4.display();
    return 0;
}
```

#### Data Conversion
Data conversion can be done between basic types and user-defined types using conversion functions.

```cpp
class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h, int m) : hours(h), minutes(m) {}

    // Conversion operator to convert Time to int
    operator int() {
        return (hours * 60) + minutes;
    }

    void display() {
        cout << "Hours: " << hours << ", Minutes: " << minutes << endl;
    }
};

int main() {
    Time t(2, 30);
    int totalMinutes = t;
    cout << "Total Minutes: " << totalMinutes << endl;
    return 0;
}
```

---

### Unit IV: Inheritance

#### Derived Class Declaration
A derived class inherits properties and behaviors from a base class.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Base class display function" << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class show function" << endl;
    }
};

int main() {
    Derived d;
    d.display();
    d.show();
    return 0;
}
```

#### Public, Private, and Protected Inheritance
Inheritance can be public, private, or protected, affecting the accessibility of base class members in the derived class.

```cpp
class Base {
protected:
    int protectedVar;

public:
    Base() : protectedVar(0) {}
};

class PublicDerived : public Base {
public:
    void setVar(int val) {
        protectedVar = val;
    }
    void display() {
        cout << "Protected Variable: " << protectedVar << endl;
    }
};

int main() {
    PublicDerived obj;
    obj.setVar(10);
    obj.display();
    return 0;
}
```

#### Friend Function and Inheritance
Friend functions can access private and protected members of a class, even in the context of inheritance.

```cpp
class Base {
private:
    int privateVar;

protected:
    int protectedVar;

public:
    Base() : privateVar(0), protectedVar(0) {}

    friend void access(Base &b);
};

void access(Base &b) {
    b.privateVar = 10;
    b.protectedVar = 20;
    cout << "Private Variable: " << b.privateVar << ", Protected Variable: " << b.protectedVar << endl;
}

int main() {
    Base b;
    access(b);
    return 0;
}
```

#### Overriding Member Function
A derived class can override a member function of the base class to provide a specific implementation.

```cpp
class Base {
public:
    virtual void display() {
        cout << "Base class display function" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived class display function" << endl;
    }
};

int main() {
    Base *b;
    Derived d;
    b = &d;
    b->display();
    return 0;
}
```

#### Forms of Inheritance
Inheritance can take various forms: single, multiple, multilevel, hierarchical, and hybrid.

```cpp
// Single Inheritance
class A {
public:
    void display() {
        cout << "Class A" << endl;
    }
};

class B : public A {
public:
    void show() {
        cout << "Class B" << endl;
    }
};

// Multiple Inheritance
class C {
public:
    void display() {
        cout << "Class C" << endl;
    }
};

class D : public A, public C {
public:
    void show() {
        cout << "Class D" << endl;
    }
};

// Multilevel Inheritance
class E : public B {
public:
    void show() {
        cout << "Class E" << endl;
    }
};

int main() {
    B objB;
    objB.display();
    objB.show();

    D objD;
    objD.A::display();
    objD.C::display();
    objD.show();

    E objE;
    objE.display();
    objE.B::show();
    objE.show();

    return 0;
}
```

#### Virtual Base Class
A virtual base class is used to avoid multiple copies of a base class when using multiple inheritance.

```cpp
class Base {
public:
    void display() {
        cout << "Base class" << endl;
    }
};

class Derived1 : virtual public Base {};
class Derived2 : virtual public Base {};

class Derived3 : public Derived1, public Derived2 {};

int main() {
    Derived3 obj;
    obj.display();
    return 0;
}
```

#### Abstract Class
An abstract class contains at least one pure virtual function and cannot be instantiated.

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Circle c;
    c.draw();
    return 0;
}
```

#### Constructor and Inheritance
Constructors of base classes are called before constructors of derived classes.

```cpp
class Base {
public:
    Base() {
        cout << "Base class constructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived class constructor" << endl;
    }
};

int main() {
    Derived d;
    return 0;
}
```

#### Destructor and Inheritance
Destructors of derived classes are called before destructors of base classes.

```cpp
class Base {
public:
    Base() {
        cout << "Base class constructor" << endl;
    }
    ~Base() {
        cout << "Base class destructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived class constructor" << endl;
    }
    ~Derived() {
        cout << "Derived class destructor" << endl;
    }
};

int main() {
    Derived d;
    return 0;
}
```

#### Advantage and Disadvantage of Inheritance
- **Advantages**:
  - Code Reusability: Inheritance allows the reuse of existing code.
  - Extensibility: New features can be added to existing classes without modifying them.
  - Maintainability: Changes in the base class automatically propagate to derived classes.

- **Disadvantages**:
  - Increased Complexity: Inheritance can make the code more complex and harder to understand.
  - Tight Coupling: Derived classes are tightly coupled with base classes, making changes in the base class affect derived classes.

### Polymorphism

#### Classification of Polymorphism
Polymorphism is classified into two types:
- **Compile-time Polymorphism**: Achieved through function overloading and operator overloading.
- **Run-time Polymorphism**: Achieved through virtual functions and inheritance.

#### Compile-time and Run-time Polymorphism
- **Compile-time Polymorphism**: The function to be invoked is determined at compile time.
- **Run-time Polymorphism**: The function to be invoked is determined at run time using virtual functions.

```cpp
class Base {
public:
    virtual void display() {
        cout << "Base class display function" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived class display function" << endl;
    }
};

int main() {
    Base *b;
    Derived d;
    b = &d;
    b->display(); // Run-time polymorphism
    return 0;
}
```

#### Pointers to Derived Class Object
Pointers to base class objects can point to derived class objects, enabling polymorphism.

```cpp
class Base {
public:
    virtual void display() {
        cout << "Base class display function" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived class display function" << endl;
    }
};

int main() {
    Base *b;
    Derived d;
    b = &d;
    b->display();
    return 0;
}
```

#### Virtual Functions
Virtual functions allow derived classes to override the behavior of base class functions.

```cpp
class Base {
public:
    virtual void display() {
        cout << "Base class display function" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Derived class display function" << endl;
    }
};

int main() {
    Base *b;
    Derived d;
    b = &d;
    b->display();
    return 0;
}
```

#### Pure Virtual Functions
A pure virtual function is a function with no implementation in the base class, making the class abstract.

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Circle c;
    c.draw();
    return 0;
}
```

### Unit V: File Handling

#### Formatted I/O
Formatted I/O operations allow data to be read and written in a specific format.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("example.txt");
    outFile << "Hello, World!" << endl;
    outFile.close();

    ifstream inFile("example.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    return 0;
}
```

#### Hierarchy of File Stream Classes
The file stream classes in C++ include `ifstream`, `ofstream`, and `fstream`.

#### Opening and Closing a File
Files can be opened using the `open` function and closed using the `close` function.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile;
    outFile.open("example.txt");
    outFile << "Hello, World!" << endl;
    outFile.close();

    ifstream inFile;
    inFile.open("example.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    return 0;
}
```

#### Working with Multiple Files
Multiple files can be handled simultaneously by creating multiple file stream objects.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile1("file1.txt");
    ofstream outFile2("file2.txt");
    outFile1 << "Hello from file1!" << endl;
    outFile2 << "Hello from file2!" << endl;
    outFile1.close();
    outFile2.close();

    ifstream inFile1("file1.txt");
    ifstream inFile2("file2.txt");
    string line;
    while (getline(inFile1, line)) {
        cout << line << endl;
    }
    while (getline(inFile2, line)) {
        cout << line << endl;
    }
    inFile1.close();
    inFile2.close();
    return 0;
}
```

#### File Modes
File modes determine how a file is opened and manipulated. Common modes include `ios::in`, `ios::out`, `ios::app`, `ios::binary`, etc.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("example.txt", ios::app);
    outFile << "Appending this line." << endl;
    outFile.close();

    ifstream inFile("example.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    return 0;
}
```

#### File Pointers
File pointers are used to read from and write to specific locations in a file.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("example.txt", ios::in | ios::out | ios::trunc);
    file << "Hello, World!" << endl;
    file.seekg(0);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
    return 0;
}
```

#### Text vs. Binary Files
Text files store data in human-readable format, while binary files store data in binary format.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("example.bin", ios::binary);
    int num = 12345;
    outFile.write(reinterpret_cast<char*>(&num), sizeof(num));
    outFile.close();

    ifstream inFile("example.bin", ios::binary);
    int readNum;
    inFile.read(reinterpret_cast<char*>(&readNum), sizeof(readNum));
    cout << "Read number: " << readNum << endl;
    inFile.close();
    return 0;
}
```

### Templates

#### Need of Template
Templates allow writing generic and reusable code that works with any data type.

#### Function Templates
Function templates define a blueprint for functions that can operate on different data types.

```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Sum of integers: " << add(3, 4) << endl;
    cout << "Sum of doubles: " << add(3.5, 4.5) << endl;
    return 0;
}
```

#### Function Template with Non-type Parameter
Function templates can also have non-type parameters.

```cpp
#include <iostream>
using namespace std;

template <typename T, int size>
void printArray(T (&arr)[size]) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr);
    return 0;
}
```

#### Overloading Function Templates
Function templates can be overloaded to handle different types of arguments.

```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T add(T a, T b, T c) {
    return a + b + c;
}

int main() {
    cout << "Sum of two integers: " << add(3, 4) << endl;
    cout << "Sum of three integers: " << add(3, 4, 5) << endl;
    return 0;
}
```

#### Class Templates
Class templates define a blueprint for classes that can operate on different data types.

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
};

int main() {
    Box<int> intBox(123);
    Box<double> doubleBox(456.78);
    cout << "Integer Box: " << intBox.getValue() << endl;
    cout << "Double Box: " << doubleBox.getValue() << endl;
    return 0;
}
```

#### Class Template with Non-type Parameter
Class templates can also have non-type parameters.

```cpp
#include <iostream>
using namespace std;

template <typename T, int size>
class Array {
private:
    T arr[size];

public:
    void set(int index, T value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }
    T get(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        return T();
    }
};

int main() {
    Array<int, 5> intArray;
    intArray.set(0, 10);
    intArray.set(1, 20);
    cout << "Array[0]: " << intArray.get(0) << endl;
    cout << "Array[1]: " << intArray.get(1) << endl;
    return 0;
}
```

### Exception Handling

#### Exception Handling Mechanism
Exception handling in C++ is done using `try`, `catch`, and `throw` keywords.

```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        int a = 10;
        int b = 0;
        if (b == 0) {
            throw "Division by zero!";
        }
        cout << "Result: " << a / b << endl;
    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    return 0;
}
```

#### Multiple Catch Blocks
Multiple catch blocks can be used to handle different types of exceptions.

```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        int a = 10;
        int b = 0;
        if (b == 0) {
            throw "Division by zero!";
        }
        cout << "Result: " << a / b << endl;
    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    } catch (...) {
        cout << "Unknown error occurred!" << endl;
    }
    return 0;
}
```

#### Catch All Exceptions
The ellipsis (`...`) can be used to catch all types of exceptions.

```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        int a = 10;
        int b = 0;
        if (b == 0) {
            throw "Division by zero!";
        }
        cout << "Result: " << a / b << endl;
    } catch (...) {
        cout << "An error occurred!" << endl;
    }
    return 0;
}
```

#### Throw an Exception
Exceptions can be thrown using the `throw` keyword.

```cpp
#include <iostream>
using namespace std;

void divide(int a, int b) {
    if (b == 0) {
        throw "Division by zero!";
    }
    cout << "Result: " << a / b << endl;
}

int main() {
    try {
        divide(10, 0);
    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    return 0;
}
```

#### Exception Specification
Exception specifications can be used to specify the types of exceptions a function can throw.

```cpp
#include <iostream>
using namespace std;

void divide(int a, int b) throw(const char*) {
    if (b == 0) {
        throw "Division by zero!";
    }
    cout << "Result: " << a / b << endl;
}

int main() {
    try {
        divide(10, 0);
    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    return 0;
}
```