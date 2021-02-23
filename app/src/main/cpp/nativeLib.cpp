#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_cn_com_hwtc_jni_TestJNI_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
