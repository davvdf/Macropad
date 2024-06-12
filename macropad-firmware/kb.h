#define KB_H

#include "quantum.h"

#define LAYOUT( \
	K00,      K02, K03, K04, K05, K06, K07, \
	K10, K11, K12, K13, K14, K15, K16, K17, \
	K20, K21, K22, K23, K24, K25, K26, K27, \
	K30,      K32, K33, K34, K35, K36,      \
	K40, K41, K42, K43, K44, K45, K46, K47, \
	K50, K51, K52, K53, K54,      K56, K57  \
) { \
	{ K00,   KC_NO, K02,   K03,   K04,   K05,   K06,   K07 }, \
	{ K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17 }, \
	{ K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27 }, \
	{ K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   KC_NO }, \
	{ K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47 }, \
	{ K50,   K51,   K52,   K53,   K54,   KC_NO, K56,   K57 }  \
}

