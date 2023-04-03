#include <cstdlib>

#include "raylib.h" //Raylib. Without this everything will crash and burn.

#include "config.h" //This is a config file which has infos like the game name and window size.

#include "raymath.h" //Raymath includes various functions to work with raylibs Rectangle and Vector2 structs.

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60); //Target FPS limits the frame rate, otherwise the game would run as fast as it could.
    // You will generally have an easier time programming with a frame limitation.

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here.
    // This includes initialising your scenes and any kind of "engine" structure
    // ...
    Texture2D myTexture = LoadTexture("assets/graphics/testimage0.png");
    Texture2D myOtherTexture = LoadTexture("assets/graphics/testimage1.png");
    Color myColor = WHITE;
    // LoadTexture creates an entry in raylibs internal texture list and loads an image into VRAM and returns a Texture object.
        // The Texture object itself, here named myTexture, does NOT contain the image, just a reference to it.
        // This means that you can use it for call-by-value.
        // But this also means, that the image will NOT be unloaded when thrown off stack or using the "delete" keyword.
        // Instead, you need to use UnloadTexture()
    // There is also a LoadImage() function which instead loads the image into regular RAM.
        // While this allow to do some runtime editing of the pictures, it's generally not recommended to use.

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // If you have an object hierarchy in your project, this usually just means you call the Update() methods of those.
        // Otherwise, this space will get bloated FAST
        // ...
        // ...
        if(IsKeyPressed(KEY_A)){ // The IsKeyPressed() function will return TRUE if the key in question was just pressed in the current game loop.
            myColor = BLUE;
        }
        if(IsKeyReleased(KEY_A)){ // Should be self-explainatory.
            myColor = WHITE;
        }
        // Also included: There is a IsKeyDown() function, which detects if a key is currently held.

        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // Do not use these two functions anywhere else in the code unless you know what you're doing
            ClearBackground(myColor);
            // You should start every drawing cycle with ClearBackground(), though the color used generally does not matter.
                // This is because any drawing function of raylib just recolors the pixels on top the existing canvas.
            DrawText("Hello, world!", 10, 10, 30, LIGHTGRAY); // Example of Raylibs most basic text drawing function.
            DrawTexture(myTexture, 10, 100, WHITE); // Example of Raylibs most basic image drawing function.
            // This will draw the Texture in question at 1:1 scale.
            DrawTexture(myOtherTexture,GetMouseX()+30,GetMouseY()+30,WHITE);
            //The +30's are offsets so the image isn't obscured by your OS Cursor.
            //You can add a DisableCursor() call in the init and remove the offset if you wish. :)

        EndDrawing(); //Outputs the current state of canvas to screen.
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(myTexture);


    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
