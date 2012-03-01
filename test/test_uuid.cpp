#include "kiss/uuid.h"

#include <gtest/gtest.h>

using namespace kiss;

TEST(UUID, creation) {
	uuid id1 = uuid::parse("69c09be0-638b-11e1-b86c-0800200c9a66");
	uuid id2 = uuid::parse("69c09be0-638b-11e1-b86c-0800200c9a66");
	uuid id3 = uuid::parse("69c09be1-638b-11e1-b86c-0800200c9a66");

	EXPECT_EQ(id1, id2);
	EXPECT_NE(id1, id3);
}

TEST(UUID, uniqueness) {
	uuid reference = uuid::create();

	for (size_t i = 0; i < 1000000; i++) {
		uuid probe = uuid::create();
		EXPECT_NE(reference, probe);
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
