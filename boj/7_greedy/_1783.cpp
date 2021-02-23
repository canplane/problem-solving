// 별 거 아닌데 규칙성 생각하는 게 어렵네..

#include <cstdio>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int ans;
    if (N >= 3) {
        if (M >= 7)
            ans = M - 2;
        else if (M >= 4)
            ans = 4;
        else
            ans = M;
    }
    else if (N == 2) {
        if (M >= 7)
            ans = 4;
        else
            ans = (M - 1)/2 + 1;
    }
    else
        ans = 1;
    printf("%d", ans);
}

/*  // 참고용 (제출 번호 26246210)

#include <iostream>

using namespace std;

int main() {
	int n;
	int m;
	cin >> n;
	cin >> m;

	if (n == 1) {
		cout << 1;
	}
	else if (n == 2) {
		cout << min(4, (m + 1) / 2);
	}
	else {
		if (m < 7) {
			cout << min(4, m);
		}
		else {
			cout << m - 7 + 5;
		}
	}

	return 0;
}

 */