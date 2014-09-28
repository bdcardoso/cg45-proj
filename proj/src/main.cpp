#include "vector3.h"
#include <iostream>

#define print_vector3(v) do { std::cout << #v << ": " << (v).x() << " " << (v).y() << " " << (v).z() << "\n"; } while (0)

#if 0
void print_vector3(const std::string &name, const vector3 &v) {
    std::cout << name << ": " << v.x() << " " << v.y() << " " << v.z() << std::endl;
}
#endif

int main() {
    vector3 v1, v2, v3(1.0, 2.0, 3.0);

    v1.x(3.0); v1.y(2.0); v1.z(1.0);
    print_vector3(v1);
    print_vector3(v2);
    print_vector3(v3);

    print_vector3(v1+v2);
    print_vector3(v1*3);
    print_vector3(v3-v1);

    return 0;
}

