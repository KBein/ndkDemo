#include <jni.h>
#include <string>
/**
 * 创建的cpp文件
 * MainActivity中的native方法即是调用一下一下方法
 *
 */

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_roger_ndkdemo_MainActivity_javaMethod(JNIEnv *env, jobject instance) {
    jclass clazz;
    jobject obj;
    jmethodID constrocMID;
    jmethodID methodId;

    //获取JavaClass类
    clazz = env->FindClass("com/example/roger/ndkdemo/JavaClass");
    //AllocObject()是指为clazz开辟一个新的对象，不调用此Class的构造方法
//    obj = env->AllocObject(clazz);
    //获取JavaClass 无参构造函数的jmethodID
    constrocMID = env->GetMethodID(clazz,"<init>","()V");
    //根据clazz和constrocMID new一个新的JavaClass对象
    obj = env->NewObject(clazz,constrocMID);

    /**
     * 第一个参数：是指定要调用的方法是在那个类
     * 第二个参数：是指定要调用的方法名字（UTF-8）
     * 第三个参数：是代表要调用方法的java方法签名（这边狭义的理解为返回值类型）
     */
    methodId = env->GetMethodID(clazz,"methodJava","()Ljava/lang/String;");

    return (jstring)env->CallObjectMethod(obj,methodId);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_roger_ndkdemo_MainActivity_getField(JNIEnv *env, jobject instance) {

    jclass clazz;
    jobject obj;
    jfieldID instance_field_id;
    jstring instance_field;


    clazz = env->FindClass("com/example/roger/ndkdemo/JavaClass");


    jmethodID constrocMID = env->GetMethodID(clazz,"<init>","()V");

    obj = env->NewObject(clazz,constrocMID);


    instance_field_id = env->GetFieldID(clazz,"nameStr","Ljava/lang/String;");

    instance_field = (jstring)env->GetObjectField(obj,instance_field_id);

    return instance_field;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_roger_ndkdemo_MainActivity_getStaticField(JNIEnv *env, jobject instance) {

    jclass clazz;

    jfieldID static_field_id;

    jstring static_field;

    clazz = env->FindClass("com/example/roger/ndkdemo/JavaClass");

    static_field_id = env->GetStaticFieldID(clazz,"staticField","Ljava/lang/String;");

    static_field = (jstring)env->GetStaticObjectField(clazz,static_field_id);




    return static_field;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_roger_ndkdemo_MainActivity_staticJavaMethod(JNIEnv *env, jclass type) {

    jclass clazz;
    jmethodID static_method_id;

    clazz = env->FindClass("com/example/roger/ndkdemo/JavaClass");

    static_method_id = env->GetStaticMethodID(clazz,"staticMethod","()Ljava/lang/String;");

    return (jstring)env->CallStaticObjectMethod(clazz,static_method_id);
}