#ifndef MOTOR_H
#define MOTOR_H

#include "mbed.h"
#include "encoder.h"

#define MOTOR_PWM_FREQ 25000 // Unit: Hz.

class Motor {
    private:
        PwmOut pwm;
        DigitalOut direction;
        DigitalOut bipolar;
        float pwmFrequency;
        float pwmDutyCycle;

    public:
        Motor(PinName pwmPin, PinName dirPin, PinName bipPin);
        void setPwmFrequency (float) ;
        float getPwmFrequency (void);
        void setPwmDutyCycle (float); 
        float getPwmDutyCycle (void);
        void setDirection (int);
        int getDirection (void);
        void setBipolar (int);
        int getBipolar (void);
}; 

// A motor module will contain an enable pin, two motors (left & right), and two encoders (left & right).
class MotorModule {
    private:
        DigitalOut motorEnable;
        DigitalOut encoderEnable;

    public:
        Motor leftMotor;
        Motor rightMotor;
        Encoder leftEncoder;
        Encoder rightEncoder;

        MotorModule(PinName mEnable, 
                    PinName lMotorPwm, PinName lMotorDir, PinName lMotorBip,
                    PinName rMotorPwm, PinName rMotorDir, PinName rMotorBip,
                    PinName eEnable,
                    PinName lEncoderChA, PinName lEncoderChB, 
                    PinName rEncoderChA, PinName rEncoderChB);

        // Set/get motor module enable status.
        void setMotorEnable (int);
        int getMotorEnable (void);

        // Set/get encoder enable. 
        void setEncoderEnable (int);
        int getEncoderEnable (void);




};

#endif
