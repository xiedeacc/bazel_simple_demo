workspace(name = "bazel_simple_demo")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
    name = "bazel_skylib",
    remote = "https://github.com/bazelbuild/bazel-skylib.git",
    tag = "1.2.1",
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

git_repository(
    name = "rules_cc",
    commit = "58f8e026c00a8a20767e3dc669f46ba23bc93bdb",
    remote = "https://github.com/bazelbuild/rules_cc.git",
)

load("@rules_cc//cc:repositories.bzl", "rules_cc_dependencies", "rules_cc_toolchains")

rules_cc_dependencies()

rules_cc_toolchains()

git_repository(
    name = "rules_foreign_cc",
    remote = "https://github.com/bazelbuild/rules_foreign_cc.git",
    tag = "0.8.0",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
    name = "com_grail_bazel_compdb",
    remote = "https://github.com/grailbio/bazel-compilation-database.git",
    tag = "0.5.2",
)

load("@com_grail_bazel_compdb//:deps.bzl", "bazel_compdb_deps")

bazel_compdb_deps()

git_repository(
    name = "bazel_build_file",
    commit = "5a927a56739a30b491a2cf48af0f76faf65f1782",
    remote = "https://github.com/xiedeacc/bazel_build_file.git",
)

load("@bazel_build_file//bazel:repositories.bzl", "deps")
load("@bazel_build_file//toolchains:toolchains.bzl", "register_all_toolchains")
load("@bazel_build_file//platforms:platforms.bzl", "register_all_execution_platforms")

deps()

register_all_toolchains()

register_all_execution_platforms()

new_git_repository(
    name = "cpplint",
    build_file = "@bazel_build_file//bazel:cpplint.BUILD",
    remote = "https://github.com/cpplint/cpplint.git",
    tag = "1.6.0",
)

git_repository(
    name = "com_google_googletest",
    remote = "https://github.com/google/googletest.git",
    tag = "release-1.11.0",
)

git_repository(
    name = "glog",
    remote = "https://github.com/google/glog.git",
    tag = "v0.5.0",
)

git_repository(
    name = "com_github_gflags_gflags",
    remote = "https://github.com/gflags/gflags.git",
    tag = "v2.2.2",
)

http_archive(
    name = "com_github_nelhage_rules_boost",
    sha256 = "1557e4e1f2d009f14919dbf49b167f6616136d0cef1ca1cfada6ce0d4e3d6146",
    strip_prefix = "rules_boost-ef58870fe00ecb8047cd34324b8c21221387d5fc",
    urls = ["https://github.com/nelhage/rules_boost/archive/ef58870fe00ecb8047cd34324b8c21221387d5fc.tar.gz"],
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

boost_deps()

http_archive(
    name = "com_github_gperftools_gperftools",
    build_file = "@bazel_build_file//bazel:gperftools.BUILD",
    sha256 = "ea566e528605befb830671e359118c2da718f721c27225cbbc93858c7520fee3",
    strip_prefix = "gperftools-2.9.1",
    urls = ["https://github.com/gperftools/gperftools/releases/download/gperftools-2.9.1/gperftools-2.9.1.tar.gz"],
)

bind(
    name = "gperftools",
    actual = "@bazel_build_file//bazel:gperftools",
)
