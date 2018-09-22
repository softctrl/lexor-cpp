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
#include "token.h"
#include <string>
#include "sc_string_utils.h"

Token::Token(const Type* type, const char *lexeme, int row, int col) {

    this->_type = type;
    SC::StringUtils::_strcpy(this->_lexeme, lexeme);
    this->_row = row;
    this->_col = col;
}

bool Token::isCode() {

    return this->_type == 0 ? false : this->_type->isCode();

}

const char *Token::lexeme() {
    return this->_lexeme;
}

int Token::row() {
    return this->_row;
}

int Token::col() {
    return this->_col;
}

const char *Token::type() {
    return (this->_type == 0 ? "??" : this->_type->value());
}

const char* Token::to_string() {

    std::string __str("");
    __str.append("Token: <")/*.append(this->_type == 0 ? "??" :this->_type->value())*/
            .append(",")/*.append(this->_lexeme)*/.append("> Linha: ")
            /*.append(std::to_string(this->_row))*/.append(" Coluna: ")
            /*.append(std::to_string(this->_col))*/;
    return __str.c_str();

}
