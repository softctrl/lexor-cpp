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
#ifndef RANDOM_FILE_READER_H
#define RANDOM_FILE_READER_H

#include "reader.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "lexor_exception.h"

/**
 * @brief The RandomFileReader class defines a reader that can access a file in a ramdomic way.
 */
class RandomFileReader : public Reader {

    public:

        /**
         * @brief RandomFileReader constructor.
         * @param filename the source code filename that will be analised.
         */
        inline RandomFileReader(const char* filename) : Reader::Reader() {

            this->_source_code = new std::ifstream;
            this->_source_code->open(filename, std::ios::in | std::ios::out);
            if (this->_source_code->fail() || !this->_source_code->is_open()) {
                throw new LexorException("Unable to open source file:");
            }

            // Go to the end of the file so we can identify the last count:
            this->_source_code->seekg(0L, std::ios::end);
            this->_last = this->_source_code->tellg();

            // Now we move the the beginning of the file:
            this->_source_code->seekg(0L, std::ios::beg);
            this->_offset = -1;

        }

        /**
         * @brief ~RandomFileReader default destructor.
         */
        inline ~RandomFileReader() {

            if (this->_source_code != 0 && this->_source_code->is_open()) {
                this->_source_code->close();
            }

        }

        /**
         * @brief next move to the next character if it exists.
         * @return
         */
        int next() override;

        /**
         * @brief prior move to the prior character if it exists.
         */
        void prior() override;

        /**
         * @brief current get the currente charcater.
         * @return
         */
        int current() override;

        /**
         * @brief row get the current row.
         * @return
         */
        long row() override;

        /**
         * @brief col get the currente column.
         * @return
         */
        long col() override;

        /**
         * @brief close
         */
        inline void close() override { this->_source_code->close(); }

    private:
        /**
         * @brief _current current character get on the source file.
         */
        char _current;
        /**
         * @brief _offset inform how much we have moved into a source file.
         */
        long _offset;
        /**
         * @brief _last inform the length of the source file.
         */
        long _last;
        /**
         * @brief _row current row.
         */
        long _row;
        /**
         * @brief _last_col TODO:
         */
        long _last_col;
        /**
         * @brief _col current column.
         */
        long _col;

        /**
         * @brief _new_line
         */
        bool _new_line = false;
        /**
         * @brief _source_code random access file used to read the source file.
         */
        std::ifstream* _source_code;

};

#endif // RANDOM_FILE_READER_H
