/*******************************************************************************
 * Copyright (c) 2022 Copyright 2022- xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#include "src/file_util.h"

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include <string>

#include "boost/filesystem.hpp"
#include "glog/logging.h"

using std::string;

bool FileUtil::IsDirectory(const string &file_path) {
  return boost::filesystem::is_directory(file_path);
}

bool FileUtil::FileIsExists(const string &file_path) {
  return boost::filesystem::exists(file_path);
}

void FileUtil::DoCompare(const string &left_file, const string &right_file) {
  uintmax_t l_size = boost::filesystem::file_size(left_file);
  uintmax_t r_size = boost::filesystem::file_size(right_file);
  if (l_size != r_size) {
    LOG(ERROR) << left_file << " " << right_file << ", size not equal!";
  }
}

bool FileUtil::CompareDirRecursive(const string &left_dir,
                                   const string &right_dir) {
  boost::filesystem::path l_path(left_dir);
  boost::filesystem::directory_iterator end_iter;
  for (boost::filesystem::directory_iterator iter(l_path); iter != end_iter;
       ++iter) {
    if (iter->path().string() == "." || iter->path().string() == "..") {
      continue;
    }

    string file_name = iter->path().string();
    string left_full_path = left_dir + "/" + file_name;
    string right_full_path = right_dir + "/" + file_name;
    if (!FileIsExists(right_full_path)) {
      LOG(ERROR) << left_full_path << " " << right_full_path
                 << ", right not exists!";
      continue;
    }

    if ((IsDirectory(left_full_path) && !IsDirectory(right_full_path)) ||
        (!IsDirectory(left_full_path) && IsDirectory(right_full_path))) {
      LOG(ERROR) << left_full_path << " " << right_full_path
                 << ", type different!";
      continue;
    }

    if (IsDirectory(left_full_path) && IsDirectory(right_full_path)) {
      CompareDirRecursive(left_full_path, right_full_path);
    } else {
      DoCompare(left_full_path, right_full_path);
    }
  }

  return true;
}
