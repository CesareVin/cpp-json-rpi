#include "gtest/gtest.h"
//#include "RPINode.h"


class RPINodeSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
    	/*b.setDevice("dev_test");
    	b.setName("name_test");
    	TCommandSchema schema;
    	schema.insert(TCommandSchemaPair("command1","int"));
    	b.setRequestSchema(schema);*/
    }

    //BaseCommand b;
};

TEST_F(RPINodeSuite, TestgetName) {

    //ASSERT_EQ("name_test",b.getName());
}
TEST_F(RPINodeSuite, TestDevice) {

    //ASSERT_EQ("dev_test",b.getDevice());
}
TEST_F(RPINodeSuite, TestRequestSchema) {

	//TCommandSchema schema = b.getRequestSchema();
	//ASSERT_EQ(schema["command1"],"int");
}
