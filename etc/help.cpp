// 컴파일 옵션 : g++ -std=c++17 foo.cpp



// 한 자리 받기
int a;

scanf("%1d", &a);



// 공백 무시
char a, b, c;

scanf(" %c %c %c", &a, &b, &c);
cin >> a >> b >> c;



// 줄 입력 ([^\n], '\n'은 delim)
char str[1000];

scanf("%[^\n]", str);
cin.getline(str, 1000, '\n');



// 메모리 할당
struct Node { int vertex; Node *next; };

Node *node = malloc(sizeof(node));
Node *node = new Node;



// pair, tuple
#include <utility>  // pair

pair<int, char> p = { 1, 'a' };
auto [i, c] = p;

pair<int, char> p = make_pair(1, 'a');
int i = p.first;  // get<0>(p)
char c = p.second;  // get<1>(p)


#include <tuple>  // tuple
tuple<int, char, double> t = { 1, 'a', 1.234 };
auto [i, c, f] = t;

pair<int, char> t = make_tuple(1, 'a', 1.234);
int i = get<0>(t);
char c = get<1>(t);

