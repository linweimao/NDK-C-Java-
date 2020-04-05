package com.lwm.ccalljava;

import android.util.Log;

/**
 * @Author: 林伟茂
 * @Version: 1.0
 */
public class JNITest {

    static {

        System.loadLibrary("ccalljava");
    }

    /*
     * 当执行这个方法的时候，让 C 代码调用
     * public int add(int x, int y)
     *
     */
    public native void callbackAdd();

    /*
     * 当执行这个方法的时候，让 C 代码调用
     * public void helloFromJava()
     *
     */
    public native void callbackHelloFromJava();

    /*
     * 当执行这个方法的时候，让 C 代码调用
     * public void printString(String s)
     *
     */
    public native void callbackPrintString();

    /*
     * 当执行这个方法的时候，让 C 代码调用静态方法
     * public static void sayHello(String s)
     *
     */
    public native void callbackSayHello();


    // 下面的所有方法让 C 来调用（既然要让 C来调用，那么就要通知 C）
    public int add(int x, int y) {

        Log.e("TAG", "add() x=" + x + " y=" + y);

        return x + y;

    }


    public void helloFromJava() {

        Log.e("TAG", "helloFromJava()");

    }


    public void printString(String s) {

        Log.e("TAG", "C中输入的：" + s);

    }


    public static void sayHello(String s) {

        Log.e("TAG", "我是java代码中的JNI."

                + "java中的sayHello(String s)静态方法，我被C调用了:" + s);

    }
}
