package com.lwm.ccalljava2;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.os.Bundle;

public class MainActivity extends Activity {
    private JNIDemo jniDemo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jniDemo = new JNIDemo();
        jniDemo.callbackSayHello();
    }
}
