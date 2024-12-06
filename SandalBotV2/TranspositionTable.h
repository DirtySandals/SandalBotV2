#pragma once

#ifndef TRANSPOSITIONTABLE_H
#define TRANSPOSITIONTABLE_H

#include "ZobristHash.h"
#include "Move.h"

#include <limits>

class TranspositionTable : public ZobristHash {
	struct Entry {
		uint64_t hash = 0ULL;
		int eval = 0;
		int depth = 1000000;
		int nodeType;
		Move move;
		Entry() {}
		Entry(uint64_t hash, int eval, int depth, int nodeType, Move& move) {
			this->hash = hash;
			this->eval = eval;
			this->depth = depth;
			this->nodeType = nodeType;
			this->move = move;
		}
		Entry& operator=(const Entry& other) {
			this->hash = other.hash;
			this->eval = other.eval;
			this->depth = other.depth;
			this->nodeType = other.nodeType;
			this->move = other.move;

			return *this;
		}
	};
private:
	Entry* table = nullptr;
	size_t sizeMB = 0;
	size_t size;
public:
	static const int notFound = std::numeric_limits<int>::min();
	static const int exact = 0;
	static const int lowerBound = 1;
	static const int upperBound = 2;
	TranspositionTable();
	TranspositionTable(Board* board, int sizeMB);
	~TranspositionTable();
	Move& getBestMove();
	void store(int eval, int remainingDepth, int currentDepth, int nodeType, Move& move, u64 hashKey);
	int lookup(int remainingDepth, int currentDepth, int alpha, int beta, u64 hashKey);
	void clear();
	int adjustStoredMateScore(int eval, int currentDepth);
	int adjustMateScore(int eval, int currentDepth);
};

#endif // !TRANSPOSITIONTABLE_H
