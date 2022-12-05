#ifndef RAY_CASTER_APPLICATION
#define RAY_CASTER_APPLICATION

#include <cmath>

#include "../olcPixelGameEngine/olcPixelGameEngine.h"

class RayCaster : public olc::PixelGameEngine
{
	private:

        olc::vf2d playerPos = { 200.0f, 200.0f };
        float playerSpeed = 0.5f;

		static const int MAP_WIDTH_IN_PIXELS = 600;
        static const int MAP_HEIGHT_IN_PIXELS = 600;


        static const int MAP_ROWS = 20;
        static const int MAP_COLS = 20;

        const std::string map_layout[MAP_ROWS] = {
            "####################",
            "#......#..#..#...#.#",
            "#.......#..........#",
            "#.....#.#..........#",
            "#.....#.#..........#",
            "#.....###..........#",
            "#..................#",
            "#..................#",
            "#..................#",
            "#..................#",
            "##.................#",
            "#......#..#..#...#.#",
            "#.......#..........#",
            "#.....#.#..........#",
            "#.....#.#..........#",
            "#.....###..........#",
            "#..................#",
            "#..................#",
            "#..................#",
            "####################"
        };

        int tileWidth;
        int tileHeight;

        float fovInDegrees = 60.0f;

        float currentAngle = -90.0f;

        float numberOfRays = 100.0;
		
	public:
		RayCaster();

		bool OnUserCreate() override;

		bool OnUserUpdate(float fElapsedTime) override;
};


#endif