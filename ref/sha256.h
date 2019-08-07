#ifndef SPX_SHA256_H
#define SPX_SHA256_H

#define SPX_SHA256_BLOCK_BYTES 64
#define SPX_SHA256_OUTPUT_BYTES 32  /* This does not necessarily equal SPX_N */

#if SPX_SHA256_OUTPUT_BYTES < SPX_N
    #error Linking against SHA-256 with N larger than 32 bytes is not supported
#endif

#define SPX_SHA256_ADDR_BYTES 22

#include <stddef.h>
#include <stdint.h>

#ifdef USE_OPENSSL_SHA256 // If you don't want to use an external library's SHA256 implementation

#include <openssl/sha.h>

#endif // USE_OPENSSL_SHA256 endif

void sha256_inc_init(uint8_t *state);
void sha256_inc_blocks(uint8_t *state, const uint8_t *in, size_t inblocks);
void sha256_inc_finalize(uint8_t *out, uint8_t *state, const uint8_t *in, size_t inlen);
void sha256(uint8_t *out, const uint8_t *in, size_t inlen);

void compress_address(unsigned char *out, const uint32_t addr[8]);

void mgf1(unsigned char *out, unsigned long outlen,
          const unsigned char *in, unsigned long inlen);

void seed_state(const unsigned char *pub_seed);

uint8_t state_seeded[40];

#endif
