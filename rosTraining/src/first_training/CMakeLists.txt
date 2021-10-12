cmake_minimum_required(VERSION 3.5)
project(first_training)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp_components REQUIRED)

# adding source code to cmake
#add_executable(first_node src/first_node.cpp) for basic
add_library(${PROJECT_NAME} SHARED src/first_node.cpp)
#ament_target_dependencies(first_node rclcpp rclcpp_components) for basic
ament_target_dependencies(${PROJECT_NAME} rclcpp rclcpp_components)
#install(TARGETS first_node DESTINATION lib/${PROJECT_NAME}) for basic
install(TARGETS ${PROJECT_NAME} DESTINATION lib)

#register component for ros to use
rclcpp_components_register_node(
  ${PROJECT_NAME}
  PLUGIN "first_training::FirstNode"
  EXECUTABLE first_node
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
