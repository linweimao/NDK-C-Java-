//
// Created by 林伟茂 on 2020/4/4.
//
#include "com_lwm_ccalljava_JNITest.h"
#include <stdlib.h>
#include <stdio.h>

//2. 包含日志头文件, 定义日志输出函数
#include <android/log.h>
#define LOG_TAG "System.out"

//第一个参数为日志的等级，第二个参数为 TAG：标志，第三个参数为__VA_ARGS__：可变参数
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)



/*
 * 让 C 代码调用 Java 中JNI类的public int add(int x, int y)
 */
JNIEXPORT void JNICALL Java_com_lwm_ccalljava_JNITest_callbackAdd
        (JNIEnv *env, jobject jobj) {

    //使用反射来调用 Java 中JNI类
    //1、得到字节码(字节码是用于实例化这个类)
    //jclass      (*FindClass)(JNIEnv*, const char*);
    // 把全类名复制过来后把 . 改为 /
    // 为什么是 /?     因为 Linux下 / 代表下级目录
    jclass jclazz = (*env)->FindClass(env, "com/lwm/ccalljava/JNITest");

    //2、得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //GetMethodID()中最后一个参数是方法签名
    jmethodID jmethodIDs = (*env)->GetMethodID(env, jclazz, "add", "(II)I");

    //3、实例化该类
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject = (*env)->AllocObject(env, jclazz);

    //4、调用方法(这个方法CallIntMethod为可变参数(...)，就可以直接写)
    // public int add(int x, int y)这个方法有返回值
    //jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    jint value = (*env)->CallIntMethod(env, jobject, jmethodIDs, 99, 1);
    //成功调用了 public int add(int x, int y)
    //因为 JNI 中的方法为 void，所以没有返回值
    printf("value=%d\n", value);
    // 打印日志
    LOGE("value=%d\n", value);
};

/*
 * 让 C 代码调用 public void helloFromJava()
 * 没有参数 也没有返回值
 */
JNIEXPORT void JNICALL Java_com_lwm_ccalljava_JNITest_callbackHelloFromJava
        (JNIEnv* env, jobject jobj){

    //1、得到字节码(字节码是用于实例化这个类)
    jclass jclazz = (*env)->FindClass(env, "com/lwm/ccalljava/JNITest");

    //2、得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //GetMethodID()中最后一个参数是方法签名
    jmethodID jmethodIDs = (*env)->GetMethodID(env, jclazz, "helloFromJava", "()V");

    //3、实例化该类
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject = (*env)->AllocObject(env, jclazz);

    //4、调用方法（调用的方法是没有返回值的）
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env, jobject, jmethodIDs);
    //成功调用了 public void helloFromJava()

};

/*
 * 让 C 代码调用 public void printString(String s)
 * 有 String 参数 但是没有返回值
 */
JNIEXPORT void JNICALL Java_com_lwm_ccalljava_JNITest_callbackPrintString
        (JNIEnv* env, jobject jobj){

    //1、得到字节码(字节码是用于实例化这个类)
    jclass jclazz = (*env)->FindClass(env, "com/lwm/ccalljava/JNITest");

    //2、得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //GetMethodID()中最后一个参数是方法签名
    jmethodID jmethodIDs = (*env)->GetMethodID(env, jclazz, "printString", "(Ljava/lang/String;)V");

    //3、实例化该类
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject = (*env)->AllocObject(env, jclazz);

    //4、调用方法（调用的方法是没有返回值的）
    // public void printString(String s)（调用的方法是没有返回值的，但是要传string参数，在jni里就传jstring）
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    //jstring     (*NewStringUTF)(JNIEnv*, const char*);
    // 调用的方法是没有返回值的，但是要传string参数，在 JNI 里就传jstring）
    jstring jst = (**env).NewStringUTF(env,"LinWeiMao!!!");//或者这么写 jstring jst = (*env)->NewStringUTF(env,"LinWeiMao!!!");
    // 要传一个string参数：要传的是string，但是这里是JNI（转调函数）里所以传 jstring
    (*env)->CallVoidMethod(env, jobject, jmethodIDs,jst);
    //成功调用了 public void helloFromJava()

};

/*
 * 让 C 代码调用 静态方法 public static void sayHello(String s)
 * 有 String 参数 但是没有返回值
 *
 * 静态方法不需要实例化
 */
JNIEXPORT void JNICALL Java_com_lwm_ccalljava_JNITest_callbackSayHello
        (JNIEnv* env, jobject jobj){

    //1、得到字节码(字节码是用于实例化这个类)
    jclass jclazz = (*env)->FindClass(env, "com/lwm/ccalljava/JNITest");

    //2、得到方法
    //jmethodID   (*GetStaticMethodID)(JNIEnv*, jclass, const char*, const char*);
    //GetMethodID()中最后一个参数是方法签名
    jmethodID jmethodIDs = (*env)->GetStaticMethodID(env, jclazz, "sayHello", "(Ljava/lang/String;)V");

    //3、实例化该类
    //有 String 参数 但是没有返回值使用 CallStaticVoidMethod 函数
    //void        (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);
    // 调用的方法是没有返回值的，但是要传string参数，在 JNI 里就传jstring）
    jstring jst = (**env).NewStringUTF(env,"LinWeiMao!!!");//或者这么写 jstring jst = (*env)->NewStringUTF(env,"LinWeiMao!!!");
    //第三个参数：因为方法在第二步时获取到 jmethodIDs 所以第三个参数传 jmethodIDs
    (*env)->CallStaticVoidMethod(env, jclazz, jmethodIDs,jst);
    //成功调用了 public static void sayHello(String s)

};