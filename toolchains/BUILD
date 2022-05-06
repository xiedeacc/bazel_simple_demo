package(default_visibility = ["//visibility:public"])

toolchain(
    name = "gcc9_arm_aarch64_xcompile_toolchain",
    exec_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:linux",
    ],
    target_compatible_with = [
        "@platforms//cpu:aarch64",
        "@platforms//os:linux",
        "//platforms:gcc_9",
    ],
    toolchain = "@gcc9_arm_aarch64//:cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

toolchain(
    name = "gcc9_arm_armv7_xcompile_toolchain",
    exec_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:linux",
    ],
    target_compatible_with = [
        "@platforms//cpu:armv7",
        "@platforms//os:linux",
        "//platforms:gcc_9",
    ],
    toolchain = "@gcc9_arm_armv7//:cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

toolchain(
    name = "gcc10_arm_aarch64_xcompile_toolchain",
    exec_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:linux",
    ],
    target_compatible_with = [
        "@platforms//cpu:aarch64",
        "@platforms//os:linux",
        "//platforms:gcc_10",
    ],
    toolchain = "@gcc10_arm_aarch64//:cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

toolchain(
    name = "gcc10_arm_armv7_xcompile_toolchain",
    exec_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:linux",
    ],
    target_compatible_with = [
        "@platforms//cpu:armv7",
        "@platforms//os:linux",
        "//platforms:gcc_10",
    ],
    toolchain = "@gcc10_arm_armv7//:cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

toolchain(
    name = "gcc11_arm_aarch64_xcompile_toolchain",
    exec_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:linux",
    ],
    target_compatible_with = [
        "@platforms//cpu:aarch64",
        "@platforms//os:linux",
        "//platforms:gcc_11",
    ],
    toolchain = "@gcc11_arm_aarch64//:cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

toolchain(
    name = "gcc11_arm_armv7_xcompile_toolchain",
    exec_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:linux",
    ],
    target_compatible_with = [
        "@platforms//cpu:armv7",
        "@platforms//os:linux",
        "//platforms:gcc_11",
    ],
    toolchain = "@gcc11_arm_armv7//:cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

toolchain(
    name = "windows_mingw_x86_64_toolchain",
    exec_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:linux",
    ],
    target_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:windows",
    ],
    toolchain = ":windows_mingw_x86_64_cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

filegroup(name = "empty")

cc_toolchain(
    name = "windows_mingw_x86_64_cc_toolchain",
    all_files = ":empty",
    compiler_files = ":empty",
    dwp_files = ":empty",
    linker_files = ":empty",
    objcopy_files = ":empty",
    strip_files = ":empty",
    supports_param_files = 0,
    toolchain_config = ":windows_mingw_x86_64_toolchain_config",
    toolchain_identifier = "windows_mingw_x86_64-toolchain",
)

load("@bazel_build_file_repo//toolchains:mingw.bzl", "cc_toolchain_config")

cc_toolchain_config(name = "windows_mingw_x86_64_toolchain_config")
