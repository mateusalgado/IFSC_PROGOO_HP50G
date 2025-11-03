#include <settings.hpp>

int main()
{
    Settings settings;
    if (settings.isFileEmpty())
    {
        // TODO: Configurar via UI QT;
        printf_s("[SETTINGS] Empty settings file.\n");
        settings.brokerAddr = "teste";
        settings.stations.push_back(1);
        settings.stations.push_back(2);
        settings.stations.push_back(3);
        settings.save();
        printf_s("[SETTINGS] Saved sample settings.\n");
    }

    settings.load();
    printf_s("- BROKER ADDR: %s\n", settings.brokerAddr.c_str());
    for (auto &s : settings.stations)
        printf_s("- Found station: %i\n", s);
    settings.close();
}