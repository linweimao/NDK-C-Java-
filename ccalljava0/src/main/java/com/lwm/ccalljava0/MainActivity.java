package com.lwm.ccalljava0;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

//在 MainActivity 一调用 JNITest类中的 native 方法，这个 native 方法就是调用对应的 C 代码(CCallJava.c)中，然后在回调 JNITest类对应的回调的方法
public class MainActivity extends Activity implements View.OnClickListener {

    private Button ccalljavaadd;
    private JNITest jniTest;
    private Button ccalljavahellofromjava;
    private Button ccalljavacallbackPrintString;
    private Button ccalljavasayhello;
    private Button callbackshowtoast;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jniTest = new JNITest();
        initView();
        ccalljavaadd.setOnClickListener(this);
        ccalljavahellofromjava.setOnClickListener(this);
        ccalljavacallbackPrintString.setOnClickListener(this);
        ccalljavasayhello.setOnClickListener(this);
        callbackshowtoast.setOnClickListener(this);
    }

    private void initView() {
        ccalljavaadd = (Button) findViewById(R.id.ccalljavaadd);
        ccalljavahellofromjava = (Button) findViewById(R.id.ccalljavahellofromjava);
        ccalljavacallbackPrintString = (Button) findViewById(R.id.ccalljavacallbackPrintString);
        ccalljavasayhello = (Button) findViewById(R.id.ccalljavasayhello);
        callbackshowtoast = (Button) findViewById(R.id.callbackshowtoast);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.ccalljavaadd:
                Add();
                break;
            case R.id.ccalljavahellofromjava:
                HelloFromJava();
                break;
            case R.id.ccalljavacallbackPrintString:
                CallBackPrintString();
                break;
            case R.id.ccalljavasayhello:
                CallBackSayHello();
                break;
            case R.id.callbackshowtoast:
                CallBackShowtoast();
                break;
        }
    }

    public void Add() {
        //当我们调用 callbackAdd 方法，那么 callbackAdd 方法会通过C代码回调add方法
        jniTest.callbackAdd();
    }

    public void HelloFromJava() {
        //当我们调用 callbackAdd 方法，那么 callbackAdd 方法会通过C代码回调add方法
        jniTest.helloFromJava();
    }

    public void CallBackPrintString() {
        //当我们调用 callbackAdd 方法，那么 callbackAdd 方法会通过C代码回调add方法
        jniTest.callbackPrintString();
    }

    public void CallBackSayHello() {
        //当我们调用 callbackAdd 方法，那么 callbackAdd 方法会通过C代码回调add方法
        jniTest.callbackSayHello();
    }
    public void CallBackShowtoast() {
        //当我们调用 callbackAdd 方法，那么 callbackAdd 方法会通过C代码回调add方法
        jniTest.callBackShowToast();
    }

    public void showToast() {
        System.out.println("showToast------");
        Toast.makeText(MainActivity.this, "showToast------", Toast.LENGTH_SHORT).show();
    }
}
