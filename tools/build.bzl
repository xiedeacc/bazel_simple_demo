def cc_test(
        deps = [],
        **kwargs):
    native.cc_test(
        deps = [
            "@com_google_googletest//:gtest_main",
            "@com_github_gperftools_gperftools//:gperftools",
        ] + deps,
        **kwargs
    )
