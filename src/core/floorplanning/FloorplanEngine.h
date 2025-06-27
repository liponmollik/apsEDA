#ifndef FLOORPLAN_ENGINE_H
#define FLOORPLAN_ENGINE_H

#include <vector>
#include <string>
#include "MacroPlacer.h"
#include "PowerGridPlanner.h"
#include "Floorplan.h"

class FloorplanEngine
{
public:
    FloorplanEngine();
    ~FloorplanEngine();

    void loadNetlist(const std::string& netlistFile);
    void defineChipOutline(int width, int height);
    void runFloorplanning();

    std::shared_ptr<Floorplan> getFloorplan() const;

private:
    std::unique_ptr<MacroPlacer> macroPlacer;
    std::unique_ptr<PowerGridPlanner> powerPlanner;
    std::shared_ptr<Floorplan> floorplan;

    void placeIOPads();
};

#endif // FLOORPLAN_ENGINE_H
