package(default_visibility = ["//visibility:public"])

exports_files(["CPPLINT.cfg"])

config_setting(
    name = "is_gcc_10",
    constraint_values = [
        ":gcc_10",
    ],
)

constraint_setting(name = "gcc_version")

constraint_value(
    name = "gcc_10",
    constraint_setting = ":gcc_version",
)
