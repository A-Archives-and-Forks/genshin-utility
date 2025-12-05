#include <thread>

#include <core/gu.hpp>

namespace {

void Init() {
  using namespace std::chrono_literals;
  
  while (GetModuleHandleA("StarRail.exe") && (!GetModuleHandleA("UnityPlayer.dll") || !GetModuleHandleA("GameAssembly.dll")))
    std::this_thread::sleep_for(10ms);

  static auto gu = GenshinUtility();
}

}

BOOL WINAPI DllMain(HINSTANCE module, DWORD reason, LPVOID) {
  DisableThreadLibraryCalls(module);

  if (reason == DLL_PROCESS_ATTACH)
    std::thread(Init).detach();

  return TRUE;
}
