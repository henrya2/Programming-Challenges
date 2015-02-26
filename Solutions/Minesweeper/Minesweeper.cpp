/***
	Minesweeper
	http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110102&format=html
 ***/
#include <stdio.h>

int main()
{
	int m, n, count;
	int minRow, minCol, maxRow, maxCol;
	char arr[100][100];
	int i, j, k, l, aroundMines;
	char ch;

	count = 0;

	scanf("%d %d", &n, &m);
	getchar();
	while (n != 0 && m != 0) {
		count++;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				ch = getchar();
				if (ch == '.')
					arr[i][j] = '0';
				else 
					arr[i][j] = '*';
			}
			getchar();
		}

		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (arr[i][j] != '*') {
					minRow = (i == 0) ? 0:(i-1);
					minCol = (j == 0) ? 0:(j-1);

					maxRow = (i == n-1) ? (n-1):(i+1);
					maxCol = (j == m-1) ? (m-1):(j+1);

					aroundMines = 0;
					for (k = minRow; k <= maxRow; k++) {
						for (l = minCol; l <= maxCol; l++) {
							if (k == i && j == l) 
								continue;
							if (arr[k][l] == '*') {
								aroundMines++;
							}
						}
					}
					arr[i][j] += aroundMines;
				}
			}
		}

		if (count > 1) 
			putchar('\n');
		printf("Field \#%d:\n", count);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				putchar(arr[i][j]);
			}
			putchar('\n');
		}

		scanf("%d %d", &n, &m);
		getchar();
	}

	return 0;
}