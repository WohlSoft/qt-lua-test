#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T20:05:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -Wno-unused-local-typedefs

TARGET = qt-lua-test
TEMPLATE = app


SOURCES += main.cpp\
        luawindow.cpp \
    oolua/include/lua/lapi.c \
    oolua/include/lua/lauxlib.c \
    oolua/include/lua/lbaselib.c \
    oolua/include/lua/lbitlib.c \
    oolua/include/lua/lcode.c \
    oolua/include/lua/lcorolib.c \
    oolua/include/lua/lctype.c \
    oolua/include/lua/ldblib.c \
    oolua/include/lua/ldebug.c \
    oolua/include/lua/ldo.c \
    oolua/include/lua/ldump.c \
    oolua/include/lua/lfunc.c \
    oolua/include/lua/lgc.c \
    oolua/include/lua/linit.c \
    oolua/include/lua/liolib.c \
    oolua/include/lua/llex.c \
    oolua/include/lua/lmathlib.c \
    oolua/include/lua/lmem.c \
    oolua/include/lua/loadlib.c \
    oolua/include/lua/lobject.c \
    oolua/include/lua/lopcodes.c \
    oolua/include/lua/loslib.c \
    oolua/include/lua/lparser.c \
    oolua/include/lua/lstate.c \
    oolua/include/lua/lstring.c \
    oolua/include/lua/lstrlib.c \
    oolua/include/lua/ltable.c \
    oolua/include/lua/ltablib.c \
    oolua/include/lua/ltm.c \
    oolua/include/lua/lua.c \
    oolua/include/lua/luac.c \
    oolua/include/lua/lundump.c \
    oolua/include/lua/lvm.c \
    oolua/include/lua/lzio.c \
    oolua/include/class_from_stack.cpp \
    oolua/include/oolua.cpp \
    oolua/include/oolua_check_result.cpp \
    oolua/include/oolua_chunk.cpp \
    oolua/include/oolua_error.cpp \
    oolua/include/oolua_exception.cpp \
    oolua/include/oolua_function.cpp \
    oolua/include/oolua_helpers.cpp \
    oolua/include/oolua_open.cpp \
    oolua/include/oolua_pull.cpp \
    oolua/include/oolua_push.cpp \
    oolua/include/oolua_ref.cpp \
    oolua/include/oolua_registration.cpp \
    oolua/include/oolua_script.cpp \
    oolua/include/oolua_stack_dump.cpp \
    oolua/include/oolua_string.cpp \
    oolua/include/oolua_table.cpp \
    oolua/include/proxy_storage.cpp \
    oolua/include/push_pointer_internal.cpp \
    oolua/include/stack_get.cpp

HEADERS  += luawindow.h \
    oolua/include/lua/lapi.h \
    oolua/include/lua/lauxlib.h \
    oolua/include/lua/lcode.h \
    oolua/include/lua/lctype.h \
    oolua/include/lua/ldebug.h \
    oolua/include/lua/ldo.h \
    oolua/include/lua/lfunc.h \
    oolua/include/lua/lgc.h \
    oolua/include/lua/llex.h \
    oolua/include/lua/llimits.h \
    oolua/include/lua/lmem.h \
    oolua/include/lua/lobject.h \
    oolua/include/lua/lopcodes.h \
    oolua/include/lua/lparser.h \
    oolua/include/lua/lstate.h \
    oolua/include/lua/lstring.h \
    oolua/include/lua/ltable.h \
    oolua/include/lua/ltm.h \
    oolua/include/lua/lua.h \
    oolua/include/lua/lua.hpp \
    oolua/include/lua/luaconf.h \
    oolua/include/lua/lualib.h \
    oolua/include/lua/lundump.h \
    oolua/include/lua/lvm.h \
    oolua/include/lua/lzio.h \
    oolua/include/char_arrays.h \
    oolua/include/class_from_stack.h \
    oolua/include/default_trait_caller.h \
    oolua/include/dsl_va_args.h \
    oolua/include/lua_includes.h \
    oolua/include/lvd_type_traits.h \
    oolua/include/lvd_types.h \
    oolua/include/oolua.h \
    oolua/include/oolua_boilerplate.h \
    oolua/include/oolua_check_result.h \
    oolua/include/oolua_chunk.h \
    oolua/include/oolua_config.h \
    oolua/include/oolua_dsl.h \
    oolua/include/oolua_dsl_export.h \
    oolua/include/oolua_error.h \
    oolua/include/oolua_exception.h \
    oolua/include/oolua_function.h \
    oolua/include/oolua_helpers.h \
    oolua/include/oolua_open.h \
    oolua/include/oolua_pull.h \
    oolua/include/oolua_push.h \
    oolua/include/oolua_ref.h \
    oolua/include/oolua_registration.h \
    oolua/include/oolua_registration_fwd.h \
    oolua/include/oolua_script.h \
    oolua/include/oolua_stack.h \
    oolua/include/oolua_stack_dump.h \
    oolua/include/oolua_stack_fwd.h \
    oolua/include/oolua_string.h \
    oolua/include/oolua_table.h \
    oolua/include/oolua_traits.h \
    oolua/include/oolua_traits_fwd.h \
    oolua/include/oolua_version.h \
    oolua/include/platform_check.h \
    oolua/include/proxy_base_checker.h \
    oolua/include/proxy_caller.h \
    oolua/include/proxy_class.h \
    oolua/include/proxy_constructor.h \
    oolua/include/proxy_constructor_param_tester.h \
    oolua/include/proxy_function_dispatch.h \
    oolua/include/proxy_function_exports.h \
    oolua/include/proxy_member_function.h \
    oolua/include/proxy_none_member_function.h \
    oolua/include/proxy_operators.h \
    oolua/include/proxy_public_member.h \
    oolua/include/proxy_stack_helper.h \
    oolua/include/proxy_storage.h \
    oolua/include/proxy_tag_info.h \
    oolua/include/proxy_tags.h \
    oolua/include/proxy_test.h \
    oolua/include/proxy_userdata.h \
    oolua/include/push_pointer_internal.h \
    oolua/include/stack_get.h \
    oolua/include/type_converters.h \
    oolua/include/type_list.h \
    oolua/include/typelist_structs.h

FORMS    += luawindow.ui
