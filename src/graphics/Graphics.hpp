#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "common/master.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <set>
#include <string>
#include <map>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Graphics {
private:
	const char* fontPath = "assets/fonts/OpenSans-Regular.ttf";
	const int screenWidth;
	const int screenHeight;
	
	high_resolution_clock::time_point start;
    SDL_Window* sdlWindow;
    SDL_Surface* gScreenSurface;
    std::map<std::string, SDL_Surface*> loadedSurfaces;
    std::map<int, TTF_Font*> loadedFontSizes;
    std::set<SDL_Keycode> pressedKeys;
    std::set<SDL_Keycode> tappedKeys;
    bool quit;

    SDL_Surface* loadSurface(std::string path);

public:
	Graphics(int screen_width, int screen_height);
	~Graphics();

	/* Setup */
	bool init();
	void close();

	/* High level drawing */
	void drawBackground();
	void drawGuppy(int x, int y, int level, Direction direction);
    void drawPiranha(int x, int y, int level, Direction direction);
    void drawSnail(int x, int y, Direction direction);
    void drawCoin(int x, int y);
    void drawPellet(int x, int y);

	/* Low level drawing */
	void clearScreen();
	void updateScreen();
	void drawImage(std::string filename, int x, int y);
	void drawText(std::string text, int font_size, int x, int y,
    	unsigned char r, unsigned char g, unsigned char b);

	/* Time */
	double timeSinceStart();

	/* Input handling */
	// Memproses masukan dari sistem operasi.
	void handleInput();

	// Mengembalikan apakah pengguna telah meminta keluar dengan menekan tombol
	// keluar di jendela program ketika handle_input() terakhir dipanggil.
	bool quitPressed();

	// Untuk dua fungsi berikut, nama konstan kode yang tepat dapat dilihat di
	// https://wiki.libsdl.org/SDL_Keycode pada kolom "SDL_Keycode Value".

	// Mengembalikan himpunan kode tombol yang sedang ditekan pada saat
	// handle_input() terakhir dipanggil.
	const std::set<SDL_Keycode>& getPressedKeys();

	// Mengembalikan himpunan kode tombol yang baru mulai ditekan pada saat
	// handle_input() terakhir dipanggil.
	const std::set<SDL_Keycode>& getTappedKeys();
};

#endif
