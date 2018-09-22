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
#ifndef NON_FINAL_STATE_H
#define NON_FINAL_STATE_H

#include "base_state.h"

/**
 * @brief The NonFinalState class define all non final states that a language have.
 */
class NonFinalState : public BaseState::BaseState {

    public:
        /**
         * @brief NonFinalState
         */
        NonFinalState(const Machine*);

};

#endif // NON_FINAL_STATE_H
