/*******************************************************************************
 * Copyright (c) 2022 Copyright 2022- xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <atomic>
#include <memory>
#include <string>

#include "boost/filesystem.hpp"
#include "gflags/gflags.h"
#include "glog/logging.h"
#include "gperftools/profiler.h"
#include "src/file_util.h"

using std::atomic;
using std::string;
using std::to_string;
using std::unique_ptr;

int main(int argc, char** argv) {
  ProfilerStart("bazel_simple_demo_profile");
  FileUtil::CompareDirRecursive("", "");
  ProfilerStop();
  return 0;
}
