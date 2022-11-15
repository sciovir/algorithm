#include "catalan.h"

#include <gtest/gtest.h>

namespace algorithm {
namespace {

TEST(CatalanTest, HandlesZeroInput) { EXPECT_EQ(mathematics::Catalan(0), 1); }

TEST(CatalanTest, HandlesPositiveInput) {
  EXPECT_EQ(mathematics::Catalan(1), 1);
  EXPECT_EQ(mathematics::Catalan(2), 2);
  EXPECT_EQ(mathematics::Catalan(3), 5);
  EXPECT_EQ(mathematics::Catalan(4), 14);
  EXPECT_EQ(mathematics::Catalan(5), 42);
  EXPECT_EQ(mathematics::Catalan(9), 4862);
}

TEST(CatalanTest, HandlesNegativeInput) {
  EXPECT_DEATH(mathematics::Catalan(-1), "");
  EXPECT_DEATH(mathematics::Catalan(-100), "");
  EXPECT_DEATH(mathematics::Catalan(-10), "");
}

}  // namespace
}  // namespace algorithm
