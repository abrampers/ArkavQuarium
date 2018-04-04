#ifndef OOP_HPP
#define OOP_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <set>
#include <string>

// Pengaturan ukuran layar yang dihasilkan.
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Nama font yang digunakan untuk menggambar tulisan.
const char* const FONT_NAME = "OpenSans-Regular.ttf";

// ---------------------------------- SETUP ----------------------------------

// Melakukan inisialisasi terhadap program.
bool init();

// Menghentikan program.
void close();

// ------------------------------ PENGGAMBARAN -------------------------------

// Menggambar suatu gambar png, jpg, bmp sehingga tengah gambar berada di
// titik (x, y).
// Perubahan di layar baru muncul ketika update_screen() dipanggil.
void draw_image(std::string filename, int x, int y);

// Menuliskan teks berukuran font_size berwarna (r, g, b) ke layar sehingga
// kiri atas teks berada di titik (x, y).
// Perubahan di layar baru muncul ketika update_screen() dipanggil.
void draw_text(std::string text, int font_size,
               int x, int y,
               unsigned char r, unsigned char g, unsigned char b);

// Mengisi layar dengan warna putih.
// Perubahan di layar baru muncul ketika update_screen() dipanggil.
void clear_screen();

// Melakukan proses update terhadap layar.
void update_screen();

// --------------------------------- MASUKAN ---------------------------------

// Memproses masukan dari sistem operasi.
void handle_input();

// Mengembalikan apakah pengguna telah meminta keluar dengan menekan tombol
// keluar di jendela program ketika handle_input() terakhir dipanggil.
bool quit_pressed();

// Untuk dua fungsi berikut, nama konstan kode yang tepat dapat dilihat di
// https://wiki.libsdl.org/SDL_Keycode pada kolom "SDL_Keycode Value".

// Mengembalikan himpunan kode tombol yang sedang ditekan pada saat
// handle_input() terakhir dipanggil.
const std::set<SDL_Keycode>& get_pressed_keys();

// Mengembalikan himpunan kode tombol yang baru mulai ditekan pada saat
// handle_input() terakhir dipanggil.
const std::set<SDL_Keycode>& get_tapped_keys();

// ---------------------------------- WAKTU ----------------------------------

// Mengembalikan waktu dari permulaan program dalam nilai detik (bisa pecahan).
double time_since_start();

#endif
