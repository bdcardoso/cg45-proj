#pragma once

template <typename T>
class singleton {
    // Hide copy and move constructors
    singleton(){}
    singleton(const singleton &) = delete;
    singleton(const singleton &&) = delete;
    void operator=(const singleton&) = delete;
    void operator=(const singleton&&) = delete;

    friend class game_manager;
    friend class collision_manager;

public:
    static T &instance() {
        static T instance;
        return instance;
    }
};

