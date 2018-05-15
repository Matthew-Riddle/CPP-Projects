#include <iostream>
#include <Windows.h>
#include <chrono>
#include <vector>
#include <string>

#include "point.h"
using namespace std;

int screenWidth = 120; //Console Screen Size. X = Cols & Y = Rows
int screenHeight = 40;

int textBoxWidth = 120;
int textBoxHeight = 10;

Point maxVel(5, 5);
Point player(5, 5);
Point pVel(0, 0);
Point pDir(1, 0);
Point camera(0, 0);
Point mouse(0, 0);

//float fov = 3.14159 / 4;

int maxDistance = 5;


char character = '@';
int speed = 10;



#include "Map.h"
#include "math.h"

int main()
{
	wchar_t * screen = new wchar_t[screenWidth * screenHeight];
	HANDLE consoleHandle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(consoleHandle);
	DWORD bytesWritten = 0;

	//Map creation
	LevelMap level(144, 96);

	std::wstring map = level.levelmap();

	

	//map[player.x + level.mapWidth * player.y] = character;
	const int TICKS_PER_SECOND = 25;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 10;

	int ANIMATION_DELAY = 1000 / 4;
	int animateDelay = 0;


	DWORD next_game_tick = GetTickCount();
	int loops;
	bool game_is_running = true;
	Direction direction;
	int count = 0;

	while (game_is_running)
	{
		loops = 0;

		while (GetTickCount() > next_game_tick && loops < MAX_FRAMESKIP)
		{
			// Update
			clearScreen(screen);

			//Movement Logic
			clampPlayerToMap(map, level);
			movementLogic(map, level);
			Point ray(player.x, player.y);
		
			/*for (int distance = 0; distance < maxDistance; distance++)
			{
				setPlayerDirection(direction); // N, S, E, W, NE, NW, SE, SW

				// Update direction distance/step
				ray.x = pDir.x * distance + ray.x;
				ray.y = pDir.y * distance + ray.y;

				// Check for a collision
				if (map[ray.x + level.mapWidth * ray.y] == '#') // TODO Create enum for Collision blocks
				{
					if (NORTH || SOUTH)
					{
						pDir.y = -pDir.y;
					}
					else
					{
						pDir.x = -pDir.x;
					}

					switch (direction)
					{
					case NORTH:
						pDir.y = -pDir.y;
						break;
					case SOUTH:
						pDir.y = -pDir.y;
						break;
					case EAST:
						pDir.x = -pDir.x;
						break;
					case WEST:
						pDir.x = -pDir.x;
						break;
					case NORTHEAST:
						pDir.x = -pDir.x;
						break;
					case NORTHWEST:
						pDir.x = -pDir.x;
						break;
					case SOUTHEAST:
						pDir.x = -pDir.x;
						break;
					case SOUTHWEST:
						pDir.x = -pDir.x;
						break;
					}
				}

			}*/

			//collision(map, level);

			
			
			setPlayerDirection(direction);
			updatePlayerPosition();


			// Center the Camera on the player
			centerCameraToPlayer();

			// Clamp the camera to the boundaries of the map
			clampCamera(level);

			
			

			next_game_tick += SKIP_TICKS;
			loops++;
		}
		
		
		count++;
		//if (count > 1000)
		//	count = 0;

		animateDelay += 1;
		if (animateDelay > ANIMATION_DELAY)
		{
			animateDelay = 0;
			animation(map, level, count);
		}
		
		
		
		
		wstring hello = L"Hello there";
		// Draw the map to the buffer. Offset the draw based on the camera coordinates
		for (int x = 0; x < screenWidth; x++)
		{
			for (int y = 0; y < screenHeight; y++)
			{
				screen[x + screenWidth * y] = map[(x + camera.x) + level.mapWidth * (y + camera.y)];
			}
		}

		//for (int x = 0; x < screenWidth; x++)
		//{
		//	for (int y = 30; y < screenHeight; y++)
		//	{
		//		if (x <= 5 && y == 30)
		//			screen[x + screenWidth * y] = getTextCount(hello);
		//		else
		//			screen[x + screenWidth * y] = ' ';
		//	}
		//}
		screen[(player.x - camera.x) + screenWidth * (player.y - camera.y)] = character;
		screen[(player.x - camera.x + pDir.x) + screenWidth * (player.y - camera.y + pDir.y)] = '.';
		//swprintf_s((wchar_t*)screen, 40, L"VX = %03.i, VY = %03.i, X = %03.i, Y = %03.i", pDir.x, pDir.y, player.x, player.y);
		// Display the Buffer
		screen[screenWidth * screenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(consoleHandle, (wchar_t*)screen, screenWidth * screenHeight, { 0,0 }, &bytesWritten);
	}
	delete screen;
}