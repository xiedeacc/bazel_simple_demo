workspace(name = "bazel_simple_demo")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
    name = "rules_foreign_cc",
    remote = "https://github.com/bazelbuild/rules_foreign_cc.git",
    tag = "0.7.1",
)
load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")
rules_foreign_cc_dependencies()

git_repository(
    name = "com_grail_bazel_compdb",
    remote = "https://github.com/grailbio/bazel-compilation-database.git",
    tag = "0.5.2",
)
load("@com_grail_bazel_compdb//:deps.bzl", "bazel_compdb_deps")
bazel_compdb_deps()

git_repository(
  name = "rules_cc",
  remote = "https://github.com/bazelbuild/rules_cc.git",
  commit = "58f8e026c00a8a20767e3dc669f46ba23bc93bdb",
)

git_repository(
    name = "io_bazel_rules_go",
    remote = "https://github.com/bazelbuild/rules_go.git",
    tag = "v0.31.0",
)
load("@io_bazel_rules_go//go:deps.bzl", "go_register_toolchains", "go_rules_dependencies")
go_rules_dependencies()
go_register_toolchains(version = "1.18")

git_repository(
    name = "io_bazel_rules_closure",
    remote = "https://github.com/bazelbuild/rules_closure.git",
    tag = "0.12.0",
)

git_repository(
    name = "rules_protobuf",
    remote = "https://github.com/pubref/rules_protobuf.git",
    tag = "v0.8.2",
)

git_repository(
    name = "rules_proto",
    remote = "https://github.com/bazelbuild/rules_proto.git",
    tag = "4.0.0-3.19.2",
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

git_repository(
    name = "build_bazel_rules_apple",
    remote = "https://github.com/bazelbuild/rules_apple.git",
    tag = "0.34.0",
)
load("@build_bazel_rules_apple//apple:repositories.bzl", "apple_rules_dependencies")
apple_rules_dependencies()

git_repository(
    name = "com_google_googleapis",
    remote = "https://github.com/googleapis/googleapis.git",
    commit = "e1b5a0175f84ef0b7f92b832a4450e6cbe376da7",
)

git_repository(
    name = "upb",
    remote = "https://github.com/protocolbuffers/upb.git",
    commit = "b25e7218ef940036d6253260f8084f2f1143bf38",
)

git_repository(
    name = "envoy_api",
    remote = "https://github.com/envoyproxy/data-plane-api.git",
    commit = "6290b71f73024a7e19cfee499b13c1e851793b2b",
)

git_repository(
    name = "com_google_protobuf",
    remote = "https://github.com/protocolbuffers/protobuf.git",
    tag = "v3.20.0",
)

git_repository(
    name = "bazel_build_file_repo",
    remote = "https://github.com/xiedeacc/bazel_build_file_repo.git",
    commit = "c6081662399760234f66e49962fe2995c3a9eaa0",
)

#####################################################################
# grpc dependencies
#####################################################################

git_repository(
    name = "com_github_grpc_grpc",
    remote = "https://github.com/grpc/grpc.git",
    tag = "v1.45.0",
)
load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_deps()
grpc_extra_deps()

git_repository(
    name = "com_github_google_benchmark",
    remote = "https://github.com/google/benchmark.git",
    tag = "v1.6.1",
)

git_repository(
    name = "com_github_gflags_gflags",
    remote = "https://github.com/gflags/gflags.git",
    tag = "v2.2.2",
)

git_repository(
  name = "com_google_googletest",
  remote = "https://github.com/google/googletest.git",
  tag = "release-1.11.0",
)

git_repository(
    name = "com_google_absl",
    remote = "https://github.com/abseil/abseil-cpp.git",
    tag = "20211102.0",
)

git_repository(
    name = "glog",
    remote = "https://github.com/google/glog.git",
    tag = "v0.5.0",
)

new_git_repository(
    name = "rapidjson",
    remote = "https://github.com/Tencent/rapidjson.git",
    commit = "8261c1ddf43f10de00fd8c9a67811d1486b2c784",
    build_file = "@bazel_build_file_repo//bazel:rapidjson.BUILD",
)

new_git_repository(
    name = "smhasher",
    remote = "https://github.com/rurban/smhasher.git",
    commit = "fb0b59ab911126082d33aaedb934cc2f787f4f5a",
    recursive_init_submodules = True,
    build_file = "@bazel_build_file_repo//bazel:smhasher.BUILD",
)

http_archive(
    name = "com_github_gperftools_gperftools",
    sha256 = "ea566e528605befb830671e359118c2da718f721c27225cbbc93858c7520fee3",
    strip_prefix = "gperftools-2.9.1",
    urls = ["https://github.com/gperftools/gperftools/releases/download/gperftools-2.9.1/gperftools-2.9.1.tar.gz"],
    build_file = "@bazel_build_file_repo//bazel:gperftools.BUILD",
)
bind(
    name = "gperftools",
    actual = "@bazel_build_file_repo//bazel:gperftools",
)

http_archive(
    name = "com_github_nelhage_rules_boost",
    sha256 = "1557e4e1f2d009f14919dbf49b167f6616136d0cef1ca1cfada6ce0d4e3d6146",
    strip_prefix = "rules_boost-ef58870fe00ecb8047cd34324b8c21221387d5fc",
    urls = ["https://github.com/nelhage/rules_boost/archive/ef58870fe00ecb8047cd34324b8c21221387d5fc.tar.gz"],
)
load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

#new_git_repository(
    #name = "jemalloc",
    #remote = "https://github.com/jemalloc/jemalloc.git",
    #tag = "5.2.1",
    #build_file = "@bazel_build_file_repo//bazel:jemalloc.BUILD",
#)

new_git_repository(
    name = "cpplint",
    remote = "https://github.com/cpplint/cpplint.git",
    tag = "1.6.0",
    build_file = "@bazel_build_file_repo//bazel:cpplint.BUILD",
)

http_archive(
    name = "openssl",
     sha256 = "892a0875b9872acd04a9fde79b1f943075d5ea162415de3047c327df33fbaee5",
     strip_prefix = "openssl-1.1.1k",
     urls = [
        "https://mirror.bazel.build/www.openssl.org/source/openssl-1.1.1k.tar.gz",
        "https://www.openssl.org/source/openssl-1.1.1k.tar.gz",
        "https://github.com/openssl/openssl/archive/OpenSSL_1_1_1k.tar.gz",
    ],
    build_file = "@bazel_build_file_repo//bazel:openssl.BUILD",
)
