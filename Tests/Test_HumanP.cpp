//
// Created by shay on 11/27/17.
//

#include <gtest/gtest.h>
#include "../src/HumanP.h"


namespace {
    class Test_HumanP : public testing::Test {
    public:
        Test_HumanP():player('T'){};

    protected:
        HumanP player;

    };
}

TEST_F(Test_HumanP, InvalidKind) {
    char kind = player.getSign();
    EXPECT_FALSE(kind == ' ');
    EXPECT_FALSE(kind != 'T');
}

TEST_F(Test_HumanP, checkScoreForPlayer) {
    EXPECT_FALSE(player.getScore() < 0);
    int width = 8;
    int length = 8;
    char other = 'O';
    Board b = Board(width, length, player.getSign(), other);

    EXPECT_TRUE(player.getScore() == 2);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            if (b.getSign(i, j) != player.getSign()) {
                b.setSign(i, j, player.getSign());
                player.ScoreUp(1);
            }
        }
    }

    EXPECT_FALSE(player.getScore() == 2);
    EXPECT_FALSE(player.getScore() > width * length);
}

TEST_F(Test_HumanP, checkMovesForHumanP) {
    int width = 8;
    int length = 8;
    char other = 'O';
    Board* b = new Board(width, length, player.getSign(), other);


    vector<cell_t> moves = player.getMovesForPlayer(b, player.getSign());
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0 ; j < moves.size(); j++) {
            int moveIX = moves.at(i).x;
            int moveIY = moves.at(i).y;
            int moveJX = moves.at(j).x;
            int moveJY = moves.at(j).y;
            EXPECT_FALSE((moveIX == moveJX) && (moveIY == moveJY));
        }
    }

    for (int i = 0; i < b->getWidth(); i++) {
        for (int j = 0 ; j < b->getHeight(); j++) {
            b->setSign(i,j,player.getSign());
        }
    }

    EXPECT_TRUE(player.getMovesForPlayer(b, player.getSign()).empty());
}

