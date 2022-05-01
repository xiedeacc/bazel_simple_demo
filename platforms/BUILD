package(default_visibility = ["//visibility:public"])

platform(
    name = "linux_gcc_aarch64",
    constraint_values = [
        "@platforms//cpu:aarch64",
        "@platforms//os:linux",
    ],
)

platform(
    name = "linux_gcc_10_aarch64",
    constraint_values = [
        "//:gcc_10",
    ],
    parents = [":linux_gcc_aarch64"],
)
