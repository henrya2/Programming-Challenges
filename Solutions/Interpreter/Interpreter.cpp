/***
	Interpreter
	http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110106&format=html
 ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_REGISTERS 10
#define NUM_WORDS 1000

unsigned short g_registers[NUM_REGISTERS];
unsigned short g_rams[NUM_WORDS];

// The number of instructions executed up to and including the halt instruction
int g_instructionExeCount = 0;

void InterpreterProc()
{
        int op, param1, param2;

        bool flag = 0;
        int index = 0;
        while (!flag)
        {
            op = g_rams[index] / 100;
            param1 = g_rams[index] % 100 / 10;
            param2 = g_rams[index] % 10;

            index++;
            index %= NUM_WORDS;
            switch (op)
            {
                case 1:
                    flag = true;
                    break;
                case 2:
                    g_registers[param1] = param2;
                    break;
                case 3:
                    g_registers[param1] += param2;
                    g_registers[param1] %= NUM_WORDS;
                    break;
                case 4:
                    g_registers[param1] *= param2;
                    g_registers[param1] %= NUM_WORDS;
                    break;
                case 5:
                    g_registers[param1] = g_registers[param2];
                    break;
                case 6:
                    g_registers[param1] += g_registers[param2];
                    g_registers[param1] %= NUM_WORDS;
                    break;
                case 7:
                    g_registers[param1] *= g_registers[param2];
                    g_registers[param1] %= NUM_WORDS;
                    break;
                case 8:
                    g_registers[param1] = g_rams[g_registers[param2]];
                    break;
                case 9:
                    g_rams[g_registers[param2]] = g_registers[param1];
                    break;
                case 0:
                    if (g_registers[param2] != 0)
                        index = g_registers[param1];
                    break;

            }
            g_instructionExeCount++;
        }
}

int main()
{
    char buf[11];
    int n;

    scanf("%d\n", &n);
    for (; n > 0; n--)
    {
        memset(g_registers, 0, sizeof(g_registers));
        memset(g_rams, 0, sizeof(g_rams));

        g_instructionExeCount = 0;

        // read input
        int i = 0;
        while (fgets(buf, 10, stdin) != NULL && buf[0] != '\n')
        {
            g_rams[i++] = atoi(buf);
        }

        InterpreterProc();

        printf("%d\n", g_instructionExeCount);
        if (n > 1)
        {
            putchar('\n');
        }
    }
    return 0;
}