# EncoderMotor Control System

A PlatformIO-based Arduino project for precise motor speed control and RPM monitoring using rotary encoders. This system enables closed-loop speed feedback and I2C communication capabilities for real-time motor telemetry.

## Features

- **Real-time RPM Calculation**: Accurate RPM monitoring using rotary encoder pulses with interrupt-driven counting
- **Potentiometer Speed Control**: Dynamic motor speed adjustment via analog input
- **I2C Slave Support**: Communicate with master controllers (Raspberry Pi, etc.) via I2C protocol
- **Configurable Sampling**: Adjustable RPM calculation frequency (default 60Hz)
- **Direction Control**: Full bidirectional motor operation with speed regulation
- **Pulse Counter**: Tracks total pulses and per-sample pulse counts for diagnostic purposes

## Hardware Requirements

- Arduino Uno
- Rotary Encoder (quadrature or single-channel)
- DC Motor with L298N H-bridge driver
- Potentiometer (10kΩ recommended)
- Power supply (5V for Arduino, 12V for motor)

## Pin Configuration

| Component | Pin | Function |
|-----------|-----|----------|
| Encoder | 2 | Interrupt-based pulse counting (RISING edge) |
| Motor Enable | 4 | PWM speed control (0-255) |
| Motor Direction | 16 | Direction control IN1 |
| Motor Direction | 17 | Direction control IN2 |
| Potentiometer | 12 | Analog input for speed reference |

## Software Architecture

### Main Components

- **counter()**: Interrupt service routine triggered on encoder rising edges
- **forward()**: Motor control function handling direction and PWM speed
- **setup()**: GPIO initialization and interrupt configuration
- **loop()**: Speed regulation and RPM calculation loop

### I2C Communication

Default slave address: `0x01`

Data format: `"Cnt:<count>\n"` (counter value with newline terminator)

## Project Structure

```
encoders/
├── src/
│   └── main.cpp                    # Primary motor control firmware
├── test/
│   ├── encoder_i2c_slave.cpp      # I2C slave variant for remote control
│   ├── encoder_without_serial.cpp # Minimal variant without serial output
│   └── rpm_calculation_test.cpp   # RPM calculation verification tests
├── include/                        # Header files (if needed)
├── lib/                           # External libraries
└── platformio.ini                 # Build configuration
```

## Build & Upload

### Prerequisites
- [PlatformIO](https://platformio.org/) installed
- Arduino IDE or PlatformIO IDE

### Build
```bash
platformio run -e uno
```

### Upload
```bash
platformio run -e uno --target upload
```

### Monitor Serial Output
```bash
platformio device monitor -b 9600
```

## Usage

1. Connect rotary encoder to pin 2 (interrupt pin)
2. Connect potentiometer to pin 12 (analog input)
3. Connect motor driver (L298N) to pins 4, 16, 17
4. Upload firmware using PlatformIO
5. Motor speed follows potentiometer position (50-255 PWM range)
6. View real-time RPM data via Serial Monitor at 9600 baud

### Expected Output
```
25 pulses: 1875 rpm: 23.43750
24 pulses: 1899 rpm: 22.50000
26 pulses: 1925 rpm: 24.37500
```

## Configuration

Edit these values in `main.cpp` to customize behavior:

```cpp
#define freq_for_rpm 60        // RPM calculation frequency (Hz)
#define I2C_SLAVE_ADDR 0x01    // I2C slave address for remote control
analogWrite(ENA, rightSpeed);  // PWM range 0-255
```

## Testing Variants

- **encoder_i2c_slave.cpp**: I2C slave variant for remote control via Raspberry Pi
- **encoder_without_serial.cpp**: Minimal variant for systems without serial monitoring
- **rpm_calculation_test.cpp**: Test and verification variant for RPM calculation accuracy

## Troubleshooting

| Issue | Solution |
|-------|----------|
| No RPM data in serial output | Check encoder connection to pin 2 and rising edge trigger |
| Inaccurate RPM values | Adjust encoder pulse-per-revolution constant (64 in code) |
| Motor not responding | Verify H-bridge connection and PWM pin functionality |
| I2C communication failing | Confirm slave address (0x01) matches master configuration |

## License

Open source for educational and commercial use.

## Author

Vilas