#include "raylib.h"
namespace raycaster {
    class Player {
        Vector2 position;
        double direction;

    public:
        Player(const Vector2 &position, double direction);

        Player();

        const Vector2 &getPosition() const;

        double getDirection() const;

        void rotate(float angle);
    };
}
