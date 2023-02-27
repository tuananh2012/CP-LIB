cc_library(
    name = "cp_lib",
    srcs = glob(["disjoint_set/*.cpp"]),
    hdrs = glob(["disjoint_set/*.h"]),
)

cc_test(
  name = "unit_tests",
  srcs = ["test/test_disjoint_set.cpp"],
  deps = [
    ":cp_lib",
    "@com_google_googletest//:gtest_main", 
    ],
)