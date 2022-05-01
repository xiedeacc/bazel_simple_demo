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

register_execution_platforms(
    "@bazel_simple_demo//platforms:linux_gcc_aarch64",
    "@bazel_simple_demo//platforms:windows_mingw_x86_64",
)

register_toolchains(
    "@bazel_simple_demo//toolchains:gcc_arm_aarch64_xcompile_toolchain",
    "@bazel_simple_demo//toolchains:windows_mingw_x86_64_toolchain",
)

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
    tag = "0.7.1",
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

new_git_repository(
    name = "cpplint",
    build_file = "@bazel_build_file_repo//bazel:cpplint.BUILD",
    remote = "https://github.com/cpplint/cpplint.git",
    tag = "1.6.0",
)

git_repository(
    name = "bazel_build_file_repo",
    commit = "63856d2a674063208e5906332f00b25d27f5470d",
    remote = "https://github.com/xiedeacc/bazel_build_file_repo.git",
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
    name = "gcc_arm_aarch64",
    build_file = "@bazel_build_file_repo//bazel:gcc_arm_aarch64.BUILD",
    sha256 = "1e33d53dea59c8de823bbdfe0798280bdcd138636c7060da9d77a97ded095a84",
    strip_prefix = "gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu",
    #urls = ["https://developer.arm.com/-/media/Files/downloads/gnu-a/10.3-2021.07/binrel/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu.tar.xz"],
    urls = ["file:///root/src/cpp/toolchains/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu.tar.xz"],
)
