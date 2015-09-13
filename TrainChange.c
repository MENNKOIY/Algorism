#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2


char *Station[] = { "", "新松戸", "柏", "松戸", "北千住", "上野",
"東京", "新木場", "西船橋", "船橋", "秋葉原", "錦糸町", "本八幡",
"住吉", "八柱", "津田沼", "千葉", "新津田沼", "南流山", "流山おおたかの森",
"大手町","春日部" , "品川", "新宿", "渋谷" };

char *Road[] = { "", "常磐線", "京葉線", "武蔵野線", "山手線",
"新京成線", "総武線", "都営新宿線", "半蔵門線", "東武野田線", "徒歩", "つくばエクスプレス"
, "京浜東北線", "東西線", "千代田線", "東海道線", "北総線", "京成線", "中央線" };

int linecolor[] = { 0, 32, 31, 31, 32, 35, 33, 32, 34, 37, 30, 31, 34, 34, 32 };

int queue[MAX], color[MAX], M[MAX][MAX], d[MAX], stack[MAX], p[MAX], rail[MAX][MAX];
int end, top, esp;

void enqueue(int n) {


	if (end == MAX)
		end = 0;

	queue[end] = n;
	end++;

}

int dequeue() {
	int retval;

	if (top == MAX)
		top = 0;


	retval = queue[top];

	top++;

	return retval;
}

void bfs(int s, int f) {
	int u, count = 0;
	enqueue(s);


	while (end != top) {
		u = dequeue();
		color[u] = BLACK;
		while (M[u][count] != 0) {
			if (color[M[u][count]] == WHITE) {
				enqueue(M[u][count]);
				color[M[u][count]] = GRAY;
				p[M[u][count]] = u;
				d[M[u][count]] = d[u] + 1;
			}
			count += 1;
		}

		count = 0;
	}

}

int main() {
	int count = 0, n, count2, id, num, f, s;
	scanf_s("%d", &n);
	for (count; count < n; count++) {
		scanf_s("%d %d", &id, &num);
		for (count2 = 0; count2 < num; count2++) {
			scanf_s("%d", &M[id][count2]);
			scanf_s("%d", &rail[id][M[id][count2]]);
		}

	}
	scanf_s("%d %d", &f, &s);

	bfs(s, f);

	count = f;
	printf("%s---", Station[f]);
	printf("%s", Road[rail[f][p[f]]]);
	printf("---");
	while (p[count] != s && count != s) {
		if (rail[count][p[count]] != rail[p[count]][p[p[count]]]) {
			printf("%s---", Station[p[count]]);	
			printf("%s", Road[rail[p[count]][p[p[count]]]]);
			printf("---");
		}
		count = p[count];
	}
