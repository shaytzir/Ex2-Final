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

/*TEST_F(Test_ReversiRules, ll)  {
    EXPECT_FALSE(rules.isThatAnOption())
}*/