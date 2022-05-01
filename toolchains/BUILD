package(default_visibility = ["//visibility:public"])

toolchain(
    name = "gcc_10_aarch64_xcompile_toolchain",
    exec_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:linux",
    ],
    target_compatible_with = [
        "@platforms//cpu:aarch64",
        "@platforms//os:linux",
        "//:gcc_10",
    ],
    toolchain = "@gcc_10_aarch64//:cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)
