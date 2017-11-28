//
// Shay Tzirin
// ID: 315314930
// YUval Hoch
// 204468474
//

#include <gtest/gtest.h>
#include "../src/ReversiRules.h"
#include "../src/HumanP.h"
#include "../src/Console.h"

namespace {
    class Test_ReversiRules: public testing::Test {
    public:
        Test_ReversiRules(): rules(new HumanP('X'), new HumanP('O'), new Console()){};

    protected:
        ReversiRules rules;

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



