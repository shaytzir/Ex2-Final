//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#include <gtest/gtest.h>
#include "../HumanP.h"


namespace {
    class Test_HumanP : public testing::Test {
    public:
        Test_HumanP():player('T'){};

    protected:
        HumanP player;

    };
}
/**
 * after setting a sign for a player, check the sign stays the same
 * cant intialize sign as " "
 */
TEST_F(Test_HumanP, InvalidKind) {
    char kind = player.getSign();
    EXPECT_FALSE(kind == ' ');
    EXPECT_FALSE(kind != 'T');
}

/**
 * checks the player cant have <0 points
 */
TEST_F(Test_HumanP, checkScoreForPlayer) {
    EXPECT_FALSE(player.getScore() < 0);
    int width = 8;
    int length = 8;
    Board b = Board(width, length, player.getSign(), 'O');
    char other = 'O';
    //when creating new board, the players score has to be 2
    EXPECT_TRUE(player.getScore() == 2);
    //after setting the entire board to hold one plalyers sign
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            if (b.getSign(i, j) != player.getSign()) {
                b.setSign(i, j, player.getSign());
                player.scoreUp(1);
            }
        }
    }
    //hid score cant stay "2"
    EXPECT_FALSE(player.getScore() == 2);
    //his score cant be larger than the board size
    EXPECT_FALSE(player.getScore() > width * length);
    EXPECT_TRUE(player.getScore() == width * length);
}

/**
 * checks the player moves are always valid
 */
TEST_F(Test_HumanP, checkMovesForHumanP) {
    int width = 8;
    int length = 8;
    char other = 'O';
    Board* b = new Board(width, length, player.getSign(), other);

    //setting board so for 2 location of player will get the same move
    b->setSign(2, 2, other);
    b->setSign(1, 3, other);
    b->setSign(3,2, player.getSign());
    b->setSign(1, 4, player.getSign());

    vector<cell_t> moves = player.getMovesForPlayer(b, player.getSign());
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0 ; j < moves.size(); j++) {
            if (i != j) {
                int moveIX = moves.at(i).x;
                int moveIY = moves.at(i).y;
                int moveJX = moves.at(j).x;
                int moveJY = moves.at(j).y;
                EXPECT_FALSE((moveIX == moveJX) && (moveIY == moveJY));
            }
        }
    }

    for (int i = 0; i < b->getWidth(); i++) {
        for (int j = 0 ; j < b->getHeight(); j++) {
            b->setSign(i,j,player.getSign());
        }
    }
    //after fiiling the entire board, the player wont have any moves
    EXPECT_TRUE(player.getMovesForPlayer(b, player.getSign()).empty());
}

