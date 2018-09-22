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
#ifndef SYMBOLS_H
#define SYMBOLS_H

#include <vector>
#include "token.h"

/**
 * @brief The Symbols class responsible for handle all founded symbols.
 */
class Symbols {

    public:

        /**
         * @brief Symbols
         */
        Symbols();

        /**
         * @brief ~Symbols
         */
        ~Symbols();

        /**
         * @brief add a new symbol on the table.
         * @param type
         * @param lexeme
         * @param row
         * @param col
         */
        void add(const Type* type, const char* lexeme, int row, int col);

        /**
         * @brief print
         */
        void print();

        /**
         * @brief print_code
         */
        void print_code();
    private:
        std::vector<Token*> _symbols;

};

#endif // SYMBOLS_H
