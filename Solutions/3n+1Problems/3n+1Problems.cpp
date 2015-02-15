/***
 The 3n + 1 problem
 http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110101&format=html
 ***/

#include <stdio.h>

int CalculateThe3n_1SequenceLength(int n)
{
	int count = 1;
	int seq = n;
	
	while (seq != 1) {
		if (seq % 2 == 0) {
			seq /= 2;
		} else {
			seq = seq * 3 + 1;
		}
		count++;
	}
	
	return count;
}

int main(int argc, char** argv)
{
	int beginInt, endInt, x, y;
	while (scanf("%d %d", &x, &y) == 2) {
		int maxLength = 0;
		if (x > y) {
			beginInt = y;
			endInt = x;
		} else {
			beginInt = x;
			endInt = y;
		}
		for (int i = beginInt; i <= endInt; ++i) {
			int result = CalculateThe3n_1SequenceLength(i);
			if (result > maxLength) {
				maxLength = result;
			}
		}
		
		printf("%d %d %d\n", x, y, maxLength);
	}
	
	return 0;
}