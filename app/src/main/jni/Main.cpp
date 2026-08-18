#include <jni.h>
#include <string>
#include <android/log.h>
#include <ModMenu/Includes.h>

bool g_AimbotHeadshot = false;
bool g_ESP = false;
bool g_NoRecoil = false;
bool g_NoSpread = false;

void Hack_Aimbot() {
    if (!g_AimbotHeadshot) return;
}

void Hack_ESP(void *instance) {
    if (!g_ESP) return;
}

void Hack_WeaponParams() {
    if (g_NoRecoil) {
    }
    if (g_NoSpread) {
    }
}

void *UpdateThread(void *) {
    while (true) {
        Hack_Aimbot();
        Hack_WeaponParams();
        sleep(1);
    }
    return NULL;
}

void *ModMenuThread(void *) {
    // AddToggle("Aimbot Headshot", &g_AimbotHeadshot);
    // AddToggle("ESP Draw", &g_ESP);
    // AddToggle("No Recoil", &g_NoRecoil);
    // AddToggle("No Spread", &g_NoSpread);
    return NULL;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    pthread_t pt;
    pthread_create(&pt, NULL, UpdateThread, NULL);
    pthread_create(&pt, NULL, ModMenuThread, NULL);
    return JNI_VERSION_1_6;
}
