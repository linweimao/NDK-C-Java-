//
// Created by 林伟茂 on 2020/4/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <jni.h>

/*
 * 调用 java代码中 JNIDemo类里面的 public void sayHello()
 */
void Java_com_lwm_ccalljava2_JNIDemo_callbackSayHello(JNIEnv *env, jobject thiz) {

    //1.得到字节码
    //jclass      (*FindClass)(JNIEnv*, const char*);
    //jclass jclazz = (*env)->FindClass(env, "com/lwm/ccalljava2/JNIDemo");
    //上面那么写（(*env)->FindClass）或者下面这么写（(**env).FindClass）
    jclass jclazz = (**env).FindClass(env, "com/lwm/ccalljava2/JNIDemo");

    //2.得到对应的方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodid = (**env).GetMethodID(env,jclazz,"sayHello","()V");

    //3.实例化 JNIDemo类
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobj = (**env).AllocObject(env,jclazz);

    //4.调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (**env).CallVoidMethod(env,jobj,jmethodid);//就这样成功调用了java中 JNIDemo里面的 sayHello() 方法
};