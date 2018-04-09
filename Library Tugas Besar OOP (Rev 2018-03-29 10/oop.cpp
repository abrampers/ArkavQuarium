// Anda tidak perlu melakukan perubahan pada file ini untuk memenuhi spek
// wajib. Namun, hal tersebut diperbolehkan.
#include "oop.hpp"

#include <map>
#include <iostream>
#include <chrono>

using namespace std::chrono;

high_resolution_clock::time_point start = high_resolution_clock::now();

double time_since_start()
{
    high_resolution_clock::time_point now = high_resolution_clock::now();
        return duration_cast<duration<double>>(now - start).count();
}

SDL_Window* sdl_window;
std::map<std::string, SDL_Surface*> loaded_surfaces;
std::map<int, TTF_Font*> loaded_font_sizes;
SDL_Surface* g_screen_surface = NULL;

bool init()
{
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {

        if(TTF_Init() == -1) {
            printf("TTF_Init: %s\n", TTF_GetError());
            success = false;
        }
        sdl_window = SDL_CreateWindow( "ArkavQuarium", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( sdl_window == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            g_screen_surface = SDL_GetWindowSurface( sdl_window );
        }
    }

    return success;
}

void close()
{
    for (auto const& x : loaded_surfaces)
    {
        SDL_FreeSurface( x.second );
    }

    for (auto const& x : loaded_font_sizes)
    {
        TTF_CloseFont( x.second );
    }

    SDL_DestroyWindow( sdl_window );
    sdl_window = NULL;

    SDL_Quit();
}

SDL_Surface* loadSurface( std::string path )
{
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    return loadedSurface;
}

void draw_image(std::string filename, int x, int y) {
    if (loaded_surfaces.count(filename) < 1) {
        loaded_surfaces[filename] = loadSurface(filename);
    }

    SDL_Surface* s = loaded_surfaces[filename];

    SDL_Rect dest;
    dest.x = x - s->w/2;
    dest.y = y - s->h/2;
    dest.w = s->w;
    dest.h = s->h;
    SDL_BlitSurface(s, NULL, g_screen_surface, &dest);
}

void draw_text(std::string text, int font_size, int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (loaded_font_sizes.count(font_size) < 1) {
        loaded_font_sizes[font_size] = TTF_OpenFont(FONT_NAME, font_size);
    }

    TTF_Font* font = loaded_font_sizes[font_size];
    SDL_Surface* result = TTF_RenderText_Blended(font, text.c_str(), {r, g, b});
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = result->w;
    dest.h = result->h;
    SDL_BlitSurface(result, NULL, g_screen_surface, &dest);
    SDL_FreeSurface(result);
}

void clear_screen() {
    SDL_FillRect(g_screen_surface, NULL, SDL_MapRGB(g_screen_surface->format, 255, 255, 255));
}

void update_screen() {
    SDL_UpdateWindowSurface(sdl_window);
}

bool quit = false;
std::set<SDL_Keycode> pressed_keys;
std::set<SDL_Keycode> tapped_keys;

void handle_input() {
    SDL_Event e;
    if (!tapped_keys.empty()) tapped_keys.clear();
    while( SDL_PollEvent( &e ) != 0 )
        {
            if ( e.type == SDL_QUIT ) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN && !e.key.repeat) {
                pressed_keys.insert(e.key.keysym.sym);
                tapped_keys.insert(e.key.keysym.sym);
            } else if (e.type == SDL_KEYUP) {
                pressed_keys.erase(e.key.keysym.sym);
            }
        }
}

bool quit_pressed() {
    return quit;
}

const std::set<SDL_Keycode>& get_pressed_keys() {
    return pressed_keys;
}

const std::set<SDL_Keycode>& get_tapped_keys() {
    return tapped_keys;
}
