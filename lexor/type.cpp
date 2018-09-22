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
#include "type.h"

const Type* Type::END_OF_FILE = new Type("EOF", true);
const Type* Type::KEY_WORD = new Type("KW", true);

Type::Type(char* value, bool isCode) {
    this->_value = value;
    this->_is_code = isCode;
}

char* Type::value() const{
    return this->_value;
}

bool Type::isCode() const {
    return this->_is_code;
}
