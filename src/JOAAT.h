/*
  JOAAT.h - Implementation of the Jenkin's HASH for Arduino.
  Created by alessandromrc, 27 September 2022.
*/


#ifndef JOAAT_H_
#define JOAAT_H_

typedef const unsigned char* JOAAT_STR;


class JOAAT {
private:
  uint32_t encode(const uint8_t* key, size_t length) {
    size_t i = 0;
    uint32_t hash = 0;
    while (i != length) {
      hash += key[i++];
      hash += hash << 10;
      hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
  }
public:

  uint32_t encode_str(JOAAT_STR str) {
    return encode(str, strlen((char*)str));
  }

  bool validate_string_checksum(JOAAT_STR str, uint32_t checksum) {
    if (encode_str(str) == checksum)
      return true;

    return false;
  }

  bool validate_checksum(uint32_t checksum1, uint32_t checksum2) {
    return (checksum1 == checksum2);
  }
};

#endif
