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
#ifndef STATE_H
#define STATE_H

#include "type.h"

/**
 * @brief The State class define a common structure for all lexical machine states.
 */
class State {

    public:
        /**
         * @brief State
         */
        State();

        /**
         * @brief ~State
         */
        ~State();

        /**
         * @brief next_transatcion
         * @return
         */
        virtual State* next_transatcion(const char) { return 0; }

        /**
         * @brief is_initial
         * @return
         */
        virtual bool is_initial() { return false; }

        /**
         * @brief is_final
         * @return
         */
        virtual bool is_final() { return false; }

        /**
         * @brief is_single
         * @return
         */
        virtual bool is_single() {return false; }

        /**
         * @brief move_next
         * @return
         */
        virtual bool move_next() { return false; }

        /**
         * @brief get_type
         * @return
         */
        virtual const Type* get_type() { return 0; }

        /**
         * @brief read_char
         * @return
         */
        virtual char read_char(const char) { return '\0'; }

        /**
         * @brief is_valid_char
         * @param ch
         * @return
         */
        virtual bool is_valid_char(const char ch) { return ch != '\n' && ch != '\r' && ch != '\t'; }

        virtual const char* to_string() { return "class State"; }

    protected:

};

#endif // STATE_H
