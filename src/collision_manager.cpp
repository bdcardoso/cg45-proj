#include "collision_manager.h"

void collision_manager::register_object(std::shared_ptr<game_object> obj) {
    if (!obj) {
        return;
    }

    auto pos = objs_.find(obj);
    if (pos == objs_.end()) {
        objs_.emplace(obj);
    }
}

void collision_manager::unregister_object(std::shared_ptr<game_object> obj) {
    if (!obj) {
        return;
    }

    auto pos = objs_.find(obj);
    if (pos != objs_.end()) {
        objs_.erase(pos);
    }
}

std::vector<std::pair<bounding_box, std::shared_ptr<game_object>>>
collision_manager::collisions(std::shared_ptr<game_object> obj) const {
    std::vector<std::pair<bounding_box, std::shared_ptr<game_object>>> ret;

    if (!obj)
        return ret;

    for (auto other : objs_) {
        if (obj != other) {
            auto isct = obj->bounding_box().intersect(other->bounding_box());

            if (isct) {
                ret.emplace_back(isct, other);
            }
        }
    }

    return ret;
}
