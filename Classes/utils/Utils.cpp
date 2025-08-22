#include "Utils.h"

namespace Utils {

    void moveTo(Node* node, const Vec2& targetPos, float duration) {
        if (!node) return;
        auto moveAction = MoveTo::create(duration, targetPos);
        node->runAction(moveAction);
    }

}  // namespace utils
