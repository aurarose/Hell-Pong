#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class resource_manager
{
public:
	resource_manager(){};
	// Returns a texture from string path. If not found in textures, it is added
	sf::Texture& lookUp(string);
	void loadSound(string path);
	void playSound(string path);
private:
	map<string,sf::Texture> textures;
	map<string, sf::Sound> sounds;
	map<string, sf::SoundBuffer> sound_buffers;
};

