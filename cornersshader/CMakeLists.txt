set(CORNERSSHADER kwin4_effect_cornersshader)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
    Gui
    Core
    UiTools
    Widgets
    X11Extras
    OpenGL
    Network
    Xml
)

#find_package(KWaylandServer CONFIG REQUIRED)
#set_package_properties(KWaylandServer PROPERTIES
#    TYPE REQUIRED
#    PURPOSE "For Wayland integration"
#)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${Qt5X11Extras_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS} ${Qt5OpenGL_INCLUDE_DIRS} ${Qt5Xml_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)

# required frameworks by Core
find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    Config
    ConfigWidgets
    CoreAddons
    Crash
    GlobalAccel
    I18n
    KIO
    Service
    Init
    Notifications
    Service
    WidgetsAddons
    WindowSystem
    GuiAddons
)

find_package(X11 REQUIRED)
find_package(XCB REQUIRED)

execute_process(COMMAND kf5-config --install module OUTPUT_VARIABLE MODULEPATH OUTPUT_STRIP_TRAILING_WHITESPACE)

find_path(EFFECTS_H kwineffects.h PATH_SUFFIXES kf5)

if (EFFECTS_H)
    include_directories(${EFFECTS_H})
else (EFFECTS_H)
    message(STATUS "didnt find kwineffects.h, not building effects")
endif (EFFECTS_H)

find_library(KWIN_EFFECTS NAMES kwineffects PATH_SUFFIXES kf5)
find_library(KWIN_GLUTILS NAMES kwinglutils PATH_SUFFIXES kf5)
find_library(OPENGL NAMES GL)

if (NOT KWIN_EFFECTS)
    message(STATUS "didnt find kwineffects lib, not building effects")
endif (NOT KWIN_EFFECTS)

if (NOT KWIN_GLUTILS)
    message(STATUS "didnt find kwin glutils lib, not building effects")
endif (NOT KWIN_GLUTILS)

if (NOT OPENGL)
    message(STATUS "didnt find opengl, not building effects")
endif (NOT OPENGL)

if (NOT EFFECTS_H OR NOT KWIN_GLUTILS OR NOT KWIN_EFFECTS OR NOT OPENGL)
    message(FATAL_ERROR "cant continue")
endif (NOT EFFECTS_H OR NOT KWIN_GLUTILS OR NOT KWIN_EFFECTS OR NOT OPENGL)

add_library(${CORNERSSHADER} MODULE cornersshader.cpp)

target_link_libraries(${CORNERSSHADER}
    PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::DBus
        ${KWIN_EFFECTS}
        ${KWIN_GLUTILS}
        epoxy
        GL
    PRIVATE
        KF5::ConfigCore
        KF5::CoreAddons
        KF5::ConfigWidgets
        KF5::GuiAddons
        KF5::WindowSystem
        KDecoration2::KDecoration
        #Plasma::KWaylandServer
        roundedsbecommon5
        )

if (XCB_FOUND)
    target_link_libraries(${CORNERSSHADER} PUBLIC Qt5::X11Extras XCB::XCB)
else (XCB_FOUND)
    if (X11_FOUND)
        target_link_libraries(${CORNERSSHADER} PUBLIC ${X11_X11_LIB} ${X11_LIBRARIES})
    endif (X11_FOUND)
endif (XCB_FOUND)


install(TARGETS ${CORNERSSHADER} DESTINATION ${MODULEPATH}/kwin/effects/plugins)

execute_process(COMMAND kf5-config --install data OUTPUT_VARIABLE DATAPATH OUTPUT_STRIP_TRAILING_WHITESPACE)

install(FILES shaders_140/cornersshader.frag DESTINATION ${DATAPATH}/kwin/shaders/1.40)
install(FILES shaders_110/cornersshader.frag DESTINATION ${DATAPATH}/kwin/shaders/1.10)


