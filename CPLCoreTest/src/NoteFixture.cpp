#include <NodeBase.h>
#include "gtest/gtest.h"


class NodeSuite : public ::testing::Test {

protected:
    virtual void SetUp() {

    }

    //Node n;
};


TEST_F(NodeSuite, TestBla) {
    ASSERT_EQ(0,0);
    ASSERT_EQ(1, 0);
}
