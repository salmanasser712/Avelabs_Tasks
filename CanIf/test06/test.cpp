#include "CppUTest/TestHarness.h"

extern "C" {
   #include <stdio.h>
   #include "CanIf.h"
   #include "CanIf_Cbk.h"
}

extern const CanIf_ConfigType CanIf_Config;

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, FirstTest)
{
   FAIL("Fail me!");
}

TEST(FirstTestGroup, SecondTest)
{
   FAIL("Fail me2!");
}