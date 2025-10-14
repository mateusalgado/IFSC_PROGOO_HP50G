#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Settings
{
public:
    Settings()
    {
        // Create file if does not exist.
        file.open("settings.sema", std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
        if (!file.is_open())
        {
            printf_s("Falha ao abrir/criar configurações.\n");
            return;
        }
        file.close();

        // Open with read & write at any pos.
        file.open("settings.sema", std::ios::binary | std::ios::in | std::ios::out);
        if (!file.is_open())
        {
            printf_s("Falha ao abrir/criar configurações.\n");
            return;
        }
    };

    void save()
    {
        // Move to the beginning  of the file.
        file.seekp(0, std::ios::beg);

        // Write brokerAddr char count.
        unsigned len = brokerAddr.length();
        file.write(reinterpret_cast<char *>(&len), sizeof(len));

        // Write brokkerAddr.
        file.write(brokerAddr.c_str(), sizeof(char) * len);

        // Write registered station's ID.
        for (auto &station : stations)
            file.write(reinterpret_cast<char *>(&station), sizeof(station));
    };

    void load()
    {
        // Move to the beginning  of the file.
        file.seekg(0, std::ios::beg);

        // Grab brokerAddr char count;
        unsigned chars;
        file.read(reinterpret_cast<char *>(&chars), sizeof(chars));

        // Read brokerAddr chars to a payload buffer.
        std::vector<char> buffer(chars);
        file.read(buffer.data(), chars);

        // Dump payload into brokerAddr;
        brokerAddr.assign(buffer.data(), chars);
        if (file.tellg() == fileSize())
        {
            printf_s("[SETTINGS] No stations found in settings file.\n");
            return;
        }

        while (file.tellg() != fileSize())
        {
            unsigned id;
            file.read(reinterpret_cast<char *>(&id), sizeof(id));
            stations.push_back(id);
        }
    };

    void close()
    {
        file.close();
    }

    std::string brokerAddr;
    std::vector<unsigned> stations;

    bool isFileEmpty()
    {
        return (fileSize() == 0);
    }

private:
    std::streampos fileSize()
    {
        // Save cur pos;
        auto fpos = file.tellg();
        // Goto end of file;
        file.seekg(0, std::ios::end);
        // Read pos;
        std::streampos s = file.tellg();
        // Seek back to saved pos;
        file.seekg(fpos);
        return s;
    }

    std::fstream file;

private:
};
