#include "raylib.h"
#include "World.hpp"
#include <map>
namespace raycaster {
    class Player {
    private:
        Vector2 position;
        double direction;
        const World& gameMap;
        const float m_SPEED = 3;
        std::map<std::string,float[2]> keyMap;
        void move(Vector2 displacement);
    public:
        Player(const Vector2 &position, double direction, const World &gameMap);

        const Vector2 &getPosition() const;

        double getDirection() const;

        void rotate(float angle);

        void actionByKeyCode();
    };
}
