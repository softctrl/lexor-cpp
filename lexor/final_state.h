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
#ifndef FINAL_STATE_H
#define FINAL_STATE_H

#include "base_state.h"

/**
 * @brief The FinalState class manage all final states that a language have.
 */
class FinalState : public BaseState::BaseState {

    public:
        /**
         * @brief FinalState creates a new final state. needs to inform a valid Lexical machine here.
         */
        FinalState(const Machine*);

        /**
         * @brief is_final
         * @return always true
         */
        bool is_final() override { return true; }

};

#endif // FINAL_STATE_H
