#include <memory>
#include "globals.h"

// Initialize global vars
resource_manager r_manager;

actor_ptr player_ptr(new player("images/paddle_player.png", 100, 100, 38, 150));
actor_ptr enemy_ptr(new paddle("images/paddle_enemy.png", 540, 100, 38, 150));
actor_ptr ball_ptr(new ball("images/ball.png", 320,240,64, 64));

sf::RenderWindow window(sf::VideoMode(640, 480), "Pang");

int g_cur_id = 0;

int g_player_score = 0;
int g_ai_score = 0;
std::map<int,shared_ptr<actor>> actors;
vector<shared_ptr<actor>> actors_add_list;
vector<int> actors_cull_list;


