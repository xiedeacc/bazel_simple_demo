/*******************************************************************************
 * Copyright (c) 2022 Copyright 2022- xiedeacc.com.
 * All rights reserved.
 *******************************************************************************/

#include "src/file_util.h"

int main(int argc, char** argv) {
  // ProfilerStart("bazel_simple_demo_profile");
  FileUtil::CompareDirRecursive("/data", "/data3");
  // ProfilerStop();
  return 0;
}
