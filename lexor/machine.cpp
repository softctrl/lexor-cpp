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
#include "machine.h"
#include "state_exception.h"
#include "lexor_exception.h"
#include <iostream>

Machine::Machine(Reader *_reader) {

    this->_reader = _reader;
    this->_symbols = new Symbols();

}

Machine::~Machine() {}

void Machine::set_init_state(State *init_state){
    this->_init_state = init_state;
}

Symbols *Machine::get_symbols() {
    return this->_symbols;
}

void Machine::proccess() {

    // Read the first source code character:
    int value = this->_reader->next();

    // Get the initial State:
    State* st = this->_init_state;

    // Initialize auxiliar variables:
    std::string str(std::string(""));
    char ch = '\0';

    while (value != Reader::_EOF_) { // While is not the end of the source code:

        // Experimental-Panic Support:
        // Identify the next state based on the informed character:
        PanicResult *p = panic_next_transiction(st, value);

        while (p->state()->is_initial() && value != Reader::_EOF_) { //
            value = this->_reader->next();
            p = panic_next_transiction(st, value);
        }

        st = p->state(); // Next State.
        value = p->value(); // Readed Character.

//        std::cout << "State: " << st->to_string() << " Char: " << (char)value << std::endl; // DEBUG

        // If value is differente of End-Of-File.
        if (value != Reader::_EOF_) {

            // Let the current state proccess the value:
            ch = st->read_char((char) value);
            if (st->is_valid_char(ch)) {
                str += ch;
                value = this->_reader->next();
            }

            while (value != Reader::_EOF_ && !st->is_final()) {

                p = panic_next_transiction(st, value); // Try to go to the next valid state:
                st = p->state(); // Next State.
                value = p->value(); // Readed Character.

//                std::cout << "State: " << st->to_string() << " Char: " << (char)value << std::endl; // DEBUG

                // Let the current state proccess the value:
                ch = st->read_char((char) value);
                if (st->is_valid_char(ch)) {
                    str += ch;
                    value = this->_reader->next();
                }



            }


        }

        if (!st->is_final() && value != Reader::_EOF_) st = st->next_transatcion((char)value);

        if (!str.empty()) {

            const char* word = str.c_str();
//            std::cout << "word: " << word << std::endl; // DEBUG

            if (this->is_keyword(word)) {
                std::string vl(word);
                this->add_symbol(Type::KEY_WORD, vl.c_str(), this->row(), this->col());
            } else {
                std::string vl(word);
                this->add_symbol(st->get_type(), vl.c_str(), this->row(), this->col());
            }

        }

        if (value == Reader::_EOF_) {

            this->add_symbol(Type::END_OF_FILE, "EOF", this->row(), this->col());
            if (!st->is_initial() && !st->is_final()) {
                // TODO: under development.
                // throw LexorException("we got a EOF withou a initial or final state");
                std::cout << "ERROR: we got a EOF withou a initial or final state" << std::endl;
            }

        }

        str.clear(); // Clear last lexeme.
        st = this->_init_state; // Move to the first state.

    }



}

PanicResult *Machine::panic_next_transiction(State *_state, int value) {

try_again:
    if (value != Reader::_EOF_) {

        try {
            return new PanicResult(_state->next_transatcion((char)value), value);
        } catch (StateException& e) {
            std::cout << "Next Transaction Error at row: " << std::to_string(this->row()) << " col: " << std::to_string(this->col()) << std::endl;
            e.error();
            value = this->_reader->next();
            goto try_again;
        } catch (std::exception& e) {
            std::cout << "Undefined Error at row: " << std::to_string(this->row()) << " col: " << std::to_string(this->col()) << " char:" << value << std::endl;
            std::cerr << e.what() << std::endl;
            value = this->_reader->next();
            goto try_again;
        }

    }
    return new PanicResult(_state, value);

}



void Machine::prior() {
    this->_reader->prior();
}

int Machine::row() {
    return this->_reader->row();
}

int Machine::col() {
    return this->_reader->col();
}

void Machine::add_symbol(const Type *type, const char* word, int row, int col) {
    this->_symbols->add(type, word, row, col);
}

int Machine::next() {
    return this->_reader->next();
}
