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
#ifndef BASE_STATE_H
#define BASE_STATE_H

#include "state.h"
#include "machine.h"

/**
 * @brief The BaseState class is responsible for define a commun structure for all gramatical states.
 */
class BaseState : public State::State {

    public:
        /**
         * @brief BaseState
         * @param machine It need to receive a valid lexical machine here.
         */
        BaseState(const Machine* machine);
        /**
         * @brief ~BaseState
         */
        ~BaseState();

    private:
        /**
         * @brief _machine
         */
        const Machine* _machine;

    protected:

        /**
         * @brief getMachine return the Lexical machine instance.
         * @return
         */
        inline const Machine* getMachine() {
            return this->_machine;
        }
};

#endif // BASE_STATE_H
