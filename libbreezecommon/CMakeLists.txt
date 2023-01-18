################# dependencies #################
### Qt/KDE
find_package(Qt5 REQUIRED CONFIG COMPONENTS Widgets)

find_package(KF5 REQUIRED COMPONENTS CoreAddons GuiAddons ConfigWidgets WindowSystem I18n IconThemes)

find_package(KDecoration2 REQUIRED)

################# configuration #################
configure_file(config-breezecommon.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-breezecommon.h )

################# breezestyle target #################
set(roundedsbecommon_LIB_SRCS
    breezeboxshadowrenderer.cpp
    breezedecorationhelper.cpp
    breezeexceptionlist.cpp
    breezesettingsprovider.cpp
)

kconfig_add_kcfg_files(roundedsbecommon_LIB_SRCS ../breezesettings.kcfgc)

add_library(roundedsbecommon5 ${roundedsbecommon_LIB_SRCS})

generate_export_header(roundedsbecommon5
    BASE_NAME breezecommon
    EXPORT_FILE_NAME breezecommon_export.h)

target_link_libraries(roundedsbecommon5
    PUBLIC
        Qt5::Core
        Qt5::Gui
    PRIVATE
        KDecoration2::KDecoration
        KF5::ConfigCore
        KF5::CoreAddons
        KF5::ConfigWidgets
        KF5::GuiAddons
        KF5::I18n
        KF5::IconThemes
        KF5::WindowSystem)

set_target_properties(roundedsbecommon5 PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR})

install(TARGETS roundedsbecommon5 ${INSTALL_TARGETS_DEFAULT_ARGS} LIBRARY NAMELINK_SKIP)
