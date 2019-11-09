#ifndef __GO_TYPES_H__
#define __GO_TYPES_H__
//#include <types.h>
#include <stdint.h>

#define GO_OK            (0)
#define GO_ERROR         (-1)
#define GO_WIN             1

#define BIT(X)      (1 << (X))
#define	L_BIT(N)	BIT(N)

#define PACK_STRUCT __attribute__((packed))


#undef FALSE
#undef TRUE

#ifndef BOOLEAN_TYPE
#define BOOLEAN_TYPE
typedef enum { FALSE = 0, TRUE = 1 } Boolean;
#endif


typedef unsigned char		u8;
typedef signed char			s8;

typedef unsigned short		u16;
typedef unsigned int		u32;
typedef signed int			s32;

typedef int64_t			    s64;
typedef uint64_t			u64;


typedef unsigned char		unchar;
typedef unsigned short		ushort;
typedef unsigned int		uint;

#endif  /* __SM_TYPES_H__ */
