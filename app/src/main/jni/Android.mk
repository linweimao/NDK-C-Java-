LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog

LOCAL_MODULE := ccalljava

LOCAL_SRC_FILES := CCallJava.c

include $(BUILD_SHARED_LIBRARY)
