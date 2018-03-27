
#include <iostream>
#include <conio.h>
#include <time.h>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

//Globals
const int ROWS = 30;
const int COLS = 30;
const int boardRows = 8;
const int boardCols = 8;
const char LIVE = 'X';
const char DEAD = ' ';
int random = 0;
int generation[ROWS][COLS];

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



string file;

void clearScreen()
{
	//HANDLE hOut;
	COORD Position;
	DWORD written;
	//hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	FillConsoleOutputCharacter(hConsole, ' ', 0, Position, &written);
	SetConsoleCursorPosition(hConsole, Position);
}

char newBoard[ROWS][COLS];

void popArray(string filename, char board[][COLS])
{
	ifstream myfile;
	myfile.open(filename.c_str());
	if (!myfile)
	{
		cout << "File not found.\n";
	}

	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			myfile >> board[r][c];
		}
	}
	myfile.close();

	for (int r = 0; r < ROWS - 2; r++)
	{
		for (int c = 0; c < COLS - 2; c++)
		{
			generation[r][c] = 0;
		}
	}
}

void drawboard(char board[][COLS])
{
	//srand(time(NULL));


	for (int r = 0; r < ROWS; r++)
	{
		cout << endl;
		for (int c = 0; c < COLS; c++)
		{
			//random = rand() % 4;
			if (r >= 10 && c >= 10 && r <= 20 && c <= 20)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			}
			else if (r >= 8 && c >= 8 && r <= 22 && c <= 22)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			else if (r >= 4 && c >= 4 && r <= 26 && c <= 26)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else if (r >= 1 && c >= 1 && r <= 28 && c <= 28)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else if (r <= 30 && c <= 30)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			cout << board[r][c] << "    ";
		}
		cout << endl;
	}
}

void checkboard(char board[][COLS])
{
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLS; c++)
		{
			int liveCnt = 0;
			if (board[r - 1][c - 1] == LIVE)
			{
				liveCnt++;
				generation[r][c] = 0;
			}
			if (board[r - 1][c] == LIVE)
			{
				liveCnt++;
				generation[r][c] = 0;
			}
			if (board[r - 1][c + 1] == LIVE)
			{
				liveCnt++;
				generation[r][c] = 0;
			}
			if (board[r][c - 1] == LIVE)
			{
				liveCnt++;
				generation[r][c] = 0;
			}
			if (board[r][c + 1] == LIVE)
			{
				liveCnt++;
				generation[r][c] = 0;
			}
			if (board[r + 1][c - 1] == LIVE)
			{
				liveCnt++;
				generation[r][c] = 0;
			}
			if (board[r + 1][c] == LIVE)
			{
				liveCnt++;
				generation[r][c] = 0;
			}
			if (board[r + 1][c + 1] == LIVE)
			{
				liveCnt++;
				generation[r][c] = 0;
			}
			else
			{
				generation[r][c] += 1;
			}

			newBoard[r][c] = DEAD;
			if (board[r][c] == '0')
			{
				newBoard[r][c] = ' ';
			}
			else if (generation[r][c] >= 20)
			{
				newBoard[r][c] = LIVE;
				generation[r][c] = 0;
			}
			else if (board[r][c] == LIVE && liveCnt < 2)
			{
				newBoard[r][c] = DEAD;
			}
			else if (board[r][c] == LIVE && (liveCnt == 2 || liveCnt == 3))
			{
				newBoard[r][c] = LIVE;
			}
			else if (board[r][c] == LIVE && liveCnt > 3)
			{
				newBoard[r][c] = DEAD;
			}
			else if (board[r][c] == DEAD && liveCnt == 3)
			{
				newBoard[r][c] = LIVE;
			}
		}
}

void switchBoard(char board[][COLS])
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			board[r][c] = newBoard[r][c];
		}
	}
}

int main()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = 0; //Set to invisible
	cursorInfo.dwSize = 1; // Required to set this for visibility to actually work, for some reason...... can be any number except 0
	SetConsoleCursorInfo(hConsole, &cursorInfo);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	
	int quit = 1;
	int count = 0;
	char board[ROWS][COLS];
	cout << "Enter file name: ";
	cin >> file;

	popArray(file, board);
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'p')
			{
				cin >> ch;
			}
		}
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		clearScreen();
		cout << endl << "Gen " << count << endl;
		drawboard(board);
		checkboard(board);
		switchBoard(board);
		count++;
		//Sleep(10);
		//cout << "Next = 1 Quit = 0";
		//cin >> quit;
	}
}