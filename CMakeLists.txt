cmake_minimum_required (VERSION 3.0 FATAL_ERROR)

project(permissions)
set(PERMISSIONS_VERSION 0.1.1b)


set(QT_MIN_VERSION     "5.11.0")
set(KF5_MIN_VERSION    "5.49.0")
set(PLASMA_MIN_VERSION "5.13.0")

find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# CMake includes
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMInstallIcons)
include(ECMSetupVersion)
include(FeatureSummary)

# QT packages
find_package(
    Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
        Core
)

# Source files to be included
set ( PERMISSIONS_SOURCES
        permissions.cpp
        main.cpp
)

add_executable(${PROJECT_NAME} ${PERMISSIONS_SOURCES})

target_link_libraries(
   permissions
        Qt5::Core
)

# More misc CMake directives
feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
