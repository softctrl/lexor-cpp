/*
 *
 * Author:
 *  Carlos Timoshenko
 *  carlostimoshenkorodrigueslopes@gmail.com
 *
 *  https://github.com/softctrl
 *
 * This project is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */
#ifndef TAIL_H
#define TAIL_H

/**
 * @brief The Pos class define token position into the source code.
 */
class Pos {

    public:
        int row = 0;
        int col  = 0;

        /**
         * @brief copy
         * @param pos
         */
        void copy(Pos* pos) {
            this->row = pos->row;
            this->col = pos->col;
        }

};

/**
 * @brief The Tail class handles the update of the position data, when machine reader read the source code file.
 */
class Tail {

    public:

        /**
         * @brief Tail
         */
        Tail();

        /**
         * @brief move based on a int that represents a valid char.
         * @param c
         */
        void move(int c);

        /**
         * @brief row return the value of the current row.
         * @return
         */
        int row();

        /**
         * @brief col return the value of the current column.
         * @return
         */
        int col();

    private:
        Pos* pos0;
        Pos* pos1;

};

#endif // TAIL_H
