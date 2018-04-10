#include "Graphics.hpp"

using namespace std;
using namespace std::chrono;

Graphics::Graphics(int screen_width, int screen_height):
screenWidth(screen_width), screenHeight(screen_height) {
    start = high_resolution_clock::now();
    g_screen_surface = NULL;
    quit = false;
}

Graphics::~Graphics() {

}

/* Private functions */
SDL_Surface* Graphics::loadSurface( std::string path ) {
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    return loadedSurface;
}

/* Setup */
bool Graphics::init() {
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        if(TTF_Init() == -1) {
            printf("TTF_Init: %s\n", TTF_GetError());
            success = false;
        }
        sdl_window = SDL_CreateWindow( "ArkavQuarium", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
        if( sdl_window == NULL ) {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        } else {
            g_screen_surface = SDL_GetWindowSurface( sdl_window );
        }
    }
    return success;
}

void Graphics::close() {
    for (auto const& x : loaded_surfaces) {
        SDL_FreeSurface(x.second);
    }
    for (auto const& x : loaded_font_sizes) {
        TTF_CloseFont(x.second);
    }
    SDL_DestroyWindow(sdl_window);
    sdl_window = NULL;
    SDL_Quit();
}

/* High level drawing */
void Graphics::drawAquarium() {
    const string bgAssetPath = "assets/graphics/statics/aquarium_background.jpg";
    const string uiAssetPath = "assets/graphics/statics/aquarium_ui.png";
    drawImage(bgAssetPath, screenWidth / 2, screenHeight / 2);
    drawImage(uiAssetPath, screenWidth / 2, 87);
}

void Graphics::drawCoinText(int value) {
    drawText(to_string(value), 23, 885, 63, 166, 255, 112);
}

void Graphics::drawGuppy(int x, int y, int level, State state, int state_progress) {
    string assetPath = "assets/graphics/sprites/guppy";
 
    if (level == 1) {
        assetPath += "_small";
    } else if (level == 2) {
        assetPath += "_medium";
    } else {
        assetPath += "_large";
    }

    if (state == State::movingLeft) {
        assetPath += "/move_left";
    } else if (state == State::movingRight) {
        assetPath += "/move_right";
    } else if (state == State::turningLeft) {
        assetPath += "/turn_left";
    } else if (state == State::turningRight) {
        assetPath += "/turn_right";
    } else if (state == State::deadLeft) {
        assetPath += "/dead_left";
    } else if (state == State::deadRight) {
        assetPath += "/dead_right";
    }

    assetPath += "/" + to_string(state_progress + 1);

    assetPath += ".png";
    drawImage(assetPath, x, y);
}

void Graphics::drawPiranha(int x, int y, State state, int state_progress) {
    string assetPath = "assets/graphics/sprites/piranha";

    if (state == State::movingLeft) {
        assetPath += "/move_left";
    } else if (state == State::movingRight) {
        assetPath += "/move_right";
    } else if (state == State::turningLeft) {
        assetPath += "/turn_left";
    } else if (state == State::turningRight) {
        assetPath += "/turn_right";
    } else if (state == State::deadLeft) {
        assetPath += "/dead_left";
    } else if (state == State::deadRight) {
        assetPath += "/dead_right";
    }

    assetPath += "/" + to_string(state_progress + 1);
    
    assetPath += ".png";
    drawImage(assetPath, x, y);
}

void Graphics::drawSnail(int x, int y, State state, int state_progress) {
    string assetPath = "assets/graphics/sprites/snail";

    if (state == State::movingLeft) {
        assetPath += "/move_left";
    } else if (state == State::movingRight) {
        assetPath += "/move_right";
    } else if (state == State::turningLeft) {
        assetPath += "/turn_left";
    } else if (state == State::turningRight) {
        assetPath += "/turn_right";
    } else if (state == State::stillRight) {
        assetPath += "/move_right";
    } else if (state == State::stillLeft) {
        assetPath += "/move_left";
    }

    assetPath += "/" + to_string(state_progress + 1);

    assetPath += ".png";
    drawImage(assetPath, x, y);
}

void Graphics::drawCoin(int x, int y) {
    string assetPath = "assets/graphics/coin";
    assetPath += ".png";
    drawImage(assetPath, x, y);
}

void Graphics::drawPellet(int x, int y, int state_progress) {
    string assetPath = "assets/graphics/sprites/pellet";
    assetPath += "/" + to_string(state_progress + 1);
    assetPath += ".png";
    drawImage(assetPath, x, y);
}

/* Low level rawing */
void Graphics::clearScreen() {
    SDL_FillRect(g_screen_surface, NULL, SDL_MapRGB(g_screen_surface->format, 255, 255, 255));
}

void Graphics::updateScreen() {
    SDL_UpdateWindowSurface(sdl_window);
}

void Graphics::drawImage(string filename, int x, int y) {
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

void Graphics::drawText(std::string text, int font_size, int x, int y,
    unsigned char r, unsigned char g, unsigned char b) {
    if (loaded_font_sizes.count(font_size) < 1) {
        loaded_font_sizes[font_size] = TTF_OpenFont(fontPath, font_size);
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

/* Time */
double Graphics::timeSinceStart() {
    high_resolution_clock::time_point now = high_resolution_clock::now();
    return duration_cast<duration<double>>(now - start).count();
}

/* Input handling */
// Memproses masukan dari sistem operasi.
void Graphics::handleInput() {
    /* Get mouse position */
    SDL_GetMouseState(&mouse_x, &mouse_y);
    
    /* Handle input events */
    SDL_Event event;
    if (!tapped_keys.empty()) {
        tapped_keys.clear();
    }
    clicked_target = -1;

    while(SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            quit = true;

        } else if (event.type == SDL_KEYDOWN && !event.key.repeat) {
            pressed_keys.insert(event.key.keysym.sym);
            tapped_keys.insert(event.key.keysym.sym);

        } else if (event.type == SDL_KEYUP) {
            pressed_keys.erase(event.key.keysym.sym);

        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                for (int i = 0; i < click_targets.size(); i++) {
                    tuple<int, int, int, int> target = click_targets[i];
                    if (mouse_x >= get<0>(target) &&
                        mouse_x <= get<1>(target) &&
                        mouse_y >= get<2>(target) &&
                        mouse_y <= get<3>(target)) {
                        clicked_target = i;
                    }
                }
            }
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
const set<SDL_Keycode>& Graphics::getPressedKeys() {
    return pressed_keys;
}

// Mengembalikan himpunan kode tombol yang baru mulai ditekan pada saat
// handle_input() terakhir dipanggil.
const set<SDL_Keycode>& Graphics::getTappedKeys() {
    return tapped_keys;
}

int Graphics::addClickTarget(int x_min, int x_max, int y_min, int y_max) {
    tuple<int, int, int, int> target = make_tuple(x_min, x_max, y_min, y_max);
    click_targets.push_back(target);
    return click_targets.size() - 1;
}

void Graphics::resetClickTargets() {
    if (!click_targets.empty()) {
        click_targets.clear();
    }
}

const int& Graphics::getClickedTarget() {
    return clicked_target;
}

int Graphics::getMouseX() {
    return mouse_x;
}

int Graphics::getMouseY() {
    return mouse_y;
}

