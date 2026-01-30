# Library Directory

This directory contains external libraries and dependencies for the encoder motor control project.

## Included Libraries

### Wire
- **Purpose**: I2C/TWI communication protocol
- **Usage**: Master/slave communication with sensors and controllers
- **Status**: Built-in Arduino library

## Adding External Libraries

### Via PlatformIO
Add to `platformio.ini`:
```ini
lib_deps =
    Wire
    AccelStepper
    timers-lib
```

### Manual Installation
Place library folders in this directory with the following structure:
```
lib/
├── LibraryName/
│   ├── src/
│   │   └── LibraryName.cpp
│   ├── include/
│   │   └── LibraryName.h
│   └── library.json
```

## Dependencies

- **Wire**: Built-in I2C library for Arduino
- **Arduino.h**: Core Arduino runtime library

## Future Library Needs

Potential libraries for expanded functionality:
- **PID Control**: For closed-loop speed feedback
- **AccelStepper**: Advanced stepper motor control
- **LiquidCrystal**: LCD display support
- **EEPROM**: Non-volatile parameter storage
