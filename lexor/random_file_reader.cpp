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
#include "random_file_reader.h"

int RandomFileReader::next() {

    if (this->_offset <= this->_last) {

        this->_source_code->seekg(++this->_offset, std::ios::beg);
        this->_current = (char) this->_source_code->get();

        if (this->_new_line) {
            this->_col = 0;
            this->_new_line = false;
        }

        switch (this->_current) {
        case '\n':
            this->_row++;
            this->_new_line = true;
            // this->_col = 0;
            // return this->next();
            return (int) this->_current;
        case '\t':
            this->_col += 3;
            return (int) '\t';
        default:
            this->_col++;
            return (int) this->_current;
        }

    } else {
        this->_current = '\0';
        return Reader::_EOF_;
    }

}

void RandomFileReader::prior() {}

int RandomFileReader::current() {
//    return this->_source_code->get();
    return (int) this->_current;
}

long RandomFileReader::row() {
    return this->_row;
}

long RandomFileReader::col() {
    return this->_col;
}
