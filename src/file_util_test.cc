#include "gtest/gtest.h"
using std::string;

TEST(FileUtilTest, IsDirectory) {
  ASSERT_TRUE(FileUtil.IsDirectory("test_data/directory"));
  ASSERT_FALSE(FileUtil::IsDirectory("test_data/file"));
}

TEST(FileUtilTest, FileIsExists) {
  ASSERT_FALSE(FileUtil::FileIsExists("test_data/not_exists"));
  ASSERT_TRUE(FileUtil::FileIsExists("test_data/file"));
}

TEST(FileUtilTest, DoCompare) {
  FileUtil::DoCompare("test_data/file_sha256_1", "file_sha256_2");
}

TEST(FileUtilTest, StringSha256) {
  char sha256_value[65];
  string str = "xiedeacc";
  FileUtil::StringSha256(str, sha256_value);
  LOG(INFO) << sha256_value;
  ASSERT_EQ(sha256_value, "");
}

TEST(FileUtilTest, FileSha256) {
  char sha256_value[65];
  FileUtil::FileSha256("test_data/file_sha256_1", sha256_value);
  LOG(INFO) << sha256_value;
  ASSERT_EQ(sha256_value, "");
}
