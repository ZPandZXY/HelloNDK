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
}extern "C"
JNIEXPORT jint JNICALL
Java_cn_zhaoping_hellondk_MainActivity_addNum__(JNIEnv *env, jobject instance) {

    // TODO
    jclass jclass1 = env->GetObjectClass(
            instance);//等价于(*env).FindClass("cn/zhaoping/hellondk/MainActivity");
    jfieldID jfieldID1 = env->GetFieldID(jclass1, "num", "I");
    jmethodID jmethodID1 = env->GetMethodID(jclass1, "showToast", "(I)V");
    jint num = env->GetIntField(instance, jfieldID1);
    env->CallVoidMethod(instance, jmethodID1, num);
    num++;
    env->CallVoidMethod(instance, jmethodID1, num);
    return num;

}extern "C"
JNIEXPORT void JNICALL
Java_cn_zhaoping_hellondk_MainActivity_accessStaticField(JNIEnv *env, jobject instance) {

    // TODO
    jclass jclass1 = env->GetObjectClass(instance);
    jfieldID jfieldID1 = env->GetStaticFieldID(jclass1, "name", "Ljava/lang/String;");
    jstring name = (jstring) env->GetStaticObjectField(jclass1, jfieldID1);
    const char *str = env->GetStringUTFChars(name, JNI_FALSE);
    char ch[30] = "hello,";
    jmethodID jmethodID1 = env->GetMethodID(jclass1, "showToast", "(Ljava/lang/String;)V");
    env->CallVoidMethod(instance, jmethodID1, name);
    strcat(ch, str);
    jstring new_str = env->NewStringUTF(ch);
    env->SetStaticObjectField(jclass1, jfieldID1, new_str);
    jfieldID jfieldID2 = env->GetStaticFieldID(jclass1, "name", "Ljava/lang/String;");
    jstring name2=(jstring)env->GetStaticObjectField(jclass1,jfieldID2);
    env->CallVoidMethod(instance, jmethodID1, name2);
}