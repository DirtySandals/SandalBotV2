#include "PieceEvaluations.h"

short int PieceEvaluations::pawnEval[64] = {
     0,   0,   0,   0,   0,   0,   0,   0, 
    50,  50,  50,  50,  50,  50,  50,  50, 
    10,  10,  20,  30,  30,  20,  10,  10, 
     5,   5,  10,  25,  25,  10,   5,   5, 
     0,   0,   0,  30,  30,   0,   0,   0, 
     5,  -5, -10,   0,   0, -10,  -5,   5, 
     5,  10,  10, -20, -20,  10,  10,   5, 
     0,   0,   0,   0,   0,   0,   0,   0 
};

short int PieceEvaluations::pawnEndgameEval[64] = {
     0,   0,   0,   0,   0,   0,   0,   0,
    80,  80,  80,  80,  80,  80,  80,  80,
    50,  50,  50,  50,  50,  50,  50,  50,
    30,  30,  30,  30,  30,  30,  30,  30,
    20,  20,  20,  20,  20,  20,  20,  20,
    10,  10,  10,  10,  10,  10,  10,  10,
    10,  10,  10,  10,  10,  10,  10,  10,
     0,   0,   0,   0,   0,   0,   0,   0
};

short int PieceEvaluations::knightEval[64] = {
    -50, -40, -30, -30, -30, -30, -40, -50,
    -40, -20,   0,   0,   0,   0, -20, -40,
    -30,   0,  10,  15,  15,  10,   0, -30,
    -30,   5,  15,  20,  20,  15,   5, -30,
    -30,   5,  15,  20,  20,  15,   5, -30,
    -30,   0,  10,  15,  15,  10,   0, -30,
    -40, -20,   0,   0,   0,   0, -20, -40,
    -50, -40, -30, -30, -30, -30, -40, -50 
};

short int PieceEvaluations::bishopEval[64] = {
    -20, -10, -10, -10, -10, -10, -10, -20,
    -10,   0,   0,   0,   0,   0,   0, -10,
    -10,   0,   5,  10,  10,   5,   0, -10,
    -10,   5,   5,  10,  10,   5,   5, -10,
    -10,   0,  10,  10,  10,  10,   0, -10,
    -10,  10,  10,  10,  10,  10,  10, -10,
    -10,  15,   0,   0,   0,   0,  15, -10,
    -20, -10, -10, -10, -10, -10, -10, -20 
};

short int PieceEvaluations::rookEval[64] = {
     0,   0,   0,   0,   0,   0,   0,   0, 
     5,  10,  10,  10,  10,  10,  10,   5, 
    -5,   0,   0,   0,   0,   0,   0,  -5, 
    -5,   0,   0,   0,   0,   0,   0,  -5, 
    -5,   0,   0,   0,   0,   0,   0,  -5, 
    -5,   0,   0,   0,   0,   0,   0,  -5, 
    -5,   0,   0,   0,   0,   0,   0,  -5, 
     0,   0,   0,   5,   5,   0,   0,   0 
};

short int PieceEvaluations::queenEval[64] = {
    -20, -10, -10,  -5,  -5, -10, -10, -20,
    -10,   0,   0,   0,   0,   0,   0, -10,
    -10,   0,   5,   5,   5,   5,   0, -10,
     -5,   0,   5,   5,   5,   5,   0,  -5,
      0,   0,   5,   5,   5,   5,   0,  -5,
    -10,   5,   5,   5,   5,   5,   0, -10,
    -10,   0,   5,   0,   0,   0,   0, -10,
    -20, -10, -10,  -5,  -5, -10, -10, -20 
};

short int PieceEvaluations::kingEval[64] = {
    -30, -40, -40, -50, -50, -40, -40, -30,
    -30, -40, -40, -50, -50, -40, -40, -30,
    -30, -40, -40, -50, -50, -40, -40, -30,
    -30, -40, -40, -50, -50, -40, -40, -30,
    -20, -30, -30, -40, -40, -30, -30, -20,
    -10, -20, -20, -20, -20, -20, -20, -10,
     20,  20,   0,   0,   0,   0,  20,  20,
     20,  30,  25,   0,   0,   0,  20,  20 
};

short int PieceEvaluations::kingEndgameEval[64] = {
    -50, -40, -30, -20, -20, -30, -40, -50,
    -30, -20, -10,   0,   0, -10, -20, -30,
    -30, -10,  20,  30,  30,  20, -10, -30,
    -30, -10,  30,  40,  40,  30, -10, -30,
    -30, -10,  30,  40,  40,  30, -10, -30,
    -30, -10,  20,  30,  30,  20, -10, -30,
    -30, -30,   0,   0,   0,   0, -30, -30,
    -50, -30, -30, -30, -30, -30, -30, -50
};

short int* PieceEvaluations::pieceEvals[7] = { nullptr, pawnEval, knightEval, bishopEval, rookEval, queenEval, kingEval };
