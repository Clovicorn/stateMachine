#pragma once

#include <map>
#include <SFML/Graphics.hpp>

using namespace sf;
namespace Clovicorn
{
    class AssetManager
    {
    public:
        AssetManager() {}
        ~AssetManager() {}

        void loadTexture(std::string name, std::string fileName);
        Texture &getTexture(std::string name);

        void loadFont(std::string name, std::string fileName);
        Font &getFont(std::string name);

    private:
        std::map<std::string, Texture> _textures;
        std::map<std::string, Font> _fonts;
    };
}