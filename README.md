# JOAAT
Simple Implementation of the Jenkin's HASH for Arduino.

#### Encode Hash
```cpp
#include <JOAAT.h>

JOAAT joaat;

JOAAT_STR str = (const unsigned char*)"0xDEADBEEF";

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  Serial.print("Calculated JOAAT Hash: ");
  Serial.println(joaat.encode_str(str), HEX);

}

void loop() {
  // not used in this example.
}
```

#### Encode And Check If The Hash Is Valid
```cpp
#include <JOAAT.h>

JOAAT joaat;

JOAAT_STR str = (const unsigned char*)"0xDEADBEEF";

void setup() {
  Serial.begin(115200);
  Serial.print("Calculated JOAAT Hash: ");
  auto jooat_HASH = joaat.encode_str(str);
  Serial.println(jooat_HASH, HEX);
  Serial.print("Is JOAAT string valid: ");
  Serial.println(joaat.validate_string_checksum(str, 0x5F3CC755) ? "true" : "false");
}

void loop() {
  // not used in this example.
}
```

#### Validate The Joaat Hash
```cpp
#include <JOAAT.h>

JOAAT joaat;

JOAAT_STR str = (const unsigned char*)"0xDEADBEEF";

void setup() {
  Serial.begin(115200);
  Serial.print("Calculated JOAAT Hash: ");
  auto jooat_HASH = joaat.encode_str(str);
  Serial.println(jooat_HASH, HEX);
  Serial.print("Is JOAAT valid: ");
  Serial.println(joaat.validate_checksum(jooat_HASH, 0x5F3CC755) ? "true" : "false");
}

void loop() {
  // not used in this example.
}
```
