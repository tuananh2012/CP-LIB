cc_library(
    name = "cp_lib",
    srcs = glob(["disjoint_set/*.cpp"]),
    hdrs = glob(["disjoint_set/*.h",
                 "fenwick_tree/*.h",
                 "segment_tree/*.h",
                ]),
)

cc_test(
  name = "unit_tests",
  srcs = glob(["test/*.cpp"]),
  deps = [
    ":cp_lib",
    "@com_google_googletest//:gtest_main", 
    ],
)