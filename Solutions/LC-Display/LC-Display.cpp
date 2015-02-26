/*** LC-Display
     http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110104&format=html
 ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REPEAT_ROW1 1
#define REPEAT_ROW2 3
#define REPEAT_COL 1

#define ROW 5
#define COLUMN 3

typedef char NumberSegements[5][4];

NumberSegements g_digitalNumbers[10] = {
	{
		{" - "},
		{"| |"},
		{"   "},
		{"| |"},
		{" - "}
	},
	{
		{"   "},
		{"  |"},
		{"   "},
		{"  |"},
		{"   "}
	},
	{
		{" - "},
		{"  |"},
		{" - "},
		{"|  "},
		{" - "}
	},
	{
		{" - "},
		{"  |"},
		{" - "},
		{"  |"},
		{" - "}
	},
	{
		{"   "},
		{"| |"},
		{" - "},
		{"  |"},
		{"   "}
	},
	{
		{" - "},
		{"|  "},
		{" - "},
		{"  |"},
		{" - "}
	},
	{
		{" - "},
		{"|  "},
		{" - "},
		{"| |"},
		{" - "}
	},
	{
		{" - "},
		{"  |"},
		{"   "},
		{"  |"},
		{"   "}
	},
	{
		{" - "},
		{"| |"},
		{" - "},
		{"| |"},
		{" - "}
	},
	{
		{" - "},
		{"| |"},
		{" - "},
		{"  |"},
		{" - "}
	}
};

void PrintDigitals(int size, char* digitals)
{
	int repeatRow = 1;
	int repeatColumn = 1;
	int strLen = strlen(digitals);
	
	for (int row = 0; row < ROW; ++row) {
		if (row == REPEAT_ROW1 || row == REPEAT_ROW2) {
			repeatRow = size;
		} else {
			repeatRow = 1;
		}
		
		for (int r = 0; r < repeatRow; ++r) {
			for (int i = 0; i < strLen; ++i) {
				for (int column = 0; column < COLUMN; ++column) {
					if (column == REPEAT_COL) {
						repeatColumn = size;
					} else {
						repeatColumn = 1;
					}
					
					for (int c = 0; c < repeatColumn; ++c) {
						putchar(g_digitalNumbers[digitals[i] - '0'][row][column]);
					}
				}
				if (i != strLen - 1)
					putchar(' ');
			}
			putchar('\n');
		}
	}
}

int main(int argc, char** argv)
{
	char sizeStr[20];
	char digitalStr[20];
	
	while (1) {
		scanf("%s %s", sizeStr, digitalStr);
		
		if (sizeStr[0] == '0')
			break;
			
		PrintDigitals(atol(sizeStr), digitalStr);
		putchar('\n');
	}
	
	return 0;
}
