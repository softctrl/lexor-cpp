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
#ifndef LEXOR_EXCEPTION_H
#define LEXOR_EXCEPTION_H

#include <iostream>
#include <exception>
#include <string.h>

/**
 * @brief The LexorException class
 */
class LexorException : public std::exception {

        public:
            /**
             * @brief LexorException
             */
            inline LexorException() : LexorException::LexorException("undefined") {}
            /**
             * @brief LexorException
             * @param __message
             */
            inline LexorException(const char* __message) {
                this->_message = __message;
                this->_file    = __FILE__;
                this->_line    = __LINE__;
            }

            /**
             * @brief error print a message for this error.
             */
            inline void error() {

                std::cout << "(" << this->_file << ":" << std::to_string(this->_line) << ") - " << this->_message << std::endl;

            }

        private:
            const char* _message;
            const char* _file;
            int _line;

};

#endif // LEXOR_EXCEPTION_H
