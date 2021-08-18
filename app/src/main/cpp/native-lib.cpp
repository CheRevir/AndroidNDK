#include <jni.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <android/log.h>

using namespace std;


#define LOG_TAG "Native"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_jni_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}extern "C"
JNIEXPORT jstring JNICALL
Java_com_jni_myapplication_MainActivity_a(JNIEnv *env, jobject thiz) {
    jclass c1 = env->FindClass("com/jni/myapplication/Test");
    jclass c2 = env->GetObjectClass(thiz);
    jint version = env->GetVersion();
    jboolean assign = env->IsAssignableFrom(c1, c2);
    jmethodID method = env->GetMethodID(c1, "<init>", "(I)V");
    jobject ob = env->NewObject(c1, method, 1);

    jfieldID valueField = env->GetFieldID(c1, "value", "J");
    jlong value = env->GetLongField(ob, valueField);

    jmethodID print = env->GetMethodID(c1, "print", "(J)V");
    jlong l = 1L;
    env->CallVoidMethod(ob, print, value);
    string s = "a";
    return env->NewStringUTF(s.c_str());
}extern "C"
JNIEXPORT void JNICALL
Java_com_jni_myapplication_MainActivity_b(JNIEnv *env, jobject thiz, jobject test) {
    jclass cl = env->GetObjectClass(test);
    jfieldID id = env->GetFieldID(cl, "v", "I");
    jint value = env->GetIntField(test, id);
    jlong v = value;
    jmethodID methodId = env->GetMethodID(cl, "print", "(J)V");

    jthrowable thr = env->ExceptionOccurred();
    if(thr!=nullptr){
        env->ExceptionClear();
        jclass error_cls = env->FindClass("java/lang/IllegalArgumentException");
        env->ThrowNew(error_cls,"asdasdfa");
        LOGE("发生异常");
    }
    else{
        long a = 100;
        if (a == v) {
            env->CallVoidMethod(test, methodId, v);
        }
        char b ='b';
        LOGE("a");
    }
}
/*

extern "C" {
static void get(JNIEnv *env, jobject, jlong handle) {

}

static JNINativeMethod jni_methods[] = {{"get", "(J)V", (void*)get},};

jint JNI_OnLoad(JavaVM *vm, void *reserved){
    return 1;
}
}*/
