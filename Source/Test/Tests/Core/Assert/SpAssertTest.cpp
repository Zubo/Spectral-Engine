#include <gtest/gtest.h>

#define ASSERTIONS_ENABLED

#include <Core/Assert/SpAssert.hpp>

namespace sp {
	namespace tests {
		TEST(SpAssert, AssertPassed) {
			// act
			SpAssert(true);
		}

		TEST(SpAssert, AssertFailed) {
			// assert
			EXPECT_THROW(SpAssert(false), SpException);
		}

		TEST(SpAssert, ExceptionMessage) {
			// arrange
			SpString exceptionMsg;
			
			// act
			try
			{
				SpAssert(false, "Hello", " there");
			}
			catch (SpException& e)
			{
				exceptionMsg = SpString{ e.what() };
			}

			// assert
			EXPECT_NE(exceptionMsg.find_first_of(SpString{ "Hello there" }), std::string::npos);
		}
	}
}
