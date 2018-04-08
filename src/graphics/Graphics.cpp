#include "Graphics.hpp"

using namespace std;
using namespace std::chrono;

Graphics::Graphics(int screen_width, int screen_height):
screenWidth(screen_width), screenHeight(screen_height) {
    start = high_resolution_clock::now();
    gScreenSurface = NULL;
    quit = false;
}

Graphics::~Graphics() {

}

/* Private functions */
SDL_Surface* Graphics::loadSurface( std::string path ) {
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;
}

/* Setup */
bool Graphics::init() {
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    } else {
        if(TTF_Init() == -1) {
            printf("TTF_Init: %s\n", TTF_GetError());
            success = false;
        }
        sdlWindow = SDL_CreateWindow( "ArkavQuarium", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
        if( sdlWindow == NULL ) {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        } else {
            gScreenSurface = SDL_GetWindowSurface( sdlWindow );
        }
    }
    return success;
}

void Graphics::close() {
    for (auto const& x : loadedSurfaces) {
        SDL_FreeSurface( x.second );
    }
    for (auto const& x : loadedFontSizes) {
        TTF_CloseFont( x.second );
    }
    SDL_DestroyWindow( sdlWindow );
    sdlWindow = NULL;
    SDL_Quit();
}

/* High level drawing */
void Graphics::drawBackground() {
    const string assetPath = "assets/graphics/aquarium.jpg";
    drawImage(assetPath, screenWidth / 2, screenHeight / 2);
}

void Graphics::drawGuppy(int x, int y, int level, Direction direction) {
    string assetPath = "assets/graphics/guppy";
    
    if (level == 1) {
        assetPath += "_small";
    } else if (level == 2) {
        assetPath += "_medium";
    } else {
        assetPath += "_large";
    }

    if (direction == Direction::left) {
        assetPath += "_left";
    } else {
        assetPath += "_right";
    }

    assetPath += ".png";
    drawImage(assetPath, x, y);
}

void Graphics::drawPiranha(int x, int y, int level, Direction direction) {

}

void Graphics::drawSnail(int x, int y, Direction direction) {
    string assetPath = "assets/graphics/snail";

    if (direction == Direction::left) {
        assetPath += "_left";
    } else {
        assetPath += "_right";
    }

    assetPath += ".png";
    drawImage(assetPath, x, y);
}

void Graphics::drawCoin(int x, int y) {

}

void Graphics::drawPellet(int x, int y) {

}

/* Low level rawing */
void Graphics::clearScreen() {
    SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 255, 255, 255));
}

void Graphics::updateScreen() {
    SDL_UpdateWindowSurface(sdlWindow);
}

void Graphics::drawImage(std::string filename, int x, int y) {
    if (loadedSurfaces.count(filename) < 1) {
        loadedSurfaces[filename] = loadSurface(filename);
    }

    SDL_Surface* s = loadedSurfaces[filename];

    SDL_Rect dest;
    dest.x = x - s->w/2;
    dest.y = y - s->h/2;
    dest.w = s->w;
    dest.h = s->h;
    SDL_BlitSurface(s, NULL, gScreenSurface, &dest);
}

void Graphics::drawText(std::string text, int font_size, int x, int y,
    unsigned char r, unsigned char g, unsigned char b) {
    if (loadedFontSizes.count(font_size) < 1) {
        loadedFontSizes[font_size] = TTF_OpenFont(fontPath, font_size);
    }

    TTF_Font* font = loadedFontSizes[font_size];
    SDL_Surface* result = TTF_RenderText_Blended(font, text.c_str(), {r, g, b});
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = result->w;
    dest.h = result->h;
    SDL_BlitSurface(result, NULL, gScreenSurface, &dest);
    SDL_FreeSurface(result);
}

/* Time */
double Graphics::timeSinceStart() {
    high_resolution_clock::time_point now = high_resolution_clock::now();
    return duration_cast<duration<double>>(now - start).count();
}

/* Input handling */
// Memproses masukan dari sistem operasi.
void Graphics::handleInput() {
    SDL_Event e;
    if (!tappedKeys.empty()) tappedKeys.clear();
    while( SDL_PollEvent( &e ) != 0 ) {
        if ( e.type == SDL_QUIT ) {
            quit = true;
        } else if (e.type == SDL_KEYDOWN && !e.key.repeat) {
            pressedKeys.insert(e.key.keysym.sym);
            tappedKeys.insert(e.key.keysym.sym);
        } else if (e.type == SDL_KEYUP) {
            pressedKeys.erase(e.key.keysym.sym);
        }
    }
}

// Mengembalikan apakah pengguna telah meminta keluar dengan menekan tombol
// keluar di jendela program ketika handle_input() terakhir dipanggil.
bool Graphics::quitPressed() {
    return quit;
}

// Untuk dua fungsi berikut, nama konstan kode yang tepat dapat dilihat di
// https://wiki.libsdl.org/SDL_Keycode pada kolom "SDL_Keycode Value".

// Mengembalikan himpunan kode tombol yang sedang ditekan pada saat
// handle_input() terakhir dipanggil.
const std::set<SDL_Keycode>& Graphics::getPressedKeys() {
    return pressedKeys;
}

// Mengembalikan himpunan kode tombol yang baru mulai ditekan pada saat
// handle_input() terakhir dipanggil.
const std::set<SDL_Keycode>& Graphics::getTappedKeys() {
    return tappedKeys;
}

