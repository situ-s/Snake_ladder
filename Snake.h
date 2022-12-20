//
// Created by Situ Singh on 20/12/22.
//

#ifndef SNAKE_LADDER_SNAKE_H
#define SNAKE_LADDER_SNAKE_H

class Snake {
private:
    int m_start;
    int m_end;

public:
    Snake(int start, int end) {
        this->m_start = start;
        this->m_end = end;
    }

    int getStart() {
        return m_start;
    }

    int getEnd() {
        return m_end;
    }
};
#endif //SNAKE_LADDER_SNAKE_H
