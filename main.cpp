#define OLC_PGE_APPLICATION

#include "RayCaster/rayCaster.hpp"

int main(void)
{

    RayCaster demo;

    if (demo.Construct(1280, 800, 1, 1))
		demo.Start();

    return 0;
}