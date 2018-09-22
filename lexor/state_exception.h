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
#ifndef STATE_EXCEPTION_H
#define STATE_EXCEPTION_H

#include <iostream>
#include <exception>
#include <sstream>

/**
 * @brief The StateException class define state exception.
 */
class StateException : public std::exception {

    public:

        /**
         * @brief StateException
         */
        inline StateException() : StateException::StateException("undefined") {}

        /**
         * @brief StateException
         * @param __message
         */
        inline StateException(const char* __message) {
            this->_message = __message;
            this->_file    = __FILE__;
            this->_line    = __LINE__;
        }

        /**
         * @brief error print a message for this error.
         */
        virtual void error() {

            std::cout << "(" << this->_file << ":" << std::to_string(this->_line) << ") - " << this->_message << std::endl;

        }

    private:
        const char* _message;
        const char* _file;
        int _line;

};

#endif // STATE_EXCEPTION_H
