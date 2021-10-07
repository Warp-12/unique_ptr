#include <gtest/gtest.h>

#include "uniquePtr.hpp"

constexpr int initValueForFixture = 1;
constexpr int initValueForTestUniquePtrValue = 11;
constexpr int initValueForTestUniquePtrValueUsingArrow = 111;

class TestClassForUniquePtr {
    int value_;

   public:
    TestClassForUniquePtr(int value) : value_(value) {
    }
    int getValue() const {
        return value_;
    }
};

class UniquePtrFixture : public ::testing::Test {
   public:
    UniquePtrFixture() : fixtureUniquePtr_(new int{initValueForFixture}) {}
    unique_ptr<int> fixtureUniquePtr_;
};

TEST_F(UniquePtrFixture, TestUniquePtrConstructor) {
    SUCCEED();
}

TEST(UniquePtrTesting, TestUniquePtrValue) {
    unique_ptr<int> ptr{new int{initValueForTestUniquePtrValue}};
    ASSERT_EQ(*ptr, initValueForTestUniquePtrValue);
}

TEST(UniquePtrTesting, TestUniquePtrValueUsingArrow) {
    unique_ptr<TestClassForUniquePtr> ptr{new TestClassForUniquePtr(initValueForTestUniquePtrValueUsingArrow)};
    ASSERT_EQ(ptr->getValue(), initValueForTestUniquePtrValueUsingArrow);
}

TEST(UniquePtrTesting, TestUniquePtrReset) {
    unique_ptr<int> ptr{new int(initValueForTestUniquePtrValue)};
    ptr.reset();
    ASSERT_EQ(ptr.get(), nullptr);
}

TEST(UniquePtrTesting, TestUniquePtrEqualOperator) {
    unique_ptr<int> ptr{new int(initValueForTestUniquePtrValue)};
    auto testPtr = ptr.get();
    ASSERT_EQ(*testPtr, initValueForTestUniquePtrValue);
}