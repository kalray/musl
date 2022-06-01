/*
 * Each core of the Coolidge processor have a coprocessor. They share
 * the CS register but have distinct bit-fields for their
 * floating-point environment.
 * This implementation allow them to be managed separately.
 *
 * Compute Status ($cs) register contains the following bit-fields for
 * floating-point exception flags.
 *
 * Bit-field Condition of the IEEE 754 binary floating-point standard
 * --------- --------------------------------------------------------
 * IO        Invalid Operation
 * DZ        Divide by Zero
 * OV        Overflow
 * UN        Underflow
 * IN        Inexact
 * XIO       Invalid Operation (coprocessor)
 * XDZ       Divide by Zero (coprocessor)
 * XOV       Overflow (coprocessor)
 * XUN       Underflow (coprocessor)
 * XIN       Inexact (coprocessor)
 */

#define FE_INVALID   0x02
#define FE_DIVBYZERO 0x04
#define FE_OVERFLOW  0x08
#define FE_UNDERFLOW 0x10
#define FE_INEXACT   0x20

#define FE_X_INVALID   0x0200
#define FE_X_DIVBYZERO 0x0400
#define FE_X_OVERFLOW  0x0800
#define FE_X_UNDERFLOW 0x1000
#define FE_X_INEXACT   0x2000

#define _FE_EXCEPT (FE_INVALID|FE_DIVBYZERO|FE_OVERFLOW|FE_UNDERFLOW|FE_INEXACT)
#define _FE_X_EXCEPT \
	(FE_X_INVALID|FE_X_DIVBYZERO|FE_X_OVERFLOW|FE_X_UNDERFLOW|FE_X_INEXACT)

#define FE_ALL_EXCEPT (_FE_EXCEPT|_FE_X_EXCEPT)

/*
 * Compute Status ($cs) register contains the following bit-fields for
 * floating-point rounding modes.
 *
 * Following table describes both the RM and XRM (coproc) bit-fields.
 *
 * Value Rounding Mode of the IEEE 754 binary floating-point standard
 * ----- ------------------------------------------------------------
 * 0b00  to nearest even
 * 0b01  toward +inf
 * 0b10  toward -inf
 * 0b11  toward zero
 */

#define _FE_TONEAREST  0
#define _FE_UPWARD     1
#define _FE_DOWNWARD   2
#define _FE_TOWARDZERO 3

#define _FE_X_TONEAREST  0
#define _FE_X_UPWARD     1
#define _FE_X_DOWNWARD   2
#define _FE_X_TOWARDZERO 3

#define FE_TONEAREST  ((_FE_TONEAREST  << 16) | (_FE_X_TONEAREST  << 20))
#define FE_UPWARD     ((_FE_UPWARD     << 16) | (_FE_X_UPWARD     << 20))
#define FE_DOWNWARD   ((_FE_DOWNWARD   << 16) | (_FE_X_DOWNWARD   << 20))
#define FE_TOWARDZERO ((_FE_TOWARDZERO << 16) | (_FE_X_TOWARDZERO << 20))

#define FE_RND_MASK FE_TOWARDZERO

/*
 * The type representing all floating-point status flags collectively.
 * The environment is simply a copy from the FPU related bits in the
 * CS register, but can be improved in the future.
 */
typedef unsigned long fexcept_t;
/*
 * The type representing the entire floating-point environment.
 * The environment is simply a copy from the FPU related bits in the CS
 * register.
 */
typedef	unsigned long fenv_t;

#define FE_DFL_ENV      ((const fenv_t *) -1)
