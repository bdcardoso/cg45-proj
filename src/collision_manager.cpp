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

    bounding_box b1 = obj->bounding_box();
    b1.scale(obj->scale());
    b1.translate(obj->position());

    for (auto other : objs_) {
        if (obj != other) {
            auto b2 = obj->bounding_box();
            b2.scale(obj->scale());
            b2.translate(obj->position());
            auto isct = b1.intersect(b2);

            if (isct) {
                ret.emplace_back(isct, other);
            }
        }
    }

    return ret;
}

std::vector<std::pair<bounding_box, std::shared_ptr<game_object>>>
collision_manager::collisions(const game_object *obj) const {
    std::vector<std::pair<bounding_box, std::shared_ptr<game_object>>> ret;

    if (!obj)
        return ret;

    bounding_box b1 = obj->bounding_box();
    b1.scale(obj->scale());
    b1.translate(obj->position());

    for (auto other : objs_) {
        if (obj != other.get()) {
            auto b2 = other->bounding_box();
            b2.scale(other->scale());
            b2.translate(other->position());
            auto isct = b1.intersect(b2);

            if (isct) {
                ret.emplace_back(isct, other);
            }
        }
    }

    return ret;
}
