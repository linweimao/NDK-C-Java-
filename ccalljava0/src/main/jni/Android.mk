LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog

LOCAL_MODULE := ccalljava0

LOCAL_SRC_FILES := CCallJava0.c

include $(BUILD_SHARED_LIBRARY)
