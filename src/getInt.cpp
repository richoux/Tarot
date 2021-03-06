/*
 * Tarot is an application for Android system to play to French Tarot.
 * Please visit https://github.com/richoux/Tarot for further information.
 * 
 * Copyright (C) 2013-2016 Florian Richoux
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

#include <iostream>
#include <sstream>

#include "getInt.hpp"

using namespace std;

int getInt(const string& message)
{
  int out;
  string in;

  while(true) {

    cout << message;
    getline(cin,in);
    stringstream ss(in); //covert input to a stream for conversion to int

    if(ss >> out && !(ss >> in)) return out;
    //(ss >> out) checks for valid conversion to integer
    //!(ss >> in) checks for unconverted input and rejects it

    cin.clear(); //in case of a cin error, like eof() -- prevent infinite loop
    cerr << "\nInvalid input. Please try again.\n"; //if you get here, it's an error
  }
}
