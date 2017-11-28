//
// Created by shay on 11/24/17.
//

#include <gtest/gtest.h>
#include "../src/ReversiRules.h"
#include "../src/HumanP.h"
#include "../src/Console.h"


namespace {
    class Test_ReversiRules: public testing::Test {

    public:
        ReversiRules rules = ReversiRules(new HumanP('X'), new HumanP('O'), new Console());

        Test_ReversiRules() {
            rules;
        }
    };
}

TEST_F(Test_ReversiRules, isGameOver) {
    EXPECT_FALSE(rules.gameover());
}

TEST_F(Test_ReversiRules, InvalidOptionToChoose)  {
    EXPECT_FALSE(rules.isThatAnOption("1.1"));
    EXPECT_FALSE(rules.isThatAnOption("0,0"));
    EXPECT_FALSE(rules.isThatAnOption("-1,0"));
    EXPECT_FALSE(rules.isThatAnOption("2.5,7"));
    EXPECT_FALSE(rules.isThatAnOption("a,b"));
    EXPECT_FALSE(rules.isThatAnOption("2,5,6"));
}
