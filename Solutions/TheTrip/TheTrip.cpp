/***
	The Trip
	http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110103&format=html
 ***/
#include <stdio.h>
#include <math.h>

#define NUM_STUDENT 1000

void TheTripProc()
{
	double costs[1000];
	int num = 0;

	while (true)
	{
		scanf("%d", &num);
		if (num <= 0)
			break;
		
		for (int i = 0; i < num; i++)
		{
			scanf("%lf", &costs[i]);
		}
		
		double sum = 0.0f;
		for (int i = 0; i < num; i++)
		{
			sum += costs[i];
		}
		
		double avg = sum / num;
		
		avg = double((int)round(avg * 100)) / 100;
		
		double totalEx1 = 0.0f;
		double totalEx2 = 0.0f;
		for (int i = 0; i < num; i++)
		{
			if (costs[i] < avg)
			{
				totalEx1 += avg - costs[i];
			}
			else if (costs[i] > avg)
			{
				totalEx2 += costs[i] - avg;
			}
		}
		
		printf("$%.2lf\n", totalEx1 < totalEx2 ? totalEx1 : totalEx2);
	}
}

int main(int argc, char **argv)
{
	TheTripProc();
	return 0;
}