#include "gtest/gtest.h"
#include "BaseCommand.h"

TEST(BaseCommand, DefaultConstructor) {
    BaseCommand b;

    ASSERT_EQ(b.getName(),"");
    ASSERT_EQ(b.getDevice(), "");
}


TEST(BaseCommand, Costructor) {
    BaseCommand* b;

    TCommandSchema schema;
    schema.insert(TCommandSchemaPair("direction","string"));

    b = new BaseCommand("cName","cDevice",schema);

    ASSERT_EQ(b->getName(),"cName");
    ASSERT_EQ(b->getDevice(),"cDevice");
    ASSERT_EQ(b->getRequestSchema(),schema);

    delete b;
}
