load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
#load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "file_util",
    srcs = ["file_util.cc"],
    hdrs = ["file_util.h"],
    deps = [
        "@boost//:filesystem",
        "@boost//:smart_ptr",
        "@glog",
    ],
)

cc_binary(
    name = "bazel_simple_demo",
    srcs = ["main.cc"],
    defines = [
        "BOOST_THREAD_BUILD_LIB=1",
        "BOOST_THREAD_PLATFORM_PTHREAD",
        "BOOST_THREAD_POSIX",
        "BOOST_THREAD_USES_CHRONO",
    ],
    linkopts = [
        "-lpthread",
    ],
    linkstatic = 1,
    deps = [
        ":file_util",
        "@boost//:algorithm",
        "@boost//:filesystem",
        "@glog",
    ],
)

#cc_test(
#name = "file_util_test",
#srcs = ["file_util_test.cc"],
#data = [
#"//test_data:exported_testdata",
#],
#deps = [":file_util"],
#)

#cpplint()
