#pragma once

#ifndef SEARCHER_H
#define SEARCHER_H

#include "Board.h"
#include "Evaluator.h"
#include "MoveGen.h"
#include "MoveOrderer.h"
#include "TranspositionTable.h"

#include <atomic>

class Searcher {
private:
	std::atomic<bool> cancelSearch;
	const int maxDeepening = 5;

	Board* board = nullptr;
	Evaluator evaluator;

	Move currentMove;
	int defaultAlpha = -2000000;
	int defaultBeta = 2000000;

	void iterativeSearch();
	int negaMax(int alpha, int beta, int depth, int maxDepth);
	uint64_t moveSearch(bool isMaximising, int depth, int maxDepth);
	int QuiescenceSearch();
public:
	MoveGen* moveGenerator = nullptr;
	MoveOrderer* orderer = nullptr;
	Move bestMove;
	int movesSince = 0;
	int movesSince0[218];
	int moves = 0;

	Searcher();
	Searcher(Board* board);
	~Searcher();
	void startSearch(int moveTimeMs);
	void endSearch();
	uint64_t perft(int depth);
};

#endif // !SEARCHER_H
