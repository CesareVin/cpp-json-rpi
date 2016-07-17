#include <BaseCommand.h>
#include "gtest/gtest.h"

TEST(BaseCommand, DefaultConstructor) {
    BaseCommand b;


    ASSERT_EQ( b.getName(),"");

   // ASSERT_FALSE(c.isFighting());
}


TEST(BaseCommand, TestFightingMove) {
  /*  GameCharacter c;
    c.setFighting(true);
    c.move(1, 1);

    ASSERT_FALSE(c.isFighting());*/
}
