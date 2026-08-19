#include <jni.h>
#include <dlfcn.h>
#include <pthread.h>
#include <unistd.h>

// Hooking function example
void* hack_thread(void*) {
    // Wait for the game to load
    sleep(10); 

    while (true) {
        // Pointer to the base address of libil2cpp (placeholder)
        uintptr_t libBase = (uintptr_t)dlopen("libil2cpp.so", RTLD_LAZY);

        // Health Hook: set Health to a high value
        // Offset 0x10 from the relevant class found in dump
        float* health = (float*)(libBase + 0x10); 
        *health = 9999.0f;

        // No Recoil Hook: set RecoilRatio to 0
        // Offset 0x40
        float* recoil = (float*)(libBase + 0x40);
        *recoil = 0.0f;

        // No Spread Hook: set blurSpread to 0
        // Offset 0x24
        float* spread = (float*)(libBase + 0x24);
        *spread = 0.0f;

        sleep(1); // Update every second
    }
    return NULL;
}

jobjectArray GetFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;
    
    
    const char *features[] = {
        "1_Toggle_No Recoil", 
        "2_Category_Features"
    };

    int Total_Length = sizeof(features) / sizeof(features[0]);

    ret = (jobjectArray)env->NewObjectArray(Total_Length, env->FindClass("java/lang/String"), env->NewStringUTF(""));
    for (int i = 0; i < Total_Length; i++) {
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));
    }
    
    return ret;
}
void Changes(JNIEnv *env, jclass clazz, jobject obj, jint featNum, jstring featName, jint value, jlong lon, jboolean boolVal, jstring strVal) {
    switch (featNum) {
        case 1:
            // Code for the first button
            break;
        default:
            break;
    }
}
