#include "strconv.h"

long utf8_to_utf32(u32* out, u8 const* in, size_t len) {
  size_t rc = 0;
  size_t units;
  u32 code;

  do {
    units = decode_utf8(&code, in);

    if( units == -1 )
      return -1;

    if( code > 0 ) {
      in += units;

      if( out != NULL ) {
        if( rc < len )
          *out++ = code;
      }

      if( SIZE_MAX - 1 >= rc )
        ++rc;
      else
        return -1;
    }
  } while( code > 0 );

  return rc;
}