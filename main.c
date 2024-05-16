#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define WIDTH 10
#define HEIGHT 10

volatile int X = 0, Y = 0;
char display[HEIGHT][WIDTH];

void Update_Display()
{
	system("csl");
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == Y && j == X)
			{
				printf("*");
			}
			else
			{
				printf("%c", display[i][j]);
			}
		}
		printf("\n");
	}
}

void Handle_Input(char c)
{
	switch (c)
	{
	case 'i':
		Y++;
		break;
	case 'k':
		Y--;
		break;
	case 'j':
		X--;
		break;
	case 'l':
		X++;
		break;
	case 'q':
		exit(0);
		break;
	default:
		break;
	}

	if (X < 0)
	{
		X = 0;
	}
	else if (X >= WIDTH)
	{
		X = WIDTH - 1;
	}

	if (Y < 0)
	{
		Y = 0;
	}
	else if (Y >= HEIGHT)
	{
		Y = HEIGHT - 1;
	}

	Update_Display();
	
}

int main()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			display[i][j] = '.';
		}
	}

	while (1)
	{
		if (_kbhit())
		{
			char input = _getch();
			Handle_Input(input);
		}
	}

	return 0;
}