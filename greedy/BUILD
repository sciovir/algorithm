cc_library(
    name = "fractional_knapsack",
    srcs = ["fractional_knapsack.cc"],
    visibility = ["//visibility:public"],
)

cc_test(
  name = "fractional_knapsack_test",
  size = "small",
  srcs = ["fractional_knapsack_test.cc"],
  copts = ["-std=c++20"],
  deps = [
    ":fractional_knapsack",
    "@com_google_googletest//:gtest_main",
  ],
)