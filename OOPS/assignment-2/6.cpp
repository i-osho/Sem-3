#include<iostream>
using namespace std;

class Osho
{
    private:
    int num=10;
    void privfunc()
    {
        cout<<"This is a private function\n";
    }
    public:
    void pubfunc()
    {
        cout<<"This is a public function\n";
        // Part 1: Calling private member function
        privfunc();
        // Part 2: Accessing private data member
        cout<<"Data member: "<<num<<endl;
    }
};

int main() {
    Osho o1;
    o1.pubfunc();
    return 0;
}