#pragma once
#include <iostream>

class LevelMap
{
public:
	
	int mapWidth;	//World Dimensions
	int mapHeight;

	LevelMap(int width, int height) : mapWidth(width), mapHeight(height){}

	

	std::wstring levelmap() 
	{
		std::wstring map;          //^
		map += L"################################################################################################################################################";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                            »»                #";
		map += L"#                 ^»»                      ^^                                                                                                  #";
		map += L"#                                                                                                                         »»»      »»          #";
		map += L"#                                            ^^^                                                                                               #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                 »»           #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#               ^»»                                      ##################                 »»»»»»»»»»»                                        #";
		map += L"#                                                        #                #                 »»»»»»»»»»»                                        #";
		map += L"#                                                        #                #                 »»»»»»»»»»»                                        #";
		map += L"#                                                        #                #                 »»»»»»»»»»»                                        #";
		map += L"#                                                        #####     ########                 »»»»»»»»»»»                                        #";
		map += L"#                                                                                           »»»»»»»»»»»                                        #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                               #  #                                                                           #";
		map += L"#                                                               #  #                                                                           #";
		map += L"#                       »»»»                                    #  #                                                                           #";
		map += L"#                                                                                                                                              #";
		map += L"#                           »»»                                                                                                                #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#           ^»^                                                                                                                                #";
		map += L"#                                                                          ^^                                                                  #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                              »»»                                             #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                             ^^                                               #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                        ^^^                                                                   #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                                                                              #";
		map += L"#                                                                                         »»»»^^                                               #";
		map += L"#                                                                                          ^^^^^                                               #";
		map += L"#                                                                                                                        ^^^                   #";
		map += L"#                                                                                                                          ^^                  #";
		map += L"#             »»»»                                                                                                                             #";
		map += L"#                 »»                                                                                                                           #";
		map += L"#              ^^ ^                                                                                                                            #";
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
		map += L"#                        ^^^^                                                                                                                  #";
		map += L"#                         ^^                                                                                                                   #";
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
		map += L"#                                                                                                 ^^^^^^^                                      #";
		map += L"#                                                     »»»»                                      ^^^^^^^^^^^                                    #";
		map += L"#                                                       ^^^                                   ^^^^^^^^^^^^^^^                                  #";
		map += L"#                                                                                            ^^^^^^^^^^^^^^^^^                                 #";
		map += L"#                                                                                             ^^^^^^^^^^^^^^^                                  #";
		map += L"#                                                                                              ^^^^^^^^^^^^^                                   #";
		map += L"#                                                                                               ^^^^^^^^^^^                                    #";
		map += L"#                                                                                                ^^^^^^^^^                                     #";
		map += L"################################################################################################################################################";

		return map;
	}
};