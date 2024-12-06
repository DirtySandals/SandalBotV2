#pragma once

#ifndef COORDHELPER_H
#define COORDHELPER_H

#include "StringUtil.h"

#include <string>

struct Coord {
	int row;
	int col;
	Coord(int row, int col);
	Coord(int index);
	Coord operator+(const Coord& other) const;
	int operator+(const int& other) const;
	Coord operator*(const int other) const;
	friend std::ostream& operator<<(std::ostream& os, const Coord& coord);
};

class CoordHelper {
public:
	static const std::string charFiles;
	static const std::string charRanks;
	static std::string indexToString(int index);
	static int stringToIndex(std::string str);
	static constexpr int indexToRow(int index);
	static constexpr int indexToCol(int index);
	static int coordToIndex(Coord coord);
	static int coordToIndex(int row, int col);
	static bool validCoord(Coord coord);
	static bool validCoordAddition(Coord coord, Coord direction);
	static bool validCoordAddition(Coord coord, Coord direction, int scalar);
	static bool validCoordAddition(int index, Coord direction);
	static bool validCoordAddition(int index, int move);
};

#endif