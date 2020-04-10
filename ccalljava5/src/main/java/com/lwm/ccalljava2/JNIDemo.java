package com.lwm.ccalljava2;

import android.util.Log;

/**
 * @Author: 林伟茂
 * @Version: 1.0
 */
public class JNIDemo {

    {
        System.loadLibrary("ccalljava2");
    }
    /*
     * 触发 C代码让其调用sayHello()方法
     */
    public native void callbackSayHello();

    public void sayHello(){
        Log.e(JNIDemo.class.getSimpleName(), "sayHello(jniLibs+)");
    }
}
