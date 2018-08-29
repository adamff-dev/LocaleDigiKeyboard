#include "DigiKeyboard.h"
#ifndef LOCALEDIGIKEYBOARD_H
#define LOCALEDIGIKEYBOARD_H

#define SHIFT      (1<<9)
#define ALT        (1<<14)

// PASTE HERE SOME LOCALE FILE CONTENT. Ex.: en_UK.lang

class LocaleDigiKeyboardDevice : public DigiKeyboardDevice{
    public:
    size_t write(uint8_t chr) {
        unsigned int temp = pgm_read_word_near(_ascii_custom_map + chr);
        unsigned char low = temp & 0xFF;
        unsigned char high = (temp >> 8) & 0xFF;
        sendKeyStroke(low,high);
        return 1;
    }
    void sendKeyReport(uchar *array,const unsigned int size){
        while (!usbInterruptIsReady()) {
            usbPoll();
            _delay_ms(5);
        }

        usbSetInterrupt(array, size);
    }
};
LocaleDigiKeyboardDevice LocaleDigiKeyboard = LocaleDigiKeyboardDevice();
#endif //LOCALEDIGIKEYBOARD_H
