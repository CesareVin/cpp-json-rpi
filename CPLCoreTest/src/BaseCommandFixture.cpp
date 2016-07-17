#include "BaseCommand.h"
#include "ICommand.h"
#include "gtest/gtest.h"


class BaseCommandSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
    	b.setDevice("dev_test");
    	b.setName("name_test");
    	TCommandSchema schema;// = {{"command1","int"},{"command2","string"}};
    	schema.insert(TCommandSchemaPair("command1","int"));
    	//schema.insert("","");
    	b.setRequestSchema(schema);
    }

    BaseCommand b;
};

TEST_F(BaseCommandSuite, TestgetName) {

    ASSERT_EQ("name_test",b.getName());
}
TEST_F(BaseCommandSuite, TestDevice) {

    ASSERT_EQ("dev_test",b.getDevice());
}
TEST_F(BaseCommandSuite, TestRequestSchema) {

	TCommandSchema schema = b.getRequestSchema();
	ASSERT_EQ(schema["command1"],"int");
}
