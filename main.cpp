#include "main.hpp"

int main(void)
{
    int width = VideoMode::getDesktopMode().width;
    int height = VideoMode::getDesktopMode().height;
    Clovicorn::Game(width, height, "Game");
    return EXIT_SUCCESS;
}