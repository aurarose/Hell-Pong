#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

#include "globals.h"
#include "actor.h"
#include "paddle.h"
#include "player.h"
#include "ball.h"

using namespace std;
using actor_ptr = shared_ptr<actor> ;

int main(){
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	// UI
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	
	// Texts
	sf::Text pscore_txt(to_string(g_player_score), font);
	sf::Text aiscore_txt(to_string(g_ai_score), font);
	sf::Text win_txt("You win! Press R to play again.", font);
	sf::Text lose_txt("You lose! Press R to play again.", font);

	aiscore_txt.setPosition(600, 0);
	win_txt.setPosition(250, 240);
	lose_txt.setPosition(250, 240);

	win_txt.setCharacterSize(16);
	lose_txt.setCharacterSize(16);

	string state = "playing";
	r_manager.loadSound("sound/bounce_orig.wav");
	r_manager.loadSound("sound/ricochet.wav");
	r_manager.loadSound("sound/hit.wav");

	player_ptr->setHitbox(14, 10, 2, 130);
	enemy_ptr->setHitbox(14, 10, 2, 130);

	actors[player_ptr->id] = player_ptr;
	actors[enemy_ptr->id] = enemy_ptr;

	while (window.isOpen()){

		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
		window.clear();
		if (g_ai_score < 19 && g_player_score < 19){
			for (auto it = actors.begin(); it != actors.end(); it++){
				(it->second)->update();
				(it->second)->draw();
			}
			auto it = actors_add_list.begin();
			while (it != actors_add_list.end()){
				actors[(*it)->id]=*it;
				it = actors_add_list.erase(it);
			}
			auto cull = actors_cull_list.begin();
			while (cull != actors_cull_list.end()){
				auto pos = actors.find(*cull);
				actors.erase(pos);
				cull = actors_cull_list.erase(cull);
			}

			actors_add_list.erase(actors_add_list.begin(),actors_add_list.end());

			pscore_txt.setString(to_string(g_player_score));
			aiscore_txt.setString(to_string(g_ai_score));
			window.draw(aiscore_txt);
			window.draw(pscore_txt);
		}
		else{
			if (g_ai_score >=19) window.draw(lose_txt);
			else window.draw(win_txt);

			

			state = "end";
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
				actors.erase(actors.begin(),actors.end());
				actors[player_ptr->id] = player_ptr;
				actors[enemy_ptr->id] = enemy_ptr;
				state = "play";
				g_ai_score = 0;
				g_player_score = 0;
			}
		}

		window.display();
	}
}
