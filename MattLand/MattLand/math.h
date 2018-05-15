#pragma once
#include <iostream>

enum Direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NORTHEAST,
	NORTHWEST,
	SOUTHEAST,
	SOUTHWEST
};

void setPlayerDirection(Direction &direction)
{
	if (pDir.x == 0 && pDir.y == 1)
		direction = NORTH;
	if (pDir.x == 0 && pDir.y == -1)
		direction = SOUTH;
	if (pDir.x == 1 && pDir.y == 0)
		direction = EAST;
	if (pDir.x == -1 && pDir.y == 0)
		direction = WEST;
	if (pDir.x == 1 && pDir.y == 1)
		direction = NORTHEAST;
	if (pDir.x == -1 && pDir.y == 1)
		direction = NORTHWEST;
	if (pDir.x == 1 && pDir.y == -1)
		direction = SOUTHEAST;
	if (pDir.x == -1 && pDir.y == -1)
		direction = SOUTHWEST;
}

void clearScreen(wchar_t * &screen)
{
	for (int i = 0; i < screenWidth * screenHeight; i++)
	{
		screen[i] = L' ';
	}
}

int getDistance(int x, int y, int u, int v)
{
	return (int)abs(sqrt(pow((u - x), 2) + pow((v - y), 2)));
}

void movementLogic( std::wstring &map, LevelMap &level )
{
	if (GetAsyncKeyState((unsigned short)'A'))
	{
		if (map[(player.x - 1) + level.mapWidth * player.y] == '#')
		{
			//pDir.x = 1;
			//pDir.y = 0;
			pVel.x - 1;//= -pVel.x;
		}
		else
		{
			pDir.x = -1;
			pDir.y = 0;
			pVel.x--;
		}

	}


	if (GetAsyncKeyState((unsigned short)'D'))
	{
		if (map[(player.x + 1) + level.mapWidth * player.y] == '#')
		{
			//pDir.x = -1;
			//pDir.y = 0;
			pVel.x - 1; // = -pVel.x;
		}
		else
		{
			pDir.x = 1;
			pDir.y = 0;
			pVel.x++;
		}

	}

	if (GetAsyncKeyState((unsigned short)'S'))
	{
		if (map[player.x + level.mapWidth * (player.y + 1)] == '#')
		{
			//pDir.y = -1;
			//pDir.x = 0;
			pVel.y - 1; //= -pVel.y;
		}
		else
		{
			pDir.y = 1;
			pDir.x = 0;
			pVel.y++;
		}

	}

	if (GetAsyncKeyState((unsigned short)'W'))
	{
		if (map[player.x + level.mapWidth * (player.y - 1)] == '#')
		{
			//pDir.y = 1;
			//pDir.x = 0;
			pVel.y - 1; // = -pVel.y;
		}
		else
		{
			pDir.y = -1;
			pDir.x = 0;
			pVel.y--;
		}

	}

	if (GetAsyncKeyState((unsigned short)'C'))
	{
		for (int x = 1; x < level.mapWidth - 1; x++)
		{
			for (int y = 1; y < level.mapHeight - 1; y++)
			{
				if (map[x + level.mapWidth * y] == character)
					map[x + level.mapWidth * y] = ' ';
			}
		}
	}

	if (GetAsyncKeyState((unsigned short)'E'))
	{
		map[(player.x + pDir.x) + level.mapWidth * (player.y + pDir.y)] = '#';
	}

	if (GetAsyncKeyState((unsigned short)'R'))
	{
		map[(player.x + pDir.x) + level.mapWidth * (player.y + pDir.y)] = ' ';
	}

	if (GetAsyncKeyState((unsigned short)'F'))
	{
		map[(player.x + 1) + level.mapWidth * (player.y + 1)] = ' '; // topright
		map[(player.x - 1) + level.mapWidth * (player.y - 1)] = ' '; // botleft
		map[(player.x - 1) + level.mapWidth * (player.y + 1)] = ' '; // topleft
		map[(player.x + 1) + level.mapWidth * (player.y - 1)] = ' '; // botright
		map[(player.x + 1) + level.mapWidth * (player.y)] = ' ';	 // right
		map[(player.x - 1) + level.mapWidth * (player.y)] = ' ';	 // left
		map[(player.x) + level.mapWidth * (player.y + 1)] = ' ';	 // up
		map[(player.x) + level.mapWidth * (player.y - 1)] = ' ';	 // down
	}

}

void collision(std::wstring &map, LevelMap &level)
{
	if (map[(player.x - 1) + level.mapWidth * player.y] == '#')
	{
		pVel.x = ++pVel.x;
	}

	if (map[(player.x + 1) + level.mapWidth * player.y] == '#')
	{
		pVel.x = --pVel.x;
	}

	if (map[player.x + level.mapWidth * (player.y + 1)] == '#')
	{
		pVel.y = --pVel.y;
	}

	if (map[player.x + level.mapWidth * (player.y - 1)] == '#')
	{
		pVel.y = ++pVel.y;
	}
}

void clampPlayerToMap(std::wstring &map, LevelMap &level)
{
	// Boundaries for the player (Edges of the map)
	if (player.x < 1) player.x = 1;
	if (player.x >= level.mapWidth) player.x = level.mapWidth - 1;
	if (player.y < 1) player.y = 1;
	if (player.y >= level.mapHeight - 1) player.y = level.mapHeight - 2;
}

void centerCameraToPlayer()
{
	camera.x = player.x - screenWidth / 2;
	camera.y = player.y - screenHeight / 2;
}

void clampCamera(LevelMap &level)
{
	if (camera.x < 0) camera.x = 0;
	if (camera.x >= level.mapWidth - screenWidth) camera.x = level.mapWidth - screenWidth;
	if (camera.y < 0) camera.y = 0;
	if (camera.y >= level.mapHeight - screenHeight) camera.y = level.mapHeight - screenHeight;
}

void updatePlayerPosition()
{
	player.x = pVel.x + player.x;
	if (pVel.x > maxVel.x)
		pVel.x = maxVel.x;
	if (pVel.x < -maxVel.x)
		pVel.x = -maxVel.x;
	pVel.x = 0;

	player.y = pVel.y + player.y;
	if (pVel.y > maxVel.y)
		pVel.y = maxVel.y;
	if (pVel.y < -maxVel.y)
		pVel.y = -maxVel.y;
	pVel.y = 0;
}

void animation(std::wstring &map, LevelMap &level, int count)
{
	for (int x = 0; x < level.mapWidth; x++)
	{
		for (int y = 0; y < level.mapHeight; y++)
		{
			if (count % 2 == 0 && (map[x + level.mapWidth * y] == L'»' || map[x + level.mapWidth * y] == L'^'))
			{

				map[x + level.mapWidth * y] = L'≈';
			}
			if (count % 2 != 0 && map[x + level.mapWidth * y] == L'≈')
			{
				map[x + level.mapWidth * y] = L'»';
			}

		}
	}
}

int getTextCount(wstring text)
{
	int count = 0;

	for (int i = 0; text[i] != '\0'; i++)
	{
		count += 1;
	}

	return count;
}

//void printText(wstring text, std::wstring &map, LevelMap &level)
