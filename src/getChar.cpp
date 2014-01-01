/*
 * Tarot is an application for Android system to play to French Tarot.
 * Please visit https://github.com/richoux/Tarot for further information.
 * 
 * Copyright (C) 2013-2014 Florian Richoux
 *
 * This file is part of Tarot.
 * Tarot is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Tarot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Tarot.  If not, see http://www.gnu.org/licenses/.
 */

// From a dude on stackoverflow.com

#include <getChar.hpp>

using namespace std;

char getChar(const string& message)
{
  char out;
  string in;

  while(true) {

    cout << message;
    getline(cin,in);
    stringstream ss(in); //covert input to a stream for conversion to char

    if(ss >> out && !(ss >> in)) return out;
    //(ss >> out) checks for valid conversion to char
    //!(ss >> in) checks for unconverted input and rejects it

    cin.clear(); //in case of a cin error, like eof() -- prevent infinite loop
    cerr << "\nInvalid input. Please try again.\n"; //if you get here, it's an error
  }
}
