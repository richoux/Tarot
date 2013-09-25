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

//! The enum containing all official announcements.
/*!
  Composed of:
    - poignee (8, 10 or 13 trumps, respectively for a 5, 4 or 3-player game). 20 points.
    - double poignee (10, 13 or 15 trumps). 30 points.
    - triple poignee (13, 15, or 18 trumps). 40 points.
    - chelem (all tricks taken). 200 points if realized without announcement, 400 points with.
 */
enum Announcements
  {
    poignee = 20,
    double_poignee = 30,
    triple_poignee = 40,
    chelem = 400
  };
