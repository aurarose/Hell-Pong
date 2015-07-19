#include "resource_manager.h"

sf::Texture& resource_manager::lookUp(string path){
	if (this->textures.find(path) == this->textures.end()){
		sf::Texture texture;
		if(texture.loadFromFile(path))
			this->textures[path] = texture;
	}
	return this->textures[path];
}

void resource_manager::loadSound(string path){
	sf::SoundBuffer buffer;
	if (this->sound_buffers.find(path) == this->sound_buffers.end())
		this->sound_buffers[path] = buffer;
	this->sound_buffers[path].loadFromFile(path);
	sf::Sound sound;
	sound.setBuffer(this->sound_buffers[path]);
	this->sounds[path] = sound;
}

void resource_manager::playSound(string path){
	this->sounds[path].play();
}