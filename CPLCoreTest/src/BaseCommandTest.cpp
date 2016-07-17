#include <BaseCommand.h>
#include "gtest/gtest.h"

TEST(Node, DefaultConstructor) {
    BaseCommand b;

    ASSERT_EQ(b.getName(),"");
    ASSERT_EQ(b.getDevice(),"");

}


TEST(Node, TestFightingMove) {
  /*
    GameCharacter c;
    c.setFighting(true);
    c.move(1, 1);

    ASSERT_FALSE(c.isFighting());*/
	BaseCommand b;

}
