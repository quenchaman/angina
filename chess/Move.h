//
// Created by ubuntu on 12/5/21.
//

#ifndef ANGINA_MOVE_H
#define ANGINA_MOVE_H

struct Move {
    Cell previous;
    Cell current;
    Side side;
    Rank rank;
};

#endif //ANGINA_MOVE_H
