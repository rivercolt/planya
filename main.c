#include <pthread.h>

#include <raylib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>


struct Resolution {

	int screenWidth;
	int screenHeight;
};


struct Borders {
	Rectangle border1;
	Rectangle border2;
	Rectangle border3;

};

struct Resolution getResolution();

enum Months {
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};


struct Borders drawUI(Color col1, Color col1grad, Color col2, int screenWidth, int screenHeight ) {
	//draw calculations
	Rectangle border1 = {5, 5, screenWidth-10, screenHeight/30.0f}; 
	Rectangle border2 = {5, (screenHeight/30.0f)+10, screenWidth/5.0f, (screenHeight-screenHeight/30.0f)-15};
	Rectangle border3 = {(screenWidth/5.0f)+10, (screenHeight/30.0f)+10, screenWidth-(screenWidth/5.0f)-15, (screenHeight-screenHeight/30.0f)-15};
	Rectangle border4 = {(screenWidth/5.0f)+10, (screenHeight/30.0f)+65, screenWidth-(screenWidth/5.0f)-15, (screenHeight-screenHeight/30.0f)-70};

	struct Borders borders1 = {border1, border2, border3};
	
	//draw gradients
	DrawRectangleGradientV(5, 5, screenWidth-10, screenHeight/30.0f, col1, col1grad);
	DrawRectangleGradientV(5, (screenHeight/30.0f)+10, screenWidth/5.0f, (screenHeight-screenHeight/30.0f)-15, col1, col1grad);
	DrawRectangleGradientV((screenWidth/5.0f)+10, (screenHeight/30.0f)+10, screenWidth-(screenWidth/5.0f)-15, (screenHeight-screenHeight/30.0f)-15, col1, col1grad);
	//draw borders
	DrawRectangleLinesEx(border1, 3, col2);
	DrawRectangleLinesEx(border2, 3, col2);
	DrawRectangleLinesEx(border3, 3, col2);
	DrawRectangleLinesEx(border4, 3, col2);
	return borders1;
}

void drawUIText(struct Borders borders, Font font, Color color) {

	Vector2 centerText3 = {(int)((borders.border3.x + borders.border3.width)/2)+75, (borders.border3.y) + 10} ;
	Vector2 origin = {0, 0};
	char monyr[] = "January 2026";
	DrawTextPro(font , monyr, centerText3, origin, 0, 40, 2, color);

}


void *clock1(void* arg){

	
	return NULL;
};

int main(void) {
	pthread_t thread1; 
	pthread_create(&thread1, NULL, clock1, NULL);
	pthread_join(thread1, NULL);

	Color x11gray = ColorFromHSV(-1,0, 7300/100.0f);
	Color darkCharcoal = ColorFromHSV(-1, 0, 2000/10.0f);
	Color darkCharcoal2 = ColorFromHSV(-1, 0, 1800/10.0f);
	struct Resolution win1 = getResolution();

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(win1.screenWidth, win1.screenHeight, "planya");

	Font pixel_arial = LoadFont("./resources/pixelarial.ttf");

	SetTargetFPS(60);
	
	time_t t = time(NULL);
	struct tm *ptr = localtime(&t);
	int year = (ptr->tm_year);
		

	printf("%s\n",	asctime(ptr));
	

	
//	char *test = ctime(ptr);
	
//	printf("%s\n", test);
	

	while (!WindowShouldClose())
	{
		int screenWidth = GetScreenWidth();
		int screenHeight = GetScreenHeight();

		BeginDrawing();
			ClearBackground(BLACK);
			struct Borders borders1 = drawUI(darkCharcoal, darkCharcoal2, x11gray, screenWidth, screenHeight);
			drawUIText(borders1, pixel_arial, x11gray);
		EndDrawing();
	};

	UnloadFont(pixel_arial);
	CloseWindow();

	return 0;
}

