//
// Created by shay on 11/23/17.
//
#include <gtest/gtest.h>
#include "../src/Board.h"



namespace {
    class Test_Board : public testing::Test {

    public:
        Board board = Board(8,8);

        Test_Board() {
            board;
        }
    };
}


TEST_F(Test_Board, checkIfInBordersFAIL)  {
    int width = board.getWidth();
    int height = board.getHeight();
    EXPECT_FALSE(board.isInBorders(-1,-1));
    EXPECT_FALSE(board.isInBorders(width + 1, height + 1));
    EXPECT_FALSE(board.isInBorders(width + 1, height));
    EXPECT_FALSE(board.isInBorders(width, height + 1));
    EXPECT_FALSE(board.isInBorders(width, height));

}

TEST_F(Test_Board, checkIfInBordersOk) {
    int width = board.getWidth();
    int height = board.getHeight();
    EXPECT_TRUE(board.isInBorders(0,0));
    EXPECT_TRUE(board.isInBorders(0,width -1));
    EXPECT_TRUE(board.isInBorders(height - 1, 0));
    EXPECT_TRUE(board.isInBorders(width - 1, height -1));
}

TEST_F(Test_Board, BoardIsFull) {
    EXPECT_FALSE(board.fullBoard());
}

TEST_F(Test_Board, BoardIsFullTrue) {
    for (int i = 0; i < board.getWidth(); i++) {
        for (int j = 0; j < board.getHeight(); j++) {
            board.getMatrix()[i][j] = 'c';
        }
    }
    EXPECT_TRUE(board.fullBoard());
}