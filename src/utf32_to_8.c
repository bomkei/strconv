#include "strconv.h"

long utf32_to_utf8(u8 *out, u32 const* in, size_t len) {
  size_t rc = 0;
  size_t units;
  u8 encoded[4];

  while( *in ) {
    units = encode_utf8(encoded, *in++);

    if( units == -1 )
      return -1;

    if( out != NULL ) {
      if( rc + units <= len ) {
        *out++ = encoded[0];
        if( units > 1 ) *out++ = encoded[1];
        if( units > 2 ) *out++ = encoded[2];
        if( units > 3 ) *out++ = encoded[3];
      }
    }

    if( SIZE_MAX - units >= rc )
      rc += units;
    else
      return -1;
  }

  return rc;
}