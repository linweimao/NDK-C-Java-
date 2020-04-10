LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog

LOCAL_MODULE := ccalljava2

LOCAL_SRC_FILES := Test.c

include $(BUILD_SHARED_LIBRARY)
