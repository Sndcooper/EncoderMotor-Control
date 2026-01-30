# Include Directory

This directory is reserved for custom header files (.h or .hpp) used in the encoder motor control project.

## Usage

Place any custom headers here that define:
- Configuration constants and macros
- Custom data structures for motor control
- Function declarations for shared utilities
- I2C communication protocols
- Sensor calibration parameters

## Example Structure

```cpp
// motor_config.h
#ifndef MOTOR_CONFIG_H
#define MOTOR_CONFIG_H

#define ENCODER_PIN 2
#define PWM_PIN 4
#define DIRECTION_PIN1 16
#define DIRECTION_PIN2 17
#define SPEED_SENSOR_PIN 12

#endif
```

## PlatformIO Integration

The build system automatically includes this directory in the compiler search path. Any headers added here will be automatically available to source files.
