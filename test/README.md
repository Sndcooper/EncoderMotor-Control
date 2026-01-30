# Testing & Variant Builds

This directory contains test implementations and alternative firmware variants for the encoder motor control system.

## Available Test Variants

### encoder_i2c_slave.cpp
**Purpose**: I2C slave implementation for remote motor control

**Features**:
- Operates as I2C slave (address 0x01)
- Responds to data requests from master controller (Raspberry Pi)
- Returns counter value formatted as `"Cnt:<value>\n"`
- Suitable for distributed control systems

**When to Use**: Integration with Raspberry Pi or other I2C master devices

### encoder_without_serial.cpp
**Purpose**: Lightweight variant without serial communication

**Features**:
- Minimal code footprint for memory-constrained systems
- Core motor control without debug output
- Faster execution due to no serial overhead
- Suitable for embedded applications with limited resources

**When to Use**: Production builds where serial monitoring isn't available

### rpm_calculation_test.cpp
**Purpose**: Testing and verification of RPM calculation accuracy

**Features**:
- Focuses on encoder pulse-per-revolution calibration
- Detailed RPM output with higher precision
- Useful for validating motor specifications
- Can be used with test fixtures and known-speed references

**When to Use**: Commissioning, calibration, and accuracy verification

## Running Tests

### Build a Specific Variant
```bash
platformio run -e uno
```

### Upload to Arduino
```bash
platformio run -e uno --target upload
```

### Monitor Output
```bash
platformio device monitor -b 9600
```

## Test Procedures

### RPM Accuracy Verification
1. Load `rpm_calculation_test.cpp`
2. Set potentiometer to known speed (50%, 75%, 100%)
3. Run motor for 30 seconds
4. Record average RPM output
5. Compare against manufacturer specifications

### I2C Communication Test
1. Load `encoder_i2c_slave.cpp` on Arduino
2. Connect I2C master device (e.g., Raspberry Pi)
3. Request data from slave address 0x01
4. Verify counter values match expected pulse count

### Power Efficiency Test
1. Load `encoder_without_serial.cpp`
2. Measure current draw at various speeds
3. Compare with full-featured main.cpp

## Expected Behavior

| Variant | Serial Output | I2C Support | Resources |
|---------|---------------|-------------|-----------|
| main.cpp | ✓ Full data | - | Full |
| encoder_i2c_slave.cpp | Minimal | ✓ Master compatible | Medium |
| encoder_without_serial.cpp | None | - | Minimal |
| rpm_calculation_test.cpp | ✓ Detailed RPM | - | Full |

## Troubleshooting Tests

- **No output**: Check Serial Monitor baud rate (9600)
- **Inconsistent RPM**: Verify encoder connection and RISING edge trigger
- **I2C not responding**: Confirm slave address matches configuration
- **Memory issues**: Use `encoder_without_serial.cpp` variant

## Adding New Tests

Create new `.cpp` files following the structure:
```cpp
#include <Arduino.h>
#include <Wire.h>

// Your test code here

void setup() {
    // Initialization
}

void loop() {
    // Test logic
}
```

PlatformIO will automatically detect and compile any `.cpp` files in this directory.
