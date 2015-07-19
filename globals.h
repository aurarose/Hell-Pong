#include "player.h"
#include "ball.h"
#include "resource_manager.h"
#include <SFML/Graphics.hpp>
#include <memory>

#pragma once

using actor_ptr = shared_ptr<actor>;

extern resource_manager r_manager;
extern std::map<int, shared_ptr<actor>> actors;
extern vector<shared_ptr<actor>> actors_add_list;
extern vector<int> actors_cull_list;

extern actor_ptr player_ptr;
extern actor_ptr enemy_ptr;
extern actor_ptr ball_ptr;
extern sf::RenderWindow window;

extern int g_player_score;
extern int g_ai_score;

extern int g_cur_id;
