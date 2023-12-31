cmake_minimum_required(VERSION 3.5)

project(Financial_Interface VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        useroverview.cpp
        src/AccessCard.cpp
        src/Actions.cpp
        src/Customer.cpp
        src/DBConnection.cpp
        src/FinancialInstrumentHelper.cpp
        src/PythonConnection.cpp
        src/Validators.cpp
        src/QtToCHelper.cpp
        src/JsonHelper.cpp
        src/PortfolioTableModel.cpp

        mainwindow.h
        mainwindow.ui
        useroverview.h
        useroverview.ui
        headers/AccessCard.h
        headers/Actions.h
        headers/Customer.h
        headers/DBConnection.h
        headers/FinancialInstrumentHelper.h
        headers/PythonConnection.h
        headers/Validators.h
        headers/QtToCHelper.h
        headers/JsonHelper.h
        headers/PortfolioTableModel.h

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Financial_Interface
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Financial_Interface APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Financial_Interface SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Financial_Interface
            ${PROJECT_SOURCES}
        )
    endif()
endif()

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

find_package(nlohmann_json REQUIRED)
target_link_libraries(Financial_Interface PRIVATE nlohmann_json::nlohmann_json)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})

target_link_libraries(Financial_Interface PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    ${PYTHON_LIBRARIES}
    ${JSONCPP_LIBRARIES}
   
    /usr/lib/x86_64-linux-gnu/libmysqlcppconn.so)

set_target_properties(Financial_Interface PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Financial_Interface
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Financial_Interface)
endif()
