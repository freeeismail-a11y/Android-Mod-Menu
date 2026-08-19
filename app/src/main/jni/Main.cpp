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

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
    return JNI_VERSION_1_4;
}
