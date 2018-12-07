#include<bits/stdc++.h>
using namespace std;
struct Node {
	int left, right;
};
int main() {
	while (true) {
		int s, b;
		scanf("%d %d", &s, &b);
		if (!s && !b) break;
		Node node[100001];
		for (int i = 1; i <= s; i++)
			node[i] = { i - 1, i + 1 };
		
		while (b--) {
			int l, r;
			scanf("%d %d", &l,&r);
			if (node[l].left == 0) printf("* ");
			else printf("%d ", node[l].left);

			if (node[r].right == s+1) printf("*\n");
			else printf("%d\n", node[r].right);

			node[node[l].left].right = node[r].right;
			node[node[r].right].left = node[l].left;
		}
		printf("-\n");
	}
}
