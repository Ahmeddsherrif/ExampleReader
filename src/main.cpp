#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string readFile(const std::string& path) {
    std::ifstream in(path);
    if (!in.is_open()) {
        throw std::runtime_error("Cannot open file: " + path);
    }
    std::stringstream ss;
    ss << in.rdbuf();
    return ss.str();
}

int main() {
    try {
        const std::string ROOT = "/root/example/ExampleReader";

        const std::string authPath   = ROOT + "/authentication/auth.ini";
        const std::string certPath   = ROOT + "/certs/server.crt";
        const std::string etcPath    = ROOT + "/etc/data.txt";
        const std::string dbJsonPath = ROOT + "/config/database.json";
        const std::string paramPath  = ROOT + "/config/parameters.json";

        // AUTHENTICATION FILE
        readFile(authPath);
        std::cout << "[Main] Read file: " << authPath << "\n";

        // CERTIFICATE
        readFile(certPath);
        std::cout << "[Main] Read file: " << certPath << "\n";

        // TEXT DATA
        readFile(etcPath);
        std::cout << "[Main] Read file: " << etcPath << "\n";

        // JSON CONFIGS
        json db = json::parse(readFile(dbJsonPath));
        std::cout << "[Main] Read file: " << dbJsonPath << "\n";

        json params = json::parse(readFile(paramPath));
        std::cout << "[Main] Read file: " << paramPath << "\n";

        std::cout << "[Main] All files loaded successfully.\n";

    } catch (const std::exception& ex) {
        std::cerr << "[Main] ERROR: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
