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
    Board b = Board(width, length);
    EXPECT_TRUE(player.getScore() == 2);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            b.setSign(i,j, player.getSign());

        }
    }
}