#pragma once

#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint8_t u8;

long decode_utf8(u32* out, u8 const* in);
long encode_utf8(u8* out, u32 in);

long utf8_to_utf32(u32* out, u8 const* in, size_t len);
long utf32_to_utf8(u8 *out, u32 const* in, size_t len);

