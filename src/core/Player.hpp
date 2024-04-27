#include "raylib.h"
#include "World.hpp"
namespace raycaster {
    class Player {
        Vector2 position;
        double direction;
        const World& gameMap;
    public:
        Player(const Vector2 &position, double direction, const World &gameMap);

        const Vector2 &getPosition() const;

        double getDirection() const;

        void rotate(float angle);

        void move(Vector2 displacement);
    };
}
