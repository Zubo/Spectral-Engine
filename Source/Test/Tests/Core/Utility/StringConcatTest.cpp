#include <Core/Utility/StringConcat.hpp>
#include <gtest/gtest.h>

namespace sp {
	namespace tests {
		TEST(StringConcat, ConcatSingle) {
			// arrange
			SpString expected{ "Hello" };

			// act
			SpString concated = Concat(expected.c_str());

			// assert
			for (int i = 0; i < static_cast<int>(concated.size()); ++i) {
				ASSERT_EQ(concated[i], expected[i]);
			}
		}

		TEST(StringConcat, ConcatEmpty) {
			// act
			SpString concated = Concat();

			// assert
			ASSERT_EQ(concated.size(), 0);
		}

		TEST(StringConcat, ConcatMultiple) {
			// arrange
			SpString arg1{ "This" };
			SpString arg2{ " is " };
			SpString arg3{ "test." };
			SpString expected{ "This is test." };

			// act
			SpString concated = Concat(arg1, arg2.c_str(), arg3);

			// assert
			for (int i = 0; i < static_cast<int>(concated.size()); ++i) {
				ASSERT_EQ(concated[i], expected[i]);
			}
		}
	}
}