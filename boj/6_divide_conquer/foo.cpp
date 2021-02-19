#include <cstdio>
#include <vector>

int main() {
    std::vector<int> v(1000);
    printf("%lu %lu\n", v.size(), v.capacity());
}