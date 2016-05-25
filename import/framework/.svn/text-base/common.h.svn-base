#ifndef COMMON
#define COMMON

#include "stdint.h"

/**
 * @brief The Separator union
 * @detailed Для разбора числа по байтам в формате little-endian + функция сборки
 */
union Separator
{
    uint64_t word_;
    struct
    {
        uint8_t b0_;
        uint8_t b1_;
        uint8_t b2_;
        uint8_t b3_;
        uint8_t b4_;
        uint8_t b5_;
        uint8_t b6_;
        uint8_t b7_;
    };

    Separator( uint64_t word = 0 )
        : word_( word )
    {;}

    /**
     * @brief Builder
     * @param b0
     * @param b1
     * @param b2
     * @param b3
     * @param b4
     * @param b5
     * @param b6
     * @param b7
     */
    void Builder(uint8_t b0, uint8_t b1 = 0, uint8_t b2 = 0, uint8_t b3 = 0, uint8_t b4 = 0,
            uint8_t b5 = 0, uint8_t b6 = 0, uint8_t b7 = 0)
    {
        b0_ = b0;
        b1_ = b1;
        b2_ = b2;
        b3_ = b3;
        b4_ = b4;
        b5_ = b5;
        b6_ = b6;
        b7_ = b7;
    }

    void clear() { word_ = 0; }
};

namespace UdpMessage
{
    /**
     * @brief Размеры добавочной части массива
     */
    enum
    {
        IpSize     = 4,
        PortSize   = 2,
        HeaderSize = 6
    };
}

typedef enum
{
    PLUGIN_NONE,
    PLUGIN_PORT,
    PLUGIN_TRANSPORT,
    PLUGIN_DEVICE,
    PLUGIN_TASK,
    PLUGIN_GUI,
    PLUGIN_STORE,
    PLUGIN_CHANNEL
} PluginType;

typedef enum
{
    PROCESS_NONE,
    PROCESS_CORE,
    PROCESS_CHANNEL,
    PROCESS_TASK,
    PROCESS_STORE,
    PROCESS_GUI
} ProcessType;

#endif // COMMON
