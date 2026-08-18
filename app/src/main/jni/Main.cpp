bool aimbotEnabled = false;
float fovValue = 90.0f;
bool espDrawEnabled = false;
bool noRecoilEnabled = false;
bool noSpreadEnabled = false;
bool fastReloadEnabled = false;

AddToggle("Aimbot Headshot", &aimbotEnabled);
AddSlider("Aimbot FOV", &fovValue, 1.0f, 180.0f);
AddToggle("ESP Draw", &espDrawEnabled);
AddToggle("No Recoil", &noRecoilEnabled);
AddToggle("No Spread", &noSpreadEnabled);
AddToggle("Fast Ammunition Loading", &fastReloadEnabled);
