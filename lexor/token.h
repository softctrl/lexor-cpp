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
#ifndef TOKEN_H
#define TOKEN_H

#include "type.h"

/**
 * @brief The Token class
 */
class Token {

    public:
        /**
         * @brief Token
         * @param type
         * @param lexeme
         * @param row
         * @param col
         */
        Token(const Type* type, const char* lexeme, int row, int col);

        /**
         * @brief isCode
         * @return
         */
        bool isCode();

        /**
         * @brief lexeme return the lexeme value.
         * @return
         */
        const char* lexeme();

        /**
         * @brief row return row number where the lexeme was found.
         * @return
         */
        int row();

        /**
         * @brief col return column number where the lexeme was found.
         * @return
         */
        int col();

        /**
         * @brief type return the type of the lexeme.
         * @return
         */
        const char* type();

        /**
         * @brief to_string return a string representation of this lexeme.
         * @return
         */
        const char* to_string();

    private:
        const char* _lexeme = 0;
        int _row = -1;
        int _col = -1;
        const Type* _type = 0;
};

#endif // TOKEN_H
