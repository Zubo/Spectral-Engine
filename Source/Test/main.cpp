#include <gtest/gtest.h>

namespace sp {
	int main(int argc, char ** argv) {
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
}
