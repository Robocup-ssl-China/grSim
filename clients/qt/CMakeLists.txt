cmake_minimum_required(VERSION 2.8)

set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(libs)

find_package(Qt5 COMPONENTS Core Widgets Network REQUIRED)
list(APPEND libs Qt5::Core Qt5::Widgets Qt5::Network)


find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
list(APPEND libs ${PROTOBUF_LIBRARIES})

protobuf_generate_cpp(PROTO_CPP PROTO_H
    ../../src/proto/grSim_Replacement.proto
    ../../src/proto/grSim_Commands.proto
    ../../src/proto/grSim_Packet.proto
    ../../src/proto/zss_cmd_type.proto
    ../../src/proto/zss_cmd.proto
)cmake_minimum_required(VERSION 2.8)

set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(libs)

find_package(Qt5 COMPONENTS Core Widgets Network REQUIRED)
list(APPEND libs Qt5::Core Qt5::Widgets Qt5::Network)


find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
list(APPEND libs ${PROTOBUF_LIBRARIES})

# protobuf_generate_cpp(PROTO_CPP PROTO_H
#     ../../src/proto/grSim_Replacement.proto
#     ../../src/proto/grSim_Commands.proto
#     ../../src/proto/grSim_Packet.proto
#     ../../src/proto/zss_cmd_type.proto
#     ../../src/proto/zss_cmd.proto
# )
get_pb_file(PROTO_H PROTO_CPP 
    messages_robocup_ssl_detection
    messages_robocup_ssl_geometry
    messages_robocup_ssl_wrapper
    messages_robocup_ssl_refbox_log
    messages_robocup_ssl_robot_status
    grSim_Replacement
    grSim_Commands
    grSim_Packet
    zss_cmd_type
    zss_cmd
)

set(app client)

add_executable(${app} MACOSX_BUNDLE
    ${PROTO_CPP}
    ${PROTO_H}
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

target_link_libraries(${app} ${libs})


set(app client)

add_executable(${app} MACOSX_BUNDLE
    ${PROTO_CPP}
    ${PROTO_H}
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

target_link_libraries(${app} ${libs})

