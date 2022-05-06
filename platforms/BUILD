package(default_visibility = ["//visibility:public"])

constraint_setting(name = "gcc_version")

constraint_value(
    name = "gcc_10",
    constraint_setting = ":gcc_version",
)

constraint_value(
    name = "gcc_11",
    constraint_setting = ":gcc_version",
)

platform(
    name = "linux_gcc10_aarch64",
    constraint_values = [
        "@platforms//cpu:aarch64",
        "@platforms//os:linux",
        ":gcc_10",
    ],
)

platform(
    name = "linux_gcc10_armv7",
    constraint_values = [
        "@platforms//cpu:armv7",
        "@platforms//os:linux",
        ":gcc_10",
    ],
)

platform(
    name = "linux_gcc11_aarch64",
    constraint_values = [
        "@platforms//cpu:aarch64",
        "@platforms//os:linux",
        ":gcc_11",
    ],
)

platform(
    name = "linux_gcc11_armv7",
    constraint_values = [
        "@platforms//cpu:armv7",
        "@platforms//os:linux",
        ":gcc_11",
    ],
)

platform(
    name = "windows_mingw_x86_64",
    constraint_values = [
        "@platforms//cpu:x86_64",
        "@platforms//os:windows",
    ],
)
