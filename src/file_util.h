/*******************************************************************************
 * Copyright (c) 2022 Copyright 2022- xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#ifndef FILE_UTIL_H_
#define FILE_UTIL_H_
#include <openssl/sha.h>

#include <cstddef>
#include <sstream>
#include <string>
#include <vector>

class FileUtil {
 private:
  FileUtil() {}
  virtual ~FileUtil() {}

 public:
  static bool CompareDirRecursive(const std::string &left_dir,
                                  const std::string &right_dir);
  static bool IsDirectory(const std::string &dir);

  static bool FileIsExists(const std::string &file_path);

  static void DoCompare(const std::string &left_file,
                        const std::string &right_file);

  static void Sha256HashString(unsigned char hash[SHA256_DIGEST_LENGTH],
                               char output_buffer[65]);

  static void StringSha256(const std::string &str, char output_buffer[65]);

  static bool FileSha256(const std::string &file_path, char output_buffer[65]);
};

#endif /* FILE_UTIL_H_ */
