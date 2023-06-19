using namespace std;
#include <cstdio>
#include <cctype>
#include <stack>

char A[103], B[103];

void in_to_post(char *dst, char *src)
{
	char c, o;
	stack<char> op;
	while (*src) {
		switch (c = *src++) {
		case '+': case '-':
			while ((o = op.top()) != '(') {
				*dst++ = o, op.pop();
			}
			op.push(c);
			break;
		case '*': case '/':
			while ((o = op.top()) != '(') {
				if (!(o == '*' || o == '/'))
					break;
				*dst++ = o, op.pop();
			}
			op.push(c);
			break;
		case '(':
			op.push(c);
			break;
		case ')':
			while ((o = op.top()) != '(') {
				*dst++ = o, op.pop();
			}
			op.pop();
			break;
		default:
			*dst++ = c;
			break;
		}
	}
	*dst = '\0';
}

int main()
{
	char *p = A, c;
	*p++ = '(';
	while ((c = getchar()) != -1) {
		if (isspace(c))
			break;
		*p++ = c;
	}
	*p++ = ')';
	*p = '\0';
	
	in_to_post(B, A);
	printf("%s", B);
}