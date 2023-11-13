#设置cmake 版本号
cmake_minimum_required(VERSION 3.25.1)

#设置工程名称,使用C++
project(CANTestDevStudio LANGUAGES CXX)
#Qt kit dir
set(CMAKE_PREFIX_PATH "E:/AppInstall/VS_MSVP_Complier/5.15.2/msvc2019_64") # Qt Kit Dir
#设置工程包含当前目录,非必须
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#打开全局moc，设置自动生成moc文件，一定要设置
set(CMAKE_AUTOMOC ON)

#打开全局uic，非必须
set(CMAKE_AUTOUIC ON)

#打开全局rcc，非必须，如需打开，注意修改33行qrc文件名
#set(CMAKE_AUTORCC ON)

#增加QtNode的导出宏定义，这里选择动态库（由Export.hpp）
add_definitions(-DNODE_EDITOR_SHARED)


#查找需要的QT库文件
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Gui)
SET(_LIB_DIRCTORES_ "E:/AppInstall/NodeLibaray")
SET(_INCLUDE_DIRCTORES_ "E:/AppInstall/NodeLibaray/include/QtNodes" 
"E:/AppInstall/NodeLibaray/include/QtNodes/internal"
"F:/Lyb-file/Code/Tools-dev/CANTestDevStudio/CANTestDevStudio/common")
#添加库路径
LINK_DIRECTORIES("${_LIB_DIRCTORES_}/lib")
#添加库
LINK_LIBRARIES(QtNodes)

include_directories("${_INCLUDE_DIRCTORES_}")
#查找当前文件夹的所有源代码文件
#FILE(GLOB SRC_FILES "./*.cpp" "./*.c" "./common/*.cpp")
#FILE(GLOB HEAD_FILES "./*.h" "./*.hpp" "E:/AppInstall/NodeLibaray/include/QtNodes/internal/*.hpp" "./common/*.h" "./common/*.hpp")
set(SRC_FILES 
CANTestDevStudio.cpp
main.cpp
common/DecimalData.cpp
common/DeviceLINModel.cpp
common/DeviceCANModel.cpp
common/SendCANModel.cpp
common/NodeFunctionStack.cpp
common/NodeWindow.cpp
common/NodePropertyWidget.cpp
common/NodeGlobeData.cpp
common/NodeShowTableImplement.cpp
common/Delegate/mComboboxDelegate.cpp
common/NodeParameterManage.cpp
)

set(HEAD_FILES
CANTestDevStudio.h
common/CommonDataStruct.h
common/DecimalData.h
common/DeviceLINModel.h
common/DeviceCANModel.h
common/SendCANModel.h
common/NodeFunctionStack.h
common/NodeWindow.h
common/NodePropertyWidget.h
common/NodeGlobeData.h
common/NodeShowTableImplement.h
common/Delegate/mComboboxDelegate.h
common/NodeParameterManage.h
)
#通过ui文件生成对应的头文件，一定要添加
qt5_wrap_ui(WRAP_FILES ${UI_FILES})

#添加资源文件，非必须，
#set(RCC_FILES rcc.qrc)

#将ui文件和生成文件整理在一个文件夹中，非必须
source_group("Ui" FILES ${UI_FILES} ${WRAP_FILES})

# Specify MSVC UTF-8 encoding   
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

#创建工程文件 加上WIN32可以去掉那个黑框
add_executable(${PROJECT_NAME} WIN32  ${HEAD_FILE} ${SRC_FILES} ${WRAP_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Widgets Qt5::Core Qt5::Gui QtNodes)
