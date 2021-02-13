#include <iostream>

int main()
{
    int a, b;
    // eof()는 eof 플래그가 발생했을 때 뜨는 것.
    // std::cin도 bool 타입으로 캐스팅될 때 fail()과 연관되는 것 같은데, eof()와 동일한 효과일 것.
    while (std::cin >> a >> b)
        std::cout << (a + b) << std::endl;
}