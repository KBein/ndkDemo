package com.example.roger.ndkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        tv = findViewById(R.id.sample_text);

    }


    //调用类JavaClass中的非静态方法；
    public native String javaMethod();
    //调用类JavaClass中的静态方法
    public static native String staticJavaMethod();
    //调用类JavaClass 中非静态属性
    public native String getField();
    //调用类JavaClass 中静态属性
    public native String getStaticField();

    public void onClickBtn(View view) {

        switch (view.getId()) {

            case R.id.btn1:
                String javaMethod = javaMethod();
                tv.setText(javaMethod);
                Log.i("KBein", "onCreate: javaMethod() == "+javaMethod);

                break;
            case R.id.btn2:

                String field = getField();
                tv.setText(field);

                Log.i("KBein", "onCreate: getField() == "+field);

                break;

            case R.id.btn3:

                String staticField = getStaticField();
                tv.setText(staticField);
                Log.i("KBein", "onCreate: getStaticField() == "+ staticField);

                break;

            case R.id.btn4:
                String staticJavaMethod = staticJavaMethod();
                tv.setText(staticJavaMethod);
                Log.i("KBein", "onClickBtn: staticJavaMethod() == "+staticJavaMethod);
                break;

        }
    }
}
