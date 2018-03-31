#include <iostream>
#include <Windows.h>
#include <chrono>
#include <vector>

using namespace std;

int screenWidth = 120; //Console Screen Size. X = Cols & Y = Rows
int screenHeight = 40;

int mapWidth = 144;	//World Dimensions
int mapHeight = 96;

int playerX = 5;
int playerY = 5;
int playerVX = 0;
int playerVY = 0;

int cameraX = 0;
int cameraY = 0;

int main()
{
	wchar_t *screen = new wchar_t[screenWidth * screenHeight];
	HANDLE consoleHandle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(consoleHandle);
	DWORD bytesWritten = 0;

	// 16 x 3

	// 48 x 3 for width


	std::wstring map;          //^
	map += L"################################################################################################################################################";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              .";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                         x                                                                    #";
	map += L"#                                                                       xxx                                                                    #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              .";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"#                                                                                                                                              #";
	map += L"################################################################################################################################################";

	map[playerX + mapWidth * playerY] = '@';
	const int TICKS_PER_SECOND = 10;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 10;

	DWORD next_game_tick = GetTickCount();
	int loops;
	bool game_is_running = true;

	while (game_is_running)
	{
		loops = 0;

		while (GetTickCount() > next_game_tick && loops < MAX_FRAMESKIP)
		{
			// Update
			for (int i = 0; i < screenWidth * screenHeight; i++)
			{
				screen[i] = ' ';
			}

			

			if (GetAsyncKeyState((unsigned short)'A'))
			{
				if (map[(playerX - 1) + mapWidth * playerY] == '#')
				{
					playerVX ++;
				}
				else
				{
					playerVX--;
				}
				
			}


			if (GetAsyncKeyState((unsigned short)'D'))
			{
				if (map[(playerX + 1) + mapWidth * playerY] == '#')
				{
					playerVX --;
				}
				else
				{
					playerVX++;
				}
				
			}

			if (GetAsyncKeyState((unsigned short)'S'))
			{
				if (map[playerX + mapWidth * (playerY + 1)] == '#')
				{
					//playerVY = 0;
				}
				else
				{
					playerVY++;
				}
				
			}

			if (GetAsyncKeyState((unsigned short)'W'))
			{
				if (map[playerX + mapWidth * (playerY - 1)] == '#')
				{
					//playerVY = 0;
				}
				else
				{
					playerVY--;
				}
				
			}

			if (GetAsyncKeyState((unsigned short)'C'))
			{
				for (int x = 0; x < mapWidth - 1; x++)
				{
					for (int y = 0; y < mapHeight - 1; y++)
					{
						map[x + mapWidth * y] = ' ';
					}
				}
			}
			//int tempX = playerVX + playerX;           // This is where i gimmicked the replacement of stuff
			//int tempY = playerVY + playerY;
			//int oldX = playerX;
			//int oldY = playerY;
			//wchar_t item = map[tempX + mapWidth * tempY];
			playerX = playerVX + playerX;
			playerY = playerVY + playerY;
			if (playerX < 2) playerX = 2;
			if (playerX >= mapWidth) playerX = mapWidth - 2;
			if (playerY < 0) playerY = 1;
			if (playerY >= mapHeight) playerY = mapHeight - 2;
			map[playerX + mapWidth * playerY] = '@';


			//map[oldX + mapWidth * oldY] = item;
			cameraX = playerX - screenWidth / 2;
			cameraY = playerY - screenHeight / 2;
			// Clamp the camera to the boundaries of the map
			if (cameraX < 0) cameraX = 0;
			if (cameraX >= mapWidth - screenWidth) cameraX = mapWidth - screenWidth;
			if (cameraY < 0) cameraY = 0;
			if (cameraY >= mapHeight - screenHeight) cameraY = mapHeight - screenHeight;

			

			next_game_tick += SKIP_TICKS;
			loops++;
		}
		
		
		// Draw the map to the buffer. Offset the draw based on the camera coordinates
		for (int x = 0; x < screenWidth; x++)
		{
			for (int y = 0; y < screenHeight; y++)
			{
				//screen[playerX + screenWidth * playerY] = '@';
				screen[x + screenWidth * y] = map[(x + cameraX) + mapWidth * (y + cameraY)];
			}
		}

		// Display the Buffer
		screen[screenWidth * screenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(consoleHandle, screen, screenWidth * screenHeight, { 0,0 }, &bytesWritten);
	}
	delete screen;
}