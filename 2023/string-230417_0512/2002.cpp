#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    char s[10];

    map<string, int> enter;
    for (int i = 0; i < N; i++) {
        scanf("%s", s);
        enter[s] = i;
    }

    int out[N];
    for (int i = 0; i < N; i++) {
        scanf("%s", s);
        out[i] = enter[s];
    }
    
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (out[i] > out[j]) {
                ret++;
                break;
            }
        }
    }
    printf("%d", ret);
}