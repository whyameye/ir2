#include "main.h"

void setup() {
    Serial.begin(115200);
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
    Serial.println("starting...");
}

void loop() {
    static int8_t lastJ = -1;
    int8_t j = -1;
    static boolean debounce = false;
    static uint32_t lastDecodeTime = 0;
    uint32_t decodeTime;

    if (IrReceiver.decode()) {
        decodeTime = millis();
        //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        //Serial.println(IrReceiver.decodedIRData.protocol);
        for (int8_t i = 0; i < sizeof(data); i++) {
            if (((IrReceiver.decodedIRData.protocol == 1) && (IrReceiver.decodedIRData.decodedRawData == data[i])) ||
                ((IrReceiver.decodedIRData.protocol == 0) && (IrReceiver.decodedIRData.decodedRawData == raw[i]))) {
                j = i;
                break;
            }
        }
        if (j != lastJ) lastDecodeTime = 0;
        if ((decodeTime - lastDecodeTime) > REPEAT_THRESH) {
            if (j == -1)
                Serial.println("Unknown button");
            else
                Serial.println(name[j]);
        }
        lastJ = j;
        lastDecodeTime = decodeTime;
    }
    IrReceiver.resume(); // Enable receiving of the next value
}