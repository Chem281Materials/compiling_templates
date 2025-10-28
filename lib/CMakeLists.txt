cmake_minimum_required(VERSION 3.22)

# Project name and version
project(CustomVector VERSION 1.0.0
        DESCRIPTION "Custom vector class"
        LANGUAGES CXX)

# Add the library as a target
add_library(CustomVector)

# Specify the C++ standard
target_compile_features(CustomVector PUBLIC cxx_std_14)

# Create an alias for CustomVector
add_library(CustomVector::CustomVector ALIAS CustomVector)

# Add the library's source files
target_sources(CustomVector
	PRIVATE src/customvector.cpp)

set_target_properties(
	CustomVector
	PROPERTIES VERSION ${PROJECT_VERSION}
	           SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Set the include directories for the library
# Generally, headers in src should only be visible within the library
# Headers meant to be visible to users should be in /include
target_include_directories(
	CustomVector
	PRIVATE src
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	       $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

##########################################################################
########################## BEGIN INSTALL SECTION #########################
##########################################################################

# Include the GNUInstallDirs module to get the canonical install paths defined
include(GNUInstallDirs)

# Set install locations
install(
	TARGETS CustomVector
	EXPORT CustomVectorTargets
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Explicitly install the header files
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
	"CustomVectorConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion)

# message(WARNING "DATAROOT: ${CMAKE_INSTALL_DATAROOTDIR}"
configure_package_config_file(
	"${CMAKE_CURRENT_LIST_DIR}/cmake/CustomVectorConfig.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/CustomVectorConfig.cmake"
	INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/CustomVector
)

install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/CustomVectorConfig.cmake
	      ${CMAKE_CURRENT_BINARY_DIR}/CustomVectorConfigVersion.cmake
	DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/CustomVector
)
install(
	EXPORT CustomVectorTargets
	FILE CustomVectorTargets.cmake
	NAMESPACE CustomVector::
	DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/CustomVector
)



