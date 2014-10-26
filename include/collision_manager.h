#pragma once
#include "game_object.h"
#include <memory>
#include <unordered_set>
#include <vector>

class collision_manager {
    std::unordered_set<std::shared_ptr<game_object>> objs_;

public:
    void register_object(std::shared_ptr<game_object> obj);
    void unregister_object(std::shared_ptr<game_object> obj);

    std::vector<std::pair<bounding_box, std::shared_ptr<game_object>>>
    collisions(std::shared_ptr<game_object> obj) const;
};
