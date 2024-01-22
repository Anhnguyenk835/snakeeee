#include "GameMatch.h"

// change text inside color
void setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void draw_rec(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width)
{
	// if cannot draw => return
	if (height < 1 || width < 1) return;


	// draw a rectangle with border and no filling color
	for (int ix = x_pos + 1; ix < x_pos + width; ++ix) {
		GotoXY(ix, y_pos);
		cout << char(205);
		GotoXY(ix, y_pos + height);
		cout << char(205);
	}
	GotoXY(x_pos, y_pos);
	for (int iy = y_pos + 1; iy < y_pos + height; ++iy) {
		GotoXY(x_pos, iy);
		cout << char(186);
		GotoXY(x_pos + width, iy);
		cout << char(186);
	}
	GotoXY(x_pos, y_pos);
	cout << char(201);
	GotoXY(x_pos + width, y_pos);
	cout << char(187);
	GotoXY(x_pos, y_pos + height);
	cout << char(200);
	GotoXY(x_pos + width, y_pos + height);
	cout << char(188);
}

// draw box with words inside
void draw_underline(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, string text, int value, int txtColor, int bg_color, int line_color) {
	text_color(bg_color, txtColor);
	if (!text.empty()) {
		GotoXY(x_pos + (width - text.size()) / 2, y_pos + height / 2);
		cout << text;
		if (value != 0) cout << value;
	}
	text_color(bg_color, line_color);

	draw_rec(x_pos, y_pos, height, width);
}

//	draw_matchBoard
void draw_matchBoard(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, int &SCORE, int &LEVEL) {

	//      play_match2(1, 9, 45, 150, obs, obs_nums, SC, LE)
	// -> 	draw_matchBoard(x_pos, y_pos, height, width, SCORE, LEVEL); draw_matchBoard(1, 9, 45, 150, SC, LE)
	// -> x_pos = 1       y_pos = 9      height = 45         width = 150
	draw_rec(x_pos, y_pos, height, width); // draw_rec(1, 9, 45 , 150)
	draw_infoBoard(x_pos + width + 5, y_pos, height - 10, width - 107, 2, 0, 5);
	draw_underline(x_pos, height + y_pos + 1, 3, width - 65, "MAP: ", 1, 2, 0, 5); // draw map box
	draw_underline(width - 65 + 2, height + y_pos + 1, 3, width - (width - 65) - 1, "PLAYER: ", 1, 2, 0, 5); // draw player box
	draw_underline(x_pos + width + 5, y_pos + (height-10) + 1, 6, width - 107, "SCORE: ", SCORE, 2, 0, 5); // draw score box
	draw_underline(x_pos + width + 5, y_pos + (height-10) + 6 + 2, 6, width - 107, "LEVEL: ", LEVEL, 2, 0, 5); // draw level box
}

// draw infor board
void draw_infoBoard(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, int txtColor, int bg_color, int line_color) {
	draw_rec(x_pos, y_pos, height, width);
	setTextColor(2);
	GotoXY(x_pos + 6, y_pos + 3); cout << "TUTORIAL";
	draw_underline(x_pos + 8, y_pos + 5, 2, 4, "W", 0, txtColor, bg_color, line_color);
	draw_underline(x_pos + 2, y_pos + 8, 2, 4, "A", 0, txtColor, bg_color, line_color);
	draw_underline(x_pos + 8, y_pos + 8, 2, 4, "S", 0, txtColor, bg_color, line_color);
	draw_underline(x_pos + 14, y_pos + 8, 2, 4, "D", 0, txtColor, bg_color, line_color);
	GotoXY(x_pos + 3, y_pos + 13); cout << "PAUSE:         PRESS U";
	GotoXY(x_pos + 3, y_pos + 15); cout << "EXIT:          PRESS ESC";
}

// draw obstacle from create_obs
void draw_obstacle(Point obs[], int obs_nums) {
	for (int i = 0; i < obs_nums; i++) {
		GotoXY(obs[i].x, obs[i].y);
		cout << char(219);
	}
}

//void draw_game(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obs[], int obs_nums) {
//	draw_matchBoard(x_pos, y_pos, height, width);
//	draw_obstacle(obs, obs_nums);
//}


