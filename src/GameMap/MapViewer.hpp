#ifndef SRC_GAMEMAP_MAPVIEWER_HPP
#define SRC_GAMEMAP_MAPVIEWER_HPP

#include "GameMap.hpp"
#include "../Misc/Console.hpp"

class MapViewer
{
public:
    static void View(GameMap map)
    {
        Console::Clear();
        Console::Line();
        Console::Log("Select row/column\nenumeration: 0-2\n");
        Console::Line();
        Console::Log("\n\n");
        map.Print();
        Console::Log("\n\n");
        Console::Line();
    }
};

#endif