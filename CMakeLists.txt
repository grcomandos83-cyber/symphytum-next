cmake_minimum_required(VERSION 3.16)

project(Symphytum
    VERSION 2.8
    DESCRIPTION "Personal database software"
    HOMEPAGE_URL "https://github.com/grcomandos83-cyber/symphytum-next"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui" "${CMAKE_CURRENT_SOURCE_DIR}/widgets")

# Find Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets Sql Network Svg PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets Sql Network Svg PrintSupport)

if(WIN32 AND QT_VERSION_MAJOR EQUAL 5)
    find_package(Qt5 REQUIRED COMPONENTS WinExtras)
endif()

# Source files
set(SOURCES
    main.cpp
    components/sync_framework/foldersyncdriver.cpp
    widgets/mainwindow.cpp
    utils/definitionholder.cpp
    views/formview/formview.cpp
    components/formlayoutmatrix.cpp
    widgets/form_widgets/abstractformwidget.cpp
    widgets/form_widgets/testformwidget.cpp
    views/formview/droprectwidget.cpp
    views/formview/selectrectwidget.cpp
    views/formview/resizedotwidget.cpp
    widgets/viewtoolbarwidget.cpp
    widgets/searchlineedit.cpp
    widgets/dockwidget.cpp
    views/tableview/tableview.cpp
    components/metadataengine.cpp
    models/standardmodel.cpp
    models/testmodel.cpp
    models/collectionlistmodel.cpp
    components/databasemanager.cpp
    views/tableview/tableviewdelegate.cpp
    components/settingsmanager.cpp
    views/collectionlistview/collectionlistview.cpp
    widgets/form_widgets/textformwidget.cpp
    utils/platformcolorservice.cpp
    widgets/form_widgets/numberformwidget.cpp
    widgets/textarea.cpp
    utils/metadatapropertiesparser.cpp
    utils/formwidgetvalidator.cpp
    views/formview/emptyformwidget.cpp
    widgets/field_widgets/addfielddialog.cpp
    widgets/field_widgets/abstractfieldwizard.cpp
    widgets/field_widgets/textfieldwizard.cpp
    widgets/field_widgets/numberfieldwizard.cpp
    components/undocommands.cpp
    views/collectionlistview/collectionviewdelegate.cpp
    utils/formviewlayoutstate.cpp
    components/sync_framework/abstractsyncdriver.cpp
    components/sync_framework/dropboxsyncdriver.cpp
    widgets/syncconfigdialog.cpp
    components/backupmanager.cpp
    components/filemanager.cpp
    components/sync_framework/syncsession.cpp
    components/sync_framework/syncengine.cpp
    widgets/syncstatuswidget.cpp
    widgets/syncprocessdialog.cpp
    utils/qtsingleapplication/qtsinglecoreapplication.cpp
    utils/qtsingleapplication/qtsingleapplication.cpp
    utils/qtsingleapplication/qtlocalpeer.cpp
    widgets/preferencesdialog.cpp
    widgets/backupdialog.cpp
    widgets/form_widgets/checkboxformwidget.cpp
    widgets/field_widgets/checkboxfieldwizard.cpp
    widgets/form_widgets/imageformwidget.cpp
    widgets/field_widgets/imagefieldwizard.cpp
    views/tableview/editors/imagetypeeditor.cpp
    components/updatemanager.cpp
    widgets/form_widgets/comboboxformwidget.cpp
    widgets/field_widgets/comboboxfieldwizard.cpp
    widgets/form_widgets/progressformwidget.cpp
    widgets/field_widgets/progressfieldwizard.cpp
    widgets/form_widgets/filesformwidget.cpp
    widgets/field_widgets/filesfieldwizard.cpp
    views/tableview/editors/filestypeeditor.cpp
    widgets/field_widgets/datefieldwizard.cpp
    widgets/form_widgets/dateformwidget.cpp
    widgets/field_widgets/creationdatefieldwizard.cpp
    widgets/form_widgets/creationdateformwidget.cpp
    widgets/field_widgets/moddatefieldwizard.cpp
    widgets/form_widgets/moddateformwidget.cpp
    utils/collectionfieldcleaner.cpp
    components/alarmmanager.cpp
    widgets/alarmlistdialog.cpp
    widgets/printdialog.cpp
    widgets/exportdialog.cpp
    widgets/importdialog.cpp
    widgets/aboutdialog.cpp
    widgets/form_widgets/urlformwidget.cpp
    widgets/field_widgets/urlfieldwizard.cpp
    widgets/field_widgets/emailfieldwizard.cpp
    widgets/form_widgets/emailformwidget.cpp
    widgets/field_widgets/currencyfieldwizard.cpp
    widgets/form_widgets/currencyformwidget.cpp
    components/sync_framework/megasyncdriver.cpp
    widgets/upgradesuccessdialog.cpp
)

if(WIN32)
    list(APPEND SOURCES
        resources/symphytum.rc
    )
endif()

# UI forms
set(FORMS
    ui/emptyformwidget.ui
    ui/textfieldwizard.ui
    ui/addfielddialog.ui
    ui/numberfieldwizard.ui
    ui/syncconfigdialog.ui
    ui/syncprocessdialog.ui
    ui/preferencesdialog.ui
    ui/backupdialog.ui
    ui/checkboxfieldwizard.ui
    ui/imagefieldwizard.ui
    ui/comboboxfieldwizard.ui
    ui/progressfieldwizard.ui
    ui/filesfieldwizard.ui
    ui/datefieldwizard.ui
    ui/creationdatefieldwizard.ui
    ui/moddatefieldwizard.ui
    ui/alarmlistdialog.ui
    ui/printdialog.ui
    ui/exportdialog.ui
    ui/importdialog.ui
    ui/aboutdialog.ui
    ui/urlfieldwizard.ui
    ui/emailfieldwizard.ui
    widgets/upgradesuccessdialog.ui
)

# Resources
set(RESOURCES
    resources/resources.qrc
)

# Executable target
if(WIN32)
    add_executable(symphytum WIN32 ${SOURCES} ${FORMS} ${RESOURCES})
elseif(APPLE)
    add_executable(symphytum MACOSX_BUNDLE ${SOURCES} ${FORMS} ${RESOURCES})
    set_target_properties(symphytum PROPERTIES
        MACOSX_BUNDLE_BUNDLE_NAME "Symphytum"
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.giowisys.symphytum"
    )
else()
    add_executable(symphytum ${SOURCES} ${FORMS} ${RESOURCES})
endif()

target_include_directories(symphytum PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(symphytum PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Svg
    Qt${QT_VERSION_MAJOR}::PrintSupport
)

if(WIN32 AND QT_VERSION_MAJOR EQUAL 5)
    target_link_libraries(symphytum PRIVATE Qt5::WinExtras)
endif()

if(WIN32)
    target_compile_definitions(symphytum PRIVATE UNICODE _UNICODE)
endif()
