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
#include <iostream>
#include "symbols.h"

Symbols::Symbols() {
    std::vector<Token*> vct;
    this->_symbols = vct;
}

Symbols::~Symbols() {

    // Need to put on tests:
    typename std::vector<Token*>::iterator myIter=this->_symbols.begin();
    while(myIter!=this->_symbols.end()) {
        delete(*myIter);
        ++myIter;
    }
    this->_symbols.clear();

}

 void Symbols::add(const Type *type, const char *lexeme, int row, int col) {

    this->_symbols.push_back(new Token(type, lexeme, row, col));

}

void Symbols::print() {

    for (Token* token : this->_symbols) {

        std::cout << "Token: <" << token->type() << "-[" << token->lexeme()
                  << "]> row: " << token->row() << " col: " << token->col()
                  << std::endl;

    }

}

void Symbols::print_code() {

    for (auto token : this->_symbols) {
        if (token->isCode()) {
            std::cout << "Token: <" << token->type() << "-[" << token->lexeme()
                      << "]> row: " << token->row() << " col: " << token->col()
                      << std::endl;
        }
    }

}
