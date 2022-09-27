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

  Serial.print("Is JOAAT valid: ");
  Serial.println(joaat.validate_checksum(jooat_HASH, 0x5F3CC755) ? "true" : "false");
}

void loop() {
  // put your main code here, to run repeatedly:
}
