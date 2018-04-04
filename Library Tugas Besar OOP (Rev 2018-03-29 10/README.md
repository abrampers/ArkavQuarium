# *Library* Grafik untuk Tugas Besar OOP

Untuk dapat menjalankan program yang menggunakan *library* ini, diperlukan
instalasi tiga *library*, yaitu:

 - SDL2
 - SDL2_Image
 - SDL2_TTF

Pada Ubuntu, ketiga *library* tersebut dapat diinstall dengan perintah berikut:

    apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev

Pada Fedora, ketiga *library* tersebut dapat diinstall dengan perintah berikut:

    yum install SDL2-devel SDL2_image-devel SDL2_ttf-devel

Untuk sistem lain, dapat mengikuti instruksi di halaman-halaman berikut:
 - [SDL2](http://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php)
 - [SDL2_Image](https://www.libsdl.org/projects/SDL_image/)
 - [SDL2_TTF](https://www.libsdl.org/projects/SDL_ttf/)

Untuk melihat fungsi-fungsi yang disediakan *library* ini, bacalah komentar di
file `oop.hpp` dan contoh pemakaian di `main.cpp`.

Disediakan sebuah Makefile sederhana untuk mengcompile seluruh program Anda.
Silakan dimodifikasi sesuai kebutuhan.
