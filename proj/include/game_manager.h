#pragma once
#include "game_object.h"
#include "light_source.h"
#include "camera.h"
#include <memory>
#include <vector>

class game_manager {
  std::vector<std::shared_ptr<game_object>> _game_objects;
  std::vector<std::shared_ptr<light_source>> _light_sources;
  std::vector<std::shared_ptr<camera>> _cameras;

public:
  game_manager();

  void display();
  void reshape(int w, int h);
  void keypress();
  void timer();
  void idle();
  void update();
  void init();
};
