#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring

JNICALL
Java_cn_zhaoping_hellondk_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_cn_zhaoping_hellondk_MainActivity_sum(JNIEnv *env, jobject instance, jint x, jint y) {

    // TODO
    int sum = x + y;
    return sum;
}extern "C"
JNIEXPORT void JNICALL
Java_cn_zhaoping_hellondk_MainActivity_callbackShowToast(JNIEnv *env, jobject instance) {

    // TODO
    jclass jc = (*env).FindClass("cn/zhaoping/hellondk/MainActivity");
    jmethodID jmethodID1 = (*env).GetMethodID(jc, "showToast", "()V");
    (*env).CallVoidMethod(instance, jmethodID1);
}extern "C"
JNIEXPORT void JNICALL
Java_cn_zhaoping_hellondk_MainActivity_callbackAdd(JNIEnv *env, jobject instance) {

    // TODO
    jclass jc = (*env).FindClass("cn/zhaoping/hellondk/MainActivity");
    jmethodID jmethodID1 = (*env).GetMethodID(jc, "addNum", "(II)I");
//    jobject jobject = (*env).AllocObject(jc);
    (*env).CallIntMethod(instance, jmethodID1, 2, 2);
}