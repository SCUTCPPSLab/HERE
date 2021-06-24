forte_add_module(TIIBenchmarks "TIIBenchmarks Function blocks")
#############################################################################
# TII BENCHMARKS FB
#############################################################################
forte_add_subdirectory(CruiseControl)
forte_add_subdirectory(DistributingStation)
forte_add_subdirectory(DrillStation)
forte_add_subdirectory(MP3PLAYER)
forte_add_subdirectory(Watch)
forte_add_subdirectory(WaterMonitor)
forte_add_subdirectory(BenchmarkTimer)
forte_add_sourcefile_hcpp(Helper)