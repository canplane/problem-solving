#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    
    for (auto it = v.begin(); it != v.end(); ) {
        if (*it == 4) {
            v.erase(it);  // it = v.erase(it); 안 해도 됨. : list는 포인터니까 it = .erase(it); 무조건 해야 함.
        } else {
            it++;
        }
    }

    for (auto& el : v) {
        std::cout << el << ' ';   
    }

}