#include <napi.h>
#include <chrono>
#include <ctime>

Napi::Value GetTrollTime(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    // Получаем реальное время
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    struct tm* parts = std::localtime(&now_c);

    // Логика троллинга: всегда показываем 03:00, если сейчас ночь, 
    // или просто прибавляем 4 часа
    int troll_hour = (parts->tm_hour + 4) % 24;
    
    char buffer[10];
    sprintf(buffer, "%02d:%02d", troll_hour, parts->tm_min);
    
    return Napi::String::New(env, buffer);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("getTrollTime", Napi::Function::New(env, GetTrollTime));
    return exports;
}

NODE_API_MODULE(troll_clock, Init)
