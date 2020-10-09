#include "Piece.hpp"

static Piece& pieceRow(Piece&& piece) { return piece; }

const std::vector<Piece> Piece::m_pieces = std::vector<Piece>{
    pieceRow(Piece(parsePoints("0 0 0 1 0 2 0 3"))),  // 0
    pieceRow(Piece(parsePoints("0 0 0 1 0 2 1 0"))),  // 1
    pieceRow(Piece(parsePoints("0 0 1 0 1 1 1 2"))),  // 2
    pieceRow(Piece(parsePoints("0 0 1 0 1 1 2 1"))),  // 3
    pieceRow(Piece(parsePoints("0 1 1 1 1 0 2 0"))),  // 4
    pieceRow(Piece(parsePoints("0 0 0 1 1 0 1 1"))),  // 5
    pieceRow(Piece(parsePoints("0 0 1 0 1 1 2 0"))),  // 6
};
