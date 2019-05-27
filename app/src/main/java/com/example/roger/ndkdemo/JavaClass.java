package com.example.roger.ndkdemo;

/**
 * 创建一个Java类
 * 类中定义静态属性和方法，以及非静态属性和方法
 *
 */
public class JavaClass {


    public String nameStr = "instance Field";

    public static String staticField = "static  Field";

    public JavaClass(){

    }

    private String methodJava(){

        String str = "这是java的方法methodJava()-->通过native String javaMethod()调用";
        return str;

    }

    private static String staticMethod(){

        return "这是JavaClass类中的静态方法-->通过static native String staticJavaMethod()调用";
    }

}
