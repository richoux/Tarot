/*
* Tarot is an application for Android system to play to French Tarot.
* Please visit https://github.com/richoux/Tarot for further information.
* 
* Copyright (C) 2013 Florian Richoux
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

#pragma once

//! The enum containing all official biddings.
/*!
  The value is the coefficient used to multiply a part of points
  at the end of a game.
  Composed of:
    - none, used when we pass. Value = 0.
    - small, with a regular coefficient 1.
    - guard, with a coefficient 2.
    - guard_w, without the dog. Coefficient 4.
    - guard_a, against the dog. Coefficient 6.
 */
typedef enum
  {
    none = 0,
    small = 1,
    guard = 2,
    guard_w = 4,
    guard_a = 6
  } Biddings;
