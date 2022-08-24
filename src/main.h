//
// Created by user on 8/20/22.
//

#ifndef IR2_MAIN_H
#define IR2_MAIN_H

#include "IRremote.hpp"
#define IR_RECEIVE_PIN 14
#define REPEAT_THRESH 220 // ms

unsigned long raw[] = {0xF1EDA99A, 0x79D60DFE, 0xF02EF976, 0xF5F178FA, 0x168574D6, 0x896E999A, 0xB828069A, 0x8A563612, 0x8B036776,
                       0xBFE64FB6, 0xEE9FBCB6, 0xB79F805E, 0xC189BA7F, 0xD8337C3A, 0xC35851D2, 0xFA15CAB6, 0xF0C04A5A,
                       0x1281A576, 0x277DC33E, 0xA29A2337, 0x1FE728BB, 0xFF532CDF};
unsigned long data[] = {0x23239B, 0x24237B, 0x25235B, 0x2F221B, 0x2E223B, 0x2D225B, 0x2C227B, 0x2B229B, 0x2A22BB,
                        0x2922DB, 0x2822FB, 0x27231B, 0x1C247B, 0x26233B, 0x3021FB, 0x2023FB, 0x3121DB,
                        0x2223BB, 0x2123DB, 0x1D245B, 0x1E243B, 0x1F241B};

String name[] = {"off", "au", "prg","1", "2", "3","4", "5", "6", "7","8","9","sel","0","buy","rcl",
                 "lch","ch+","ch-","mute","vol-","vol+"};

#endif //IR2_MAIN_H
