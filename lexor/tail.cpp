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
#include "tail.h"
#include "reader.h"

Tail::Tail() {
    this->pos0 = new Pos();
    this->pos1 = new Pos();
}


void Tail::move(int c) {

    if (c == Reader::_NL_) {
        this->pos1->row++;
        this->pos1->col = 0;
        this->pos0->col++;
    } else if (c != Reader::_EOF_) {
        this->pos0->row = this->pos1->row;
        if (c == Reader::_TAB_) {
            this->pos0->col = this->pos1->col = this->pos1->col + 3;
        } else {
            this->pos0->col = ++this->pos1->col;
        }
    }

}

int Tail::row() {
    return this->pos0->row;
}

int Tail::col() {
    return this->pos0->col;
}
