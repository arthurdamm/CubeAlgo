#include "TestUtilities.h"

bool FUtilitiesTest::RunTest(const FString& Parameters)
{
    TestUtilities TestUtilities;

    TestUtilities.TestDtoi(*this);
    TestUtilities.TestHandleNegativeZero(*this);
    TestUtilities.TestAreQuatsEqual(*this);
    TestUtilities.TestAreQuatsNotEqual(*this);
    TestUtilities.TestFilter(*this);

    return true;
}

void TestUtilities::TestDtoi(FAutomationTestBase& Test)
{
    Test.TestEqual("Dtoi", dtoi(1.5), 2);
    Test.TestEqual("Dtoi", dtoi(1.4), 1);
    Test.TestEqual("Dtoi", dtoi(-1.5), 2);
    Test.TestEqual("Dtoi", dtoi(-1.4), 1);
}

void TestUtilities::TestHandleNegativeZero(FAutomationTestBase& Test)
{
    Test.TestEqual("HandleNegativeZero", HandleNegativeZero(-0.0), 0.0);
}

void TestUtilities::TestAreQuatsEqual(FAutomationTestBase& Test)
{
    FQuat quat1(1, 2, 3, 4);
    FQuat quat2(1, 2, 3, 4);

    Test.TestTrue("AreQuatsEqual True", AreQuatsEqual(quat1, quat2));

    quat2 = -quat2;
    Test.TestTrue("AreQuatsEqual Negative", AreQuatsEqual(quat1, quat2));

    FQuat quat3(2, 2, 3, 4);
    Test.TestFalse("AreQuatsEqual False", AreQuatsEqual(quat1, quat3));
}

void TestUtilities::TestAreQuatsNotEqual(FAutomationTestBase& Test)
{
    FQuat quat(1, 2, 3, 4);
    FQuat shouldBeEqualQuat(1, 2, 3, 4 + 1e-7);
    FQuat shouldBeNotEqualQuat(1, 2, 3, 4 + 1e-6);

    Test.TestTrue("AreQuatsNotEqual Should be equal", AreQuatsEqual(quat, shouldBeEqualQuat));
    Test.TestFalse("AreQuatsNotEqual Should not be equal", AreQuatsEqual(quat, shouldBeNotEqualQuat));
}

void TestUtilities::TestFilter(FAutomationTestBase& Test)
{
    std::vector<int> input = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> expected = { 2, 4, 6, 8 };

    auto isEven = [](int n) { return n % 2 == 0; };
    auto result = filter(input, isEven);

    Test.TestEqual("Filter", result, expected);
}