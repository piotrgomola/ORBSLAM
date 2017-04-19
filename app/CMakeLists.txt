set(pathToProject /home/pgomola/Dokumenty/ORBSLAM)
set(pathToOpenCv /home/pgomola/Dokumenty/ORBSLAM/app/OpenCV-android-sdk)

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)

# MY NATIVE
add_library( native-lib SHARED src/main/cpp/native-lib.cpp )

# OPENCV
include_directories(${pathToOpenCv}/sdk/native/jni/include)
add_library( lib_opencv SHARED IMPORTED )
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${pathToProject}/app/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)

# NATIVE LOG LIB
find_library( log-lib log )

# EIGEN
include_directories(eigen INTERFACE ${pathToProject}/Thirdparty/eigen3)

# BOOST
include_directories( ${pathToProject}/Thirdparty/Boost/include )
set( boost_lib
     ${pathToProject}/Thirdparty/Boost/lib/libboost_chrono-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_date_time-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_exception-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_filesystem-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_graph-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_iostreams-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_math_c99f-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_math_c99-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_math_c99l-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_math_tr1f-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_math_tr1-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_math_tr1l-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_prg_exec_monitor-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_program_options-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_random-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_regex-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_serialization-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_signals-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_system-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_test_exec_monitor-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_thread-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_timer-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_unit_test_framework-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_wave-gcc-mt-1_49.a
     ${pathToProject}/Thirdparty/Boost/lib/libboost_wserialization-gcc-mt-1_49.a)

# g2o
# Generate config.h
SET(G2O_CXX_COMPILER "${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER}")
configure_file(${pathToProject}/Thirdparty/g2o/config.h.in ${pathToProject}/Thirdparty/g2o/config.h)
SET (G2O_LIB_TYPE SHARED)
ADD_LIBRARY(g2o ${G2O_LIB_TYPE}
#types
${pathToProject}/Thirdparty/g2o/types/types_sba.h
${pathToProject}/Thirdparty/g2o/types/types_six_dof_expmap.h
${pathToProject}/Thirdparty/g2o/types/types_sba.cpp
${pathToProject}/Thirdparty/g2o/types/types_six_dof_expmap.cpp
${pathToProject}/Thirdparty/g2o/types/types_seven_dof_expmap.cpp
${pathToProject}/Thirdparty/g2o/types/types_seven_dof_expmap.h
${pathToProject}/Thirdparty/g2o/types/se3quat.h
${pathToProject}/Thirdparty/g2o/types/se3_ops.h
${pathToProject}/Thirdparty/g2o/types/se3_ops.hpp
#core
${pathToProject}/Thirdparty/g2o/core/base_edge.h
${pathToProject}/Thirdparty/g2o/core/base_binary_edge.h
${pathToProject}/Thirdparty/g2o/core/hyper_graph_action.cpp
${pathToProject}/Thirdparty/g2o/core/base_binary_edge.hpp
${pathToProject}/Thirdparty/g2o/core/hyper_graph_action.h
${pathToProject}/Thirdparty/g2o/core/base_multi_edge.h
${pathToProject}/Thirdparty/g2o/core/hyper_graph.cpp
${pathToProject}/Thirdparty/g2o/core/base_multi_edge.hpp
${pathToProject}/Thirdparty/g2o/core/hyper_graph.h
${pathToProject}/Thirdparty/g2o/core/base_unary_edge.h
${pathToProject}/Thirdparty/g2o/core/linear_solver.h
${pathToProject}/Thirdparty/g2o/core/base_unary_edge.hpp
${pathToProject}/Thirdparty/g2o/core/marginal_covariance_cholesky.cpp
${pathToProject}/Thirdparty/g2o/core/base_vertex.h
${pathToProject}/Thirdparty/g2o/core/marginal_covariance_cholesky.h
${pathToProject}/Thirdparty/g2o/core/base_vertex.hpp
${pathToProject}/Thirdparty/g2o/core/matrix_structure.cpp
${pathToProject}/Thirdparty/g2o/core/batch_stats.cpp
${pathToProject}/Thirdparty/g2o/core/matrix_structure.h
${pathToProject}/Thirdparty/g2o/core/batch_stats.h
${pathToProject}/Thirdparty/g2o/core/openmp_mutex.h
${pathToProject}/Thirdparty/g2o/core/block_solver.h
${pathToProject}/Thirdparty/g2o/core/block_solver.hpp
${pathToProject}/Thirdparty/g2o/core/parameter.cpp
${pathToProject}/Thirdparty/g2o/core/parameter.h
${pathToProject}/Thirdparty/g2o/core/cache.cpp
${pathToProject}/Thirdparty/g2o/core/cache.h
${pathToProject}/Thirdparty/g2o/core/optimizable_graph.cpp
${pathToProject}/Thirdparty/g2o/core/optimizable_graph.h
${pathToProject}/Thirdparty/g2o/core/solver.cpp
${pathToProject}/Thirdparty/g2o/core/solver.h
${pathToProject}/Thirdparty/g2o/core/creators.h
${pathToProject}/Thirdparty/g2o/core/optimization_algorithm_factory.cpp
${pathToProject}/Thirdparty/g2o/core/estimate_propagator.cpp
${pathToProject}/Thirdparty/g2o/core/optimization_algorithm_factory.h
${pathToProject}/Thirdparty/g2o/core/estimate_propagator.h
${pathToProject}/Thirdparty/g2o/core/factory.cpp
${pathToProject}/Thirdparty/g2o/core/optimization_algorithm_property.h
${pathToProject}/Thirdparty/g2o/core/factory.h
${pathToProject}/Thirdparty/g2o/core/sparse_block_matrix.h
${pathToProject}/Thirdparty/g2o/core/sparse_optimizer.cpp
${pathToProject}/Thirdparty/g2o/core/sparse_block_matrix.hpp
${pathToProject}/Thirdparty/g2o/core/sparse_optimizer.h
${pathToProject}/Thirdparty/g2o/core/hyper_dijkstra.cpp
${pathToProject}/Thirdparty/g2o/core/hyper_dijkstra.h
${pathToProject}/Thirdparty/g2o/core/parameter_container.cpp
${pathToProject}/Thirdparty/g2o/core/parameter_container.h
${pathToProject}/Thirdparty/g2o/core/optimization_algorithm.cpp
${pathToProject}/Thirdparty/g2o/core/optimization_algorithm.h
${pathToProject}/Thirdparty/g2o/core/optimization_algorithm_with_hessian.cpp
${pathToProject}/Thirdparty/g2o/core/optimization_algorithm_with_hessian.h
${pathToProject}/Thirdparty/g2o/core/optimization_algorithm_levenberg.cpp
${pathToProject}/Thirdparty/g2o/core/optimization_algorithm_levenberg.h
${pathToProject}/Thirdparty/g2o/core/jacobian_workspace.cpp
${pathToProject}/Thirdparty/g2o/core/jacobian_workspace.h
${pathToProject}/Thirdparty/g2o/core/robust_kernel.cpp
${pathToProject}/Thirdparty/g2o/core/robust_kernel.h
${pathToProject}/Thirdparty/g2o/core/robust_kernel_factory.cpp
${pathToProject}/Thirdparty/g2o/core/robust_kernel_factory.h
${pathToProject}/Thirdparty/g2o/core/robust_kernel_impl.cpp
${pathToProject}/Thirdparty/g2o/core/robust_kernel_impl.h
#stuff
${pathToProject}/Thirdparty/g2o/stuff/string_tools.h
${pathToProject}/Thirdparty/g2o/stuff/color_macros.h
${pathToProject}/Thirdparty/g2o/stuff/macros.h
${pathToProject}/Thirdparty/g2o/stuff/timeutil.cpp
${pathToProject}/Thirdparty/g2o/stuff/misc.h
${pathToProject}/Thirdparty/g2o/stuff/timeutil.h
${pathToProject}/Thirdparty/g2o/stuff/os_specific.c
${pathToProject}/Thirdparty/g2o/stuff/os_specific.h
${pathToProject}/Thirdparty/g2o/stuff/string_tools.cpp
${pathToProject}/Thirdparty/g2o/stuff/property.cpp
${pathToProject}/Thirdparty/g2o/stuff/property.h)

#[[
#DBOW2
set(HDRS_DBOW2
  ${pathToProject}/Thirdparty/DBoW2/DBoW2/BowVector.h
  ${pathToProject}/Thirdparty/DBoW2/DBoW2/FORB.h
  ${pathToProject}/Thirdparty/DBoW2/DBoW2/FClass.h
  ${pathToProject}/Thirdparty/DBoW2/DBoW2/FeatureVector.h
  ${pathToProject}/Thirdparty/DBoW2/DBoW2/ScoringObject.h
  ${pathToProject}/Thirdparty/DBoW2/DBoW2/TemplatedVocabulary.h)
set(SRCS_DBOW2
  ${pathToProject}/Thirdparty/DBoW2/DBoW2/BowVector.cpp
  ${pathToProject}/Thirdparty/DBoW2/DBoW2/FORB.cpp
  ${pathToProject}/Thirdparty/DBoW2/DBoW2/FeatureVector.cpp
  ${pathToProject}/Thirdparty/DBoW2/DBoW2/ScoringObject.cpp)
set(HDRS_DUTILS
  ${pathToProject}/Thirdparty/DBoW2/DUtils/Random.h
  ${pathToProject}/Thirdparty/DBoW2/DUtils/Timestamp.h)
set(SRCS_DUTILS
  ${pathToProject}/Thirdparty/DBoW2/DUtils/Random.cpp
  ${pathToProject}/Thirdparty/DBoW2/DUtils/Timestamp.cpp)
add_library(DBoW2 SHARED ${SRCS_DBOW2} ${SRCS_DUTILS})
]]

target_link_libraries( native-lib $\{log-lib} lib_opencv g2o ${boost_lib})