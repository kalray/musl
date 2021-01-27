#define LDSO_ARCH "kvx"

#define NO_LEGACY_INITFINI

#define REL_SYMBOLIC    R_KVX_64
#define REL_GOT         R_KVX_GLOB_DAT
#define REL_PLT         R_KVX_JMP_SLOT
#define REL_RELATIVE    R_KVX_RELATIVE
#define REL_COPY        R_KVX_COPY
#define REL_DTPMOD      R_KVX_64_DTPMOD
#define REL_DTPOFF      R_KVX_64_DTPOFF
#define REL_TPOFF       R_KVX_64_TPOFF

#define CRTJMP(pc, sp) __asm__ __volatile__(\
	"copyd $sp = %1\n" \
	"igoto %0\n" \
	";;\n" : : "r"(pc), "r"(sp) : "memory")
