#include "MapViewer.hpp"

void MapViewer::View(GameMap map)
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