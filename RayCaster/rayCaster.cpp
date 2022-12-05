#include "rayCaster.hpp"

RayCaster::RayCaster()
{
    sAppName = "Example";

    tileWidth = MAP_WIDTH_IN_PIXELS / MAP_COLS;
    tileHeight = MAP_HEIGHT_IN_PIXELS / MAP_ROWS;

    std::cout<<tileWidth<<" "<<tileHeight<<"\n";
}

bool RayCaster::OnUserCreate() 
{
    // Called once at the start, so create things here
    return true;
}

bool RayCaster::OnUserUpdate(float fElapsedTime) 
{
    float angleInRad = ( currentAngle * M_PI ) / 180.0 ;
    
    // erase previous frame
    Clear(olc::BLACK);
    

    olc::vf2d initPos = {playerPos.x, playerPos.y};

    // get the user input
    if (GetKey(olc::Key::A).bHeld) currentAngle -= 1.0f;
    if (GetKey(olc::Key::D).bHeld) currentAngle += 1.0f;
    if (GetKey(olc::Key::W).bHeld)
    {
        playerPos.x += playerSpeed * cos(angleInRad);
        playerPos.y += playerSpeed * sin(angleInRad);
    }
    if (GetKey(olc::Key::S).bHeld)
    {
        playerPos.x -= playerSpeed * cos(angleInRad);
        playerPos.y -= playerSpeed * sin(angleInRad);
    }

    // check the collision
    if(map_layout[int(playerPos.y/tileHeight)][int(playerPos.x/tileWidth)] == '#')
    {
        playerPos = initPos;
    }

    // draw the tiles(the map) on the left of the screen
    for(int i=0; i<MAP_ROWS; ++i)
    {
        for(int j=0; j<MAP_COLS; ++j)
        {
            switch (map_layout[i][j])
            {
            case '#':
                FillRect(j*tileWidth, i*tileHeight, tileWidth, tileHeight, olc::DARK_YELLOW);

                break;
            
            default:
                break;
            }
        }
    }

    // draw the player
    FillCircle(playerPos, 5, olc::CYAN);

    // draw the rays

    float inc = 0.1f;

    int verticalLinePos = MAP_WIDTH_IN_PIXELS;
    int lineWidth = (ScreenWidth() - MAP_WIDTH_IN_PIXELS) / numberOfRays;
    
    for(float angle = currentAngle - fovInDegrees/2; angle < currentAngle + fovInDegrees/2; angle += fovInDegrees/numberOfRays)
    {

        olc::vf2d newP = {playerPos.x, playerPos.y};
        float angleInRad = ( angle * M_PI ) / 180.0 ;

        while(map_layout[int(newP.y/tileHeight)][int(newP.x/tileWidth)] != '#')
        {
            newP.x += inc * cos(angleInRad);
            newP.y += inc * sin(angleInRad);
        }

        DrawLine(playerPos, newP);

        verticalLinePos += lineWidth;
    }

    return true;
}