```
 clear && bazel build --incompatible_enable_cc_toolchain_resolution --platforms=@bazel_build_file//platforms:linux_gcc11_aarch64_none_musleabi -s --copt=-g3 --strip=never //...

```

```
clear && bazel build --incompatible_enable_cc_toolchain_resolution --platforms=@bazel_build_file//platforms:linux_gcc11_armv7_none_musleabi -s --copt=-g3 --strip=never //...
```
