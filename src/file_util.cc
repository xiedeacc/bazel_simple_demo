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

void FileUtil::Sha256HashString(unsigned char hash[SHA256_DIGEST_LENGTH],
                                char output_buffer[65]) {
  int i = 0;
  for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    sprintf(output_buffer + (i * 2), "%02x", hash[i]);  // NOLINT
  }
  output_buffer[64] = 0;
}

void FileUtil::StringSha256(const string &str, char output_buffer[65]) {
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, str.c_str(), str.size());
  SHA256_Final(hash, &sha256);
  Sha256HashString(hash, output_buffer);
}

bool FileUtil::FileSha256(const string &file_path, char output_buffer[65]) {
  FILE *file = fopen(file_path.c_str(), "rb");
  if (!file) return false;

  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  const int buf_size = 32768;
  unsigned char *buffer = (unsigned char *)malloc(buf_size);
  int bytes_read = 0;
  if (!buffer) return false;
  while ((bytes_read = fread(buffer, 1, buf_size, file))) {
    SHA256_Update(&sha256, buffer, bytes_read);
  }
  SHA256_Final(hash, &sha256);

  Sha256HashString(hash, output_buffer);
  fclose(file);
  free(buffer);
  return true;
}

bool FileUtil::IsDirectory(const string &dir) {
  struct stat st;
  return ::stat(dir.c_str(), &st) == 0 && ((st.st_mode & S_IFDIR) != 0);
}

bool FileUtil::FileIsExists(const string &file_path) {
  if (access(file_path.c_str(), F_OK) == 0) {
    return true;
  }
  return false;
}

void FileUtil::DoCompare(const string &left_file, const string &right_file) {
  if (left_file.find(".wiki.git") != string::npos) {
    return;
  }
  struct stat left_st;
  ::stat(left_file.c_str(), &left_st);

  struct stat right_st;
  ::stat(right_file.c_str(), &right_st);

  if (left_st.st_size != right_st.st_size) {
    char left_sha256_value[65];
    char right_sha256_value[65];

    FileSha256(left_file, left_sha256_value);
    FileSha256(right_file, right_sha256_value);

    LOG(ERROR) << left_file;
    LOG(ERROR) << right_file;
    LOG(ERROR) << "left sha256 value: " << left_sha256_value;
    LOG(ERROR) << "right sha256 value:" << right_sha256_value;
    LOG(ERROR) << "size not equal!";
    LOG(ERROR) << "=============================================";
  }
}

bool FileUtil::CompareDirRecursive(const string &left_dir,
                                   const string &right_dir) {
  ::DIR *d;
  struct dirent *ent;
  if ((d = opendir(left_dir.c_str())) == nullptr) {
    LOG(ERROR) << "Fail to opendir " << left_dir;
    return false;
  }
  while ((ent = readdir(d)) != nullptr) {
    string file_name = ent->d_name;
    if (file_name == "." || file_name == "..") {
      continue;
    }

    string left_full_path = left_dir + "/" + file_name;
    string right_full_path = right_dir + "/" + file_name;
    if (!FileIsExists(right_full_path)) {
      LOG(ERROR) << left_full_path;
      LOG(ERROR) << right_full_path;
      LOG(ERROR) << "right not exists!";
      LOG(ERROR) << "=============================================";
      continue;
    }

    if ((IsDirectory(left_full_path) && !IsDirectory(right_full_path)) ||
        (!IsDirectory(left_full_path) && IsDirectory(right_full_path))) {
      LOG(ERROR) << left_full_path << " is "
                 << (IsDirectory(left_full_path) ? "directory" : "file");
      LOG(ERROR) << right_full_path << " is "
                 << (IsDirectory(left_full_path) ? "directory" : "file");
      LOG(ERROR) << "different type!";
      LOG(ERROR) << "=============================================";
      continue;
    }

    if (IsDirectory(left_full_path) && IsDirectory(right_full_path)) {
      CompareDirRecursive(left_full_path, right_full_path);
    } else {
      DoCompare(left_full_path, right_full_path);
    }
  }
  closedir(d);
  return true;
}
