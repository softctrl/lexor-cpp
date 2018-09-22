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
#ifndef MACHINE_H
#define MACHINE_H

#include "reader.h"
#include "symbols.h"
#include <unordered_set>
#include "state.h"

/**
 * @brief The PanicResult class define a sctructure that handle all panic results.
 */
class PanicResult {

    public:

        /**
         * @brief PanicResult
         * @param _st
         * @param _vlr
         */
        PanicResult(State *_st, int _vlr) {
            this->_st = _st;
            this->_vlr = _vlr;
        }

        /**
         * @brief state
         * @return
         */
        State *state() {
            return this->_st;
        }

        /**
         * @brief value
         * @return
         */
        int value() {
            return this->_vlr;
        }

    private:
        State *_st;
        int _vlr;

};

/**
 * @brief The Machine class all language machines need to implement this class.
 */
class Machine {
    public:

        /**
         * @brief Machine
         */
        Machine(Reader*);

        /**
         * @brief ~Machine
         */
        ~Machine();

        /**
          * @brief set_init_state
          */
         void set_init_state(State*);

         /**
          * @brief get_symbols
          * @return
          */
         Symbols* get_symbols();

         /**
          * @brief print_keywords
          */
         inline virtual void print_keywords() {}

         /**
          * @brief proccess
          */
         void proccess();

         /**
          * @brief panic_next_transiction
          * @return
          */
         PanicResult* panic_next_transiction(State*, int);

         /**
          * @brief next
          * @return
          */
         int next();

         /**
          * @brief prior
          */
         void prior();

         /**
          * @brief row
          * @return
          */
         int row();

         /**
          * @brief col
          * @return
          */
         int col();

    private:
        Reader* _reader;
        Symbols* _symbols;
        State* _init_state;

    protected:

        /**
         * @brief add_symbol add a symbol <word> with a <type> that was identified at line <row> and column <col>.
         * @param type Type of that symbol. eg.: Key Word.
         * @param word Symbol Value.
         * @param row row number.
         * @param col column number.
         */
        void add_symbol(const Type* type, const char* word, int row, int col);

        /**
         * @brief is_keyword validate when a symbol is a keyword.
         * @param word symbol value.
         * @return
         */
        virtual bool is_keyword(const char* word) = 0;

        /**
         * @brief reader
         * @return
         */
        inline const Reader* reader() {
            return this->_reader;
        }
};

#endif // MACHINE_H
