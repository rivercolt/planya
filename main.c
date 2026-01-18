#include <raylib.h>
#include <time.h>
#include <stdio.h>


enum Months {
	Jan = 1,
	Feb,
	Mar,
	Apr,
	May,
	Jun,
	Jul,
	Aug,
	Sep,
	Oct,
	Nov,
	Dec
};


int main(void) {

	int screenWidth = 1920;
	int screenHeight = 1080;



	InitWindow(screenWidth, screenHeight, "planya");
	Font pixel_arial = LoadFont("./resources/pixelarial.ttf");
	SetTargetFPS(60);

	Vector2 point =  {0,  0};
	while (!WindowShouldClose())
	{


		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawTextEx(pixel_arial , "meow", point, 32, 2, BLACK);

		EndDrawing();



	};

	UnloadFont(pixel_arial);
	CloseWindow();
	return 0;
}
