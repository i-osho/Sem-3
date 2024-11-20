// Use of variables and function with same name using namespace
#include<iostream>
namespace n1 {
    int num = 10;
    int func() {
        std::cout << "This is the first namespace" << std::endl;
        return 0;
    }
}
namespace n2 {
    int num = 20;
    int func() {
        std::cout << "This is the second namespace" << std::endl;
        return 0;
    }
}
using namespace std;
using namespace n1;
using namespace n2;
int main() {
    n1::func();
    std::cout << "Number from first namespace: " << n1::num << std::endl;
    n2::func();
    std::cout << "Number from second namespace: " << n2::num << std::endl;
    return 0;
}
